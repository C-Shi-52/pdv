// ����PDV�ӿ�ͷ�ļ�  
#include "DftBase.h"  
#include "PDVISceneData.h"  
#include "PDVIObjectFactory.h"  
#include "PDVFile.h"  

// ģ�������ͷ�ļ�  
#include "PDVIModelTree.h"  
#include "PDVIModelTreeNode.h"  
#include "PDVIModel.h"  

// ���κ��������ͷ�ļ�  
#include "PDVIBRep.h"  
#include "PDVITopo.h"  
#include "PDVIGeomPointData.h"  
#include "PDVIGeomCurveData.h"  
#include "PDVIGeomSurfaceData.h"  

// ��Ⱦ���ͷ�ļ�  
#include "PDVIRenderBody.h"  
#include "PDVIRenderMesh.h"  
#include "PDVIRenderVertex.h"  
#include "PDVIReferenceGeometry.h"  

// �������ͷ�ļ�  
#include "PDVIAttribute.h"  
#include "PDVIAttributeGroup.h"  
#include "PDVIAttributeItem.h"  

// ��ע���ͷ�ļ�  
#include "PDVIAnnotation.h"  
#include "PDVIAnnotationItem.h"  
#include "PDVIAnnotationView.h"  
#include "PDVIAnnotationGeometry.h"  

// ��׼��ͷ�ļ�  
#include <fstream>  
#include <vector>  
#include <iostream>  
#include <iomanip>  
#include <stack>  
#include <sstream>  
#include <map>  
#include <set>  
#include <functional>  
#include <Windows.h> // ���ڴ���Ŀ¼  

using namespace std;
using namespace kernel::pdv;

// ���ݽṹ����  
struct NodeInfo {
    DftUInt64 nodeID;
    string nodeName;
    string modelName;
    PDVMatrix4F worldTransform;
    DftUInt64 parentID;
    bool hasModel;
    map<string, string> attributes;

    // ����PMI�����Ϣ  
    struct PMIData {
        DftUInt64 annotationID;
        string annotationType;
        string annotationName;
        string viewMode;
        map<string, string> properties;
    };
    vector<PMIData> pmiData;  // һ���ڵ�����ж��PMI��ע  
};

// ȫ�ֱ����洢�ڵ���Ϣ  
vector<NodeInfo> g_nodeInfos;

// ��������  
void CollectNodeInfo(ISceneData* iSceneData, const string& outputDir);
void CollectPMIData(IAnnotation* annotation, vector<NodeInfo::PMIData>& pmiData);
void CollectAttributes(IAttribute* attr, map<string, string>& attributes);
void MatrixToTransform(const PDVMatrix4F& matrix, float& x, float& y, float& z,
    float& qx, float& qy, float& qz, float& qw,
    float& sx, float& sy, float& sz);
void GenerateCSVFiles(const string& outputDir);
void TraverseModelTree(ISceneData* iSceneData, const string& outputDir);
void ProcessTreeNode(IModelTreeNode* node, int depth, ISceneData* sceneData, const string& outputDir);
void PrintAttributeInfo(IAttribute* attr, int depth);
void PrintPMIInfo(IAnnotation* annotation, int depth);
void ExportBRepAsText(IBRep* bRep, const string& filename);
string TopoTypeToString(DftUInt8 topoType);
string OrientationToString(DftUInt8 orientation);
string GeomTypeToString(DftUInt8 geomType);
bool ExportNodeToStl(ISceneData* iSceneData, IModelTreeNode* node, const string& stlPath);

// ����ת��Ϊλ�ú���ת��PDV�Ѿ���ȫ������ϵ��  
void MatrixToTransform(const PDVMatrix4F& matrix, float& x, float& y, float& z,
    float& qx, float& qy, float& qz, float& qw,
    float& sx, float& sy, float& sz) {

    // ��ȡλ����Ϣ��4x4����ĵ�4��ǰ3��Ԫ�أ�  
    x = matrix[0][3];
    y = matrix[1][3];
    z = matrix[2][3];

    // ��ȡ������Ϣ�����������ĳ��ȣ�  
    sx = sqrt(matrix[0][0] * matrix[0][0] + matrix[1][0] * matrix[1][0] + matrix[2][0] * matrix[2][0]);
    sy = sqrt(matrix[0][1] * matrix[0][1] + matrix[1][1] * matrix[1][1] + matrix[2][1] * matrix[2][1]);
    sz = sqrt(matrix[0][2] * matrix[0][2] + matrix[1][2] * matrix[1][2] + matrix[2][2] * matrix[2][2]);

    // �������ֵ��С��ʹ�õ�λ����  
    if (sx < 1e-6f) sx = 1.0f;
    if (sy < 1e-6f) sy = 1.0f;
    if (sz < 1e-6f) sz = 1.0f;

    // �򻯴�����ʱʹ�õ�λ��Ԫ��  
    // �����Ҫ��ȷ����ת��Ϣ�����Ժ�������ת���󲿷ּ���  
    qx = qy = qz = 0.0f;
    qw = 1.0f;
}

// �ռ��ڵ���Ϣ�ı�������  
void CollectNodeInfo(ISceneData* iSceneData, const string& outputDir)
{
    if (!iSceneData) return;

    g_nodeInfos.clear();

    std::vector<IModelTree*> modelTreeArray;
    iSceneData->GetModelTreeArray(modelTreeArray);

    for (DftUInt t = 0; t < modelTreeArray.size(); t++)
    {
        IModelTree* tree = modelTreeArray[t];
        if (!tree) continue;

        IModelTreeNode* rootNode = nullptr;
        if (tree->GetRootNode(rootNode) == PDV_RESULT_NO_ERROR && rootNode)
        {
            stack<pair<pair<IModelTreeNode*, int>, DftUInt64>> nodeStack;
            nodeStack.push(make_pair(make_pair(rootNode, 0), 0));

            while (!nodeStack.empty())
            {
                IModelTreeNode* currentNode = nodeStack.top().first.first;
                int depth = nodeStack.top().first.second;
                DftUInt64 parentID = nodeStack.top().second;
                nodeStack.pop();

                NodeInfo nodeInfo;
                nodeInfo.nodeID = currentNode->GetID();
                nodeInfo.parentID = parentID;

                CUnicodeString nodeName;
                currentNode->GetName(nodeName);
                nodeInfo.nodeName = nodeName.ToMultiByte();

                // ���������任��־λ����ȷ��ȡ�任����  
                if (currentNode->GetWorldTransformFlag())
                {
                    PDV_RESULT result = currentNode->GetWorldTransform(nodeInfo.worldTransform);
                    if (result != PDV_RESULT_NO_ERROR)
                    {
                        if (currentNode->GetLocalTransformFlag())
                        {
                            currentNode->GetLocalTransform(nodeInfo.worldTransform);
                        }
                        else
                        {
                            nodeInfo.worldTransform.SetIdentity();
                        }
                    }
                }
                else if (currentNode->GetLocalTransformFlag())
                {
                    currentNode->GetLocalTransform(nodeInfo.worldTransform);
                }
                else
                {
                    nodeInfo.worldTransform.SetIdentity();
                }

                nodeInfo.hasModel = currentNode->GetModelFlag();
                if (nodeInfo.hasModel)
                {
                    IModel* model = currentNode->GetModel();
                    if (model)
                    {
                        CUnicodeString modelName;
                        model->GetName(modelName);
                        nodeInfo.modelName = modelName.ToMultiByte();

                        IAttribute* attr = model->GetAttribute();
                        if (attr)
                        {
                            CollectAttributes(attr, nodeInfo.attributes);
                        }

                        IAnnotation* annotation = model->GetAnnotation();
                        if (annotation)
                        {
                            CollectPMIData(annotation, nodeInfo.pmiData);
                        }
                    }
                }

                g_nodeInfos.push_back(nodeInfo);

                std::vector<IModelTreeNode*> children;
                if (currentNode->GetChildren(children) == PDV_RESULT_NO_ERROR)
                {
                    for (int i = static_cast<int>(children.size()) - 1; i >= 0; i--)
                    {
                        if (children[i])
                        {
                            nodeStack.push(make_pair(make_pair(children[i], depth + 1), nodeInfo.nodeID));
                        }
                    }
                }
            }
        }
    }
}

// ����PMI�����ռ�����  
void CollectPMIData(IAnnotation* annotation, vector<NodeInfo::PMIData>& pmiData)
{
    if (!annotation) return;

    DftUInt itemCount = annotation->GetAnnotationItemCount();

    for (DftUInt i = 0; i < itemCount; i++)
    {
        IAnnotationItem* item = annotation->GetAnnotationItemByIndex(i);
        if (!item) continue;

        NodeInfo::PMIData pmi;
        pmi.annotationID = item->GetID();

        // ��ȡ��ע������  
        CUnicodeString itemType = item->GetType();
        pmi.annotationType = itemType.ToMultiByte();

        // ��ȡ��ע������  
        CUnicodeString itemName;
        if (item->GetName(itemName) == PDV_RESULT_NO_ERROR)
        {
            pmi.annotationName = itemName.ToMultiByte();
        }

        // ��ȡ��ʾģʽ  
        DftUInt8 viewMode = item->GetFaceViewMode();
        switch (viewMode)
        {
        case ANNOTATIONVIEWMODE_DEFAULTVIEW:
            pmi.viewMode = "Default View";
            break;
        case ANNOTATIONVIEWMODE_PARALLELSCREEN:
            pmi.viewMode = "Parallel Screen";
            break;
        case ANNOTATIONVIEWMODE_FIXEDSCREEN:
            pmi.viewMode = "Fixed Screen";
            break;
        default:
            pmi.viewMode = "Unknown";
            break;
        }

        // �ռ�����PMI����  
        DftUInt64 renderBodyID = item->GetRenderBodyID();
        if (renderBodyID != 0)
        {
            pmi.properties["RenderBodyID"] = to_string(renderBodyID);
        }

        RGBColor triangleColor = item->GetTriangleColor();
        stringstream colorStr;
        colorStr << "RGB(" << static_cast<int>(triangleColor._red) << ","
            << static_cast<int>(triangleColor._green) << ","
            << static_cast<int>(triangleColor._blue) << ")";
        pmi.properties["TriangleColor"] = colorStr.str();

        pmiData.push_back(pmi);
    }
}

// �ռ�������Ϣ  
void CollectAttributes(IAttribute* attr, map<string, string>& attributes)
{
    if (!attr) return;

    std::vector<IAttributeGroup*> attributeGroups;
    if (attr->GetAttributeGroupArray(attributeGroups) == PDV_RESULT_NO_ERROR)
    {
        for (DftUInt i = 0; i < attributeGroups.size(); i++)
        {
            IAttributeGroup* group = attributeGroups[i];
            if (!group) continue;

            std::vector<IAttributeItem*> attributeItems;
            if (group->GetAttributeItemArray(attributeItems) == PDV_RESULT_NO_ERROR)
            {
                for (DftUInt j = 0; j < attributeItems.size(); j++)
                {
                    IAttributeItem* item = attributeItems[j];
                    if (!item) continue;

                    CUnicodeString key;
                    if (item->GetKey(key) == PDV_RESULT_NO_ERROR)
                    {
                        string keyStr = key.ToMultiByte();
                        string valueStr = "";

                        DftUInt valueType = item->GetValueType();
                        switch (valueType)
                        {
                        case DATATYPE_BOOL:
                        {
                            DftBool boolValue;
                            if (item->GetBoolean(boolValue) == PDV_RESULT_NO_ERROR)
                                valueStr = boolValue ? "true" : "false";
                        }
                        break;
                        case DATATYPE_INT32:
                        {
                            DftInt intValue;
                            if (item->GetInteger(intValue) == PDV_RESULT_NO_ERROR)
                                valueStr = to_string(intValue);
                        }
                        break;
                        case DATATYPE_FLOAT:
                        {
                            DftFloat floatValue;
                            if (item->GetFloat(floatValue) == PDV_RESULT_NO_ERROR)
                                valueStr = to_string(floatValue);
                        }
                        break;
                        case DATATYPE_DOUBLE:
                        {
                            DftDouble doubleValue;
                            if (item->GetDouble(doubleValue) == PDV_RESULT_NO_ERROR)
                                valueStr = to_string(doubleValue);
                        }
                        break;
                        case DATATYPE_STRING:
                        {
                            CUnicodeString stringValue;
                            if (item->GetString(stringValue) == PDV_RESULT_NO_ERROR)
                                valueStr = stringValue.ToMultiByte();
                        }
                        break;
                        case DATATYPE_VECTOR3F:
                        {
                            PDVVector3F vectorValue;
                            if (item->GetVectorFloat3(vectorValue) == PDV_RESULT_NO_ERROR)
                            {
                                stringstream ss;
                                ss << "(" << vectorValue.x() << "," << vectorValue.y() << "," << vectorValue.z() << ")";
                                valueStr = ss.str();
                            }
                        }
                        break;
                        case DATATYPE_VECTOR3D:
                        {
                            PDVVector3D vectorValue;
                            if (item->GetVectorDouble3(vectorValue) == PDV_RESULT_NO_ERROR)
                            {
                                stringstream ss;
                                ss << "(" << vectorValue.x() << "," << vectorValue.y() << "," << vectorValue.z() << ")";
                                valueStr = ss.str();
                            }
                        }
                        break;
                        }

                        attributes[keyStr] = valueStr;
                    }
                }
            }
        }
    }
}

// ��������CSV�ļ�  
void GenerateCSVFiles(const string& outputDir)
{
    // 1. ���� produce_models.csv  
    ofstream modelsFile(outputDir + "\\produce_models.csv");
    modelsFile << "UUID,ʵ������,����ģ������,X,Y,Z,QX,QY,QZ,QW,SX,SY,SZ\n";

    for (const auto& nodeInfo : g_nodeInfos)
    {
        if (nodeInfo.hasModel)
        {
            float x, y, z, qx, qy, qz, qw, sx, sy, sz;
            MatrixToTransform(nodeInfo.worldTransform, x, y, z, qx, qy, qz, qw, sx, sy, sz);

            modelsFile << nodeInfo.nodeID << ","
                << "\"" << nodeInfo.nodeName << "\","
                << "\"" << nodeInfo.modelName << "\","
                << fixed << setprecision(6) << x << ","
                << y << "," << z << ","
                << qx << "," << qy << "," << qz << "," << qw << ","
                << sx << "," << sy << "," << sz << "\n";
        }
    }
    modelsFile.close();

    // 2. ���� product_tree.csv  
    ofstream treeFile(outputDir + "\\product_tree.csv");
    treeFile << "��UUID,��ʾ����,��ƷUUID,ʵ������\n";

    for (const auto& nodeInfo : g_nodeInfos)
    {
        treeFile << nodeInfo.parentID << ","
            << "\"" << nodeInfo.nodeName << "\","
            << nodeInfo.nodeID << ","
            << "\"" << nodeInfo.nodeName << "\"\n";
    }
    treeFile.close();

    // 3. ���� product_properties.csv  
    ofstream propsFile(outputDir + "\\product_properties.csv");

    set<string> allAttributeKeys;
    for (const auto& nodeInfo : g_nodeInfos)
    {
        for (const auto& attr : nodeInfo.attributes)
        {
            allAttributeKeys.insert(attr.first);
        }
    }

    propsFile << "UUID,ʵ������,�����,����,�汾";
    for (const auto& key : allAttributeKeys)
    {
        propsFile << ",\"" << key << "\"";
    }
    propsFile << "\n";

    for (const auto& nodeInfo : g_nodeInfos)
    {
        propsFile << nodeInfo.nodeID << ","
            << "\"" << nodeInfo.nodeName << "\","
            << "\"" << nodeInfo.modelName << "\","
            << "\"\","
            << "\"\"";

        for (const auto& key : allAttributeKeys)
        {
            auto it = nodeInfo.attributes.find(key);
            if (it != nodeInfo.attributes.end())
            {
                propsFile << ",\"" << it->second << "\"";
            }
            else
            {
                propsFile << ",\"\"";
            }
        }
        propsFile << "\n";
    }
    propsFile.close();

    // 4. ���� product_pmi.csv - ͳһ����PMI����  
    ofstream pmiFile(outputDir + "\\product_pmi.csv");

    // �ռ�����PMI���Լ�  
    set<string> allPMIKeys;
    for (const auto& nodeInfo : g_nodeInfos)
    {
        for (const auto& pmi : nodeInfo.pmiData)
        {
            for (const auto& prop : pmi.properties)
            {
                allPMIKeys.insert(prop.first);
            }
        }
    }

    // д��PMI��ͷ  
    pmiFile << "�ڵ�UUID,�ڵ�����,��עID,��ע����,��ע����,��ʾģʽ";
    for (const auto& key : allPMIKeys)
    {
        pmiFile << ",\"" << key << "\"";
    }
    pmiFile << "\n";

    // д��PMI������  
    for (const auto& nodeInfo : g_nodeInfos)
    {
        for (const auto& pmi : nodeInfo.pmiData)
        {
            pmiFile << nodeInfo.nodeID << ","
                << "\"" << nodeInfo.nodeName << "\","
                << pmi.annotationID << ","
                << "\"" << pmi.annotationType << "\","
                << "\"" << pmi.annotationName << "\","
                << "\"" << pmi.viewMode << "\"";

            for (const auto& key : allPMIKeys)
            {
                auto it = pmi.properties.find(key);
                if (it != pmi.properties.end())
                {
                    pmiFile << ",\"" << it->second << "\"";
                }
                else
                {
                    pmiFile << ",\"\"";
                }
            }
            pmiFile << "\n";
        }
    }
    pmiFile.close();
}

// ��������ת��Ϊ�ַ���  
string TopoTypeToString(DftUInt8 topoType)
{
    switch (topoType)
    {
    case TOPOTYPE_COMPOUND: return "COMPOUND";
    case TOPOTYPE_SOLID:    return "SOLID";
    case TOPOTYPE_SHELL:    return "SHELL";
    case TOPOTYPE_FACE:     return "FACE";
    case TOPOTYPE_LOOP:     return "LOOP";
    case TOPOTYPE_COEDGE:   return "COEDGE";
    case TOPOTYPE_EDGE:     return "EDGE";
    case TOPOTYPE_VERTEX:   return "VERTEX";
    default:                return "UNKNOWN";
    }
}

// ����ת��Ϊ�ַ���  
string OrientationToString(DftUInt8 orientation)
{
    switch (orientation)
    {
    case ORIENTATION_FORWARD:  return "FORWARD";
    case ORIENTATION_REVERSED: return "REVERSED";
    default:                   return "UNKNOWN";
    }
}

// ��������ת��Ϊ�ַ���  
string GeomTypeToString(DftUInt8 geomType)
{
    switch (geomType)
    {
    case GEOMTYPE_POINT:   return "POINT";
    case GEOMTYPE_CURVE:   return "CURVE";
    case GEOMTYPE_SURFACE: return "SURFACE";
    default:               return "UNKNOWN";
    }
}

// �޸ĺ����ת������  
DftBool Convert(const CUnicodeString& iPdvPath, const string& outputDir)
{
    IObjectFactory* piObjectFactory = IObjectFactory::GetObjectFactory();
    if (!piObjectFactory)
        return FALSE;

    ISceneData* sceneData = nullptr;
    PDV_RESULT res = piObjectFactory->CreateSceneData(sceneData);
    if (!sceneData)
        return FALSE;

    res = PDVFileServices::LoadSceneData(sceneData, iPdvPath);
    if (res != PDV_RESULT_NO_ERROR)
    {
        cout << "Error loading PDV file: " << res << endl;
        sceneData->Release();
        return FALSE;
    }

    // ȷ�����Ŀ¼����  
    if (!CreateDirectoryA(outputDir.c_str(), NULL)) {
        if (GetLastError() != ERROR_ALREADY_EXISTS) {
            cerr << "Failed to create output directory: " << outputDir << endl;
            sceneData->Release();
            return FALSE;
        }
    }

    // �ռ��ڵ���Ϣ  
    CollectNodeInfo(sceneData, outputDir);

    // ����CSV�ļ�  
    GenerateCSVFiles(outputDir);

    cout << "Generated CSV files:" << endl;
    cout << "  - produce_models.csv" << endl;
    cout << "  - product_tree.csv" << endl;
    cout << "  - product_properties.csv" << endl;
    cout << "  - product_pmi.csv" << endl;

    // �����Ҫ����Ȼ���Ա���ģ�����������ϸ��Ϣ  
    TraverseModelTree(sceneData, outputDir);

    // �ͷ���Դ  
    sceneData->Release();
    return TRUE;
}

void TraverseModelTree(ISceneData* iSceneData, const string& outputDir)
{
    if (!iSceneData)
        return;

    // ��ȡ����ģ����  
    std::vector<IModelTree*> modelTreeArray;
    iSceneData->GetModelTreeArray(modelTreeArray);

    cout << "Found " << modelTreeArray.size() << " model trees" << endl;

    for (DftUInt t = 0; t < modelTreeArray.size(); t++)
    {
        IModelTree* tree = modelTreeArray[t];
        if (!tree)
            continue;

        // ��ȡģ��������  
        CUnicodeString treeName;
        tree->GetName(treeName);
        cout << "\nModel Tree: " << treeName.ToMultiByte() << endl;

        // ��ȡ���ڵ�  
        IModelTreeNode* rootNode = nullptr;
        if (tree->GetRootNode(rootNode) == PDV_RESULT_NO_ERROR && rootNode)
        {
            // ʹ��ջ���зǵݹ�������ȱ���  
            stack<pair<IModelTreeNode*, int>> nodeStack;
            nodeStack.push(make_pair(rootNode, 0));

            while (!nodeStack.empty())
            {
                IModelTreeNode* currentNode = nodeStack.top().first;
                int depth = nodeStack.top().second;
                nodeStack.pop();

                // ����ǰ�ڵ�  
                ProcessTreeNode(currentNode, depth, iSceneData, outputDir);

                // ��ȡ�ӽڵ�  
                std::vector<IModelTreeNode*> children;
                if (currentNode->GetChildren(children) == PDV_RESULT_NO_ERROR)
                {
                    // ��������ӽڵ��Ա�֤ԭʼ˳��  
                    for (int i = static_cast<int>(children.size()) - 1; i >= 0; i--)
                    {
                        if (children[i])
                        {
                            nodeStack.push(make_pair(children[i], depth + 1));
                        }
                    }
                }
            }
        }
    }
}

void ProcessTreeNode(IModelTreeNode* node, int depth, ISceneData* sceneData, const string& outputDir)
{
    if (!node) return;

    // ��ȡ�ڵ���Ϣ  
    CUnicodeString nodeName;
    node->GetName(nodeName);
    DftUInt64 nodeID = node->GetID();

    // ��ӡ�ڵ���Ϣ  
    string indent(depth * 2, ' ');
    cout << "\n" << indent << "Node: " << nodeName.ToMultiByte()
        << " (ID: " << nodeID << ")" << endl;

    // ��ӡ�ɼ���  
    cout << indent << "  Visible: " << (node->GetVisible() ? "Yes" : "No") << endl;

    // ��ȡ�任��Ϣ - ���������ӡ  
    PDVMatrix4F worldTransform;
    if (node->GetWorldTransform(worldTransform) == PDV_RESULT_NO_ERROR)
    {
        cout << indent << "  World Transform:" << endl;
        // ��ȷ��ӡ����Ԫ��ֵ  
        for (int i = 0; i < 4; i++) {
            cout << indent << "    ";
            for (int j = 0; j < 4; j++) {
                // ʹ�ù̶���������ʽ�����þ���Ϊ6λ  
                cout << fixed << setw(12) << setprecision(6)
                    << worldTransform._data[i * 4 + j] << " ";
            }
            cout << endl;
        }
    }

    // ����Ƿ����ģ��  
    if (node->GetModelFlag())
    {
        IModel* model = node->GetModel();
        if (model)
        {
            // ��ȡģ������  
            CUnicodeString modelName;
            model->GetName(modelName);
            cout << indent << "  Model: " << modelName.ToMultiByte() << endl;

            // ��ӡ���Ա�  
            IAttribute* attr = model->GetAttribute();
            if (attr)
            {
                PrintAttributeInfo(attr, depth);
            }
            else
            {
                cout << indent << "  No Attributes" << endl;
            }

            // ��ӡPMI��Ϣ  
            IAnnotation* annotation = model->GetAnnotation();
            if (annotation)
            {
                PrintPMIInfo(annotation, depth);
            }
            else
            {
                cout << indent << "  No PMI Information" << endl;
            }

            // ����BRep����  
            DftUInt brepCount = model->GetBRepCount();
            cout << indent << "  BRep Count: " << brepCount << endl;

            // Ϊ�ڵ㴴����Ŀ¼  
            string nodeDir = outputDir + "\\Node_" + to_string(nodeID);
            CreateDirectoryA(nodeDir.c_str(), NULL);

            // �����ڵ�����STL  
            string nodeStlPath = nodeDir + "\\" + nodeName.ToMultiByte() + ".stl";
            if (ExportNodeToStl(sceneData, node, nodeStlPath))
            {
                cout << indent << "    Exported Node STL to: " << nodeStlPath << endl;
            }

            // ����ÿ��BRep  
            for (DftUInt i = 0; i < brepCount; i++)
            {
                IBRep* brep = model->GetBRep(i);
                if (brep)
                {
                    // ���ɻ����ļ���  
                    stringstream filename;
                    filename << nodeDir << "\\BRep_" << i;

                    // ����BRep�ı�����  
                    ExportBRepAsText(brep, filename.str());
                    cout << indent << "    Exported BRep text to: " << filename.str() << ".brep" << endl;
                }
            }
        }
    }
}

void PrintAttributeInfo(IAttribute* attr, int depth)
{
    if (!attr) return;

    string indent(depth * 2 + 4, ' ');

    // ��ȡ����������    
    DftUInt groupCount = attr->GetAttributeGroupCount();
    cout << indent << "Attributes (" << groupCount << " groups):" << endl;

    // ��ȡ����������    
    std::vector<IAttributeGroup*> attributeGroups;
    if (attr->GetAttributeGroupArray(attributeGroups) == PDV_RESULT_NO_ERROR)
    {
        for (DftUInt i = 0; i < attributeGroups.size(); i++)
        {
            IAttributeGroup* group = attributeGroups[i];
            if (!group) continue;

            cout << indent << "  Group " << i + 1 << ": " << endl;
            cout << indent << "    Group ID: " << group->GetID() << endl;

            // ��ȡ����������    
            CUnicodeString groupName;
            if (group->GetName(groupName) == PDV_RESULT_NO_ERROR)
            {
                cout << indent << "    Group Name: " << groupName.ToMultiByte() << endl;
            }

            // ��ȡ����������������    
            DftUInt itemCount = group->GetAttributeItemCount();
            cout << indent << "    Attribute Items: " << itemCount << endl;

            std::vector<IAttributeItem*> attributeItems;
            if (group->GetAttributeItemArray(attributeItems) == PDV_RESULT_NO_ERROR)
            {
                for (DftUInt j = 0; j < attributeItems.size(); j++)
                {
                    IAttributeItem* item = attributeItems[j];
                    if (!item) continue;

                    // ��ȡ�������ֵ    
                    CUnicodeString key;
                    if (item->GetKey(key) == PDV_RESULT_NO_ERROR)
                    {
                        cout << indent << "      Item " << j + 1 << ": " << key.ToMultiByte();

                        // �����������ͻ�ȡֵ    
                        DftUInt valueType = item->GetValueType();
                        cout << " (Type: " << valueType << ") = ";

                        switch (valueType)
                        {
                        case DATATYPE_BOOL:
                        {
                            DftBool boolValue;
                            if (item->GetBoolean(boolValue) == PDV_RESULT_NO_ERROR)
                                cout << (boolValue ? "true" : "false");
                        }
                        break;
                        case DATATYPE_INT32:
                        {
                            DftInt intValue;
                            if (item->GetInteger(intValue) == PDV_RESULT_NO_ERROR)
                                cout << intValue;
                        }
                        break;
                        case DATATYPE_FLOAT:
                        {
                            DftFloat floatValue;
                            if (item->GetFloat(floatValue) == PDV_RESULT_NO_ERROR)
                                cout << floatValue;
                        }
                        break;
                        case DATATYPE_DOUBLE:
                        {
                            DftDouble doubleValue;
                            if (item->GetDouble(doubleValue) == PDV_RESULT_NO_ERROR)
                                cout << doubleValue;
                        }
                        break;
                        case DATATYPE_STRING:
                        {
                            CUnicodeString stringValue;
                            if (item->GetString(stringValue) == PDV_RESULT_NO_ERROR)
                                cout << "\"" << stringValue.ToMultiByte() << "\"";
                        }
                        break;
                        case DATATYPE_VECTOR3F:
                        {
                            PDVVector3F vectorValue;
                            if (item->GetVectorFloat3(vectorValue) == PDV_RESULT_NO_ERROR)
                                cout << "(" << vectorValue.x() << ", " << vectorValue.y() << ", " << vectorValue.z() << ")";
                        }
                        break;
                        case DATATYPE_VECTOR3D:
                        {
                            PDVVector3D vectorValue;
                            if (item->GetVectorDouble3(vectorValue) == PDV_RESULT_NO_ERROR)
                                cout << "(" << vectorValue.x() << ", " << vectorValue.y() << ", " << vectorValue.z() << ")";
                        }
                        break;
                        default:
                            cout << "[Unknown Type]";
                            break;
                        }
                        cout << endl;
                    }
                }
            }
        }
    }
    else
    {
        cout << indent << "Failed to retrieve attribute groups" << endl;
    }
}

void PrintPMIInfo(IAnnotation* annotation, int depth)
{
    if (!annotation) return;

    string indent(depth * 2 + 4, ' ');

    // ��ȡ�����ע���������    
    DftUInt itemCount = annotation->GetAnnotationItemCount();
    DftUInt viewCount = annotation->GetAnnotationViewCount();
    DftUInt geomCount = annotation->GetAnnotationGeometryCount();

    cout << indent << "PMI Information:" << endl;
    cout << indent << "  Annotation Items: " << itemCount << endl;
    cout << indent << "  Annotation Views: " << viewCount << endl;
    cout << indent << "  Annotation Geometries: " << geomCount << endl;

    // ��ϸ�����ע����Ϣ    
    for (DftUInt i = 0; i < itemCount; i++)
    {
        IAnnotationItem* item = annotation->GetAnnotationItemByIndex(i);
        if (!item) continue;

        cout << indent << "  Item " << i + 1 << ":" << endl;
        cout << indent << "    ID: " << item->GetID() << endl;

        // ��ȡ��ע������    
        CUnicodeString itemName;
        if (item->GetName(itemName) == PDV_RESULT_NO_ERROR)
        {
            cout << indent << "    Name: " << itemName.ToMultiByte() << endl;
        }

        // ��ȡ��ע������    
        CUnicodeString itemType = item->GetType();
        cout << indent << "    Type: " << itemType.ToMultiByte() << endl;
        // ��ȡ��ʾģʽ    
        DftUInt8 viewMode = item->GetFaceViewMode();
        string viewModeStr;
        switch (viewMode)
        {
        case ANNOTATIONVIEWMODE_DEFAULTVIEW:
            viewModeStr = "Default View";
            break;
        case ANNOTATIONVIEWMODE_PARALLELSCREEN:
            viewModeStr = "Parallel Screen";
            break;
        case ANNOTATIONVIEWMODE_FIXEDSCREEN:
            viewModeStr = "Fixed Screen";
            break;
        default:
            viewModeStr = "Unknown";
            break;
        }
        cout << indent << "    View Mode: " << viewModeStr << endl;

        // ��ȡ�任����    
        PDVMatrix4F transformation = item->GetTransformation();
        cout << indent << "    Transformation Matrix:" << endl;
        for (int row = 0; row < 4; row++)
        {
            cout << indent << "      ";
            for (int col = 0; col < 4; col++)
            {
                cout << fixed << setw(10) << setprecision(4)
                    << transformation._data[row * 4 + col] << " ";
            }
            cout << endl;
        }

        // ��ȡ��Ⱦ����ID    
        DftUInt64 renderBodyID = item->GetRenderBodyID();
        if (renderBodyID != 0)
        {
            cout << indent << "    Render Body ID: " << renderBodyID << endl;
        }

        // ��ȡ������������Ϣ    
        std::vector<PDVVector2F> trianglePoints;
        if (item->GetTrianglePoints(trianglePoints) == PDV_RESULT_NO_ERROR && !trianglePoints.empty())
        {
            cout << indent << "    Triangle Points: " << trianglePoints.size() << endl;
        }

        std::vector<DftUInt> triangleIndexes;
        if (item->GetTriangleIndexes(triangleIndexes) == PDV_RESULT_NO_ERROR && !triangleIndexes.empty())
        {
            cout << indent << "    Triangle Indexes: " << triangleIndexes.size() << endl;
        }

        // ��ȡ��������ɫ    
        RGBColor triangleColor = item->GetTriangleColor();
        cout << indent << "    Triangle Color: RGB("
            << static_cast<int>(triangleColor._red) << ", "
            << static_cast<int>(triangleColor._green) << ", "
            << static_cast<int>(triangleColor._blue) << ")" << endl;

        // ��ȡ�߿�����    
        std::vector<WireFrame2DData> wires;
        if (item->GetWires(wires) == PDV_RESULT_NO_ERROR && !wires.empty())
        {
            cout << indent << "    Wire Frames: " << wires.size() << endl;
            for (size_t w = 0; w < wires.size(); w++)
            {
                const WireFrame2DData& wire = wires[w];
                cout << indent << "      Wire " << w + 1 << ": "
                    << wire._points.size() << " points";

                // ����߿�����    
                if (wire._bitMasks & WIRE_MASK_CLOSE)
                    cout << " [Closed]";
                if (wire._bitMasks & WIRE_MASK_FILLED)
                    cout << " [Filled]";
                if (wire._bitMasks & WIRE_MASK_COLORED)
                    cout << " [Colored]";
                cout << endl;
            }
        }

        // ��ȡͼ������    
        AnnotationGraphicData graphicData;
        if (item->GetGraphicData(graphicData) == PDV_RESULT_NO_ERROR)
        {
            if (!graphicData._points.empty())
            {
                cout << indent << "    Graphic Data:" << endl;
                cout << indent << "      Points: " << graphicData._points.size() << endl;
                cout << indent << "      Point Indexes: " << graphicData._pointIndexes.size() << endl;
                cout << indent << "      Facet Indexes: " << graphicData._facetIndexes.size() << endl;
                cout << indent << "      Wire Frames: " << graphicData._wires.size() << endl;
                cout << indent << "      Transparency: " << static_cast<int>(graphicData._transparency) << endl;
            }
        }

        // ��ȡ�������Ϣ    
        OrientedBoundingBox boundingBox;
        if (item->GetBox(boundingBox) == PDV_RESULT_NO_ERROR)
        {
            cout << indent << "    Bounding Box: Available" << endl;
        }

        // ��ȡ���ӵļ��ζ�����Ϣ    
        LinkedSubsetInfoArray linkedSubsets;
        if (item->GetLinkedSubsetInfoArray(linkedSubsets) == PDV_RESULT_NO_ERROR && !linkedSubsets.empty())
        {
            cout << indent << "    Linked Subsets: " << linkedSubsets.size() << endl;
            for (size_t s = 0; s < linkedSubsets.size(); s++)
            {
                const LinkedSubsetInfo& subset = linkedSubsets[s];
                cout << indent << "      Subset " << s + 1 << ": "
                    << "Node=" << subset._nodeID
                    << ", RenderBody=" << subset._renderBodyID
                    << ", RenderMesh=" << subset._renderMeshID
                    << ", Subset=" << subset._subsetID << endl;
            }
        }

        // ��ȡ���ӵĸ������ζ���ID    
        std::vector<DftUInt64> annotationGeometryIDs;
        if (item->GetAnnotationGeometryIDs(annotationGeometryIDs) == PDV_RESULT_NO_ERROR && !annotationGeometryIDs.empty())
        {
            cout << indent << "    Linked Annotation Geometries: ";
            for (size_t g = 0; g < annotationGeometryIDs.size(); g++)
            {
                cout << annotationGeometryIDs[g];
                if (g < annotationGeometryIDs.size() - 1) cout << ", ";
            }
            cout << endl;
        }

        cout << endl;
    }

    // �����ע��ͼ��Ϣ    
    if (viewCount > 0)
    {
        cout << indent << "  Annotation Views:" << endl;
        for (DftUInt i = 0; i < viewCount; i++)
        {
            IAnnotationView* view = annotation->GetAnnotationViewByIndex(i);
            if (!view) continue;

            cout << indent << "    View " << i + 1 << ":" << endl;
            cout << indent << "      ID: " << view->GetID() << endl;

            // ��ȡ��ͼ����    
            CUnicodeString viewName;
            if (view->GetName(viewName) == PDV_RESULT_NO_ERROR)
            {
                cout << indent << "      Name: " << viewName.ToMultiByte() << endl;
            }

            // �����ͼ����    
            cout << indent << "      Is Default View: " << (view->IsDefaultView() ? "Yes" : "No") << endl;
            cout << indent << "      Has Camera: " << (view->GetCameraFlag() ? "Yes" : "No") << endl;
            cout << indent << "      Has Clip Plane: " << (view->GetClipPlaneFlag() ? "Yes" : "No") << endl;

            // ��ȡ��ͼ��ʶλ    
            DftByte bitMask = view->GetBitMask();
            cout << indent << "      View Properties:" << endl;
            if (bitMask & ANNOVIEW_MASK_DEFAULT_VIEW)
                cout << indent << "        - Default View" << endl;
            if (bitMask & ANNOVIEW_MASK_CAMERA)
                cout << indent << "        - Contains Camera Data" << endl;
            if (bitMask & ANNOVIEW_MASK_CLIP_PLANE)
                cout << indent << "        - Contains Clipping Data" << endl;
            if (bitMask & ANNOVIEW_MASK_VISIBLE)
                cout << indent << "        - Visible" << endl;
            if (bitMask & ANNOVIEW_MASK_MESHVISIBLE)
                cout << indent << "        - Mesh Visible" << endl;

            // ��ȡ�����ı�ע��ID    
            std::vector<DftUInt64> annotationItemIDs;
            if (view->GetAnnotationItemIDs(annotationItemIDs) == PDV_RESULT_NO_ERROR && !annotationItemIDs.empty())
            {
                cout << indent << "      Associated Annotation Items: ";
                for (size_t j = 0; j < annotationItemIDs.size(); j++)
                {
                    cout << annotationItemIDs[j];
                    if (j < annotationItemIDs.size() - 1) cout << ", ";
                }
                cout << endl;
            }

            // ��ȡ�������Ϣ    
            if (view->GetCameraFlag())
            {
                DftUInt64 cameraID = view->GetCameraID();
                if (cameraID != 0)
                {
                    cout << indent << "      Camera ID: " << cameraID << endl;
                }
            }

            // ��ȡ��������Ϣ    
            if (view->GetClipPlaneFlag())
            {
                std::vector<PlaneData> clippingPlanes;
                if (view->GetClippingPlanes(clippingPlanes) == PDV_RESULT_NO_ERROR && !clippingPlanes.empty())
                {
                    cout << indent << "      Clipping Planes: " << clippingPlanes.size() << endl;
                    for (size_t p = 0; p < clippingPlanes.size(); p++)
                    {
                        const PlaneData& plane = clippingPlanes[p];
                        cout << indent << "        Plane " << p + 1 << ":" << endl;
                        cout << indent << "          Origin: (" << plane._vOrigin.x() << ", "
                            << plane._vOrigin.y() << ", " << plane._vOrigin.z() << ")" << endl;
                        cout << indent << "          Normal: (" << plane._vAxisZ.x() << ", "
                            << plane._vAxisZ.y() << ", " << plane._vAxisZ.z() << ")" << endl;
                    }
                }
            }

            // ��ȡ�����к����صĽڵ�ID    
            std::vector<DftUInt64> clippedNodeIDs;
            if (view->GetClippedNodeIDs(clippedNodeIDs) == PDV_RESULT_NO_ERROR && !clippedNodeIDs.empty())
            {
                cout << indent << "      Clipped Nodes: ";
                for (size_t c = 0; c < clippedNodeIDs.size(); c++)
                {
                    cout << clippedNodeIDs[c];
                    if (c < clippedNodeIDs.size() - 1) cout << ", ";
                }
                cout << endl;
            }

            std::vector<DftUInt64> hiddenNodeIDs;
            if (view->GetHiddenNodeIDs(hiddenNodeIDs) == PDV_RESULT_NO_ERROR && !hiddenNodeIDs.empty())
            {
                cout << indent << "      Hidden Nodes: ";
                for (size_t h = 0; h < hiddenNodeIDs.size(); h++)
                {
                    cout << hiddenNodeIDs[h];
                    if (h < hiddenNodeIDs.size() - 1) cout << ", ";
                }
                cout << endl;
            }

            // ��ȡ�����ĸ�������ID    
            std::vector<DftUInt64> refGeometryIDs;
            if (view->GetReferenceGeometryIDs(refGeometryIDs) == PDV_RESULT_NO_ERROR && !refGeometryIDs.empty())
            {
                cout << indent << "      Reference Geometries: ";
                for (size_t r = 0; r < refGeometryIDs.size(); r++)
                {
                    cout << refGeometryIDs[r];
                    if (r < refGeometryIDs.size() - 1) cout << ", ";
                }
                cout << endl;
            }

            cout << endl;
        }
    }

    // �����ע������Ϣ    
    if (geomCount > 0)
    {
        cout << indent << "  Annotation Geometries:" << endl;
        for (DftUInt i = 0; i < geomCount; i++)
        {
            IAnnotationGeometry* geom = annotation->GetAnnotationGeometryByIndex(i);
            if (!geom) continue;

            cout << indent << "    Geometry " << i + 1 << ":" << endl;
            cout << indent << "      ID: " << geom->GetID() << endl;

            // ��ȡ�任����    
            PDVMatrix4F matrix = geom->GetMatrix();
            cout << indent << "      Transformation Matrix:" << endl;
            for (int row = 0; row < 4; row++)
            {
                cout << indent << "        ";
                for (int col = 0; col < 4; col++)
                {
                    cout << fixed << setw(10) << setprecision(4)
                        << matrix._data[row * 4 + col] << " ";
                }
                cout << endl;
            }

            // ��ȡ�����    
            OrientedBoundingBox boundingBox;
            if (geom->GetBox(boundingBox) == PDV_RESULT_NO_ERROR)
            {
                cout << indent << "      Bounding Box:" << endl;
                cout << indent << "        Center: (" << boundingBox._center.x() << ", "
                    << boundingBox._center.y() << ", " << boundingBox._center.z() << ")" << endl;
                cout << indent << "        X Axis: (" << boundingBox._axisX.x() << ", "
                    << boundingBox._axisX.y() << ", " << boundingBox._axisX.z() << ")" << endl;
                cout << indent << "        Y Axis: (" << boundingBox._axisY.x() << ", "
                    << boundingBox._axisY.y() << ", " << boundingBox._axisY.z() << ")" << endl;
                cout << indent << "        Z Axis: (" << boundingBox._axisZ.x() << ", "
                    << boundingBox._axisZ.y() << ", " << boundingBox._axisZ.z() << ")" << endl;
            }

            // ��ȡ��Ⱦ����ID    
            DftUInt64 renderBodyID = geom->GetRenderBodyID();
            if (renderBodyID != 0)
            {
                cout << indent << "      Render Body ID: " << renderBodyID << endl;
            }

            cout << endl;
        }
    }
}

void ExportBRepAsText(IBRep* bRep, const string& filenameBase)
{
    if (!bRep) return;

    // �����ı��ļ�  
    ofstream outFile((filenameBase + ".brep").c_str());
    if (!outFile.is_open())
    {
        cerr << "Failed to create BREP file: " << filenameBase << ".brep" << endl;
        return;
    }

    // �ļ�ͷ  
    outFile << "BRep Text Format" << endl;
    outFile << "=================" << endl << endl;

    // 1. ������Ϣ  
    std::vector<ITopo*> topos;
    if (bRep->GetTopoArray(topos) == PDV_RESULT_NO_ERROR)
    {
        outFile << "Topology Elements (" << topos.size() << "):" << endl;
        outFile << "-------------------" << endl;

        // ʹ��ӳ��洢���˶��󣬱��ں�������  
        map<DftUInt64, ITopo*> topoMap;

        for (size_t i = 0; i < topos.size(); i++)
        {
            ITopo* topo = topos[i];
            if (!topo) continue;

            DftUInt64 topoID = topo->GetID();
            topoMap[topoID] = topo;

            // ������˻�����Ϣ  
            outFile << "Topo ID: " << topoID << endl;
            outFile << "  Type: " << TopoTypeToString(topo->GetTopoType()) << endl;
            outFile << "  Original ID: " << topo->GetOriginalID().ToMultiByte() << endl;
            outFile << "  Orientation: " << OrientationToString(topo->GetOrientation()) << endl;

            // ��������ļ�����Ϣ  
            outFile << "  Geometry:" << endl;
            outFile << "    Type: " << GeomTypeToString(topo->GetGeometryType()) << endl;
            outFile << "    ID: " << topo->GetGeometryID() << endl;

            // ���������  
            const std::vector<DftUInt64>& subTopoIDs = topo->GetTopoIDs();
            if (!subTopoIDs.empty())
            {
                outFile << "  Sub-Topos (" << subTopoIDs.size() << "):" << endl;
                for (size_t j = 0; j < subTopoIDs.size(); j++)
                {
                    outFile << "    - " << subTopoIDs[j] << endl;
                }
            }
            outFile << endl;
        }

        // 2. ���˲�νṹ  
        outFile << endl << "Topology Hierarchy:" << endl;
        outFile << "-------------------" << endl;

        // ���Ҷ������ˣ�û�и����˵ģ�  
        set<DftUInt64> childTopos;
        for (auto& pair : topoMap)
        {
            const std::vector<DftUInt64>& subIDs = pair.second->GetTopoIDs();
            for (DftUInt64 id : subIDs)
            {
                childTopos.insert(id);
            }
        }

        // �ݹ��ӡ���˲��  
        std::function<void(DftUInt64, int)> printTopoHierarchy = [&](DftUInt64 topoID, int level) {
            auto it = topoMap.find(topoID);
            if (it == topoMap.end()) return;

            ITopo* topo = it->second;
            string indent(level * 2, ' ');

            outFile << indent << TopoTypeToString(topo->GetTopoType())
                << " [ID: " << topoID << "]" << endl;

            // �ݹ��ӡ������  
            const std::vector<DftUInt64>& subIDs = topo->GetTopoIDs();
            for (DftUInt64 subID : subIDs)
            {
                printTopoHierarchy(subID, level + 1);
            }
            };

        // ��ӡ���ж�������  
        for (auto& pair : topoMap)
        {
            if (childTopos.find(pair.first) == childTopos.end())
            {
                printTopoHierarchy(pair.first, 0);
                outFile << endl;
            }
        }
    }
    else
    {
        outFile << "No topology information available" << endl;
    }

    // 3. ���ε���Ϣ  
    std::vector<IGeomPointData*> points;
    if (bRep->GetGeomPointDataArray(points) == PDV_RESULT_NO_ERROR)
    {
        outFile << endl << "Points (" << points.size() << "):" << endl;
        outFile << "-------" << endl;

        for (size_t i = 0; i < points.size(); i++)
        {
            IGeomPointData* point = points[i];
            if (point)
            {
                PDVVector3D position = point->GetPosition();
                outFile << "Point " << i + 1 << " (ID: " << point->GetID() << "): ("
                    << position.x() << ", " << position.y() << ", " << position.z() << ")" << endl;
            }
        }
    }

    // 4. ����������Ϣ  
    std::vector<IGeomCurveData*> curves;
    if (bRep->GetGeomCurveDataArray(curves) == PDV_RESULT_NO_ERROR)
    {
        outFile << endl << "Curves (" << curves.size() << "):" << endl;
        outFile << "-------" << endl;

        for (size_t i = 0; i < curves.size(); i++)
        {
            IGeomCurveData* curve = curves[i];
            if (curve)
            {
                outFile << "Curve " << i + 1 << " (ID: " << curve->GetID() << "):" << endl;
                outFile << "  Type: " << static_cast<int>(curve->GetType()) << endl;
                outFile << "  Start Parameter: " << curve->GetStartParameter() << endl;
                outFile << "  End Parameter: " << curve->GetEndParameter() << endl;
            }
        }
    }

    // 5. ����������Ϣ  
    std::vector<IGeomSurfaceData*> surfaces;
    if (bRep->GetGeomSurfaceDataArray(surfaces) == PDV_RESULT_NO_ERROR)
    {
        outFile << endl << "Surfaces (" << surfaces.size() << "):" << endl;
        outFile << "---------" << endl;

        for (size_t i = 0; i < surfaces.size(); i++)
        {
            IGeomSurfaceData* surface = surfaces[i];
            if (surface)
            {
                outFile << "Surface " << i + 1 << " (ID: " << surface->GetID() << "):" << endl;
                outFile << "  Type: " << static_cast<int>(surface->GetType()) << endl;

                PDVVector2D domainMin = surface->GetDomainMin();
                PDVVector2D domainMax = surface->GetDomainMax();
                outFile << "  Domain Min: (" << domainMin.x() << ", " << domainMin.y() << ")" << endl;
                outFile << "  Domain Max: (" << domainMax.x() << ", " << domainMax.y() << ")" << endl;
            }
        }
    }

    outFile.close();
}

bool ExportNodeToStl(ISceneData* iSceneData, IModelTreeNode* node, const string& stlPath)
{
    if (!node || !node->GetModelFlag() || !iSceneData)
        return false;

    IModel* model = node->GetModel();
    if (!model)
        return false;

    ofstream ofStl(stlPath);
    if (!ofStl.is_open())
        return false;

    ofStl << "solid " << stlPath << endl;

    DftUInt renderBodyCount = model->GetRenderBodyCount();
    if (renderBodyCount == 0)
    {
        ofStl << "endsolid" << endl;
        ofStl.close();
        return false;
    }

    PDVMatrix4F worldTrans;
    node->GetWorldTransform(worldTrans);

    for (DftUInt i = 0; i < renderBodyCount; i++)
    {
        DftUInt64 renderBodyID = model->GetRenderBodyID(i);
        IRenderBody* renderBody = iSceneData->FindRenderBodyByID(renderBodyID);
        if (!renderBody)
            continue;

        std::vector<DftUInt64> faceMeshIDs;
        renderBody->GetFaceMeshIDs(faceMeshIDs);

        for (DftUInt j = 0; j < faceMeshIDs.size(); j++)
        {
            IRenderMesh* renderMesh = iSceneData->FindRenderMeshByID(faceMeshIDs[j]);
            if (!renderMesh || renderMesh->GetType() != RENDER_MESH_TYPE_MAIN)
                continue;

            IRenderGeometry* renderGeometry = iSceneData->FindRenderGeometryByID(renderMesh->GetFirstRenderGeometryID());
            if (!renderGeometry)
                continue;

            IRenderVertex* renderVertex = iSceneData->FindRenderVertexByID(renderGeometry->GetVertexID());
            if (!renderVertex)
                continue;

            std::vector<kernel::pdv::VertexData> vertexData;
            renderVertex->GetVertexes(vertexData);

            std::vector<DftUInt> indexes;
            renderGeometry->GetIndexes(indexes);

            DftUInt triangleCount = static_cast<DftUInt>(indexes.size()) / 3;
            for (DftUInt c = 0; c < triangleCount; c++)
            {
                PDVVector3F worldNormal, worldP1, worldP2, worldP3;
                const VertexData& v1 = vertexData[indexes[c * 3]];
                const VertexData& v2 = vertexData[indexes[c * 3 + 1]];
                const VertexData& v3 = vertexData[indexes[c * 3 + 2]];

                // Ӧ������任  
                DftTransformVector3F(v1._normal, worldTrans._data, worldNormal);
                DftTransformPoint3F(v1._position, worldTrans._data, worldP1);
                DftTransformPoint3F(v2._position, worldTrans._data, worldP2);
                DftTransformPoint3F(v3._position, worldTrans._data, worldP3);

                // д��STL��ʽ  
                ofStl << "   facet normal " << worldNormal.x() << " " << worldNormal.y() << " " << worldNormal.z() << endl;
                ofStl << "      outer loop" << endl;
                ofStl << "         vertex " << worldP1.x() << " " << worldP1.y() << " " << worldP1.z() << endl;
                ofStl << "         vertex " << worldP2.x() << " " << worldP2.y() << " " << worldP2.z() << endl;
                ofStl << "         vertex " << worldP3.x() << " " << worldP3.y() << " " << worldP3.z() << endl;
                ofStl << "      endloop" << endl;
                ofStl << "   endfacet" << endl;
            }
        }
    }

    ofStl << "endsolid" << endl;
    ofStl.close();
    return true;
}

int main()
{
    // ʹ��ʵ��PDV�ļ�·�������Ŀ¼  
    Convert(
        "D:\\work\\code\\DevelopmentCode\\PDVReader\\test\\pdv_top\\top.pdv",
        "D:\\work\\code\\DevelopmentCode\\PDVReader\\test\\output"
    );
    return 0;
}
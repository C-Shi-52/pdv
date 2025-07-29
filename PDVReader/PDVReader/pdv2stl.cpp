#include "DftBase.h"
#include "PDVISceneData.h"
#include "PDVIModelTree.h"
#include "PDVIModelTreeNode.h"
#include "PDVIModel.h"
#include "PDVIBRep.h"
#include "PDVIRenderBody.h"
#include "PDVIRenderMesh.h"
#include "PDVIReferenceGeometry.h"
#include "PDVIRenderVertex.h"
#include "PDVIObjectFactory.h"
#include "PDVFile.h"
#include "PDVITopo.h"
#include <fstream>
#include <vector>

using namespace std;
using namespace kernel::pdv;

DftBool ConvertToStl(ISceneData* iSceneData, const CUnicodeString& iStlPath)
{
    if (!iSceneData)
        return FALSE;

    // iSceneData->RevertBatchedAndInstanced();

    // 获取所有模型树节点，将其网格数据转换到stl文件中
    ofstream ofStl(iStlPath.ToMultiByte());
    ofStl << "solid block" << endl;
    std::vector<IModelTree*> modelTreeArray;
    iSceneData->GetModelTreeArray(modelTreeArray);

    for (DftUInt t = 0; t < (DftUInt)modelTreeArray.size(); t++)
    {
        IModelTree* tree = modelTreeArray[t];
        if (!tree)
            continue;
        std::vector<IModelTreeNode*> modelTreeNodeArray;
        tree->GetChildrenNodes(modelTreeNodeArray);
        for (DftUInt n = 0; n < (DftUInt)modelTreeNodeArray.size(); n++)
        {
            IModelTreeNode* node = modelTreeNodeArray[n];
            if (!node)
                continue;
            if (!node->GetModelFlag())
                continue;
            IModel* model = node->GetModel();
            if (!model)
                continue;

            IBRep* bRep = model->GetBRep(n);
            IAttribute* attr = model->GetAttribute();
            
            //升级3.0 zhangheng20250612
            DftUInt renderBodyCount = model->GetRenderBodyCount();
            if (renderBodyCount == 0)
                continue;
            CUnicodeString nodeName;
            node->GetName(nodeName);
            // 组
            //ofObj << "g " << nodeName.ToMultiByte() << endl;
            DftUInt64 tempRenderBodyID;
            IRenderBody* tempRenderBody = NULL;
            IRenderMesh* tempRenderMesh = NULL;
            IRenderGeometry* tempRenderGeometry = NULL;
            kernel::pdv::IRenderVertex* tempRenderVertex = NULL;
            DftUInt64 tempRenderMeshID = DFT_INVALID_ID;
            for (DftUInt i = 0; i < renderBodyCount; i++)
            {
                tempRenderBodyID = model->GetRenderBodyID(i);
                tempRenderBody = iSceneData->FindRenderBodyByID(tempRenderBodyID);
                std::vector<DftUInt64> faceMeshIDs;
                tempRenderBody->GetFaceMeshIDs(faceMeshIDs);

                for (DftUInt j = 0; j < faceMeshIDs.size(); j++)
                {
                    tempRenderMesh = iSceneData->FindRenderMeshByID(faceMeshIDs[j]);
                    if (tempRenderMesh->GetType() != RENDER_MESH_TYPE_MAIN)
                        continue;

                    tempRenderMeshID = tempRenderMesh->GetID();
                    tempRenderGeometry = iSceneData->FindRenderGeometryByID(tempRenderMesh->GetFirstRenderGeometryID());
                    tempRenderVertex = iSceneData->FindRenderVertexByID(tempRenderGeometry->GetVertexID());

                    std::vector<kernel::pdv::VertexData> tempVertexData;
                    tempRenderVertex->GetVertexes(tempVertexData);

                    std::vector<PDVVector3F> coords;
                    std::vector<PDVVector3F> normals;
                    std::vector<DftUInt> vecOfIndex;

                    for (DftUInt v = 0; v < tempVertexData.size(); v++)
                    {
                        coords.push_back(tempVertexData[v]._position);
                        normals.push_back(tempVertexData[v]._normal);
                    }
                    tempRenderGeometry->GetIndexes(vecOfIndex);

                    PDVMatrix4F worldTrans;
                    node->GetWorldTransform(worldTrans);
                    DftUInt triangleCount = (DftUInt)vecOfIndex.size() / 3;
                    for (DftUInt c = 0; c < triangleCount; c++)
                    {
                        PDVVector3F worldNormal, worldP1, worldP2, worldP3;
                        DftStatus status = DftTransformVector3F(normals[vecOfIndex[c * 3]], worldTrans._data, worldNormal);
                        status = DftTransformPoint3F(coords[vecOfIndex[c * 3]], worldTrans._data, worldP1);
                        status = DftTransformPoint3F(coords[vecOfIndex[c * 3 + 1]], worldTrans._data, worldP2);
                        status = DftTransformPoint3F(coords[vecOfIndex[c * 3 + 2]], worldTrans._data, worldP3);
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
        }
    }

    ofStl << "endsolid" << endl;

    return TRUE;
}

DftBool Convert(const CUnicodeString& iPdvPath, const CUnicodeString& iStlPath)
{
    IObjectFactory* piObjectFactory = IObjectFactory::GetObjectFactory();
    if (!piObjectFactory)
        return FALSE;
    ISceneData* sceneData = NULL;
    PDV_RESULT res = piObjectFactory->CreateSceneData(sceneData);
    if (!sceneData)
        return FALSE;
    res = PDVFileServices::LoadSceneData(sceneData, iPdvPath);

    DftBool result = ConvertToStl(sceneData, iStlPath);
    // 释放内存
    sceneData->Release();
    sceneData = NULL;

    return result;
}

//int main()
//{
//    Convert("D:\\work\\code\\DevelopmentCode\\PDVReader\\test\\pdv_top\\top.pdv", "D:\\work\\code\\DevelopmentCode\\PDVReader\\test\\stl_top\\top.stl");
//    return 0;
//}


/**
 * @file PDVLog.h
 * @author
 * @version 1.0
 * @date
 * @brief 概述：输出日志的接口声明
 * @details 详细说明
 */

#ifndef PDVLOG_H
#define PDVLOG_H

#include "PDVBase.h"
#include "PDVISceneData.h"
#include "PDVIScene.h"
#include "PDVICamera.h"
#include "PDVIResource.h"
#include "PDVISecurity.h"
#include "PDVIModelTree.h"
#include "PDVIModelTreeNode.h"
#include "PDVIModel.h"
#include "PDVIAttribute.h"
#include "PDVIAttributeGroup.h"
#include "PDVIAttributeItem.h"
#include "PDVIAnnotation.h"
#include "PDVIAnnotationItem.h"
#include "PDVIAnnotationView.h"
#include "PDVIMesh.h"
#include "PDVIMeshVertex.h"
#include "PDVIMeshPrimitive.h"
#include "PDVIMeshPrimCollection.h"
#include "PDVITopo.h"
#include "PDVIPhysicalQuantity.h"
#include "PDVIRenderBodySubset.h"
#include "PDVIRenderBody.h"
#include "PDVIRenderVertex.h"
#include "PDVIRenderGeometry.h"
#include "PDVIResultConfig.h"
#include "PDVIReferenceGeometry.h"
#include "PDVINodeSubsetMaterial.h"
#include "PDVIInstancedMesh.h"
#include "PDVIBatchedMesh.h"
#include "PDVIAnalysisResult.h"
#include "DftJson.h"
#include "PDVMath.h"

struct cJSON;

namespace kernel
{

namespace pdv
{

class IModelTree;
class IModel;
class IMesh;
class IAttribute;
class ICamera;
class IAnnotation;
class IMaterial;
class IBRep;

PDVCORE_API CUnicodeString ValueToString(DftFloat value);
PDVCORE_API CUnicodeString ValueToString(DftDouble value);

PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftInt8 value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftUInt8 value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftInt16 value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftUInt16 value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftInt value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftUInt value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftInt64 value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftUInt64 value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftFloat value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftDouble value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDV_CHAR* value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDV_WCHAR* value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const CUnicodeString& value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector2F& value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector3F& value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector4F& value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector2D& value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector3D& value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector4D& value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const RGBColor& value);
PDVCORE_API void OutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVMatrix4D& value);
PDVCORE_API void OutputValue(std::ostream &os, const PDV_CHAR *prefix, const PDV_CHAR *name, const PDVMatrix4F& value);

PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftInt8>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftUInt8>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftInt16>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftUInt16>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftInt>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftUInt>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftInt64>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftUInt64>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftFloat>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftDouble>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<CUnicodeString>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<PDVVector2F>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<PDVVector3F>& values);

PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<PDVVector4F>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<PDVVector2D>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<PDVVector3D>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<PDVVector4D>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<RGBColor>& values);
PDVCORE_API void OutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<PDVMatrix4D>& values);
PDVCORE_API void OutputValues(std::ostream &os, const PDV_CHAR *prefix, const PDV_CHAR *name, const std::vector<PDVMatrix4F> &values);

// JSON缩进
extern const PDV_CHAR* JSON_INDENT;

// 增加Json格式的log信息导出函数 [2023/7/14 Steven.Liu]
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftInt8 value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftUInt8 value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftInt16 value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftUInt16 value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftInt value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftUInt value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftInt64 value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftUInt64 value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftFloat value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, DftDouble value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDV_CHAR* value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDV_WCHAR* value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const CUnicodeString& value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector2F& value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector3F& value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector4F& value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector2D& value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector3D& value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVVector4D& value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const RGBColor& value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const PDVMatrix4D& value, DftBool withComma);
PDVCORE_API void JsonOutputValue(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const DftMatrix4D& value, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftInt8>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftUInt8>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftInt16>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftUInt16>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftInt>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftUInt>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftInt64>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftUInt64>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftFloat>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DftDouble>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<CUnicodeString>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<PDVVector2F>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<PDVVector3F>& values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream &os, const PDV_CHAR *prefix, const PDV_CHAR *name, const std::vector<PDVVector4F> &values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream &os, const PDV_CHAR *prefix, const PDV_CHAR *name, const std::vector<PDVVector2D> &values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream &os, const PDV_CHAR *prefix, const PDV_CHAR *name, const std::vector<PDVVector3D> &values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream &os, const PDV_CHAR *prefix, const PDV_CHAR *name, const std::vector<PDVVector4D> &values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream &os, const PDV_CHAR *prefix, const PDV_CHAR *name, const std::vector<RGBColor> &values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream &os, const PDV_CHAR *prefix, const PDV_CHAR *name, const std::vector<PDVMatrix4D> &values, DftBool withComma);
PDVCORE_API void JsonOutputValues(std::ostream &os, const PDV_CHAR *prefix, const PDV_CHAR *name, const std::vector<DftMatrix4D> &values, DftBool withComma);

template <class DataType>
void JsonOutputData(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const DataType& data, DftBool withComma)
{
    CUnicodeString indent0 = prefix;
    CUnicodeString indent1 = indent0 + JSON_INDENT;
    os << indent0 << "\"" << name << "\": {" << std::endl;
    data.Output(os, indent1);
    os << indent0 << "}" << (withComma ? "," : "") << std::endl;
}

template<class DataType>
void JsonOutputDataArray(std::ostream& os, const PDV_CHAR* prefix, const PDV_CHAR* name, const std::vector<DataType>& dataArray, DftBool withComma)
{
    CUnicodeString indent0 = prefix;
    CUnicodeString indent1 = indent0 + JSON_INDENT;
    CUnicodeString indent2 = indent1 + JSON_INDENT;
    DftUInt32 count = (DftUInt32)dataArray.size();
    if (count == 0)
        os << indent0 << "\"" << name << "(size = " << count << ")\": { }" << (withComma ? "," : "") << std::endl;
    else
    {
        os << indent0 << "\"" << name << "(size = " << count << ")\": {" << std::endl;
        for (DftUInt32 i = 0; i < count; i++)
        {
            os << indent1 << "\"" << name << "[" << i << "]\": {" << std::endl;
            dataArray[i].Output(os, indent2);
            os << indent1 << "}" << ((i != count - 1) ? "," : "") << std::endl;
        }
        os << indent0 << "}" << (withComma ? "," : "") << std::endl;
    }
}

// 增加优化的Json格式的log信息导出函数 [2023/7/14 Steven.Liu]
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, DftInt8 value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, DftUInt8 value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, DftInt16 value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, DftUInt16 value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, DftInt value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, DftUInt value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, DftInt64 value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, DftUInt64 value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, DftFloat value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, DftDouble value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, const PDV_CHAR* value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, const PDV_WCHAR* value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, const CUnicodeString& value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, const PDVVector2F& value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, const PDVVector3F& value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, const PDVVector4F& value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, const PDVVector2D& value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, const PDVVector3D& value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, const PDVVector4D& value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, const RGBColor& value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR* name, const PDVMatrix4D& value);
PDVCORE_API void JsonOutputValue(DftJson jsonNode, const PDV_CHAR *name, const PDVMatrix4F &value);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DftInt8>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DftUInt8>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DftInt16>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DftUInt16>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DftInt>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DftUInt>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DftInt64>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DftUInt64>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DftFloat>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DftDouble>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<CUnicodeString>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR* name, const std::vector<PDVVector2F>& values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR *name, const std::vector<PDVVector3F> &values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR *name, const std::vector<PDVVector4F> &values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR *name, const std::vector<PDVVector2D> &values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR *name, const std::vector<PDVVector3D> &values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR *name, const std::vector<PDVVector4D> &values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR *name, const std::vector<RGBColor> &values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR *name, const std::vector<PDVMatrix4D> &values);
PDVCORE_API void JsonOutputValues(DftJson jsonNode, const PDV_CHAR *name, const std::vector<PDVMatrix4F> &values);

template <class DataType>
void JsonOutputData(DftJson jsonNode, const PDV_CHAR* name, const DataType& data)
{
    data.Output(DftJsonAddObjectToObject(jsonNode, name));
}

template<class DataType>
void JsonOutputDataArray(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DataType>& dataArray)
{
    CUnicodeString nodeName;
    DftUInt count = (DftUInt)dataArray.size();
    nodeName.Format("%s(size = %u)", name, count);
    DftJson jsonItemRoot = DftJsonAddObjectToObject(jsonNode, nodeName.ToMultiByte());
    if (jsonItemRoot)
    {
        for (DftUInt i = 0; i < count; i++)
        {
            nodeName.Format("%s[%u]", name, i);
            JsonOutputData(jsonItemRoot, nodeName.ToMultiByte(), dataArray[i]);
        }
    }
}

template<class DataType>
void JsonOutputDataArrayGlobalInterface(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DataType>& dataArray)
{
    CUnicodeString nodeName;
    DftUInt count = (DftUInt)dataArray.size();
    nodeName.Format("%s(size = %u)", name, count);
    DftJson jsonItemRoot = DftJsonAddObjectToObject(jsonNode, nodeName.ToMultiByte());
    if (jsonItemRoot)
    {
        for (DftUInt i = 0; i < count; i++)
        {
            nodeName.Format("%s[%u]", name, i);
            Output(DftJsonAddObjectToObject(jsonItemRoot, nodeName.ToMultiByte()),dataArray[i]);
        }
    }
}

template<class DataType>
void JsonOutputDataPtr(DftJson jsonNode, const PDV_CHAR* name, const DataType* dataPtr)
{
    dataPtr->Output(DftJsonAddObjectToObject(jsonNode, name));
}

template<class DataType>
void JsonOutputDataPtrArray(DftJson jsonNode, const PDV_CHAR* name, const std::vector<DataType*>& dataPtrArray)
{
    CUnicodeString nodeName;
    DftUInt count = (DftUInt)dataPtrArray.size();
    nodeName.Format("%s(size = %u)", name, count);
    DftJson jsonItemRoot = DftJsonAddObjectToObject(jsonNode, nodeName.ToMultiByte());
    if (jsonItemRoot)
    {
        for (DftUInt i = 0; i < count; i++)
        {
            nodeName.Format("%s[%u]", name, i);
            JsonOutputDataPtr(jsonItemRoot, nodeName.ToMultiByte(), dataPtrArray[i]);
        }
    }
}

// 导出场景信息数据
PDVCORE_API void OutputPDVScene(std::ostream &os, IScene* &scene);
// 导出标注数据
PDVCORE_API void OutputPDVAnnotations(std::ostream &os, const std::vector<IAnnotation*> &annotations);
PDVCORE_API void OutputPDVAnnotation(std::ostream& os, IAnnotation* annotation);
// 导出模型数据
PDVCORE_API void OutputPDVMeshes(std::ostream &os, const std::vector<IMesh*> &meshes);
PDVCORE_API void OutputPDVMesh(std::ostream& os, IMesh* mesh);
// 导出模型数据
PDVCORE_API void OutputPDVModels(std::ostream &os, const std::vector<IModel*> &modelInstances);
// 导出材质数据
PDVCORE_API void OutputPDVMaterials(std::ostream &os, const std::vector<IMaterial*> &materials);
// 导出模型树
PDVCORE_API void OutputPDVModelTrees(std::ostream &os, const std::vector<IModelTree*> &modelTrees);
// 导出摄像机
PDVCORE_API void OutputPDVCameras(std::ostream &os, const std::vector<ICamera*> &cameras);
// 导出属性
PDVCORE_API void OutputPDVAttributes(std::ostream &os, const std::vector<IAttribute*> &attributes);
// 导出视图
PDVCORE_API void OutputPDVViews(std::ostream &os, const std::vector<IView*> &attributes);
// 导出几何拓扑数据
PDVCORE_API void OutputPDVBreps(std::ostream& os, const std::vector<IBRep*>& breps);
// 导出动画数据
PDVCORE_API void OutputPDVAnimations(std::ostream& os, const std::vector<IAnimation*>& animations);
// 导出基本体数据
PDVCORE_API void OutputPDVPrimities(std::ostream& os, const std::vector<IPrimity*>& primities);
// 导出文件头
PDVCORE_API void OutputPDVFileHeader(std::ostream &os, ISceneData* &sceneData);
// 导出外部链接
PDVCORE_API void OutputPDVExternalLink(std::ostream &os, IExternalLink* &externalLink);
// 导出安全控制文件
PDVCORE_API void OutputPDVSecurity(std::ostream &os, ISecurity* &security);
// 导出灯光数据
PDVCORE_API void OutputPDVLights(std::ostream& os, const std::vector<ILight*>& lights);
// 导出纹理数据
PDVCORE_API void OutputPDVTextures(std::ostream& os, const std::vector<ITexture*>& textures);
// 导出资源文件数据
PDVCORE_API void OutputPDVResources(std::ostream& os, const std::vector<IResource*>& resources);
// 导出审阅对象数据
PDVCORE_API void OutputPDVReviews(std::ostream& os, const std::vector<IReview*>& reviews);
// 导出物理量对象数据
PDVCORE_API void OutputPDVPhysicalQuantities(std::ostream& os, const std::vector<IPhysicalQuantity*>& physicalQuantities);
// 导出渲染主体子集对象数据
PDVCORE_API void OutputPDVRenderBodySubsets(std::ostream& os, const std::vector<IRenderBodySubset*>& renderBodySubsets);
// 导出渲染主体对象数据
PDVCORE_API void OutputPDVRenderBodies(std::ostream& os, const std::vector<IRenderBody*>& renderBodies);
// 导出渲染几何顶点数据
PDVCORE_API void OutputPDVRenderVertexes(std::ostream& os, const std::vector<IRenderVertex*>& renderVertexes);
PDVCORE_API void OutputPDVRenderVertex(std::ostream& os, IRenderVertex* renderVertex);
// 导出渲染几何体对象数据
PDVCORE_API void OutputPDVRenderGeometries(std::ostream& os, const std::vector<IRenderGeometry*>& renderGeometries);
PDVCORE_API void OutputPDVRenderGeometry(std::ostream& os, IRenderGeometry* renderGeometry);
// 导出分析结果配置对象数据
PDVCORE_API void OutputPDVResultConfigs(std::ostream& os, const std::vector<IResultConfig*>& resultConfigs);
// 导出渲染网格对象数据
PDVCORE_API void OutputPDVRenderMeshes(std::ostream& os, const std::vector<IRenderMesh*>& renderMeshes);
// 导出辅助几何对象数据
PDVCORE_API void OutputPDVReferenceGeometryGroups(std::ostream& os, const std::vector<IReferenceGeometryGroup*>& referenceGeometryGroups);
// 导出节点面材质对象数据
PDVCORE_API void OutputPDVNodeSubsetMaterials(std::ostream& os, const std::vector<INodeSubsetMaterial*>& nodeSubsetMaterials);
// 导出实例化网格对象数据
PDVCORE_API void OutputPDVInstanceMeshes(std::ostream& os, const std::vector<IInstancedMesh*>& instanceMeshes);
// 导出批处理网格对象数据
PDVCORE_API void OutputPDVBatchedMeshes(std::ostream& os, const std::vector<IBatchedMesh*>& batchedMeshes);
// 导出分析结果对象数据
PDVCORE_API void OutputPDVAnalysisResults(std::ostream& os, const std::vector<IAnalysisResult*>& analysisResults);
// 导出瓦片对象数据
PDVCORE_API void OutputPDVTileSet(std::ostream &os, ITileSet* &tileSet);

} // namespace pdv

} // namespace kernel
#endif
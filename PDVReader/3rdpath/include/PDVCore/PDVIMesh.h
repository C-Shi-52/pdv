/**
 * @file PDVIMesh.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：网格数据的接口声明
 * @details 详细说明
 */

#ifndef PDVIMESH_H
#define PDVIMESH_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

class IMeshVertex;
class IMeshPrimitive;
class IMeshPrimCollection;
class IGeomCurveData;
class IGeomSurfaceData;

/** @brief 网格对象掩码信息 */
enum MeshMaskType
{
    MESH_MASK_MATERIAL = 0x01,      ///< 是否包含颜色和透明度数据，1表示是，0表示否
    MESH_MASK_PRIMCOLLECTION = 0x02 ///< 是否包含图元集合数据，1表示是，0表示否
};

/** @brief 模型对象来源类型标识符 */
enum SourceType
{
    SOURCETYPE_NULL = 0,        ///< 未知
    SOURCETYPE_PROE_CREO = 1,   ///< ProE/Creo
    SOURCETYPE_CATIA_V5 = 2,    ///< CATIA V5
    SOURCETYPE_CATIA_V6 = 3,    ///< CATIA V6
    SOURCETYPE_UG = 4,          ///< UG
    SOURCETYPE_SOLIDWORKS = 5,  ///< SolidWorks
    SOURCETYPE_SOLIDEDGE = 6,   ///< SolidEdge
    SOURCETYPE_3DSMAX = 7,      ///< 3D Studio MAX
    SOURCETYPE_REVIT = 8,       ///< Revit
    SOURCETYPE_STL = 9,         ///< STL
    SOURCETYPE_OBJ = 10,        ///< OBJ
    SOURCETYPE_STEP = 11,       ///< STEP
    SOURCETYPE_IGES = 12,       ///< IGES
    SOURCETYPE_ZW3D = 13,       ///< 中望3D
    SOURCETYPE_CAXA = 14,       ///< CAXA
    SOURCETYPE_SINOVATION = 15, ///< SINOVATION
    SOURCETYPE_FBX = 16,        ///< FBX
    SOURCETYPE_VTK = 17,        ///< VTK
    SOURCETYPE_IFC = 18,        ///< IFC
    SOURCETYPE_3MF = 19,        ///< 3MF
    SOURCETYPE_ACIS = 20,       ///< ACIS  ext:SAT,SAB
    SOURCETYPE_AUTOCAD_2D = 21, ///< AutoCAD_2D  ext:DAE
    SOURCETYPE_AUTOCAD_3D = 22, ///< AutoCAD_3D  ext:DWG,DXF
    SOURCETYPE_DWF = 23,        ///< Autodesk DWF  ext:DWF,DWFX
    SOURCETYPE_INVENTOR = 24,   ///< Autodesk Inventor  ext:IPT,IAM
    SOURCETYPE_NAVISWORKS = 25, ///< Autodesk Navisworks  ext:NWD
    SOURCETYPE_DGN = 26,        ///< DGN
    SOURCETYPE_GLTF = 27,       ///< GLTF,GLB  Version 2.0 only
    SOURCETYPE_I_DEAS = 28,     ///< I-deas  ext:MF1,ARC,UNV,PKG
    SOURCETYPE_JT = 29,         ///< JT
    SOURCETYPE_PARASOLID = 30,  ///< Parasolid  ext:X_B,X_T,XMT,XMT_TXT
    SOURCETYPE_PDF = 31,        ///< PDF
    SOURCETYPE_PRC = 32,        ///< PRC
    SOURCETYPE_RHINO3D = 33,    ///< Rhino3D  ext:3DM
    SOURCETYPE_U3D = 34,        ///< U3D
    SOURCETYPE_VDA = 35,        ///< VDA
    SOURCETYPE_VRML = 36,       ///< VRML  ext:WRL,VRML
    SOURCETYPE_3DXML = 37,      ///< 3DXML ext:.3dxml
    SOURCETYPE_VTU = 38,        ///< VTU
    SOURCETYPE_RST = 39,        ///< RST
    SOURCETYPE_INP = 40,        ///< INP
    SOURCETYPE_COUNT            ///< 计数变量，注意修改
};

/**
 * @brief 获取模型对象来源类型标识符
 * @return DftUInt8 模型对象来源类型标识符
 * @param[in] typeStr 模型对象来源类型
 * @note
 */
PDVCORE_API DftInt8 GetSourceType(const CUnicodeString &typeStr);

/**
 * @brief 获取模型对象来源类型标识符
 * @return CUnicodeString 模型对象来源类型标识符
 * @param[in] typeEnum 模型对象来源类型
 * @note
 */
PDVCORE_API CUnicodeString GetSourceType(DftInt8 typeEnum);

/** @brief 网格数据的接口 */
class PDVCORE_API IMesh : public IDataObject
{
public:
    /**
     * @brief 获取网格对象的内容标志
     * @return DftUInt8 网格对象的内容标志
     * @note 第1位：是否关联材质；第2位：是否包含图元集合；第3-8位：保留使用，固定设置为0
     */
    virtual DftUInt8 GetBitMask() = 0;

    /**
     * @brief 设置网格对象的内容标志
     * @return PDV_RESULT
     * @param[in] iBitMask 网格对象的内容标志
     * @note
     */
    virtual PDV_RESULT SetBitMask(const DftUInt8 &iBitMask) = 0;

    /**
     * @brief 获取网格对象名称
     * @return PDV_RESULT
     * @param[out] oName 网格对象名称
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString &oName) = 0;

    /**
     * @brief 设置网格对象名称
     * @return PDV_RESULT
     * @param[in] iName 网格对象名称
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString &iName) = 0;

    /**
     * @brief 获取网格对象的包围盒
     * @return PDV_RESULT
     * @param[out] oBox 网格对象的包围盒
     * @note
     */
    virtual PDV_RESULT GetBoundingBox(BoundingBox &oBox) = 0;

    /**
     * @brief 设置网格对象的包围盒
     * @return PDV_RESULT
     * @param[in] iBox 网格对象的包围盒
     * @note
     */
    virtual PDV_RESULT SetBoundingBox(const BoundingBox &iBox) = 0;

    /**
     * @brief 获取材质ID
     * @return PDV_RESULT
     * @param[out] oMaterialID 网格材质ID
     * @note 如果网格包含材质，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESH_NO_MATERIAL
     */
    virtual PDV_RESULT GetMaterialID(DftUInt64 &oMaterialID) = 0;

    /**
     * @brief 设置网格的颜色和透明度数据
     * @return PDV_RESULT
     * @param[in] iMaterialID 网格材质ID
     * @note 如果网格包含材质，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESH_NO_MATERIAL
     */
    virtual PDV_RESULT SetMaterialID(const DftUInt64 &iMaterialID) = 0;

    /**
     * @brief 获取网格顶点数据接口
     * @return IMeshVertex 网格顶点数据接口
     * @note
     */
    virtual IMeshVertex *GetVertex() = 0;

    /**
     * @brief 添加网格顶点数据接口
     * @return IMeshPrimitive 网格顶点数据接口
     * @note
     */
    virtual IMeshPrimitive *AddPrimitive() = 0;

    /**
     * @brief 清空网格顶点数据
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearPrimitive() = 0;

    /**
     * @brief 获取图元数量
     * @return DftUInt 返回数量
     * @note
     */
    virtual DftUInt GetPrimitiveCount() = 0;

    /**
     * @brief 获取图元数组
     * @return PDV_RESULT
     * @param[out] oMeshPrimitiveArray 图元数组
     * @note
     */
    virtual PDV_RESULT GetPrimitiveArray(std::vector<IMeshPrimitive *> &oMeshPrimitiveArray) = 0;

    /**
     * @brief 添加网格图元集合数据接口
     * @return IMeshPrimCollection 网格图元集合数据接口
     * @note
     */
    virtual IMeshPrimCollection *AddPrimCollection() = 0;

    /**
     * @brief 清空网格图元集合数据
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearPrimCollection() = 0;

    /**
     * @brief 获取网格图元集合数据数量
     * @return DftUInt 返回网格图元集合数据数组数量
     * @note
     */
    virtual DftUInt GetPrimCollectionCount() = 0;

    /**
     * @brief 获取网格图元集合数据
     * @return PDV_RESULT
     * @param[out] oMeshPrimCollectionArray 网格数据图元集合数组
     * @note
     */
    virtual PDV_RESULT GetPrimCollectionArray(std::vector<IMeshPrimCollection *> &oMeshPrimCollectionArray) = 0;

    /**
     * @brief 获取数据的长度
     * @return DftInt64 数据长度
     * @note
     */
    virtual DftInt64 GetDataLength() const = 0;

    /**
     * @brief 从二进制数据流中读取数据信息
     * @return DftInt64 数据长度
     * @param[in] iStreamBuffer 数据流
     * @param[in] iBufferLength 数据流长度
     * @note
     */
    virtual DftInt64 ReadData(const PDV_CHAR *iStreamBuffer, DftInt64 iBufferLength) = 0;

    /**
     * @brief 向二进制数据流中写入数据信息
     * @return DftInt64 数据长度
     * @param[in,out] ioStreamBuffer 数据流
     * @param[in] iBufferLength 数据流长度
     * @note
     */
    virtual DftInt64 WriteData(PDV_CHAR *ioStreamBuffer, DftInt64 iBufferLength) const = 0;
};

} // namespace pdv

} // namespace kernel

#endif
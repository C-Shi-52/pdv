/**
 * @file PDVIModel.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：模型的接口声明
 * @details 详细说明
 */

#ifndef PDVIMODEL_H
#define PDVIMODEL_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

class IMesh;
class IMaterial;

/** @brief 模型对象的内容标志 */
enum ModelBitMaskType
{
    MODEL_MASK_PROPERTY = 1 << 0,   ///< 是否包含体积、表面积、重量和重心数据, 1表示是, 0表示否
    MODEL_MASK_MESH = 1 << 1,       ///< 是否包含网格数据, 1表示包含, 0表示不包含
    MODEL_MASK_PRIMITY = 1 << 2,    ///< 是否包含基本体数据, 1表示包含, 0表示不包含
    MODEL_MASK_TOPO = 1 << 3,       ///< 是否包含几何拓扑数据, 1表示包含, 0表示不包含
    MODEL_MASK_ANNOTATION = 1 << 4, ///< 是否关联标注, 1表示包含, 0表示不包含
    MODEL_MASK_ATTRIBUTE = 1 << 5,  ///< 是否关联属性, 1表示包含, 0表示不包含
};

/** @brief 模型对象的拓展内容标志 */
enum ModelExtendBitMaskType
{
    MODEL_MASK_EXTEND_RENDERBODY = 1 << 0,          ///< 是否关联渲染主体对象, 1表示关联, 0表示不关联
    MODEL_MASK_EXTEND_RESULT = 1 << 1,              ///< 是否关联分析结果对象, 1表示关联, 0表示不关联
    MODEL_MASK_EXTEND_REFERENCEGEOMETRY = 1 << 2,   ///< 是否关联辅助几何集合对象, 1表示关联, 0表示不关联
};

/** @brief 模型的接口 */
class PDVCORE_API IModel : public IDataObject
{
public:

    /**
     * @brief 获取模型对象的内容标志
     * @return DftUInt8 模型对象的内容标志
     * @note 详见 ModelBitMaskType 枚举
     */
    virtual DftUInt8 GetBitMask() = 0;

    /**
     * @brief 设置模型对象的内容标志
     * @return PDV_RESULT
     * @param[in] iBitMask 模型对象的内容标志
     * @note
     */
    virtual PDV_RESULT SetBitMask(const DftUInt8 &iBitMask) = 0;

    /**
     * @brief 获取模型名称
     * @return PDV_RESULT
     * @param[out] oName 模型名称
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString &oName) = 0;

    /**
     * @brief 设置模型名称
     * @return PDV_RESULT
     * @param[in] iName 模型名称
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString &iName) = 0;

    /**
     * @brief 获取模型对象的包围盒
     * @return PDV_RESULT
     * @param[out] oBox 模型对象的包围盒
     * @note
     */
    virtual PDV_RESULT GetBoundingBox(BoundingBox& oBox) = 0;

    /**
     * @brief 设置模型对象的包围盒
     * @return PDV_RESULT
     * @param[in] iBox 模型对象的包围盒
     * @note
     */
    virtual PDV_RESULT SetBoundingBox(const BoundingBox& iBox) = 0;

    /**
     * @brief 获取模型包围盒的角点
     * @return PDV_RESULT
     * @param[out] oCornerPoints 模型包围盒的角点
     * @note
     */
    virtual PDV_RESULT GetBoundingBoxCornerPoints(DftPoint3F oCornerPoints[8]) = 0;

    /**
     * @brief 获取模型质量特性数据
     * @return PDV_RESULT
     * @param[out] oVolume 模型体积
     * @param[out] oSurfaceArea 模型表面积
     * @param[out] oMass 模型质量
     * @param[out] oCenterOfGravity 模型重心
     * @note 如果模型包含质量特性数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESH_NO_MASS_PROPERTY
     */
    virtual PDV_RESULT GetMassProperty(DftFloat &oVolume, DftFloat &oSurfaceArea, DftFloat &oMass, PDVVector3F &oCenterOfGravity) = 0;

    /**
     * @brief 设置模型质量特性数据
     * @return PDV_RESULT
     * @param[in] iVolume 模型体积
     * @param[in] iSurfaceArea 模型表面积
     * @param[in] iMass 模型质量
     * @param[in] iCenterOfGravity 模型重心
     * @note 如果模型包含质量特性数据, 则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESH_NO_MASS_PROPERTY
     */
    virtual PDV_RESULT SetMassProperty(DftFloat iVolume, DftFloat iSurfaceArea, DftFloat iMass, const PDVVector3F &iCenterOfGravity) = 0;

    /**
     * @brief 获取模型关联的网格对象个数
     * @return DftUInt 模型关联的网格对象个数
     * @note
     */
    virtual DftUInt GetMeshCount() = 0;

    /**
     * @brief 获取模型关联的网格对象
     * @return IMesh 模型关联的网格对象
     * @param[in] iIndex 网格对象的索引
     * @note
     */
    virtual IMesh *GetMesh(DftUInt iIndex) = 0;

    /**
     * @brief 获取模型关联的网格对象ID
     * @return DftUInt64 模型关联的网格对象ID
     * @param[in] iIndex 网格对象的索引
     * @note
     */
    virtual DftUInt64 GetMeshID(DftUInt iIndex) = 0;

    /**
     * @brief 添加模型关联的网格对象
     * @return PDV_RESULT
     * @param[in] iID 模型关联的网格对象ID
     * @note
     */
    virtual PDV_RESULT AddMeshID(DftUInt64 iID) = 0;

    /**
     * @brief 清空模型关联的网格对象
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearMeshID() = 0;

     /**
     * @brief 获取模型关联的基本体对象个数
     * @return DftUInt 模型关联的基本体对象个数
     * @note
     */
    virtual DftUInt GetPrimityCount() = 0;

    /**
     * @brief 获取模型关联的基本体对象
     * @return IPrimity 模型关联的基本体对象
     * @param[in] iIndex 基本体对象的索引
     * @note
     */
    virtual IPrimity *GetPrimity(DftUInt iIndex) = 0;

    /**
     * @brief 获取模型关联的基本体对象ID
     * @return DftUInt64 模型关联的基本体对象ID
     * @param[in] iIndex 基本体对象的索引
     * @note
     */
    virtual DftUInt64 GetPrimityID(DftUInt iIndex) = 0;

    /**
     * @brief 添加模型关联的基本体对象ID
     * @return PDV_RESULT
     * @param[in] iID 模型关联的基本体对象ID
     * @note
     */
    virtual PDV_RESULT AddPrimityID(DftUInt64 iID) = 0;

    /**
     * @brief 清空模型关联的基本体对象ID存储结构
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearPrimityID() = 0;

    /**
    * @brief 获取模型关联的几何拓扑对象个数
    * @return DftUInt 模型关联的几何拓扑对象个数
    * @note
    */
    virtual DftUInt GetBRepCount() = 0;

    /**
     * @brief 获取模型关联的几何拓扑对象ID
     * @return DftUInt64 模型关联的几何拓扑对象ID
     * @param[in] iIndex 几何拓扑对象的索引
     * @note
     */
    virtual DftUInt64 GetBRepID(DftUInt iIndex) = 0;

    /**
     * @brief 获取模型关联的几何拓扑对象
     * @return IBRep 模型关联的几何拓扑对象
     * @param[in] iIndex 几何拓扑对象的索引
     * @note
     */
    virtual IBRep *GetBRep(DftUInt iIndex) = 0;

    /**
     * @brief 添加模型关联的几何拓扑对象ID
     * @return PDV_RESULT
     * @param[in] iID 模型关联的几何拓扑对象ID
     * @note
     */
    virtual PDV_RESULT AddBRepID(DftUInt64 iID) = 0;

    /**
     * @brief 清空模型关联的几何拓扑对象ID结构
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearBRepID() = 0;

    /**
     * @brief 获取关联标注ID
     * @return DftUInt64 关联标注ID
     * @note 如果关联标注对象，则返回关联标注ID，否则返回 \ref DFT_INVALID_ID
     */
    virtual DftUInt64 GetAnnotationID() = 0;

    /**
     * @brief 获取关联标注对象接口
     * @return IAnnotation * 关联标注对象接口
     * @note 如果关联标注对象，则返回关联标注对象接口，否则返回NULL
     */
    virtual IAnnotation* GetAnnotation() = 0;

    /**
     * @brief 设置关联标注对象ID
     * @return PDV_RESULT
     * @param[in] iAnnotationID 关联标注对象ID
     * @note 如果关联标注对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_ANNOTATION
     */
    virtual PDV_RESULT SetAnnotationID(DftUInt64 iAnnotationID) = 0;

    /**
     * @brief 获取关联属性ID
     * @return DftUInt64 关联属性ID
     * @note 如果关联属性对象，则返回关联属性ID，否则返回 \ref DFT_INVALID_ID
     */
    virtual DftUInt64 GetAttributeID() = 0;

    /**
     * @brief 设置关联属性ID
     * @return PDV_RESULT
     * @param[in] iAttributeID: 关联属性ID
     * @note 如果关联属性对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_ATTRIBUTE
     */
    virtual PDV_RESULT SetAttributeID(DftUInt64 iAttributeID) = 0;

    /**
     * @brief 获取关联属性对象接口
     * @return IAttribute * 关联属性对象接口
     * @note 如果关联属性对象，则返回关联属性对象接口，否则返回NULL
     */
    virtual IAttribute* GetAttribute() = 0;

     /**
      * @brief 获取模型对象的拓展内容标志
      * @return DftUInt8 模型对象的拓展内容标志
      * @note 详见 ModelExtendBitMaskType 枚举
      */
    virtual DftUInt8 GetExtendBitMask() = 0;

    /**
     * @brief 设置模型对象的拓展内容标志
     * @return PDV_RESULT
     * @param[in] iBitMask 模型对象的拓展内容标志
     * @note
     */
    virtual PDV_RESULT SetExtendBitMask(const DftUInt8 &iBitMask) = 0;

    /**
     * @brief 获取模型对象的外包区域
     * @return PDV_RESULT
     * @param[out] oBoundingVolume 模型对象的外包区域
     * @note
     */
    virtual PDV_RESULT GetBoundingVolume(BoundingVolume &oBoundingVolume) = 0;

    /**
     * @brief 设置模型对象的外包区域
     * @return PDV_RESULT
     * @param[in] iBoundingVolume 模型对象的外包区域
     * @note
     */
    virtual PDV_RESULT SetBoundingVolume(const BoundingVolume &iBoundingVolume) = 0;

    /**
     * @brief 获取模型统计信息
     * @return PDV_RESULT
     * @param[out] oStatistics 模型统计信息
     * @note 如果关联渲染主体对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_EXTENDINFO
     */
    virtual PDV_RESULT GetModelStatistics(Statistics &oStatistics) = 0;

    /**
     * @brief 设置模型统计信息
     * @return PDV_RESULT
     * @param[in] iStatistics 模型统计信息
     * @note 如果关联渲染主体对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_EXTENDINFO
     */
    virtual PDV_RESULT SetModelStatistics(const Statistics &iStatistics) = 0;

    /**
     * @brief 获取标注几何统计信息
     * @return PDV_RESULT
     * @param[out] oStatistics 标注几何统计信息
     * @note 如果关联标注对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_EXTENDINFO
     */
    virtual PDV_RESULT GetPMIStatistics(Statistics &oStatistics) = 0;

    /**
     * @brief 设置标注几何统计信息
     * @return PDV_RESULT
     * @param[in] iStatistics 标注几何统计信息
     * @note 如果关联标注对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_EXTENDINFO
     */
    virtual PDV_RESULT SetPMIStatistics(const Statistics &iStatistics) = 0;

    /**
    * @brief 获取模型关联的渲染主体对象个数
    * @return DftUInt 模型关联的渲染主体对象个数
    * @note
    */
    virtual DftUInt GetRenderBodyCount() = 0;

    /**
     * @brief 获取模型关联的渲染主体对象ID
     * @return DftUInt64 模型关联的渲染主体对象ID
     * @param[in] iIndex 渲染主体对象的索引
     * @note
     */
    virtual DftUInt64 GetRenderBodyID(DftUInt iIndex) = 0;

    /**
     * @brief 添加模型关联的渲染主体对象ID
     * @return PDV_RESULT
     * @param[in] iID 模型关联的渲染主体对象ID
     * @note 如果关联渲染主体对象, 则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_EXTENDINFO
     */
    virtual PDV_RESULT AddRenderBodyID(DftUInt64 iID) = 0;

    /**
     * @brief 清空模型关联的渲染主体对象ID结构
     * @return PDV_RESULT
     * @note 如果关联渲染主体对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_EXTENDINFO
     */
    virtual PDV_RESULT ClearRenderBodyID() = 0;

    /**
     * @brief 获取模型关联的渲染主体对象ID集
     * @return PDV_RESULT
     * @param[out] oRenderBodyIDs 模型关联的渲染主体对象ID集
     * @note 如果关联渲染主体对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_EXTENDINFO
     */
    virtual PDV_RESULT GetRenderBodyIDs(std::vector<DftUInt64>& oRenderBodyIDs) = 0;

    /**
     * @brief 设置模型关联的渲染主体对象ID集
     * @return PDV_RESULT
     * @param[in] iRenderBodyIDs 模型关联的渲染主体对象ID集
     * @note 如果关联渲染主体对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_EXTENDINFO
     */
    virtual PDV_RESULT SetRenderBodyIDs(const std::vector<DftUInt64>& iRenderBodyIDs) = 0;

    /**
     * @brief 获取模型关联分析结果配置ID
     * @return DftUInt64 模型关联分析结果配置ID
     * @note 如果关联分析结果配置对象，则返回关联分析结果配置ID，否则返回 \ref DFT_INVALID_ID
     */
    virtual DftUInt64 GetResultConfigID() = 0;

    /**
     * @brief 设置模型关联分析结果配置ID
     * @return PDV_RESULT
     * @param[in] iResultConfigID 模型关联分析结果配置ID
     * @note 如果关联分析结果配置对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_EXTENDINFO
     */
    virtual PDV_RESULT SetResultConfigID(DftUInt64 iResultConfigID) = 0;

    /**
     * @brief 获取模型关联分析结果ID
     * @return DftUInt64 模型关联分析结果ID
     * @note 如果关联分析结果对象，则返回关联分析结果ID，否则返回 \ref DFT_INVALID_ID
     */
    virtual DftUInt64 GetResultID() = 0;

    /**
     * @brief 设置模型关联分析结果ID
     * @return PDV_RESULT
     * @param[in] iResultID 模型关联分析结果ID
     * @note 如果关联分析结果对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_EXTENDINFO
     */
    virtual PDV_RESULT SetResultID(DftUInt64 iResultID) = 0;

    /**
     * @brief 获取模型关联辅助几何集合ID
     * @return DftUInt64 模型关联辅助几何集合ID
     * @note 如果关联辅助几何集合对象，则返回关联辅助几何集合ID，否则返回 \ref DFT_INVALID_ID
     */
    virtual DftUInt64 GetReferenceGeometryGroupID() = 0;

    /**
     * @brief 设置模型关联辅助几何集合ID
     * @return PDV_RESULT
     * @param[in] iReferenceGeometryGroupID 模型关联辅助几何集合ID
     * @note 如果关联辅助几何集合对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODEL_NO_EXTENDINFO
     */
    virtual PDV_RESULT SetReferenceGeometryGroupID(DftUInt64 iReferenceGeometryGroupID) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
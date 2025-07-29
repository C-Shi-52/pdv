/**
 * @file PDVIMeshPrimCollection.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：网格图元集合的接口声明
 * @details 详细说明
 */

#ifndef PDVIMESHPRIMCOLLECTION_H
#define PDVIMESHPRIMCOLLECTION_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

/** @brief 模型图元集合数据类型标识符 */
enum PrimCollectionType
{
    PRIMCOLLECTIONTYPE_NULL = 0,    ///< 未知
    PRIMCOLLECTIONTYPE_POINT = 1,   ///< 点
    PRIMCOLLECTIONTYPE_CURVE = 2,   ///< 曲线
    PRIMCOLLECTIONTYPE_SURFACE = 3, ///< 曲面
    PRIMCOLLECTIONTYPE_BODY = 4,    ///< 体
};

// 图元集合数据掩码信息
#define PRIMCOLLECTION_MASK_MATERIAL 0x01    // 是否包含颜色和透明度数据，1表示是，0表示否
#define PRIMCOLLECTION_MASK_BOUNDINGBOX 0x02 // 是否包含包围盒数据，1表示是，0表示否
#define PRIMCOLLECTION_MASK_TOPO_SOLID 0x04  // 是否是拓扑实体，1表示是，0表示否

/** @brief 网格图元集合的接口 */
class PDVCORE_API IMeshPrimCollection
{
public:
    /**
     * @brief 获取图元集合对象的内容标志
     * @return DftUInt8 图元集合对象的内容标志
     * @note 第1位：是否关联材质；第2位：是否包含图元集合；第3-8位：保留使用，固定设置为0
     */
    virtual DftUInt8 GetBitMask() = 0;

    /**
     * @brief 设置图元集合对象的内容标志
     * @return PDV_RESULT
     * @param[in] iBitMask 图元集合对象的内容标志
     * @note
     */
    virtual PDV_RESULT SetBitMask(const DftUInt8 &iBitMask) = 0;

    /**
     * @brief 获取图元集合对象唯一标识
     * @return DftUInt64 图元集合对象唯一标识
     * @note
     */
    virtual DftUInt64 GetID() = 0;

    /**
     * @brief 获取图元集合对象是否包含材质
     * @return DftBool 图元集合对象是否包含材质
     * @note
     */
    virtual DftBool GetMaterialFlag() = 0;

    /**
     * @brief 设置图元集合对象是否包含材质
     * @return PDV_RESULT
     * @param[in] iMaterialFlag 图元集合对象是否包含材质
     * @note
     */
    virtual PDV_RESULT SetMaterialFlag(const DftBool &iMaterialFlag) = 0;

    /**
     * @brief 获取图元集合对象是否包含包围盒数据
     * @return DftBool 图元集合对象是否包含包围盒数据
     * @note
     */
    virtual DftBool GetBoundingBoxFlag() = 0;

    /**
     * @brief 设置图元集合对象是否包含包围盒数据
     * @return PDV_RESULT
     * @param[in] iBoundingBoxFlag 图元集合对象是否包含包围盒数据
     * @note
     */
    virtual PDV_RESULT SetBoundingBoxFlag(const DftBool &iBoundingBoxFlag) = 0;

    /**
     * @brief 获取图元集合对象是否是拓扑实体
     * @return DftBool 图元集合对象是否是拓扑实体
     * @note
     */
    virtual DftBool GetTopoFlag() = 0;

    /**
     * @brief 设置图元集合对象是否是拓扑实体
     * @return PDV_RESULT
     * @param[in] iIsTopoSolid 图元集合对象是否是拓扑实体
     * @note
     */
    virtual PDV_RESULT SetTopoFlag(const DftBool &iIsTopoSolid) = 0;

    /**
     * @brief 获取图元集合类型
     * @return DftUInt 图元集合类型
     * @note
     */
    virtual DftUInt GetType() = 0;

    /**
     * @brief 设置图元集合类型
     * @return PDV_RESULT
     * @param[in] iType 图元集合类型
     * @note
     */
    virtual PDV_RESULT SetType(const DftUInt &iType) = 0;

    /**
     * @brief 获取图元集合对象的材质ID
     * @return PDV_RESULT
     * @param[out] oMaterialID 图元集合对象的材质ID
     * @note 如果图元集合对象包含颜色和透明度数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESHPRIMCOLLECTION_NO_MATERIAL
     */
    virtual PDV_RESULT GetMaterialID(DftUInt64 &oMaterialID) = 0;

    /**
     * @brief 设置图元集合对象的材质ID
     * @return PDV_RESULT
     * @param[in] iMaterialID 图元集合对象的材质ID
     * @note 如果图元集合对象包含颜色和透明度数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESHPRIMCOLLECTION_NO_MATERIAL
     */
    virtual PDV_RESULT SetMaterialID(const DftUInt64 &iMaterialID) = 0;

    /**
     * @brief 获取图元集合对象的点类型
     * @return PDV_RESULT
     * @param[out] oPointStyle 图元集合对象的点类型
     * @note 如果图元集合对象的类型为 \ref PRIMCOLLECTIONTYPE_POINT 则返回点类型
     */
    virtual PDV_RESULT GetPointStyle(DftUInt8 &oPointStyle) = 0;

    /**
     * @brief 设置图元集合对象的点类型
     * @return PDV_RESULT
     * @param[in] iPointStyle 图元集合对象的曲点类型
     * @note 如果图元集合对象的类型为 \ref PRIMCOLLECTIONTYPE_POINT 则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESHPRIMCOLLECTION_TYPE_ERROR
     */
    virtual PDV_RESULT SetPointStyle(const DftUInt8 &iPointStyle) = 0;

    /**
     * @brief 获取图元集合对象的线类型
     * @return PDV_RESULT
     * @param[out] oLineStyle 图元集合对象的线类型
     * @note 如果图元集合对象的类型为 \ref PRIMCOLLECTIONTYPE_CURVE 则返回线类型
     */
    virtual PDV_RESULT GetLineStyle(DftUInt8 &oLineStyle) = 0;

    /**
     * @brief 设置图元集合对象的线类型
     * @return PDV_RESULT
     * @param[in] iLineStyle 图元集合对象的线类型
     * @note 如果图元集合对象的类型为 \ref PRIMCOLLECTIONTYPE_CURVE 则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESHPRIMCOLLECTION_TYPE_ERROR
     */
    virtual PDV_RESULT SetLineStyle(const DftUInt8 &iLineStyle) = 0;

    /**
     * @brief 获取子集对象的曲线长度
     * @return DftFloat
     * @note 如果子集对象的类型为 \ref SUBSETTYPE_CURVE 则返回曲线长度，否则返回0
     */
    virtual DftFloat GetLength() = 0;

    /**
     * @brief 设置子集对象的曲线长度
     * @return PDV_RESULT
     * @param[in] iLength 子集对象的曲线长度
     * @note 如果子集对象的类型为 \ref SUBSETTYPE_CURVE 则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESHSUBSET_TYPE_ERROR
     */
    virtual PDV_RESULT SetLength(const DftFloat& iLength) = 0;

    /**
     * @brief 获取子集对象的曲面面积
     * @return DftFloat 曲面面积
     * @note 如果子集对象的类型为 \ref SUBSETTYPE_SURFACE 则返回曲面面积，否则返回0
     */
    virtual DftFloat GetArea() = 0;

    /**
     * @brief 设置子集对象的曲面面积
     * @return PDV_RESULT
     * @param[in] iArea 子集对象的曲面面积
     * @note 如果子集对象的类型为 \ref SUBSETTYPE_SURFACE 则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESHSUBSET_TYPE_ERROR
     */
    virtual PDV_RESULT SetArea(const DftFloat& iArea) = 0;

    /**
     * @brief 获取包围盒数据
     * @return PDV_RESULT
     * @param[out] oBoundingBox 包围盒数据
     * @note 如果图元集合对象包含包围盒数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESHPRIMCOLLECTION_NO_BOUNDINGBOX
     */
    virtual PDV_RESULT GetBoundingBox(BoundingBox &oBoundingBox) = 0;

    /**
     * @brief 获取图元集合包围盒的角点
     * @return PDV_RESULT
     * @param[out] oCornerPoints 图元集合包围盒的角点
     * @note
     */
    virtual PDV_RESULT GetBoundingBoxCornerPoints(DftVector3F oCornerPoints[8]) = 0;

    /**
     * @brief 设置包围盒数据
     * @return PDV_RESULT
     * @param[in] iBoundingBox 包围盒数据
     * @note 如果图元集合对象包含包围盒数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESHPRIMCOLLECTION_NO_BOUNDINGBOX
     */
    virtual PDV_RESULT SetBoundingBox(const BoundingBox &iBoundingBox) = 0;

    /**
     * @brief 获取图元集合关联拓扑ID
     * @return 如果图元集合对象包含topo数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESHPRIMCOLLECTION_NO_TOPO
     * @param[out] oTopoID 图元集合关联拓扑ID
     * @note
     */
    virtual PDV_RESULT GetTopoID(DftUInt64 &oTopoID) = 0;

    /**
     * @brief 设置图元集合关联拓扑ID
     * @return 如果图元集合对象包含topo数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MESHPRIMCOLLECTION_NO_TOPO
     * @param[in] iTopoID 图元集合关联拓扑ID
     * @note
     */
    virtual PDV_RESULT SetTopoID(const DftUInt64 &iTopoID) = 0;

    /**
     * @brief 获取图元索引数据
     * @return PDV_RESULT
     * @param[out] oPrimitiveIndexArray 图元索引数据
     * @note
     */
    virtual PDV_RESULT GetPrimitiveIndexArray(std::vector<DftUInt> &oPrimitiveIndexArray) = 0;

    /**
     * @brief 设置图元索引数据
     * @return PDV_RESULT
     * @param[in] iPrimitiveIndexArray 图元索引数据
     * @note
     */
    virtual PDV_RESULT SetPrimitiveIndexArray(const std::vector<DftUInt> &iPrimitiveIndexArray) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
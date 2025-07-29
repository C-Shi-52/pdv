/**
 * @file PDVIPhysicalQuantity.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-2-24
 * @brief 概述：PDVIPhysicalQuantity的接口声明
 * @details 详细说明
 */

#ifndef PDVIPHYSICALQUANTITY_H
#define PDVIPHYSICALQUANTITY_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 物理量类型 */
enum PhysicalQuantityType
{
    PHYSICAL_QUANTITY_TYPE_SCALAR = 1, ///< 标量
    PHYSICAL_QUANTITY_TYPE_VECTOR = 2  ///< 矢量
};

/** @brief 物理量图元类型 */
enum PhysicalQuantityPrimitiveType
{
    PHYSICAL_QUANTITY_PRIMITIVE_TYPE_VERTEX = 1, ///< 顶点
    PHYSICAL_QUANTITY_PRIMITIVE_TYPE_FACE = 2    ///< 三角面
};

/** @brief 顶点物理量 */
struct VertexQuantity
{
    DftUInt64 _vertexID;               ///< 顶点数据ID
    DftUInt32 _count;                  ///< 顶点数量（primitiveType = 1：顶点个数；primitiveType = 2：顶点个数/3）
    std::vector<DftFloat> _scalars;    ///< 顶点标量数据，类型为标量时有效
    std::vector<PDVVector3F> _vectors; ///< 顶点矢量数据，类型为矢量时有效
    /** 默认构造函数 */
    VertexQuantity() { Clear(); }
    /** 拷贝构造函数 */
    VertexQuantity(const VertexQuantity& data)
    {
        _vertexID = data._vertexID;
        _count = data._count;
        _scalars = data._scalars;
        _vectors = data._vectors;
    }
    /** 赋值运算符 */
    VertexQuantity& operator=(const VertexQuantity& data)
    {
        if (&data != this)
        {
            _vertexID = data._vertexID;
            _count = data._count;
            _scalars = data._scalars;
            _vectors = data._vectors;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _vertexID = DFT_INVALID_ID;
        _count = 0;
        _scalars.clear();
        _vectors.clear();
    }
};

/** @brief 顶点物理量集 */
typedef std::vector<VertexQuantity> VertexQuantityArray;

/** @brief 物理量的接口 */
class PDVCORE_API IPhysicalQuantity : public IDataObject
{
public:
    /**
     * @brief 获取物理量的名称
     * @return PDV_RESULT
     * @param[out] oName 物理量的名称
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString& oName) = 0;

    /**
     * @brief 设置物理量的名称
     * @return PDV_RESULT
     * @param[in] iName 物理量的名称
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString& iName) = 0;

    /**
     * @brief 获取物理量的类型
     * @return DftUInt8 物理量的类型，参见 PhysicalQuantityType
     * @note
     */
    virtual DftUInt8 GetType() = 0;

    /**
     * @brief 设置物理量的类型
     * @return PDV_RESULT
     * @param[in] iType 物理量的类型
     * @note
     */
    virtual PDV_RESULT SetType(const DftUInt8& iType) = 0;

    /**
     * @brief 获取图元类型
     * @return DftUInt8 图元类型，参见 PhysicalQuantityPrimitiveType
     * @note
     */
    virtual DftUInt8 GetPrimitiveType() = 0;

    /**
     * @brief 设置图元类型
     * @return PDV_RESULT
     * @param[in] iPrimitiveType 图元类型
     * @note
     */
    virtual PDV_RESULT SetPrimitiveType(const DftUInt8& iPrimitiveType) = 0;

    /**
     * @brief 获取顶点数据集对应数据
     * @return PDV_RESULT
     * @param[out] oVertexQuantityArray 顶点数据集对应数据
     * @note
     */
    virtual PDV_RESULT GetVertexQuantityArray(VertexQuantityArray& oVertexQuantityArray) = 0;

    /**
     * @brief 设置顶点数据集对应数据
     * @return PDV_RESULT
     * @param[in] iVertexQuantityArray 顶点数据集对应数据
     * @note
     */
    virtual PDV_RESULT SetVertexQuantityArray(const VertexQuantityArray& iVertexQuantityArray) = 0;
};

} // namespace pdv

} // namespace kernel

#endif

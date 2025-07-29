/**
 * @file PDVIReferenceGeometry.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-02-24
 * @brief 概述：PDVIReferenceGeometry的接口声明
 * @details 详细说明
 */

#ifndef PDVIREFERENCEGEOMETRY_H
#define PDVIREFERENCEGEOMETRY_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 辅助几何类型 */
enum ReferenceGeometryType
{
    REFERENCE_GEOMETRY_TYPE_CSYS = 1,  ///< 坐标系
    REFERENCE_GEOMETRY_TYPE_POINT = 2, ///< 点
    REFERENCE_GEOMETRY_TYPE_LINE = 3,  ///< 线
    REFERENCE_GEOMETRY_TYPE_PLANE = 4, ///< 面
};

/** @brief 辅助几何实现类 */
struct ReferenceGeometry
{
    DftUInt64 _id;       ///< 需要用户创建时进行设置
    DftUInt8 _mask;      ///< 标识位（第1个比特位：显示隐藏状态，1表示显示，0表示隐藏）
    DftUInt8 _type;      ///< 类型, 见 ReferenceGeometryType
    PDVVector3D _origin; ///< 原点
    PDVVector3D _axisX;  ///< X轴（坐标系、线、面时有效）
    PDVVector3D _axisY;  ///< Y轴（坐标系、面时有效）
    /** 默认构造函数 */
    ReferenceGeometry() { Clear(); }
    /** 析构函数 */
    ~ReferenceGeometry() { Clear(); }
    /** 带参构造函数 */
    ReferenceGeometry(const ReferenceGeometry& iValue)
    {
        _id = iValue._id;
        _mask = iValue._mask;
        _type = iValue._type;
        _origin = iValue._origin;
        _axisX = iValue._axisX;
        _axisY = iValue._axisY;
    }
    /** 赋值运算符 */
    ReferenceGeometry& operator=(const ReferenceGeometry& iValue)
    {
        if (&iValue != this)
        {
            _id = iValue._id;
            _mask = iValue._mask;
            _type = iValue._type;
            _origin = iValue._origin;
            _axisX = iValue._axisX;
            _axisY = iValue._axisY;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _id = DFT_INVALID_ID;
        _mask = 1;
        _type = 0;
        _origin.SetZero();
        _axisX.SetUnitX();
        _axisY.SetUnitY();
    }
};

/** @brief 辅助几何实现集 */
typedef std::vector<ReferenceGeometry> ReferenceGeometryArray;

/** @brief 辅助几何集集合的接口 */
class PDVCORE_API IReferenceGeometryGroup : public IDataObject
{
public:
    /**
     * @brief 获取顶点数据集对应数据
     * @return PDV_RESULT
     * @param[out] oReferenceGeometryArray 顶点数据集对应数据
     * @note
     */
    virtual PDV_RESULT GetReferenceGeometryArray(ReferenceGeometryArray& oReferenceGeometryArray) = 0;

    /**
     * @brief 设置顶点数据集对应数据
     * @return PDV_RESULT
     * @param[in] iReferenceGeometryArray 顶点数据集对应数据
     * @note
     */
    virtual PDV_RESULT SetReferenceGeometryArray(const ReferenceGeometryArray& iReferenceGeometryArray) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
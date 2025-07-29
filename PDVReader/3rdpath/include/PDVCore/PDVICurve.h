/**
 * @file PDVICurve.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-30
 * @brief 概述：曲线接口声明
 * @details 详细说明
 */

#ifndef PDVICURVE_H
#define PDVICURVE_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

/** @brief 曲线类型 */
enum CurveType
{
    CT_UNDIFINED = 0,      ///< 未知
    CT_LINE = 1,           ///< 直线
    CT_CIRCLE = 2,         ///< 圆
    CT_ELLIPSE = 3,        ///< 椭圆
    CT_BSPLINECURVE = 4    ///< B样条
};

/** @brief 二维曲线接口 */
class PDVCORE_API ICurve2d
{
public:
    /**
    * @brief 获取曲线类型
    * @return CurveType 曲线类型
    * @note
    */
    virtual CurveType GetType() const = 0;

    /**
    * @brief 获取参数的空间位置
    * @return PDVVector2D 空间位置
    * @param[in] iPara 参数
    * @note
    */
    virtual PDVVector2D GetPosition(DftDouble iPara) const = 0;
};

/** @brief 二维圆锥曲线接口 */
class PDVCORE_API IConic2d
{
public:
    /**
    * @brief 获取原点
    * @return PDVVector2D 原点坐标
    * @note
    */
    virtual PDVVector2D GetOrigin() const = 0;

    /**
    * @brief 设置原点
    * @param[in] iOrigin 原点
    * @note
    */
    virtual void SetOrigin(const PDVVector2D &iOrigin) = 0;

    /**
    * @brief 获取X轴方向
    * @return PDVVector2D X轴方向向量
    * @note
    */
    virtual PDVVector2D GetXDirection() const = 0;

    /**
    * @brief 设置X轴方向
    * @param[in] iXDir X轴方向向量
    * @note
    */
    virtual void SetXDirection(const PDVVector2D &iXDir) = 0;

    /**
    * @brief 获取Y轴方向
    * @return PDVVector2D Y轴方向向量
    * @note
    */
    virtual PDVVector2D GetYDirection() const = 0;

    /**
    * @brief 设置Y轴方向
    * @param[in] iYDir Y轴方向向量
    * @note
    */
    virtual void SetYDirection(const PDVVector2D &iYDir) = 0;
};

/** @brief 曲线接口 */
class PDVCORE_API ICurve
{
public:
    /**
     * @brief 获取曲线类型
     * @return CurveType 曲线类型
     * @note
     */
    virtual CurveType GetType() const = 0;

    /**
     * @brief 获取参数的空间位置
	 * @return PDVVector3D 空间位置
     * @param[in] iPara 参数
     * @note
     */
    virtual PDVVector3D GetPosition(DftDouble iPara) const = 0;
};

/** @brief 圆锥曲线接口 */
class PDVCORE_API IConic :public ICurve
{
public:
    /**
    * @brief 获取原点
    * @return PDVVector3D 原点坐标
    * @note
    */
    virtual PDVVector3D GetOrigin() const = 0;

    /**
    * @brief 设置原点
    * @param[in] iOrigin 原点
    * @note
    */
    virtual void SetOrigin(const PDVVector3D &iOrigin) = 0;

    /**
    * @brief 获取X轴方向
    * @return PDVVector3D X轴方向向量
    * @note
    */
    virtual PDVVector3D GetXDirection() const = 0;

    /**
    * @brief 设置X轴方向
    * @param[in] iXDir X轴方向向量
    * @note
    */
    virtual void SetXDirection(const PDVVector3D &iXDir) = 0;

    /**
    * @brief 获取Y轴方向
    * @return PDVVector3D Y轴方向向量
    * @note
    */
    virtual PDVVector3D GetYDirection() const = 0;

    /**
    * @brief 设置Y轴方向
    * @param[in] iYDir Y轴方向向量
    * @note
    */
    virtual void SetYDirection(const PDVVector3D &iYDir) = 0;

    /**
    * @brief 获取Z轴方向
    * @return PDVVector3D Z轴方向向量
    * @note
    */
    virtual PDVVector3D GetZDirection() const = 0;

    /**
    * @brief 设置Z轴方向
    * @param[in] iZDir Z轴方向向量
    * @note
    */
    virtual void SetZDirection(const PDVVector3D &iZDir) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
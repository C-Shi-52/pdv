/**
 * @file PDVILine.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-30
 * @brief 概述：直线接口声明
 * @details 详细说明：直线数据表示一条无限长的直线，通过原点和方向定义，参数区域无限大
 */

#ifndef PDVILINE_H
#define PDVILINE_H

#include "PDVBase.h"
#include "PDVICurve.h"

namespace kernel
{

namespace pdv
{

/** @brief 二维直线接口 */
class PDVCORE_API ILine2d : public ICurve2d
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
     * @brief 获取方向
     * @return PDVVector2D 方向向量
     * @note
     */
    virtual PDVVector2D GetDirection() const = 0;

    /**
     * @brief 设置方向
     * @param[in] iDirection 方向
     * @note
     */
    virtual void SetDirection(const PDVVector2D &iDirection) = 0;
};

/** @brief 直线接口 */
class PDVCORE_API ILine : public ICurve
{
public:
    /**
     * @brief 获取原点
     * @return PDVVector3D 原点坐标
     * @note
     */
    virtual PDVVector3D GetOrigin() const = 0;

    /**
     * @brief 获取方向
     * @return PDVVector3D 方向向量
     * @note
     */
    virtual PDVVector3D GetDirection() const = 0; 

    /**
     * @brief 设置原点
     * @param[in] iOrigin 原点
     * @note
     */
    virtual void SetOrigin(const PDVVector3D &iOrigin) = 0;

    /**
     * @brief 设置方向
     * @param[in] iDirection 方向
     * @note
     */
    virtual void SetDirection(const PDVVector3D &iDirection) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
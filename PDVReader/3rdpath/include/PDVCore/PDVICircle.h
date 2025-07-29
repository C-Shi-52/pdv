/**
 * @file PDVICircle.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-30
 * @brief 概述：圆接口声明
 * @details 详细说明：三维空间中的圆，通过原点、x轴方向、y轴方向定义
 */

#ifndef PDVICIRCLE_H
#define PDVICIRCLE_H

#include "PDVBase.h"
#include "PDVICurve.h"

namespace kernel
{

namespace pdv
{

/** @brief 二维圆接口 */
class PDVCORE_API ICircle2d : public IConic2d
{
public:
    /**
     * @brief 获取半径
     * @return DftDouble 半径
     * @note
     */
    virtual DftDouble GetRadius() const = 0;

    /**
    * @brief 设置半径
    * @param[in] iRadius 半径
    * @note
    */
    virtual void SetRadius(DftDouble iRadius) = 0;
};

/** @brief 圆接口 */
class ICircle : public IConic
{
public:
    /**
     * @brief 获取半径
     * @return DftDouble 半径
     * @note
     */
    virtual DftDouble GetRadius() const = 0;

    /**
     * @brief 设置半径
     * @param[in] iRadius 半径
     * @note
     */
    virtual void SetRadius(DftDouble iRadius) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
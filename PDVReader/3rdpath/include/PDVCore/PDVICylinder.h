/**
 * @file PDVICylinder.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-12-06
 * @brief 概述：圆柱面接口声明
 * @details 详细说明
 */

#ifndef PDVICYLINDER_H
#define PDVICYLINDER_H

#include "PDVBase.h"
#include "PDVISurface.h"

namespace kernel
{

namespace pdv
{

/** @brief 圆柱面接口 */
class PDVCORE_API ICylinder : public IElementarySurface
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
    virtual void SetRadius(const DftDouble &iRadius) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
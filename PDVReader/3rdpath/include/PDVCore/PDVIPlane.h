/**
 * @file PDVIPlane.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-12-05
 * @brief 概述：平面接口声明
 * @details
 */

#ifndef PDVIPLANE_H
#define PDVIPLANE_H

#include "PDVBase.h"
#include "PDVISurface.h"

namespace kernel
{

namespace pdv
{

/** @brief 平面接口 */
class PDVCORE_API IPlane : public IElementarySurface
{
public:
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
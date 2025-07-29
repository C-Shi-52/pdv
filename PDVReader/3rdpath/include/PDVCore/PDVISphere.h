/**
 * @file PDVISphere.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-12-06
 * @brief 概述：球面接口声明
 * @details 详细说明
 */

#ifndef PDVISPHERE_H
#define PDVISPHERE_H

#include "PDVBase.h"
#include "PDVISurface.h"

namespace kernel
{

namespace pdv
{
/** @brief 球面接口 */
class PDVCORE_API ISphere : public IElementarySurface
{
public:
    /**
     * @brief 获取球半径
     * @return DftDouble 球半径
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
/**
 * @file PDVITorus.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-12-06
 * @brief 概述：圆环面接口声明
 * @details 详细说明
 */

#ifndef PDVITORUS_H
#define PDVITORUS_H

#include "PDVBase.h"
#include "PDVISurface.h"

namespace kernel
{

namespace pdv
{

/** @brief 圆环面接口 */
class PDVCORE_API ITorus : public IElementarySurface
{
public:
    /**
     * @brief 获取主半径
     * @return DftDouble 主半径
     * @note
     */
    virtual DftDouble GetMajorRadius() const = 0;

    /**
     * @brief 设置主半径
     * @param[in] iMajorRadius 主半径
     * @note
     */
    virtual void SetMajorRadius(const DftDouble &iMajorRadius) = 0;

    /**
     * @brief 获取副半径
     * @return DftDouble 副半径
     * @note
     */
    virtual DftDouble GetMinorRadius() const = 0;

    /**
     * @brief 设置副半径
     * @param[in] iMinorRadius 副半径
     * @note
     */
    virtual void SetMinorRadius(const DftDouble &iMinorRadius) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
/**
 * @file PDVICone.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-12-06
 * @brief 概述：圆锥面接口声明
 * @details 详细说明
 */

#ifndef PDVICONE_H
#define PDVICONE_H

#include "PDVBase.h"
#include "PDVISurface.h"

namespace kernel
{

namespace pdv
{

/** @brief 圆锥面接口 */
class PDVCORE_API ICone : public IElementarySurface
{
public:
    /**
     * @brief 获取角度（圆锥z轴和母线之间的夹角）
     * @return DftDouble 锥角（圆锥z轴和母线之间的夹角）
     * @note
     */
    virtual DftDouble GetHalfAngle() const = 0;

    /**
     * @brief 设置角度（圆锥z轴和母线之间的夹角）
     * @param[in] iHalfAngle 角度（圆锥z轴和母线之间的夹角）
     * @note
     */
    virtual void SetHalfAngle(const DftDouble &iHalfAngle) = 0;

	/**
	* @brief 获取半径（圆锥面的半径）
	* @return DftDouble 半径（圆锥面的半径）
	* @note
	*/
	virtual DftDouble GetRadius() const = 0;

	/**
	* @brief 设置半径（圆锥面的半径）
	* @param[in] iRadius 半径（圆锥面的半径）
	* @note
	*/
	virtual void SetRadius(const DftDouble &iRadius) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
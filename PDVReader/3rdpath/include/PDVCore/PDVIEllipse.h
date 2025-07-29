/**
 * @file PDVIEllipse.h
 * @author wei.li
 * @version 1.0
 * @date 2024-02-18
 * @brief 概述：椭圆接口声明
 * @details 详细说明：三维空间中的椭圆，通过原点、x轴方向、y轴方向、长轴、短轴定义
 */

#ifndef PDVIELLIPSE_H
#define PDVIELLIPSE_H

#include "PDVBase.h"
#include "PDVICurve.h"

namespace kernel
{

namespace pdv
{

/** @brief 二维椭圆接口 */
class PDVCORE_API IEllipse2d : public IConic2d
{
public:
    /**
     * @brief 获取长轴半径
     * @return DftDouble 长轴半径
     * @note
     */
    virtual DftDouble GetMajorRadius() const = 0;

	/**
	* @brief 获取短轴半径
	* @return DftDouble 短轴半径
	* @note
	*/
	virtual DftDouble GetMinorRadius() const = 0;

    /**
    * @brief 设置长轴半径
    * @param[in] iMajorRadius 长轴半径
    * @note
    */
    virtual void SetMajorRadius(DftDouble iMajorRadius) = 0;

    /**
    * @brief 设置短轴半径
    * @param[in] iMinorRadius 短轴半径
    * @note
    */
    virtual void SetMinorRadius(DftDouble iMinorRadius) = 0;
};

/** @brief 椭圆接口 */
class PDVCORE_API IEllipse : public IConic
{
public:
    /**
     * @brief 设置Z轴方向
     * @param[in] iZDir Z轴方向向量
     * @note
     */
    virtual void SetZDirection(const PDVVector3D &iZDir) = 0;

    /**
     * @brief 获取长轴半径
     * @return DftDouble 长轴半径
     * @note
     */
    virtual DftDouble GetMajorRadius() const = 0;

	/**
	* @brief 获取短轴半径
	* @return DftDouble 短轴半径
	* @note
	*/
	virtual DftDouble GetMinorRadius() const = 0;

    /**
     * @brief 设置长轴半径
     * @param[in] iMajorRadius 长轴半径
     * @note
     */
    virtual void SetMajorRadius(DftDouble iMajorRadius) = 0;

    /**
    * @brief 设置短轴半径
    * @param[in] iMinorRadius 短轴半径
    * @note
    */
    virtual void SetMinorRadius(DftDouble iMinorRadius) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
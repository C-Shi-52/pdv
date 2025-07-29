/**
 * @file PDVINurbsCurve.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-30
 * @brief 概述：Nurbs曲线接口声明
 * @details 详细说明：Nurbs曲线可以用来描述空间中的任意曲线
 */

#ifndef PDVINURBSCURVE_H
#define PDVINURBSCURVE_H

#include "PDVBase.h"
#include "PDVICurve.h"

namespace kernel
{

namespace pdv
{
/** @brief 二维NURBS曲线数据 */
struct NurbsCurve2dData;
/** @brief NURBS曲线数据 */
struct NurbsCurveData;

/** @brief 二维Nurbs曲线接口 */
class PDVCORE_API INurbsCurve2d : public ICurve2d
{
public:
    /**
     * @brief 获取nurbs曲线
     * @param[out] oData nurbs曲线数据
     * @note
     */
    virtual void GetNurbsCurve(NurbsCurve2dData& oData) const = 0;

    /**
     * @brief 设置nurbs曲线
     * @param[in] iData nurbs曲线数据
     * @note
     */
    virtual void SetNurbsCurve(const NurbsCurve2dData& iData) = 0;
};

/** @brief Nurbs曲线接口 */
class PDVCORE_API INurbsCurve : public ICurve
{
public:
    /**
     * @brief 获取nurbs曲线
     * @param[out] oData nurbs曲线数据
     * @note
     */
    virtual void GetNurbsCurve(NurbsCurveData& oData) const = 0;

    /**
     * @brief 设置nurbs曲线
     * @param[in] iData nurbs曲线数据
     * @note
     */
    virtual void SetNurbsCurve(NurbsCurveData& iData) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
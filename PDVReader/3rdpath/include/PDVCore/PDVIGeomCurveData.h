/**
 * @file PDVIGeomCurveData.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-30
 * @brief 概述：几何曲线数据接口声明
 * @details 详细说明：几何曲线数据是一种包含裁剪区域的曲线数据
 */

#ifndef PDVIGEOMCURVEDATA_H
#define PDVIGEOMCURVEDATA_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

class ICurve2d;
class ICurve;
class ICurveOnSurface;

/** @brief 二维几何曲线数据接口 */
class PDVCORE_API IGeomCurve2dData
{
public:
    /**
    * @brief 获取唯一标识
    * @return DftUInt64 唯一标识
    * @note
    */
    virtual DftUInt64 GetID() const = 0;

    /**
    * @brief 获取曲线类型
    * @return DftUInt8 曲线类型，见 CurveType
    * @note
    */
    virtual DftUInt8 GetType() const = 0;

    /**
    * @brief 获取曲线接口
    * @return ICurve2d * 曲线接口
    * @note
    */
    virtual ICurve2d* GetCurve() const = 0;

    /**
    * @brief 获取起始参数
    * @return DftDouble 起始参数
    * @note
    */
    virtual DftDouble GetStartParameter() const = 0;

    /**
    * @brief 获取终止参数
    * @return DftDouble 终止参数
    * @note
    */
    virtual DftDouble GetEndParameter() const = 0;
};

/** @brief 几何曲线数据接口 */
class PDVCORE_API IGeomCurveData
{
public:
    /**
     * @brief 获取唯一标识
     * @return DftUInt64 唯一标识
     * @note
     */
    virtual DftUInt64 GetID() const = 0;

    /**
     * @brief 获取曲线类型
     * @return DftUInt8 曲线类型，见 CurveType
     * @note
     */
    virtual DftUInt8 GetType() const = 0;

    /**
     * @brief 获取曲线接口
     * @return ICurve * 曲线接口
     * @note
     */
    virtual ICurve* GetCurve() const = 0;

    /**
     * @brief 获取起始参数
     * @return DftDouble 起始参数
     * @note
     */
    virtual DftDouble GetStartParameter() const = 0;

    /**
     * @brief 获取终止参数
     * @return DftDouble 终止参数
     * @note
     */
    virtual DftDouble GetEndParameter() const = 0;

    /**
    * @brief 获取曲面上的曲线数据
    * @return ICurveOnSurface * 曲面上的曲线数据
    * @param[in] iSrfId 曲面的唯一标识
    * @note
    */
    virtual const ICurveOnSurface* GetCurveOnSurfaceData(DftUInt64 iSrfId) const = 0;

    /**
    * @brief 获取曲面上的曲线数据
    * @param[in] iCrvOnSrfs 曲面上的曲线数据
    * @note
    */
    virtual void GetCurveOnSurfaceData(std::vector<ICurveOnSurface*>& iCrvOnSrfs) const = 0;
};

} // namespace pdv

} // namespace kernel

#endif
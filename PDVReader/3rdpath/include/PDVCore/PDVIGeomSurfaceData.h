/**
 * @file PDVIGeomSurfaceData.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-12-05
 * @brief 概述：几何曲面数据接口声明
 * @details 详细说明：几何曲面数据是一种包含裁剪区域的曲面数据
 */

#ifndef PDVIGEOMSURFACEDATA_H
#define PDVIGEOMSURFACEDATA_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

class ISurface;

/** @brief 几何曲面数据接口 */
class PDVCORE_API IGeomSurfaceData
{
public:
    /**
     * @brief 获取唯一标识
     * @return DftUInt64 唯一标识
     * @note
     */
    virtual DftUInt64 GetID() const = 0;

    /**
     * @brief 获取曲面类型
     * @return DftUInt8 曲面类型，见 SurfaceType
     * @note
     */
    virtual DftUInt8 GetType() const = 0;

    /**
     * @brief 获取曲面接口
     * @return ISurface * 曲面接口
     * @note
     */
    virtual ISurface* GetSurface() const = 0;

    /**
     * @brief 设置曲面接口
     * @param[in] iSurface 曲面
     * @note
     */
    virtual void SetSurface(ISurface* iSurface) = 0;

    /**
     * @brief 获取参数域的最小值
     * @return PDVVector2D 获取参数域的最小值
     * @note
     */
    virtual PDVVector2D GetDomainMin() const = 0;

    /**
     * @brief 设置参数域的最小值
     * @param[in] iMin 参数域的最小值
     * @note
     */
    virtual void SetDomainMin(const PDVVector2D& iMin) = 0;

    /**
     * @brief 获取参数域的最大值
     * @return PDVVector2D 获取参数域的最大值
     * @note
     */
    virtual PDVVector2D GetDomainMax() const = 0;

    /**
     * @brief 设置参数域的最大值
     * @param[in] iMax 参数域的最大值
     * @note
     */
    virtual void SetDomainMax(const PDVVector2D& iMax) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
/**
 * @file PDVICurveOnSurface.h
 * @author tian.zhao
 * @version 1.0
 * @date 2024-07-05
 * @brief 概述：曲面上的曲线接口声明
 * @details 详细说明
 */

#ifndef PDVICURVEONSURFACE_H
#define PDVICURVEONSURFACE_H

#include "PDVBase.h"
#include "PDVISurface.h"
#include "PDVICurve.h"

namespace kernel
{

namespace pdv
{

class IGeomCurve2dData;

/** @brief 曲面上的曲线接口 */
class PDVCORE_API ICurveOnSurface
{
public:
    /**
     * @brief 获取曲面的id
     * @return DftUInt64 曲面的id
     * @note
     */
    virtual DftUInt64 GetSrfId() const = 0;

    /**
     * @brief 获取参数曲线数据
     * @return IGeomCurve2dData 参数曲线数据
     * @note
     */
    virtual const IGeomCurve2dData* GetPCrvData() const = 0;
};

} // namespace pdv

} // namespace kernel

#endif
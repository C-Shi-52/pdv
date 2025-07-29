/**
 * @file PDVINurbsSurface.h
 * @author zhaotian
 * @version 1.0
 * @date 2024-08-12
 * @brief 概述：nurbs曲面接口声明
 * @details 详细说明
 */

#ifndef PDVINURBSSURFACE_H
#define PDVINURBSSURFACE_H

#include "PDVBase.h"
#include "PDVISurface.h"

namespace kernel
{

namespace pdv
{
/** @brief NURBS曲面数据 */
struct NurbsSurfaceData;

/** @brief NURBS曲面接口 */
class PDVCORE_API INurbsSurface : public ISurface
{
public:
    /**
    * @brief 获取nurbs曲面
    * @param[in] iData nurbs曲线数据
    * @note
    */
    virtual void GetNurbsSurface(NurbsSurfaceData& iData) const = 0;

    /**
    * @brief 设置nurbs曲面
    * @param[in] iData nurbs曲线数据
    * @note
    */
    virtual void SetNurbsSurface(NurbsSurfaceData& iData) = 0;
};
} // namespace pdv

} // namespace kernel
#endif
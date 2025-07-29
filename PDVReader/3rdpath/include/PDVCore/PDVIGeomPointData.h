/**
 * @file PDVIGeomPointData.h
 * @author wei.li
 * @version 1.0
 * @date 2024-2-21
 * @brief 概述：几何点数据接口声明
 * @details 详细说明
 */

#ifndef PDVIGEOMPOINTDATA_H
#define PDVIGEOMPOINTDATA_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

/** @brief 几何点数据接口 */
class PDVCORE_API IGeomPointData
{
public:
    /**
     * @brief 获取唯一标识
     * @return DftUInt64 唯一标识
     * @note
     */
    virtual DftUInt64 GetID() const = 0;

    /**
     * @brief 获取位置点
     * @return PDVVector3D 位置点
     * @note
     */
    virtual PDVVector3D GetPosition() const = 0;

    /**
     * @brief 设置位置
     * @param[in] iPosition 坐标点
     * @note
     */
    virtual void SetPosition(PDVVector3D iPosition) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
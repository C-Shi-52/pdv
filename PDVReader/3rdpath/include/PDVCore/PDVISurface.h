/**
 * @file PDVISurface.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-12-05
 * @brief 概述：曲面接口声明
 * @details 详细说明
 */

#ifndef PDVISURFACE_H
#define PDVISURFACE_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

/** @brief 曲面类型 */
enum SurfaceType
{
    ST_UNDIFINED = 0,          ///< 未知曲面
    ST_PLANE = 1,              ///< 平面
    ST_CYLINDER = 2,           ///< 圆柱面
    ST_CONE = 3,               ///< 圆锥面
    ST_TORUS = 4,              ///< 圆环面
    ST_SPHERE = 5,             ///< 球面
    ST_BSPLINESURFACE = 6,     ///< B样条曲面
    ST_LINEAREXTRUSION = 7,    ///< 拉伸面
    ST_REVOLUTION = 8          ///< 旋转面
};

/** @brief 曲面接口 */
class PDVCORE_API ISurface
{
public:
    /**
     * @brief 获取曲面类型
     * @return SurfaceType 曲面类型
     * @note
     */
    virtual SurfaceType GetType() const = 0;

    /**
     * @brief 获取参数的空间位置
     * @param[in] iUPara 参数U
     * @param[in] iVPara 参数V
     * @return PDVVector3D 空间位置
     * @note
     */
    virtual PDVVector3D GetPosition(DftDouble iUPara, DftDouble iVPara) const = 0;
};

/** @brief 基本几何曲面接口 */
class PDVCORE_API IElementarySurface : public ISurface
{
public:
    /**
    * @brief 获取原点
    * @return PDVVector3D 原点坐标
    * @note
    */
    virtual PDVVector3D GetOrigin() const = 0;

    /**
    * @brief 设置原点
    * @param[in] iOrigin 原点
    * @note
    */
    virtual void SetOrigin(const PDVVector3D &iOrigin) = 0;

    /**
    * @brief 获取X轴方向
    * @return PDVVector3D X轴方向向量
    * @note
    */
    virtual PDVVector3D GetXDirection() const = 0;

    /**
    * @brief 设置X轴方向
    * @param[in] iXDir X轴方向向量
    * @note
    */
    virtual void SetXDirection(const PDVVector3D &iXDir) = 0;

    /**
    * @brief 获取Y轴方向
    * @return PDVVector3D Y轴方向向量
    * @note
    */
    virtual PDVVector3D GetYDirection() const = 0;

    /**
    * @brief 设置Y轴方向
    * @param[in] iYDir Y轴方向向量
    * @note
    */
    virtual void SetYDirection(const PDVVector3D &iYDir) = 0;

    /**
    * @brief 获取Z轴方向
    * @return PDVVector3D Z轴方向向量
    * @note
    */
    virtual PDVVector3D GetZDirection() const = 0;

    /**
    * @brief 设置Z轴方向
    * @param[in] iZDir Z轴方向向量
    * @note
    */
    virtual void SetZDirection(const PDVVector3D &iZDir) = 0;
};
} // namespace pdv

} // namespace kernel
#endif
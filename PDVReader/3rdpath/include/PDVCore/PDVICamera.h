/**
 * @file PDVICamera.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-15
 * @brief 概述：摄像机数据的接口
 * @details 详细说明
 */

#ifndef PDVICAMERA_H
#define PDVICAMERA_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 摄像机类型 */
enum CameraType
{
    PERSPECTIVE = 1, ///< 透视摄像机
    PARALLEL = 2     ///< 平行摄像机
};

/** @brief 摄像机数据的接口 */
class PDVCORE_API ICamera : public IDataObject
{
public:
    /**
     * @brief 获取相机类型
     * @return DftUInt8 相机类型
     * @note
     */
    virtual DftUInt8 GetType() = 0;

    /**
     * @brief 设置相机类型
     * @return PDV_RESULT
     * @param[in] iType 相机类型
     * @note
     */
    virtual PDV_RESULT SetType(DftUInt8 iType) = 0;

    /**
     * @brief 获取Y方向的视角(弧度值)
     * @return DftFloat Y方向的视角(弧度值)
     * @note
     */
    virtual DftFloat GetFOV() = 0;

    /**
     * @brief 设置Y方向的视角(弧度值)
     * @return PDV_RESULT
     * @param[in] iFOVY Y方向的视角(弧度值)
     * @note
     */
    virtual PDV_RESULT SetFOV(const DftFloat& iFOV) = 0;

    /**
     * @brief 获取相机横向视野大小
     * @return DftFloat 相机横向视野大小
     * @note
     */
    virtual DftFloat GetXSize() = 0;

    /**
     * @brief 设置相机横向视野大小
     * @return PDV_RESULT
     * @param[in] iXSize 相机横向视野大小
     * @note
     */
    virtual PDV_RESULT SetXSize(DftFloat iXSize) = 0;

    /**
     * @brief 获取相机纵向视野大小
     * @return DftFloat 相机纵向视野大小
     * @note
     */
    virtual DftFloat GetYSize() = 0;

    /**
     * @brief 设置相机纵向视野大小
     * @return PDV_RESULT
     * @param[in] iYSize 相机纵向视野大小
     * @note
     */
    virtual PDV_RESULT SetYSize(DftFloat iYSize) = 0;

    /**
     * @brief 获取摄像机位置
     * @return PDV_RESULT
     * @param[out] oPosition 摄像机位置
     * @note
     */
    virtual PDV_RESULT GetPosition(PDVVector3F &oPosition) = 0;

    /**
     * @brief 设置摄像机位置
     * @return PDV_RESULT
     * @param[in] iPosition 摄像机位置
     * @note
     */
    virtual PDV_RESULT SetPosition(const PDVVector3F &iPosition) = 0;

    /**
     * @brief 获取摄像机兴趣点位置
     * @return PDV_RESULT
     * @param[out] oTarget 摄像机兴趣点位置
     * @note
     */
    virtual PDV_RESULT GetTarget(PDVVector3F &oTarget) = 0;

    /**
     * @brief 设置摄像机兴趣点位置
     * @return PDV_RESULT
     * @param[in] iTarget 摄像机兴趣点位置
     * @note
     */
    virtual PDV_RESULT SetTarget(const PDVVector3F &iTarget) = 0;

    /**
     * @brief 获取摄像机的上方向向量
     * @return PDV_RESULT
     * @param[out] oUp 摄像机的上方向向量
     * @note
     */
    virtual PDV_RESULT GetUp(PDVVector3F &oUp) = 0;

    /**
     * @brief 设置摄像机的上方向向量
     * @return PDV_RESULT
     * @param[in] iUp 摄像机的上方向向量
     * @note
     */
    virtual PDV_RESULT SetUp(const PDVVector3F &iUp) = 0;

    /**
     * @brief 获取近平面
     * @return DftFloat 近平面
     * @note
     */
    virtual DftFloat GetZNear() = 0;

    /**
     * @brief 设置近平面
     * @return PDV_RESULT
     * @param[in] iZNear 近平面
     * @note
     */
    virtual PDV_RESULT SetZNear(const DftFloat &iZNear) = 0;

    /**
     * @brief 获取远平面
     * @return DftFloat 远平面
     * @note
     */
    virtual DftFloat GetZFar() = 0;

    /**
     * @brief 设置远平面
     * @return PDV_RESULT
     * @param[in] iZFar 远平面
     * @note
     */
    virtual PDV_RESULT SetZFar(const DftFloat &iZFar) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
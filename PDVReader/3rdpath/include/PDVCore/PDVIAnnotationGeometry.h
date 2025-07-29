/**
 * @file PDVIAnnotationGeometry.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2023-06-19
 * @brief 概述：标注辅助几何的接口声明
 * @details 详细说明
 */

#ifndef PDVIANNOTATIONGEOMETRY_H
#define PDVIANNOTATIONGEOMETRY_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

/** @brief 标注几何的接口 */
class PDVCORE_API IAnnotationGeometry
{
public:
    /**
     * @brief 获取标注辅助几何对象唯一标识
     * @return DftUInt64 标注辅助几何对象唯一标识
     * @note
     */
    virtual DftUInt64 GetID() = 0;

    /**
     * @brief 获取标注辅助几何相对于模型对象的局部变换信息
     * @return PDVMatrix4F 局部变换信息
     * @note
     */
    virtual PDVMatrix4F GetMatrix() = 0;

    /**
     * @brief 设置标注辅助几何相对于模型对象的局部变换信息
     * @return PDV_RESULT
     * @param[in] iTransformation 局部变换信息
     * @note
     */
    virtual PDV_RESULT SetMatrix(const PDVMatrix4F &iTransformation) = 0;

    /**
     * @brief 获取外包盒
     * @return PDV_RESULT
     * @param[out] oBox 外包盒
     * @note
     */
    virtual PDV_RESULT GetBox(OrientedBoundingBox &oBox) = 0;

    /**
     * @brief 设置标注辅助几何的外包盒
     * @return PDV_RESULT
     * @param[in] iBox 外包盒
     * @note
     */
    virtual PDV_RESULT SetBox(const OrientedBoundingBox &iBox) = 0;

    /**
     * @brief 获取标注辅助几何的渲染主体数据ID
     * @return DftUInt64 标注辅助几何的渲染主体数据ID
     * @note
     */
    virtual DftUInt64 GetRenderBodyID() = 0;

    /**
     * @brief 设置标注辅助几何的渲染主体数据ID
     * @return PDV_RESULT
     * @param[in] iRenderBodyID 标注辅助几何的渲染主体数据ID
     * @note
     */
    virtual PDV_RESULT SetRenderBodyID(const DftUInt64 &iRenderBodyID) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
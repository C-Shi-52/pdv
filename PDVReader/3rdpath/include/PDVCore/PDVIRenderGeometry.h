/**
 * @file PDVIRenderGeometry.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-02-24
 * @brief 概述：PDVRenderGeometry的接口声明
 * @details 详细说明
 */

#ifndef PDVIRENDERGEOMETRY_H
#define PDVIRENDERGEOMETRY_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 渲染几何体的接口 */
class PDVCORE_API IRenderGeometry : public IDataObject
{
public:
    /**
     * @brief 获取索引个数
     * @return DftUInt 索引个数
     * @note
     */
    virtual DftUInt GetIndexCount() const = 0;

    /**
     * @brief 获取索引集
     * @return PDV_RESULT
     * @param[out] oIndexes 索引集
     * @note
     */
    virtual PDV_RESULT GetIndexes(std::vector<DftUInt32>& oIndexes) = 0;

    /**
     * @brief 设置索引集
     * @return PDV_RESULT
     * @param[in] iIndexes 索引集
     * @note
     */
    virtual PDV_RESULT SetIndexes(const std::vector<DftUInt32>& iIndexes) = 0;

    /**
     * @brief 追加索引集
     * @return PDV_RESULT
     * @param[in] iIndexes 索引集
     * @note
     */
    virtual PDV_RESULT AddIndexes(const std::vector<DftUInt32>& iIndexes) = 0;

    /**
     * @brief 获取顶点数据ID
     * @return DftUInt64 顶点数据ID
     * @note
     */
    virtual DftUInt64 GetVertexID() = 0;

    /**
     * @brief 设置顶点数据ID
     * @return PDV_RESULT
     * @param[in] iVertexID 顶点数据ID
     * @note
     */
    virtual PDV_RESULT SetVertexID(const DftUInt64& iVertexID) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
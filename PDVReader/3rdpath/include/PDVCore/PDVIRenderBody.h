/**
 * @file PDVIRenderBody.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-02-24
 * @brief 概述：渲染主体的接口声明
 * @details 详细说明
 */

#ifndef PDVIRENDERBODY_H
#define PDVIRENDERBODY_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{
/** @brief  */
enum RenderBodyBitMask
{
    RENDER_BODY_MASK_BREP = 0x0001,   ///< 是否关联几何拓扑数据
    RENDER_BODY_MASK_SUBSET = 0x0002, ///< 是否关联渲染主体子集数据
    RENDER_BODY_MASK_MATRIX = 0x0004  ///< 是否包含局部坐标系矩阵数据
};

/** @brief 渲染主体的接口 */
class PDVCORE_API IRenderBody : public IDataObject
{
public:

    /**
     * @brief 获取标识位
     * @return DftUInt8 标识位
     * @note
     */
    virtual DftUInt8 GetBitMask() = 0;

    /**
     * @brief 设置标识位
     * @return PDV_RESULT
     * @param[in] iBitMask 标识位
     * @note
     */
    virtual PDV_RESULT SetBitMask(const DftUInt8 &iBitMask) = 0;

    /**
     * @brief 获取名称
     * @return PDV_RESULT
     * @param[out] oName 名称
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString &oName) = 0;

    /**
     * @brief 设置名称
     * @return PDV_RESULT
     * @param[in] iName 名称
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString &iName) = 0;

    /**
     * @brief 获取点网格对象列表
     * @return PDV_RESULT
     * @param[out] oPointMeshIDs 点网格对象列表
     * @note
     */
    virtual PDV_RESULT GetPointMeshIDs(std::vector<DftUInt64> &oPointMeshIDs) = 0;

    /**
     * @brief 设置点网格对象列表
     * @return PDV_RESULT
     * @param[in] iPointMeshIDs 点网格对象列表
     * @note
     */
    virtual PDV_RESULT SetPointMeshIDs(const std::vector<DftUInt64> &iPointMeshIDs) = 0;

    /**
     * @brief 获取线网格对象列表
     * @return PDV_RESULT
     * @param[out] oLineMeshIDs 线网格对象列表
     * @note
     */
    virtual PDV_RESULT GetLineMeshIDs(std::vector<DftUInt64> &oLineMeshIDs) = 0;

    /**
     * @brief 设置线网格对象列表
     * @return PDV_RESULT
     * @param[in] iLineMeshIDs 线网格对象列表
     * @note
     */
    virtual PDV_RESULT SetLineMeshIDs(const std::vector<DftUInt64> &iLineMeshIDs) = 0;

    /**
     * @brief 获取面网格对象列表
     * @return PDV_RESULT
     * @param[out] oFaceMeshIDs 面网格对象列表
     * @note
     */
    virtual PDV_RESULT GetFaceMeshIDs(std::vector<DftUInt64> &oFaceMeshIDs)= 0;

    /**
     * @brief 设置面网格对象列表
     * @return PDV_RESULT
     * @param[in] iFaceMeshIDs 面网格对象列表
     * @note
     */
    virtual PDV_RESULT SetFaceMeshIDs(const std::vector<DftUInt64> &iFaceMeshIDs) = 0;

    /**
     * @brief 获取关联的几何拓扑对象ID
     * @return DftUInt64 关联的几何拓扑对象ID
     * @note
     */
    virtual DftUInt64 GetBrepID() = 0;

    /**
     * @brief 设置关联的几何拓扑对象ID
     * @return PDV_RESULT
     * @param[in] iBrepID 关联的几何拓扑对象ID
     * @note
     */
    virtual PDV_RESULT SetBrepID(const DftUInt64 &iBrepID) = 0;

    /**
     * @brief 获取关联的渲染主体子集对象ID
     * @return DftUInt64 关联的渲染主体子集对象ID
     * @note
     */
    virtual DftUInt64 GetRenderBodySubsetID() = 0;

    /**
     * @brief 设置关联的渲染主体子集对象ID
     * @return PDV_RESULT
     * @param[in] iRenderBodySubsetID 关联的渲染主体子集对象ID
     * @note
     */
    virtual PDV_RESULT SetRenderBodySubsetID(const DftUInt64 &iRenderBodySubsetID) = 0;

    /**
     * @brief 获取关统计信息
     * @return PDV_RESULT
     * @param[out] oStatistics 统计信息
     * @note
     */
    virtual PDV_RESULT GetStatistics(Statistics &oStatistics) = 0;

    /**
     * @brief 获取关联的局部坐标系矩阵
     * @return PDVMatrix4F 关联的局部坐标系矩阵
     * @note
     */
    virtual PDVMatrix4F GetMatrix() = 0;

    /**
     * @brief 设置关联的局部坐标系矩阵
     * @return PDV_RESULT
     * @param[in] iMatrix 关联的局部坐标系矩阵
     * @note
     */
    virtual PDV_RESULT SetMatrix(const PDVMatrix4F &iMatrix) = 0;

    /**
     * @brief 获取有向包围盒
     * @return PDV_RESULT
     * @param[out] oBox 有向包围盒
     * @note
     */
    virtual PDV_RESULT GetBox(OrientedBoundingBox& oBox) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
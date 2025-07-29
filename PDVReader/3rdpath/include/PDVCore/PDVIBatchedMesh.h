/**
 * @file PDVIBatchedMesh.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-02-24
 * @brief 概述：IBatchedMesh的接口声明
 * @details 详细说明
 */

#ifndef PDVIBATCHEDMESH_H
#define PDVIBATCHEDMESH_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 渲染几何体范围信息 */
struct RenderGeometryRangeInfo
{
    DftUInt64 _renderGeometryID;               ///< 渲染几何体ID
    DftUInt32 _vertexIndexMax;                 ///< 顶点索引最大值
    DftUInt32 _vertexIndexMin;                 ///< 顶点索引最小值
    DftUInt32 _indexMax;                       ///< 索引最大值
    DftUInt32 _indexMin;                       ///< 索引最小值
    /** 默认构造函数 */
    RenderGeometryRangeInfo() { Clear(); }
    /** 拷贝构造函数 */
    RenderGeometryRangeInfo(const RenderGeometryRangeInfo& iData)
    {
        _renderGeometryID = iData._renderGeometryID;
        _vertexIndexMax = iData._vertexIndexMax;
        _vertexIndexMin = iData._vertexIndexMin;
        _indexMax = iData._indexMax;
        _indexMin = iData._indexMin;
    }
    /** 赋值运算符 */
    RenderGeometryRangeInfo& operator=(const RenderGeometryRangeInfo& iData)
    {
        if (&iData != this)
        {
            _renderGeometryID = iData._renderGeometryID;
            _vertexIndexMax = iData._vertexIndexMax;
            _vertexIndexMin = iData._vertexIndexMin;
            _indexMax = iData._indexMax;
            _indexMin = iData._indexMin;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _renderGeometryID = DFT_INVALID_ID;
        _vertexIndexMax = 0;
        _vertexIndexMin = 0;
        _indexMax = 0;
        _indexMin = 0;
    }
};
/** @brief 渲染几何体范围信息列表 */
typedef std::vector<RenderGeometryRangeInfo> RenderGeometryRangeInfoArray;

/** @brief 关联的渲染网格信息 */
struct BatchedRenderMeshInfo
{
    DftUInt64 _treeNodeID;                     // 节点对象ID
    DftUInt64 _renderBodyID;                   // 渲染主体对象对象ID
    DftUInt64 _renderMeshID;                   // 渲染网格对象ID
    RenderGeometryRangeInfoArray _renderGeometryRangeInfos;        // 渲染几何体范围信息列表
    /** 默认构造函数 */
    BatchedRenderMeshInfo() { Clear(); }
    /** 拷贝构造函数 */
    BatchedRenderMeshInfo(const BatchedRenderMeshInfo& iData)
    {
        _treeNodeID = iData._treeNodeID;
        _renderBodyID = iData._renderBodyID;
        _renderMeshID = iData._renderMeshID;
        _renderGeometryRangeInfos = iData._renderGeometryRangeInfos;
    }
    /** 赋值运算符 */
    BatchedRenderMeshInfo& operator=(const BatchedRenderMeshInfo& iData)
    {
        if (&iData != this)
        {
            _treeNodeID = iData._treeNodeID;
            _renderBodyID = iData._renderBodyID;
            _renderMeshID = iData._renderMeshID;
            _renderGeometryRangeInfos = iData._renderGeometryRangeInfos;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _treeNodeID = DFT_INVALID_ID;
        _renderBodyID = DFT_INVALID_ID;
        _renderMeshID = DFT_INVALID_ID;
        _renderGeometryRangeInfos.clear();
    }
};
/** @brief 关联的渲染网格信息列表 */
typedef std::vector<BatchedRenderMeshInfo> BatchedRenderMeshInfoArray;

/** @brief 批处理网格的接口 */
class PDVCORE_API IBatchedMesh : public IDataObject
{
public:

    /**
     * @brief 获取关联的渲染网格信息列表
     * @return PDV_RESULT
     * @param[out] oBatchedMeshID 关联的渲染网格信息列表
     * @note
     */
    virtual PDV_RESULT GetBatchedRenderMeshInfoArray(BatchedRenderMeshInfoArray &oBatchedRenderMeshInfoArray) = 0;

    /**
     * @brief 设置关联的渲染网格信息列表
     * @return PDV_RESULT
     * @param[in] BatchedRenderMeshInfoArray 关联的渲染网格信息列表
     * @note
     */
    virtual PDV_RESULT SetBatchedRenderMeshInfoArray(const BatchedRenderMeshInfoArray &iBatchedRenderMeshInfoArray) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
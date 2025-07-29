/**
 * @file PDVIRenderBodySubset.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-2-24
 * @brief 概述：渲染主体子集的接口声明
 * @details 详细说明
 */

#ifndef PDVIRENDERBODYSUBSET_H
#define PDVIRENDERBODYSUBSET_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 渲染网格数据边界 */
struct RenderMeshRange
{
    DftUInt32 _vertexRangeStart; ///< 顶点起始下标
    DftUInt32 _vertexRangeEnd;   ///< 顶点终止下标
    DftUInt32 _indexRangeStart; ///< 索引起始下标
    DftUInt32 _indexRangeEnd;    ///< 索引终止下标
    /** 默认构造函数 */
    RenderMeshRange() { Clear(); }
    /** 拷贝构造函数 */
    RenderMeshRange(const RenderMeshRange& iData)
    {
        _vertexRangeStart = iData._vertexRangeStart;
        _vertexRangeEnd = iData._vertexRangeEnd;
        _indexRangeStart = iData._indexRangeStart;
        _indexRangeEnd = iData._indexRangeEnd;
    }
    /** 赋值运算符 */
    RenderMeshRange& operator=(const RenderMeshRange& iData)
    {
        if (&iData != this)
        {
            _vertexRangeStart = iData._vertexRangeStart;
            _vertexRangeEnd = iData._vertexRangeEnd;
            _indexRangeStart = iData._indexRangeStart;
            _indexRangeEnd = iData._indexRangeEnd;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _vertexRangeStart = 0;
        _vertexRangeEnd = 0;
        _indexRangeStart = 0;
        _indexRangeEnd = 0;
    }
};

/** @brief 渲染网格数据边界集 */
typedef std::vector<RenderMeshRange> RenderMeshRangeArray;

/** @brief 渲染子集 */
struct RenderSubsetData
{
    DftUInt64 _id;                          ///< 唯一标识
    DftUInt8 _type;                         ///< 子集类型
    OrientedBoundingBox _box;               ///< 外包盒
    RenderMeshRangeArray _renderMeshRanges; ///< 网格边界
    DftFloat _length;                       ///< 长度
    DftFloat _area;                         ///< 面积
    DftUInt8 _isTopoSolid;                  ///< 是否是拓扑实体
    DftUInt64 _brepID;                      ///< 几何拓扑ID
    DftUInt64 _topoID;                      ///< 拓扑对象ID
    DftUInt64 _geomID;                      ///< 几何对象ID
    /** 默认构造函数 */
    RenderSubsetData() { Clear(); }
    /** 拷贝构造函数 */
    RenderSubsetData(const RenderSubsetData& iData)
    {
        _id = iData._id;
        _type = iData._type;
        _box = iData._box;
        _renderMeshRanges = iData._renderMeshRanges;
        _length = iData._length;
        _area = iData._area;
        _isTopoSolid = iData._isTopoSolid;
        _brepID = iData._brepID;
        _topoID = iData._topoID;
        _geomID = iData._geomID;
    }
    /** 赋值运算符 */
    RenderSubsetData& operator=(const RenderSubsetData& iData)
    {
        if (&iData != this)
        {
            _id = iData._id;
            _type = iData._type;
            _box = iData._box;
            _renderMeshRanges = iData._renderMeshRanges;
            _length = iData._length;
            _area = iData._area;
            _isTopoSolid = iData._isTopoSolid;
            _brepID = iData._brepID;
            _topoID = iData._topoID;
            _geomID = iData._geomID;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _id = DFT_INVALID_ID;
        _type = 0;
        _box.Clear();
        _renderMeshRanges.clear();
        _length = 0;
        _area = 0;
        _isTopoSolid = FALSE;
        _brepID = DFT_INVALID_ID;
        _topoID = DFT_INVALID_ID;
        _geomID = DFT_INVALID_ID;
    }
};
/** @brief 渲染子集数据集 */
typedef std::vector<RenderSubsetData> RenderSubsetDataArray;

/** @brief 网格子集 */
struct MeshSubsetData
{
    DftUInt64 _renderMeshID;             ///< 渲染网格唯一标识
    RenderSubsetDataArray _renderSubsets; ///< 子集数据列表
    /** 默认构造函数 */
    MeshSubsetData() { Clear(); }
    /** 拷贝构造函数 */
    MeshSubsetData(const MeshSubsetData& iData)
    {
        _renderMeshID = iData._renderMeshID;
        _renderSubsets = iData._renderSubsets;
    }
    /** 赋值运算符 */
    MeshSubsetData& operator=(const MeshSubsetData& iData)
    {
        if (&iData != this)
        {
            _renderMeshID = iData._renderMeshID;
            _renderSubsets = iData._renderSubsets;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _renderMeshID = DFT_INVALID_ID;
        _renderSubsets.clear();
    }
    /** 输出数据 */
    void Output(DftJson iJsonNode) const;
};
/** @brief 网格子集数据集 */
typedef std::vector<MeshSubsetData> MeshSubsetDataArray;

/** @brief 场景数据的接口 */
class PDVCORE_API IRenderBodySubset : public IDataObject
{
public:
    /**
     * @brief 获取点网格子集数据
     * @return PDV_RESULT
     * @param[out] oPointMeshSubsets 点网格子集数据
     * @note
     */
    virtual PDV_RESULT GetPointMeshSubsets(MeshSubsetDataArray &oPointMeshSubsets) = 0;

    /**
     * @brief 设置点网格子集数据
     * @return PDV_RESULT
     * @param[in] iPointMeshSubsets 点网格子集数据
     * @note
     */
    virtual PDV_RESULT SetPointMeshSubsets(const MeshSubsetDataArray &iPointMeshSubsets) = 0;

    /**
     * @brief 获取线网格子集数据
     * @return PDV_RESULT
     * @param[out] oLineMeshSubsets 线网格子集数据
     * @note
     */
    virtual PDV_RESULT GetLineMeshSubsets(MeshSubsetDataArray &oLineMeshSubsets) = 0;

    /**
     * @brief 设置线网格子集数据
     * @return PDV_RESULT
     * @param[in] iLineMeshSubsets 线网格子集数据
     * @note
     */
    virtual PDV_RESULT SetLineMeshSubsets(const MeshSubsetDataArray &iLineMeshSubsets) = 0;

    /**
     * @brief 获取面网格子集数据
     * @return PDV_RESULT
     * @param[out] oFaceMeshSubsets 面网格子集数据
     * @note
     */
    virtual PDV_RESULT GetFaceMeshSubsets(MeshSubsetDataArray &oFaceMeshSubsets) = 0;

    /**
     * @brief 设置面网格子集数据
     * @return PDV_RESULT
     * @param[in] iFaceMeshSubsets 面网格子集数据
     * @note
     */
    virtual PDV_RESULT SetFaceMeshSubsets(const MeshSubsetDataArray &iFaceMeshSubsets) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
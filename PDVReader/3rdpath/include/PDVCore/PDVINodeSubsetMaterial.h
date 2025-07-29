/**
 * @file PDVINodeSubsetMaterial.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-2-24
 * @brief 概述：NodeSubsetMaterial的接口声明
 * @details 详细说明
 */

#ifndef PDVINODESUBSETMATERIAL_H
#define PDVINODESUBSETMATERIAL_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{
/** @brief 作为map的key使用，用于合批实例化算法中对rendermesh按照材质数据进行分组 */
struct MaterialKey
{
    std::vector< DftUInt64> _materialIDs; ///< 材质ID
    /** 比较函数 */
    DftBool operator<(const MaterialKey& iData) const
    {
        if (_materialIDs.size() != iData._materialIDs.size())
            return _materialIDs.size() < iData._materialIDs.size();

        for (DftUInt i = 0; i < _materialIDs.size(); i++)
        {
            if (_materialIDs[i] != iData._materialIDs[i])
                return _materialIDs[i] < iData._materialIDs[i];
        }

        return FALSE;
    }
};

/** @brief 顶点材质信息 */
struct VertexMaterialInfo
{
    DftUInt32 _vertexStart;         ///< 顶点索引起始
    DftUInt32 _vertexEnd;           ///< 顶点索引结束
    DftUInt32 _indexStart;          ///< 索引起始
    DftUInt32 _indexEnd;            ///< 索引结束
    DftUInt64 _materialID;          ///< 材质ID
    /** 默认构造函数 */
    VertexMaterialInfo() { Clear(); }
    /** 拷贝构造函数 */
    VertexMaterialInfo(const VertexMaterialInfo& iData)
    {
        _vertexStart = iData._vertexStart;
        _vertexEnd = iData._vertexEnd;
        _indexStart = iData._indexStart;
        _indexEnd = iData._indexEnd;
        _materialID = iData._materialID;
    }
    /** 赋值运算符 */
    VertexMaterialInfo& operator=(const VertexMaterialInfo& iData)
    {
        if (&iData != this)
        {
            _vertexStart = iData._vertexStart;
            _vertexEnd = iData._vertexEnd;
            _indexStart = iData._indexStart;
            _indexEnd = iData._indexEnd;
            _materialID = iData._materialID;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _vertexStart = 0;
        _vertexEnd = 0;
        _indexStart = 0;
        _indexEnd = 0;
        _materialID = 0;
    }
};
/** @brief 顶点材质信息列表 */
typedef std::vector<VertexMaterialInfo> VertexMaterialInfoArray;

/** @brief 节点关联渲染网格信息 */
struct NodeRenderMeshInfo
{
    DftUInt64 _renderMeshID;                 ///< 渲染网格唯一标识
    VertexMaterialInfoArray _nodeVertexInfoArray; ///< 顶点信息数组
    /** 默认构造函数 */
    NodeRenderMeshInfo() { Clear(); }
    /** 拷贝构造函数 */
    NodeRenderMeshInfo(const NodeRenderMeshInfo& iData)
    {
        _renderMeshID = iData._renderMeshID;
        _nodeVertexInfoArray = iData._nodeVertexInfoArray;
    }
    /** 赋值运算符 */
    NodeRenderMeshInfo& operator=(const NodeRenderMeshInfo& iData)
    {
        if (&iData != this)
        {
            _renderMeshID = iData._renderMeshID;
            _nodeVertexInfoArray = iData._nodeVertexInfoArray;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _renderMeshID = DFT_INVALID_ID;
        _nodeVertexInfoArray.clear();
    }
};
/** @brief 节点关联渲染网格信息列表 */
typedef std::vector<NodeRenderMeshInfo> NodeRenderMeshInfoArray;

/** @brief 节点关联渲染主体信息 */
struct NodeRenderBodyInfo
{
    DftUInt64 _renderBodyID;                     ///< 渲染主体唯一标识
    NodeRenderMeshInfoArray _renderMeshInfoArray; ///< 渲染网格信息数组
    /** 默认构造函数 */
    NodeRenderBodyInfo() { Clear(); }
    /** 拷贝构造函数 */
    NodeRenderBodyInfo(const NodeRenderBodyInfo& iData)
    {
        _renderBodyID = iData._renderBodyID;
        _renderMeshInfoArray = iData._renderMeshInfoArray;
    }
    /** 赋值运算符 */
    NodeRenderBodyInfo& operator=(const NodeRenderBodyInfo& iData)
    {
        if (&iData != this)
        {
            _renderBodyID = iData._renderBodyID;
            _renderMeshInfoArray = iData._renderMeshInfoArray;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _renderBodyID = DFT_INVALID_ID;
        _renderMeshInfoArray.clear();
    }
};
/** @brief 节点关联渲染主体信息列表 */
typedef std::vector<NodeRenderBodyInfo> NodeRenderBodyInfoArray;

/** @brief 节点面材质的接口 */
class PDVCORE_API INodeSubsetMaterial : public IDataObject
{
public:

    /**
     * @brief 获取关联的节点ID
     * @return DftUInt64 节点ID
     * @note
     */
    virtual DftUInt64 GetNodeID() = 0;

    /**
     * @brief 设置关联的节点ID
     * @return PDV_RESULT
     * @param[in] iNodeID 关联的节点ID
     * @note
     */
    virtual PDV_RESULT SetNodeID(const DftUInt64 &iNodeID) = 0;

    /**
     * @brief 获取关联的renderBody信息数组
     * @return PDV_RESULT
     * @param[out] oNodeRenderBodyInfoArray 关联的renderBody信息数组
     * @note
     */
    virtual PDV_RESULT GetNodeRenderBodyInfoArray(NodeRenderBodyInfoArray &oNodeRenderBodyInfoArray) = 0;

    /**
     * @brief 设置关联的renderBody信息数组
     * @return PDV_RESULT
     * @param[in] iNodeRenderBodyInfoArray 关联的renderBody信息数组
     * @note
     */
    virtual PDV_RESULT SetNodeRenderBodyInfoArray(const NodeRenderBodyInfoArray &iNodeRenderBodyInfoArray) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
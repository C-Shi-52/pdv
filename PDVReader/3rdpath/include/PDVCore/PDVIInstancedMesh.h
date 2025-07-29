/**
 * @file PDVIInstancedMesh.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-02-24
 * @brief 概述：实例化网格接口说明
 * @details 详细说明
 */

#ifndef PDVIINSTANCEDMESH_H
#define PDVIINSTANCEDMESH_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{
    
/** @brief 实例化关联的渲染网格信息 */
struct InstancedRenderMeshInfo
{
    DftUInt64 _treeNodeID;         ///< 节点对象ID
    DftUInt64 _renderBodyID;       ///< 渲染主体对象ID
    DftUInt64 _renderMeshID;       ///< 渲染网格对象ID
    PDVMatrix4F _instancedMatrix;      ///< 实例化矩阵
    /** 默认构造函数 */
    InstancedRenderMeshInfo() { Clear(); }
    /** 拷贝构造函数 */
    InstancedRenderMeshInfo(const InstancedRenderMeshInfo& iData)
    {
        _treeNodeID = iData._treeNodeID;
        _renderBodyID = iData._renderBodyID;
        _renderMeshID = iData._renderMeshID;
        _instancedMatrix = iData._instancedMatrix;
    }
    /** 赋值运算符 */
    InstancedRenderMeshInfo& operator=(const InstancedRenderMeshInfo& iData)
    {
        if (&iData != this)
        {
            _treeNodeID = iData._treeNodeID;
            _renderBodyID = iData._renderBodyID;
            _renderMeshID = iData._renderMeshID;
            _instancedMatrix = iData._instancedMatrix;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _treeNodeID = DFT_INVALID_ID;
        _renderBodyID = DFT_INVALID_ID;
        _renderMeshID = DFT_INVALID_ID;
        _instancedMatrix.SetIdentity();
    }
};

/** @brief 实例化关联的渲染网格信息列表 */
typedef std::vector<InstancedRenderMeshInfo> InstancedRenderMeshInfoArray;

/** @brief 实例化网格的接口 */
class PDVCORE_API IInstancedMesh : public IDataObject
{
public:
    
    /**
     * @brief 获取关联的渲染网格信息列表
     * @return PDV_RESULT
     * @param[out] oInstancedRenderMeshInfoArray 关联的渲染网格信息列表
     * @note
     */
    virtual PDV_RESULT GetInstancedRenderMeshInfoArray(InstancedRenderMeshInfoArray &oInstancedRenderMeshInfoArray) = 0;

    /**
     * @brief 设置关联的渲染网格信息列表
     * @return PDV_RESULT
     * @param[in] iInstancedRenderMeshInfoArray 关联的渲染网格信息列表
     * @note
     */
    virtual PDV_RESULT SetInstancedRenderMeshInfoArray(const InstancedRenderMeshInfoArray &iInstancedRenderMeshInfoArray) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
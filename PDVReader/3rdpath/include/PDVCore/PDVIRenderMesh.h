/**
 * @file PDVIRenderMesh.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-02-24
 * @brief 概述：渲染网格的接口声明
 * @details 详细说明
 */

#ifndef PDVIRENDERMESH_H
#define PDVIRENDERMESH_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 渲染网格类型 */
enum RenderMeshType
{
    RENDER_MESH_TYPE_MAIN = 1,      ///< 主体网格
    RENDER_MESH_TYPE_AUXILIARY = 2, ///< 辅助网格
    RENDER_MESH_TYPE_PMI = 3,       ///< PMI网格
};

/** @brief 渲染网格类型 */
enum RenderMethodType
{
    RENDER_METHOD_TYPE_COMMON = 1,    ///< 普通渲染
    RENDER_METHOD_TYPE_BATCHED = 2,   ///< 合批渲染
    RENDER_METHOD_TYPE_INSTANCED = 3, ///< 实例化渲染
};

/** @brief 渲染几何体信息 */
struct RenderGeomInfo
{
    DftUInt64 _renderGeometryID; ///< 渲染几何体对象ID
    DftFloat _lodDetail;         ///< LOD系数
    /** 默认构造函数 */
    RenderGeomInfo() { Clear(); }
    /** 拷贝构造函数 */
    RenderGeomInfo(const RenderGeomInfo& iData)
    {
        _renderGeometryID = iData._renderGeometryID;
        _lodDetail = iData._lodDetail;
    }
    /** 赋值运算符 */
    RenderGeomInfo& operator=(const RenderGeomInfo& iData)
    {
        if (&iData != this)
        {
            _renderGeometryID = iData._renderGeometryID;
            _lodDetail = iData._lodDetail;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _renderGeometryID = DFT_INVALID_ID;
        _lodDetail = 0.f;
    }
};
/** @brief 渲染几何体信息列表 */
typedef std::vector<RenderGeomInfo> RenderGeomInfoArray;

/** @brief 渲染网格的接口 */
class PDVCORE_API IRenderMesh : public IDataObject
{
public:

    /**
     * @brief 获取类型
     * @return DftUInt8 类型
     * @note
     */
    virtual DftUInt8 GetType() = 0;

    /**
     * @brief 设置类型
     * @return PDV_RESULT
     * @param[in] iType 类型
     * @note
     */
    virtual PDV_RESULT SetType(const DftUInt8 &iType) = 0;

    /**
     * @brief 获取关联的渲染几何体列表
     * @return PDV_RESULT
     * @param[out] oRenderGeomInfoArray 关联的渲染几何体列表
     * @note
     */
    virtual PDV_RESULT GetRenderGeomInfoArray(RenderGeomInfoArray& oRenderGeomInfoArray) = 0;

    /**
     * @brief 设置关联的渲染几何体列表
     * @return PDV_RESULT
     * @param[in] iRenderGeomInfoArray 关联的渲染几何体列表
     * @note
     */
    virtual PDV_RESULT SetRenderGeomeInfoArray(const RenderGeomInfoArray& iRenderGeomInfoArray) = 0;

    /**
     * @brief 获取关联的第一个渲染几何体ID
     * @return DftUInt64 几何体ID
     * @note
     */
    virtual DftUInt64 GetFirstRenderGeometryID() = 0;

    /**
     * @brief 设置关联的第一个渲染几何体ID
     * @return PDV_RESULT
     * @param[in] iID 关联的渲染几何体ID
     * @note
     */
    virtual PDV_RESULT SetFirstRenderGeometryID(DftUInt64 iID) = 0;

    /**
     * @brief 获取关联的材质对象ID
     * @return DftUInt64 关联的材质对象ID
     * @note
     */
    virtual DftUInt64 GetMaterialID() = 0;

    /**
     * @brief 设置关联的材质对象ID
     * @return PDV_RESULT
     * @param[in] iMaterialID 关联的材质对象ID
     * @note
     */
    virtual PDV_RESULT SetMaterialID(const DftUInt64 &iMaterialID) = 0;

    /**
     * @brief 获取有向包围盒
     * @return PDV_RESULT
     * @param[out] oBox 有向包围盒
     * @note
     */
    virtual PDV_RESULT GetBox(OrientedBoundingBox &oBox) = 0;

    /**
     * @brief 设置有向包围盒
     * @return PDV_RESULT
     * @param[in] iBox 有向包围盒
     * @note
     */
    virtual PDV_RESULT SetBox(const OrientedBoundingBox &iBox) = 0;

    /**
     * @brief 通过顶点数据构建有向包围盒
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT BuildBoxByVertexData() = 0;

    /**
     * @brief 获取渲染方式
     * @return DftUInt64 渲染方式
     * @note
     */
    virtual DftUInt8 GetRenderMethod() = 0;

    /**
     * @brief 设置渲染方式
     * @return PDV_RESULT
     * @param[in] iRenderMethod 渲染方式
     * @note
     */
    virtual PDV_RESULT SetRenderMethod(const DftUInt8 &iRenderMethod) = 0;

    /**
     * @brief 获取关联的批处理网格对象ID
     * @return DftUInt64 关联的批处理网格对象ID
     * @note
     */
    virtual DftUInt64 GetBatchedMeshID() = 0;

    /**
     * @brief 设置关联的批处理网格对象ID
     * @return PDV_RESULT
     * @param[in] iBatchedMeshID 关联的批处理网格对象ID
     * @note
     */
    virtual PDV_RESULT SetBatchedMeshID(const DftUInt64 &iBatchedMeshID) = 0;

    /**
     * @brief 获取关联的实例化网格对象ID
     * @return DftUInt64 关联的实例化网格对象ID
     * @note
     */
    virtual DftUInt64 GetInstancedMeshID() = 0;

    /**
     * @brief 设置关联的实例化网格对象ID
     * @return PDV_RESULT
     * @param[in] iInstancedMeshID 关联的实例化网格对象ID
     * @note
     */
    virtual PDV_RESULT SetInstancedMeshID(const DftUInt64 &iInstancedMeshID) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
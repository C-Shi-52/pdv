/**
 * @file PDVITileSet.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-02-24
 * @brief 概述：ITileSet的接口声明
 * @details 详细说明
 */

#ifndef PDVITILESET_H
#define PDVITILESET_H

#include "PDVIDataObject.h"
#include "PDVIModelTreeNode.h"
#include "PDVIModel.h"
#include "PDVIDGenerator.h"
#include <set>
#include "PDVIBatchedMesh.h"

namespace kernel
{

namespace pdv
{

/** @brief 细化类型 */
enum RefineType
{
    REFINE_TYPE_REPLACE = 1,        ///< 渲染子瓦片时删除当前级别瓦片
    REFINE_TYPE_ADD = 2,            ///< 子瓦片与当前级别瓦片同时渲染
};

/** @brief 标识位 */
enum TileContentBitMask
{
    TILE_CONTENT_MASK_TREE_NODE_FLAG = 0x0001,      ///< 是否关联模型树节点
    TILE_CONTENT_MASK_RENDER_BODY_FLAG = 0x0002,    ///< 是否关联渲染主体
};

/** @brief 包络数据 */
struct TileEnvelope
{
    DftUInt64 _renderBodyID;                        ///< 渲染主体ID
    std::vector<DftUInt64> _childRenderBodyIDs;     ///< 子渲染主体ID集
    /** 默认构造函数 */
    TileEnvelope()
    {
        Clear();
    }
    /** 拷贝构造函数 */
    TileEnvelope(const TileEnvelope& iData)
    {
        _renderBodyID = iData._renderBodyID;
        _childRenderBodyIDs = iData._childRenderBodyIDs;
    }
    /** 赋值运算符 */
    TileEnvelope& operator=(const TileEnvelope& iData)
    {
        if (&iData != this)
        {
            _renderBodyID = iData._renderBodyID;
            _childRenderBodyIDs = iData._childRenderBodyIDs;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _renderBodyID = DFT_INVALID_ID;
        _childRenderBodyIDs.clear();
    }
};

/** @brief 包络数据集 */
typedef std::vector<TileEnvelope> TileEnvelopeArray;

/** @brief 瓦片实例信息 */
struct TileContent
{
    DftUInt8 _bitMask;                          ///< 标识位，见 TileContentBitMask
    DftUInt64 _treeNodeID;                      ///< 关联的模型树节点ID
    std::vector<DftUInt64> _LodRenderBodyIDs;   ///< lod渲染主体IDs
    TileEnvelopeArray _envelopes;               ///< 包络数据集
    /** 默认构造函数 */
    TileContent()
    {
        Clear();
    }
    /** 拷贝构造函数 */
    TileContent(const TileContent& iData)
    {
        _bitMask = iData._bitMask;
        _treeNodeID = iData._treeNodeID;
        _LodRenderBodyIDs = iData._LodRenderBodyIDs;
        _envelopes = iData._envelopes;
    }
    /** 赋值运算符 */
    TileContent& operator=(const TileContent& iData)
    {
        if (&iData != this)
        {
            _bitMask = iData._bitMask;
            _treeNodeID = iData._treeNodeID;
            _LodRenderBodyIDs = iData._LodRenderBodyIDs;
            _envelopes = iData._envelopes;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _bitMask = 0;
        _treeNodeID = DFT_INVALID_ID;
        _LodRenderBodyIDs.clear();
        _envelopes.clear();
    }
};

/** @brief 瓦片数据信息 */
struct TileData
{
    DftUInt64 _id;                              ///< 唯一标识
    BoundingVolume _boundingVolume;          ///< 外包区域
    DftFloat _geometricError;                   ///< 几何误差
    DftUInt8 _refine;                           ///< 细化，见 RefineType
    TileContent _content;                        ///< 实例数据
    std::vector<TileData> _children;             ///< 子瓦片

    PDVMatrix4F _localTransform;     ///< 局部转换矩阵（不参与存储）
    CUnicodeString _name;            ///< 瓦片名称（不参与存储）
    /** 默认构造函数 */
    TileData()
    {
        Clear();
    }
    /** 拷贝构造函数 */
    TileData(const TileData& iData)
    {
        CopyLocalData(iData);
        _children = iData._children;
    }
    /** 赋值运算符 */
    TileData& operator=(const TileData& iData)
    {
        if (&iData != this)
        {
            CopyLocalData(iData);
            _children = iData._children;
        }
        return *this;
    }
    /** 拷贝本层数据 */
    void CopyLocalData(const TileData& iData)
    {
        _id = iData._id;
        _boundingVolume = iData._boundingVolume;
        _geometricError = iData._geometricError;
        _refine = iData._refine;
        _content = iData._content;
        _children.clear();
        _localTransform = iData._localTransform;
        _name = iData._name;
    }
    /** 清除数据 */
    void Clear()
    {
        _id = DFT_INVALID_ID;
        _boundingVolume.Clear();
        _geometricError = 0.f;// boundingVolume.sphere.w() * 2.f;
        _refine = REFINE_TYPE_REPLACE;
        _content.Clear();
        _children.clear();
        _localTransform = PDVMatrix4F::Identity();
        _name = DFT_L_CWCHAR("");
    }
    /** 根据产品结构树生成 */
    void BuildFromTreeNode(IModelTreeNode* node);
    /** 根据产品结构树生成 */
    void BuildFromTreeNodeToCGo(TreeNodeInfo* treeNodeInfo);
    /** 判断包围区域是否有效 */
    DftBool IsBoundingVolumeValid();
    /** 计算包围区域 */
    void UpdateBoundingVolumeAndGeometricError();
    /** 将外包区域按空间分成8份 */
    static void BreakBoundingVolumeTo8Pieces(const BoundingVolume& iVolume, BoundingVolume oPieces[8]);
    /** 返回两个区域的相交范围 */
    DftFloat GetIntersectionOfTwoRegion(DftFloat region1Min, DftFloat region1Max, DftFloat region2Min, DftFloat region2Max);
    /** 查找匹配的空间位置 */
    DftInt FindMatchPieceIndex(const BoundingVolume& iVolume, BoundingVolume iPieces[8]);
    /** 将子节点根据空间位置合并 */
    void MergeChildrenBySpace();
    /** 根据瓦片树的包围盒数据计算渲染网格合批数据 batchedTileNodeDepth是瓦片开始合批的层级 */
    void CalculateRenderMeshBatchedData(std::map< DftUInt64, std::vector<BatchedRenderMeshInfo>>& nodeID2BatchedRenderMeshInfos,
        std::map<DftUInt64, DftUInt>& meshID2RenderVertexPointNum, DftUInt batchedTileNodeDepth, DftUInt batchedMaxVertexCount, std::vector<std::vector< BatchedRenderMeshInfo>>& batchedRenderMeshInfosGroup);
    /** 获取当前瓦片及所有子瓦片的nodeID */
    void GetAllNodeIDs(std::vector< DftUInt64>& nodeIDs);
    /** 获取瓦片树层数 */
    void GetTreeDepth(DftUInt& maxDepth, DftUInt curDepth);
};

/** @brief 瓦片数据信息集 */
typedef std::vector<TileData> TileDataArray;

/** @brief 瓦片的接口 */
class PDVCORE_API ITileSet : public IDataObject
{
public:
    
    /**
     * @brief 几何误差
     * @return DftFloat 几何误差
     * @note
     */
    virtual DftFloat GetGeometricError() = 0;

    /**
     * @brief 设置几何误差
     * @return PDV_RESULT
     * @param[in] iGeometricError 几何误差
     * @note
     */
    virtual PDV_RESULT SetGeometricError(const DftFloat iGeometricError) = 0;

    /**
     * @brief 根瓦片
     * @return PDV_RESULT
     * @param[out] oTileData 根瓦片
     * @note
     */
    virtual PDV_RESULT GetTileData(TileData &oTileData) = 0;

    /**
     * @brief 设置根瓦片
     * @return PDV_RESULT
     * @param[in] iTileData 根瓦片
     * @note
     */
    virtual PDV_RESULT SetTileData(const TileData &iTileData) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
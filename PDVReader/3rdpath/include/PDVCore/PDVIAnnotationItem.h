/**
 * @file PDVIAnnotationItem.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-12-20
 * @brief 概述：标注项的接口声明
 * @details 详细说明
 */

#ifndef PDVIANNOTATIONITEM_H
#define PDVIANNOTATIONITEM_H

#include "PDVBase.h"
#include "PDVAnnotationDef.h"

namespace kernel
{

namespace pdv
{
/** @brief 标注项的显示模式 */
enum AnnotationViewMode
{
    ANNOTATIONVIEWMODE_DEFAULTVIEW = 0,         ///< 默认显示
    ANNOTATIONVIEWMODE_PARALLELSCREEN = 1,      ///< 平行屏幕
    ANNOTATIONVIEWMODE_FIXEDSCREEN = 2,         ///< 固定屏幕
};

/** @brief 关联子集信息 */
struct LinkedSubsetInfo
{
    DftUInt64 _nodeID;       ///< 节点ID
    DftUInt64 _renderBodyID; ///< 渲染主体ID
    DftUInt64 _renderMeshID; ///< 渲染网格ID
    DftUInt64 _subsetID;     ///< 子集ID 

    /** 默认构造函数 */
    LinkedSubsetInfo() { Clear(); }
    /** 拷贝构造函数 */
    LinkedSubsetInfo(const LinkedSubsetInfo& iData)
    {
        _nodeID = iData._nodeID;
        _renderBodyID = iData._renderBodyID;
        _renderMeshID = iData._renderMeshID;
        _subsetID = iData._subsetID;
    }
    /** 赋值运算符 */
    LinkedSubsetInfo& operator=(const LinkedSubsetInfo& iData)
    {
        if (&iData != this)
        {
            _nodeID = iData._nodeID;
            _renderBodyID = iData._renderBodyID;
            _renderMeshID = iData._renderMeshID;
            _subsetID = iData._subsetID;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _nodeID = 0;
        _renderBodyID = 0;
        _renderMeshID = 0;
        _subsetID = 0;
    }
};

/** @brief 关联子集信息数组 */
typedef std::vector<LinkedSubsetInfo> LinkedSubsetInfoArray;

/** @brief 标注项的接口 */
class PDVCORE_API IAnnotationItem
{
public:
    /**
     * @brief 获取标注项对象唯一标识
     * @return DftUInt64 标注项对象唯一标识
     * @note
     */
    virtual DftUInt64 GetID() = 0;

    /**
     * @brief 获取标注项的命名
     * @return PDV_RESULT
     * @param[out] oName 标注项的命名
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString &oName) = 0;

    /**
     * @brief 设置标注项的命名
     * @return PDV_RESULT
     * @param[in] iName 标注项的命名
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString &iName) = 0;
    
    /**
     * @brief 获取标注项的类型
     * @return CUnicodeString 标注项的类型
     * @note
     */
    virtual CUnicodeString GetType() = 0;

    /**
     * @brief 设置标注项的类型
     * @return PDV_RESULT
     * @param[in] iType 标注项的类型
     * @note
     */
    virtual PDV_RESULT SetType(const CUnicodeString &iType) = 0;

    /**
     * @brief 获取标注项的三角形网格顶点
     * @return PDV_RESULT
     * @param[out] o2DPoints 二维三角形网格顶点
     * @note
     */
    virtual PDV_RESULT GetTrianglePoints(std::vector<PDVVector2F> &o2DPoints) = 0;

    /**
     * @brief 设置标注项的三角形网格顶点
     * @return PDV_RESULT
     * @param[in] i2DPoints 三角形网格顶点
     * @note
     */
    virtual PDV_RESULT SetTrianglePoints(const std::vector<PDVVector2F> &i2DPoints) = 0;

    /**
     * @brief 获取标注项的三角形网格索引
     * @return PDV_RESULT
     * @param[out] oIndexes 二维三角形网格索引
     * @note
     */
    virtual PDV_RESULT GetTriangleIndexes(std::vector<DftUInt> &oIndexes) = 0;

    /**
     * @brief 设置标注项的三角形网格索引
     * @return PDV_RESULT
     * @param[in] iIndexes 三角形网格索引
     * @note
     */
    virtual PDV_RESULT SetTriangleIndexes(const std::vector<DftUInt> &iIndexes) = 0;

    /**
     * @brief 获取标注项的三角形网格颜色
     * @return RGBColor 标注项三角形颜色
     * @note
     */
    virtual RGBColor GetTriangleColor() = 0;

    /**
     * @brief 设置标注项的三角形网格颜色
     * @return PDV_RESULT
     * @param[in] iColor 三角形网格颜色
     * @note
     */
    virtual PDV_RESULT SetTriangleColor(const RGBColor &iColor) = 0;

    /**
     * @brief 获取图形数据
     * @return PDV_RESULT
     * @param[out] oGraphicData 图形数据
     * @note
     */
    virtual PDV_RESULT GetGraphicData(AnnotationGraphicData &oGraphicData) = 0;

    /**
     * @brief 设置图形数据
     * @return PDV_RESULT
     * @param[in] iGraphicData 图形数据
     * @note
     */
    virtual PDV_RESULT SetGraphicData(const AnnotationGraphicData &iGraphicData) = 0;

    /**
     * @brief 获取标注项的线框数据
     * @return PDV_RESULT
     * @param[out] oWires 线框数据
     * @note
     */
    virtual PDV_RESULT GetWires(std::vector<WireFrame2DData> &oWires) = 0;

    /**
     * @brief 设置标注项的线框数据
     * @return PDV_RESULT
     * @param[in] iWires 线框数据
     * @note
     */
    virtual PDV_RESULT SetWires(const std::vector<WireFrame2DData> &iWires) = 0;

    /**
     * @brief 获取标注项相对于模型对象的局部变换信息
     * @return PDVMatrix4F 局部变换信息
     * @note
     */
    virtual PDVMatrix4F GetTransformation() = 0;

    /**
     * @brief 设置标注项相对于模型对象的局部变换信息
     * @return PDV_RESULT
     * @param[in] iTransformation 局部变换信息
     * @note
     */
    virtual PDV_RESULT SetTransformation(const PDVMatrix4F &iTransformation) = 0;

    /**
     * @brief 获取标注项的显示模式
     * @return DftUInt8 标注项的显示模式，见 AnnotationViewMode
     * @note
     */
    virtual DftUInt8 GetFaceViewMode() = 0;

    /**
     * @brief 设置标注项的显示模式
     * @return PDV_RESULT
     * @param[in] iFaceViewMode 显示模式，见 AnnotationViewMode
     * @note
     */
    virtual PDV_RESULT SetFaceViewMode(const DftUInt8 &iFaceViewMode) = 0;
    
    /**
     * @brief 获取链接的图元集合对象ID
     * @return PDV_RESULT
     * @param[out] oLinkedPrimCollectionIDs 链接的图元集合对象ID
     * @note
     */
    virtual PDV_RESULT GetLinkedPrimCollectionIDs(std::vector<DftUInt64>& oLinkedPrimCollectionIDs) = 0;

    /**
     * @brief 设置链接的图元集合对象ID
     * @return PDV_RESULT
     * @param[in] iLinkedPrimCollectionIDs 链接的图元集合对象ID
     * @note
     */
    virtual PDV_RESULT SetLinkedPrimCollectionIDs(const std::vector<DftUInt64>& iLinkedPrimCollectionIDs) = 0;

    /**
     * @brief 获取外包盒
     * @return PDV_RESULT
     * @param[out] oBox 外包盒
     * @note
     */
    virtual PDV_RESULT GetBox(OrientedBoundingBox &oBox) = 0;

    /**
     * @brief 设置标注项的外包盒
     * @return PDV_RESULT
     * @param[in] iBox 外包盒
     * @note
     */
    virtual PDV_RESULT SetBox(const OrientedBoundingBox &iBox) = 0;
    
    /**
     * @brief 获取标注项的渲染主体数据ID
     * @return DftUInt64 标注项的渲染主体数据ID
     * @note
     */
    virtual DftUInt64 GetRenderBodyID() = 0;

    /**
     * @brief 设置标注项的渲染主体数据ID
     * @return PDV_RESULT
     * @param[in] iRenderBodyID 标注项的渲染主体数据ID
     * @note
     */
    virtual PDV_RESULT SetRenderBodyID(const DftUInt64 &iRenderBodyID) = 0;

    /**
     * @brief 获取链接的辅助几何对象ID
     * @return PDV_RESULT
     * @param[out] oAnnotationGeometryIDs 链接的辅助几何对象ID
     * @note
     */
    virtual PDV_RESULT GetAnnotationGeometryIDs(std::vector<DftUInt64>& oAnnotationGeometryIDs) = 0;

    /**
     * @brief 设置链接的辅助几何对象ID
     * @return PDV_RESULT
     * @param[in] iAnnotationGeometryIDs 链接的辅助几何对象ID
     * @note
     */
    virtual PDV_RESULT SetAnnotationGeometryIDs(const std::vector<DftUInt64>& iAnnotationGeometryIDs) = 0;

    /**
     * @brief 获取链接的几何对象
     * @return PDV_RESULT
     * @param[out] oLinkedSubsetInfoArray 链接的几何对象
     * @note
     */
    virtual PDV_RESULT GetLinkedSubsetInfoArray(LinkedSubsetInfoArray &oLinkedSubsetInfoArray) = 0;

    /**
     * @brief 设置链接的几何对象
     * @return PDV_RESULT
     * @param[in] iLinkedSubsetInfoArray 链接的几何对象
     * @note
     */
    virtual PDV_RESULT SetLinkedSubsetInfoArray(const LinkedSubsetInfoArray &iLinkedSubsetInfoArray) = 0;
};

} // namespace pdv

} // namespace kernel

#endif

/**
 * @file PDVIView.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：视图的接口声明
 * @details 详细说明
 */

#ifndef PDVIVIEW_H
#define PDVIVIEW_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 渲染背景类型 */
enum RenderBackgroundType
{
    RNDBKGTYPE_INVALID = 0,   ///< 无效类型
    RNDBKGTYPE_PURECOLOR = 1, ///< 纯色
    RNDBKGTYPE_PICTURE = 2,   ///< 单一背景图
};

class ICamera;

/** @brief 视图的接口 */
class PDVCORE_API IView : public IDataObject
{
public:
    /**
     * @brief 获取视图的命名
     * @return PDV_RESULT
     * @param[out] oName 视图的命名
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString &oName) = 0;

    /**
     * @brief 设置视图的命名
     * @return PDV_RESULT
     * @param[in] iName 视图的命名
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString &iName) = 0;

    /**
     * @brief 获取视图相机ID
     * @return DftUInt64 视图相机ID
     * @note
     */
    virtual DftUInt64 GetCameraID() = 0;

    /**
     * @brief 设置视图的相机ID
     * @return PDV_RESULT
     * @param[in] iID 视图的相机ID
     * @note
     */
    virtual PDV_RESULT SetCameraID(DftUInt64 iID) = 0;

    /**
     * @brief 函数名称 GetClippedNodeCount, 被剖切的节点数量
     * @return 说明 DftUInt, 返回个数
     * @note
     */
    virtual DftUInt GetClippedNodeCount() = 0;

    /**
     * @brief 函数名称 GetClippedNodeIDArray, 获取被剖切的结构树节点ID数组
     * @return 说明 PDV_RESULT, 见PDVResultType
     * @param[out] oClippedNodeIDs: 被剖切的结构树节点ID数组
     * @note
     */
    virtual PDV_RESULT GetClippedNodeIDArray(std::vector<DftUInt64> &oClippedNodeIDs) = 0;

    /**
     * @brief 函数名称 SetClippedNodeIDArray, 设置视图被剖切的产品结构树ID
     * @return 说明 PDV_RESULT, 见PDVResultType
     * @param[in] iClippedNodeIDs: 视图被剖切的产品结构树ID列表
     * @note
     */
    virtual PDV_RESULT SetClippedNodeIDArray(const std::vector<DftUInt64> &iClippedNodeIDs) = 0;

    /**
     * @brief 函数名称 GetHiddenNodeCount, 隐藏节点数量
     * @return 说明 DftUInt, 返回个数
     * @note
     */
    virtual DftUInt GetHiddenNodeCount() = 0;

    /**
     * @brief 获取隐藏的结构树节点ID数组
     * @return PDV_RESULT
     * @param[out] oHiddenNodeIDs 隐藏的结构树节点ID数组
     * @note
     */
    virtual PDV_RESULT GetHiddenNodeIDArray(std::vector<DftUInt64> &oHiddenNodeIDs) = 0;

    /**
     * @brief 设置视图隐藏的产品结构树ID
     * @return PDV_RESULT
     * @param[in] iHiddenNodeIDs 视图隐藏的产品结构树ID列表
     * @note
     */
    virtual PDV_RESULT SetHiddenNodeIDArray(const std::vector<DftUInt64> &iHiddenNodeIDs) = 0;

    /**
     * @brief 位置变换的结构树节点数量
     * @return DftUInt 位置变换的结构树节点数量
     * @note
     */
    virtual DftUInt GetTransformedNodeCount() = 0;

    /**
     * @brief 视图控制位置变换的结构树节点ID
     * @return PDV_RESULT
     * @param[out] oTransformedNodeIDs 位置变换的结构树节点ID
     * @note
     */
    virtual PDV_RESULT GetTransformedNodeIDArray(std::vector<DftUInt64> &oTransformedNodeIDs) = 0;

    /**
     * @brief 设置视图控制位置变换的结构树节点ID
     * @return PDV_RESULT
     * @param[in] iTransformedNodeIDs 视图控制位置变换的结构树节点ID
     * @note
     */
    virtual PDV_RESULT SetTransformedNodeIDArray(const std::vector<DftUInt64> &iTransformedNodeIDs) = 0;

	/**
	  * @brief 视图控制位置变换信息
	  * @return std::vector< \ref PDVMatrix4D > 返回数组信息
	  * @note
	  */
    virtual std::vector<PDVMatrix4D> &GetNodeTransformations() = 0;

    /**
     * @brief 设置视图控制位置变换信息
     * @return PDV_RESULT
     * @param[in] iTransformations 视图控制位置变换信息
     * @note
     */
    virtual PDV_RESULT SetNodeTransformations(const std::vector<PDVMatrix4D>& iTransformations) = 0;

    /**
     * @brief 视图的剖切面数据个数
     * @return DftUInt 返回个数
     * @note
     */
    virtual DftUInt GetClippingPlaneCount() = 0;

    /**
     * @brief 视图的剖切面数据
     * @return PDV_RESULT
     * @param[in] iClippingPlaneIndex 视图剖切面所在index
     * @param[out] oOrigin 原点
     * @param[out] oAxisX X轴向量
     * @param[out] oAxisY Y轴向量
     * @param[out] oAxisZ Z轴向量
     * @note
     */
    virtual PDV_RESULT GetClippingPlaneData(DftUInt iClippingPlaneIndex, PDVVector3F &oOrigin, PDVVector3F &oAxisX, PDVVector3F &oAxisY, PDVVector3F &oAxisZ) = 0;

    /**
     * @brief 获取视图的剖切面数据
     * @return PDV_RESULT
     * @param[out] oClippingPlanes 返回剖切面数据
     * @note
     */
    virtual PDV_RESULT GetClippingPlanes(std::vector<PlaneData> &oClippingPlanes) = 0;

    /**
     * @brief 设置视图剖切面数据
     * @return PDV_RESULT
     * @param[in] iClippingPlanes 视图剖切面数据
     * @note
     */
    virtual PDV_RESULT SetClippingPlanes(const std::vector<PlaneData> &iClippingPlanes) = 0;

    /**
     * @brief 材质发生变化的产品结构树节点数量
     * @return DftUInt 返回个数
     * @note
     */
    virtual DftUInt GetMatChangedNodeCount() = 0;

    /**
     * @brief 材质发生变化的产品结构树节点标识列表
     * @return PDV_RESULT
     * @param[out] oMatChangedNodeIDs 材质发生变化的产品结构树节点标识列表
     * @note
     */
    virtual PDV_RESULT GetMatChangedNodeIDArray(std::vector<DftUInt64> &oMatChangedNodeIDs) = 0;

    /**
     * @brief 设置视图材质发生变化的产品结构树节点标识列表
     * @return PDV_RESULT
     * @param[in] iMatChangedNodeIDs 视图材质发生变化的产品结构树节点标识列表
     * @note
     */
    virtual PDV_RESULT SetMatChangedNodeIDArray(const std::vector<DftUInt64> &iMatChangedNodeIDs) = 0;

    /**
     * @brief 材质发生变化的产品结构树各节点关联的材质
     * @return PDV_RESULT
     * @param[out] oNodeMaterialIDs 材质发生变化的产品结构树各节点关联的材质
     * @note
     */
    virtual PDV_RESULT GetNodeMaterialIDArray(std::vector<DftUInt64> &oNodeMaterialIDs) = 0;

    /**
     * @brief 设置材质发生变化的产品结构树各节点关联的材质
     * @return PDV_RESULT
     * @param[in] iNodeMaterialIDs 视图材质发生变化的产品结构树各节点关联的材质
     * @note
     */
    virtual PDV_RESULT SetNodeMaterialIDArray(const std::vector<DftUInt64> &iNodeMaterialIDs) = 0;

    /**
     * @brief 视图背景类型  0：无视图背景；1：颜色；2：图像；
     * @return DftUInt8 背景类型，见 RenderBackgroundType
     * @note
     */
    virtual DftUInt8 GetBackgroundType() = 0;

    /**
     * @brief 设置视图背景类型
     * @return PDV_RESULT
     * @param[in] iBackgroundType 视图背景类型
     * @note
     */
    virtual PDV_RESULT SetBackgroundType(const DftUInt8 iBackgroundType) = 0;

    /**
     * @brief 视图的背景颜色
     * @return PDV_RESULT
     * @param[out] oColorValue 背景颜色
     * @note
     */
    virtual PDV_RESULT GetBackgroundColor(RGBColor &oColorValue) = 0;

    /**
     * @brief 设置视图背景颜色
     * @return PDV_RESULT
     * @param[in] iColorValue 视图背景颜色
     * @note
     */
    virtual PDV_RESULT SetBackgroundColor(const RGBColor &iColorValue) = 0;

    /**
     * @brief 视图背景图像关联的资源文件
     * @return PDV_RESULT
     * @param[out] oImageID 资源文件ID
     * @note
     */
    virtual PDV_RESULT GetBackgroundImageID(DftUInt64 &oImageID) = 0;

    /**
     * @brief 设置视图背景图像关联的资源文件
     * @return PDV_RESULT
     * @param[in] iImageID 视图背景图像关联的资源文件
     * @note
     */
    virtual PDV_RESULT SetBackgroundImageID(const DftUInt64 &iImageID) = 0;

    /**
     * @brief 视图背景透明度
     * @return PDV_RESULT
     * @param[out] oTransparencyValue 背景透明度
     * @note
     */
    virtual PDV_RESULT GetBackgroundTransparency(DftUInt8 &oTransparencyValue) = 0;

    /**
     * @brief 设置视图背景透明度
     * @return PDV_RESULT
     * @param[in] iTransparencyValue 视图背景透明度
     * @note
     */
    virtual PDV_RESULT SetBackgroundTransparency(const DftUInt8 &iTransparencyValue) = 0;

    /**
     * @brief 获取视图包含的审阅意见数量
     * @return DftUInt 审阅意见数量
     * @note
     */
    virtual DftUInt GetReviewCount() = 0;

    /**
     * @brief 获取视图包含的审阅意见ID数组
     * @return PDV_RESULT
     * @param[out] oReviewIDs 审阅意见ID数组
     * @note
     */
    virtual PDV_RESULT GetReviewIDArray(std::vector<DftUInt64> &oReviewIDs) = 0;

    /**
     * @brief 设置包含的审阅意见ID数组
     * @return PDV_RESULT
     * @param[in] iReviewIDs 视图包含的审阅意见ID数组
     * @note
     */
    virtual PDV_RESULT SetReviewIDArray(const std::vector<DftUInt64> &iReviewIDs) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
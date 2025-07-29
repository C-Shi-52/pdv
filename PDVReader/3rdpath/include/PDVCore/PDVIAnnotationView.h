/**
 * @file PDVIAnnotationView.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-12-20
 * @brief 概述：标注视图的接口声明
 * @details 详细说明
 */

#ifndef PDVIANNOTATIONVIEW_H
#define PDVIANNOTATIONVIEW_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

class ICamera;

/** @brief 标注视图比特位信息 */
enum AnnotationViewBitMask
{
    ANNOVIEW_MASK_DEFAULT_VIEW = 0x0001, ///< 是否为默认标注视图
    ANNOVIEW_MASK_CAMERA = 0x0002,       ///< 是否包含摄像机数据
    ANNOVIEW_MASK_CLIP_PLANE = 0x0004,   ///< 是否包含剖切数据
    ANNOVIEW_MASK_VISIBLE = 0x0008,      ///< 是否显示隐藏  1表示显示  0表示隐藏
    ANNOVIEW_MASK_MESHVISIBLE = 0x0010   ///< 是否显示节点模型主体网格数据 1表示是 0表示否
};

/** @brief 标注视图的接口 */
class PDVCORE_API IAnnotationView
{
public:
    /**
     * @brief 获取标注视图对象唯一标识
     * @return DftUInt64 标注视图对象唯一标识
     * @note
     */
    virtual DftUInt64 GetID() = 0;

    /**
     * @brief 设置标注视图对象唯一标识
     * @return PDV_RESULT
     * @param[in] iID 标注视图对象唯一标识
     * @note
     */
    virtual PDV_RESULT SetID(DftUInt64 iID) = 0;

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
     * @brief 获取是否是默认视图
     * @return DftBool 是否是默认视图
     * @note
     */
    virtual DftBool IsDefaultView() = 0;

    /**
     * @brief 设置是否是默认视图
     * @return PDV_RESULT
     * @param[in] iIsDefaultView 是否是默认视图
     * @note
     */
    virtual PDV_RESULT SetIsDefaultView(const DftBool &iIsDefaultView) = 0;

    /**
     * @brief 获取标注视图是否包含摄像机数据
     * @return DftBool 标注视图是否包含摄像机数据
     * @note
     */
    virtual DftBool GetCameraFlag() const = 0;

    /**
     * @brief 设置标注视图是否包含摄像机数据
     * @return PDV_RESULT
     * @param[in] iCameraFlag 标注视图是否包含摄像机数据
     * @note
     */
    virtual PDV_RESULT SetCameraFlag(const DftBool &iCameraFlag) = 0;

    /**
     * @brief 获取标注视图是否包含剖切面数据
     * @return DftBool 标注视图是否包含剖切面数据
     * @note
     */
    virtual DftBool GetClipPlaneFlag() = 0;

    /**
     * @brief 设置标注视图是否包含剖切面数据
     * @return PDV_RESULT
     * @param[in] iClipPlaneFlag 标注视图是否包含剖切面数据
     * @note
     */
    virtual PDV_RESULT SetClipPlaneFlag(const DftBool &iClipPlaneFlag) = 0;

    /**
     * @brief 获取视图显示的标注项ID
     * @return PDV_RESULT
     * @param[out] oAnnotationItemIDs 视图显示的标注项ID
     * @note
     */
    virtual PDV_RESULT GetAnnotationItemIDs(std::vector<DftUInt64> &oAnnotationItemIDs) = 0;

    /**
     * @brief 设置视图显示的标注项ID
     * @return PDV_RESULT
     * @param[in] iAnnotationItemIDs 视图显示的标注项ID
     * @note
     */
    virtual PDV_RESULT SetAnnotationItemIDs(const std::vector<DftUInt64> &iAnnotationItemIDs) = 0;

    /**
     * @brief 获取摄像机对象ID
     * @return DftUInt64 摄像机对象ID
     * @note
     */
    virtual DftUInt64 GetCameraID() = 0;

    /**
     * @brief 获取摄像机对象
     * @return ICamera * 摄像机对象
     * @note
     */
    virtual ICamera* GetCamera() = 0;

    /**
     * @brief 设置摄像机对象ID
     * @return PDV_RESULT
     * @param[in] iCameraID 摄像机对象ID
     * @note
     */
    virtual PDV_RESULT SetCameraID(DftUInt64 iCameraID) = 0;

    /**
     * @brief 获取剖切面数据
     * @return PDV_RESULT
     * @param[out] oClippingPlanes 剖切面数据
     * @note
     */
    virtual PDV_RESULT GetClippingPlanes(std::vector<PlaneData> &oClippingPlanes) = 0;

    /**
     * @brief 设置剖切面数据
     * @return PDV_RESULT
     * @param[in] iClippingPlanes 剖切面数据
     * @note
     */
    virtual PDV_RESULT SetClippingPlanes(const std::vector<PlaneData> &iClippingPlanes) = 0;

    /**
     * @brief 获取标注视图的标识位
     * @return DftByte
     * @note
     */
    virtual DftByte GetBitMask() = 0;

    /**
     * @brief 设置标注视图的标识位
     * @return PDV_RESULT
     * @param[in] iBitMask 标注视图的标识位
     * @note
     */
    virtual PDV_RESULT SetBitMask(DftByte iBitMask) = 0;

    /**
     * @brief 获取视图被剖切对象节点ID列表
     * @return PDV_RESULT
     * @param[out] oClippedNodeIDs 被剖切对象节点ID列表
     * @note
     */
    virtual PDV_RESULT GetClippedNodeIDs(std::vector<DftUInt64> &oClippedNodeIDs) = 0;

    /**
     * @brief 设置视图被剖切对象节点ID列表
     * @return PDV_RESULT
     * @param[in] iClippedNodeIDs 被剖切对象节点ID列表
     * @note
     */
    virtual PDV_RESULT SetClippedNodeIDs(const std::vector<DftUInt64> &iClippedNodeIDs) = 0;

    /**
     * @brief 获取视图被隐藏对象节点ID列表
     * @return PDV_RESULT
     * @param[out] oHiddenNodeIDs 被隐藏对象节点ID列表
     * @note
     */
    virtual PDV_RESULT GetHiddenNodeIDs(std::vector<DftUInt64> &oHiddenNodeIDs) = 0;

    /**
     * @brief 设置视图被隐藏对象节点ID列表
     * @return PDV_RESULT
     * @param[in] iHiddenNodeIDs 被隐藏对象节点ID列表
     * @note
     */
    virtual PDV_RESULT SetHiddenNodeIDs(const std::vector<DftUInt64> &iHiddenNodeIDs) = 0;

    /**
     * @brief 获取视图关联的辅助几何ID
     * @return PDV_RESULT
     * @param[out] oAnnotationReferenceGeometryIDs 视图关联的辅助几何ID
     * @note
     */
    virtual PDV_RESULT GetReferenceGeometryIDs(std::vector<DftUInt64> &oAnnotationReferenceGeometryIDs) = 0;

    /**
     * @brief 设置视图关联的辅助几何ID
     * @return PDV_RESULT
     * @param[in] iAnnotationReferenceGeometryIDs 视图关联的辅助几何ID
     * @note
     */
    virtual PDV_RESULT SetReferenceGeometryIDs(const std::vector<DftUInt64> &iAnnotationReferenceGeometryIDs) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
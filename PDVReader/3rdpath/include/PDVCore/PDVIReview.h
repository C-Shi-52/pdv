/**
 * @file PDVIReview.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：审阅对象的接口声明
 * @details 详细说明
 */

#ifndef PDVIREVIEW_H
#define PDVIREVIEW_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 审阅对象内容标识类型 */
enum ReviewMask
{
    REVIEWMASK_NULL = 0,        ///< 未知
    REVIEWMASK_REPLY = 1,       ///< 是否关联当前审阅对象答复的审阅对象ID
    REVIEWMASK_CAMERA = 1 << 1, ///< 是否关联摄像机对象
    REVIEWMASK_OBJECT = 1 << 2, ///< 是否包含被审阅对象的链接点
};

/** @brief 审阅对象的接口 */
class PDVCORE_API IReview : public IDataObject
{
public:
    /**
     * @brief 获取审阅对象的内容标志
     * @return DftUInt8 审阅对象的内容标志
     * @note 第1位：是否包含答复的审阅对象；第2位：是否关联摄像机对象；第3位：是否包含被审阅对象的链接点；第3-8位：保留使用，固定设置为0
     */
    virtual DftUInt8 GetBitMask() = 0;

    /**
     * @brief 设置审阅对象的内容标志
     * @return PDV_RESULT
     * @param[in] iBitMask 审阅对象的内容标志
     * @note
     */
    virtual PDV_RESULT SetBitMask(const DftUInt8 &iBitMask) = 0;

    /**
     * @brief 获取当前审阅对象的答复对象ID
     * @return PDV_RESULT
     * @param[out] oReplyID 答复对象ID
     * @note
     */
    virtual PDV_RESULT GetReplyID(DftUInt64 &oReplyID) = 0;

    /**
     * @brief 设置当前审阅对象的答复对象ID
     * @return PDV_RESULT
     * @param[in] iReplyID 答复对象ID
     * @note
     */
    virtual PDV_RESULT SetReplyID(const DftUInt64 &iReplyID) = 0;

    /**
     * @brief 获取审阅者
     * @return PDV_RESULT
     * @param[out] oReviewer 审阅者
     * @note
     */
    virtual PDV_RESULT GetReviewer(CUnicodeString &oReviewer) = 0;

    /**
     * @brief 设置审阅者
     * @return PDV_RESULT
     * @param[in] iReviewer 审阅者
     * @note
     */
    virtual PDV_RESULT SetReviewer(const CUnicodeString &iReviewer) = 0;

    /**
     * @brief 获取审阅时间
     * @return PDV_RESULT
     * @param[out] oDateTime 审阅时间，取值为相对于1970年1月1日0时的毫秒数
     * @note
     */
    virtual PDV_RESULT GetDateTime(DftUInt64 &oDateTime) = 0;

    /**
     * @brief 设置审阅时间
     * @return PDV_RESULT
     * @param[in] iDateTime 审阅时间
     * @note
     */
    virtual PDV_RESULT SetDateTime(const DftUInt64 &iDateTime) = 0;

    /**
     * @brief 获取审阅文本
     * @return PDV_RESULT
     * @param[out] oText 审阅文本
     * @note
     */
    virtual PDV_RESULT GetText(CUnicodeString &oText) = 0;

    /**
     * @brief 设置审阅文本
     * @return PDV_RESULT
     * @param[in] iText 审阅文本
     * @note
     */
    virtual PDV_RESULT SetText(const CUnicodeString &iText) = 0;

    /**
     * @brief 获取文本颜色
     * @return PDV_RESULT
     * @param[out] oColor 文本颜色
     * @note
     */
    virtual PDV_RESULT GetColor(RGBColor &oColor) = 0;

    /**
     * @brief 设置文本颜色
     * @return PDV_RESULT
     * @param[in] iColor 文本颜色
     * @note
     */
    virtual PDV_RESULT SetColor(const RGBColor &iColor) = 0;

    /**
     * @brief 获取使用的字体名称
     * @return PDV_RESULT
     * @param[out] oFontName 使用的字体名称
     * @note
     */
    virtual PDV_RESULT GetFontName(CUnicodeString &oFontName) = 0;

    /**
     * @brief 设置使用的字体名称
     * @return PDV_RESULT
     * @param[in] iFontName 使用的字体名称
     * @note
     */
    virtual PDV_RESULT SetFontName(const CUnicodeString &iFontName) = 0;

    /**
     * @brief 获取文本大小
     * @return DftFloat 文本大小，单位为毫米
     * @note
     */
    virtual DftFloat GetFontSize() = 0;

    /**
     * @brief 设置文本大小
     * @return PDV_RESULT
     * @param[in] iFontSize 文本大小
     * @note
     */
    virtual PDV_RESULT SetFontSize(const DftFloat &iFontSize) = 0;

    /**
     * @brief 获取审阅文本定位位置
     * @return PDVVector3F 审阅文本定位位置
     * @note
     */
    virtual PDVVector3F GetTextPosition() = 0;

    /**
     * @brief 设置审阅文本定位位置
     * @return PDV_RESULT
     * @param[in] iTextPosition 审阅文本定位位置
     * @note
     */
    virtual PDV_RESULT SetTextPosition(const PDVVector3F &iTextPosition) = 0;

    /**
     * @brief 获取审阅关联的摄像机ID
     * @return PDV_RESULT
     * @param[out] oCameraID 摄像机ID
     * @note
     */
    virtual PDV_RESULT GetCameraID(DftUInt64 &oCameraID) = 0;

    /**
     * @brief 设置审阅关联的摄像机ID
     * @return PDV_RESULT
     * @param[in] iCameraID 摄像机ID
     * @note
     */
    virtual PDV_RESULT SetCameraID(const DftUInt64 &iCameraID) = 0;

    /**
     * @brief 清空被审阅的对象ID
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearLinkedObjects() = 0;

    /**
     * @brief 获取被审阅的对象ID数量
     * @return PDV_RESULT
     * @param[out] oLinkedObjIDsCount 返回被审阅的对象ID数量
     * @note
     */
    virtual PDV_RESULT GetLinkedObjectCount(DftUInt &oLinkedObjIDsCount) = 0;

    /**
     * @brief 获取被审阅的对象ID集合数据
     * @return PDV_RESULT
     * @param[out] oLinkedObjIDs 被审阅的对象ID集合数组
     * @param[out] oLinkedObjPositions 被审阅对象的链接点位置
     * @note
     */
    virtual PDV_RESULT GetLinkedObjects(std::vector<DftUInt64> &oLinkedObjIDs, std::vector<PDVVector3F> &oLinkedObjPositions) = 0;

    /**
     * @brief 设置被审阅的对象ID集合数据
     * @return PDV_RESULT
     * @param[in] iLinkedObjIDs 被审阅的对象ID集合数据
     * @param[in] iLinkedObjPositions 被审阅对象的链接点位置
     * @note
     */
    virtual PDV_RESULT SetLinkedObjects(const std::vector<DftUInt64> &iLinkedObjIDs, const std::vector<PDVVector3F> &iLinkedObjPositions) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
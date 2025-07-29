/**
 * @file PDVISecurity.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-17
 * @brief 概述：安全控制对象的接口声明
 * @details 详细说明
 */

#ifndef PDVISECURITY_H
#define PDVISECURITY_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 安全控制对象的接口 */
class PDVCORE_API ISecurity : public IDataObject
{
public:
    /**
     * @brief 获取所有权限标志
     * @return DftUInt32 所有权限标志
     * @note
     */
    virtual DftUInt32 GetPermission() = 0;

    /**
     * @brief 设置所有权限标志
     * @return PDV_RESULT
     * @param[in] iPermission 所有权限标志值
     * @note
     */
    virtual PDV_RESULT SetPermission(const DftUInt32 &iPermission) = 0;

    /**
     * @brief 获取是否包含有效期标志
     * @return DftBool 是否包含有效期标志，TRUE说明存在有效期，FALSE说明不存在有效期
     * @note
     */
    virtual DftBool GetTimeLimitFlag() = 0;

    /**
     * @brief 设置是否包含有效期标志
     * @return PDV_RESULT
     * @param[in] iTimeLimitFlag 是否包含有效期标志，TRUE说明存在有效期，FALSE说明不存在有效期
     * @note
     */
    virtual PDV_RESULT SetTimeLimitFlag(const DftBool &iTimeLimitFlag) = 0;

    /**
     * @brief 添加所有权限
     * @return PDV_RESULT
     * @note 如果包含权限数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_SECURITY_NO_PERMISSION
     */
    virtual PDV_RESULT AddAllPermissions() = 0;

    /**
     * @brief 设置浏览权限
     * @return PDV_RESULT
     * @param[in] iOpenFlag 浏览权限
     * @note 如果包含权限数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_SECURITY_NO_PERMISSION
     */
    virtual PDV_RESULT SetOpenFlag(const DftBool &iOpenFlag) = 0;

    /**
     * @brief 获取浏览权限
     * @return DftBool 是否包含浏览权限，TRUE说明存在浏览权限，FALSE说明不存在浏览权限
     * @note
     */
    virtual DftBool GetOpenFlag() = 0;

    /**
     * @brief 设置编辑模型权限
     * @return PDV_RESULT
     * @param[in] iModelEditFlag 编辑模型权限
     * @note 如果包含权限数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_SECURITY_NO_PERMISSION
     */
    virtual PDV_RESULT SetModelEditFlag(const DftBool &iModelEditFlag) = 0;

    /**
     * @brief 获取编辑模型权限
     * @return DftBool 是否包含编辑模型权限，TRUE说明存在编辑模型权限，FALSE说明不存在编辑模型权限
     * @note
     */
    virtual DftBool GetModelEditFlag() = 0;

    /**
     * @brief 设置动画编辑权限
     * @return PDV_RESULT
     * @param[in] iAnimationEditFlag 动画编辑权限
     * @note 如果包含权限数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_SECURITY_NO_PERMISSION
     */
    virtual PDV_RESULT SetAnimationEditFlag(const DftBool &iAnimationEditFlag) = 0;

    /**
     * @brief 获取动画编辑权限
     * @return DftBool 是否包含动画编辑权限，TRUE说明存在动画编辑权限，FALSE说明不存在动画编辑权限
     */
    virtual DftBool GetAnimationEditFlag() = 0;

    /**
     * @brief 设置动画播放权限
     * @return PDV_RESULT
     * @param[in] iAnimationPlayFlag 动画播放权限
     * @note 如果包含权限数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_SECURITY_NO_PERMISSION
     */
    virtual PDV_RESULT SetAnimationPlayFlag(const DftBool &iAnimationPlayFlag) = 0;

    /**
     * @brief 获取动画播放权限
     * @return DftBool 是否包含动画播放权限，TRUE说明存在动画播放权限，FALSE说明不存在动画播放权限
     */
    virtual DftBool GetAnimationPlayFlag() = 0;

    /**
     * @brief 设置审阅编辑权限
     * @return PDV_RESULT
     * @param[in] iReviewFlag 审阅编辑权限
     * @note, 如果包含权限数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_SECURITY_NO_PERMISSION
     */
    virtual PDV_RESULT SetReviewEditFlag(const DftBool &iReviewFlag) = 0;

    /**
     * @brief 获取审阅编辑权限
     * @return DftBool 是否包含审阅编辑权限，TRUE说明存在审阅编辑权限，FALSE说明不存在审阅编辑权限
     */
    virtual DftBool GetReviewEditFlag() = 0;

    /**
     * @brief 设置视图编辑权限
     * @return PDV_RESULT
     * @param[in] iViewFlag 视图编辑权限
     * @note, 如果包含权限数据，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_SECURITY_NO_PERMISSION
     */
    virtual PDV_RESULT SetViewEditFlag(const DftBool &iViewFlag) = 0;

    /**
     * @brief 获取视图编辑权限
     * @return DftBool 是否包含视图编辑权限，TRUE说明存在视图编辑权限，FALSE说明不存在视图编辑权限
     */
    virtual DftBool GetViewEditFlag() = 0;

    /**
     * @brief 获取有效期开始时间戳
     * @return DftUInt64 有效期开始时间戳
     * @note
     */
    virtual DftUInt64 GetStartTime() = 0;

    /**
     * @brief 设置有效期开始时间戳
     * @return PDV_RESULT
     * @param[in] iStartTime 有效期开始时间戳
     * @note
     */
    virtual PDV_RESULT SetStartTime(const DftUInt64 &iStartTime) = 0;

    /**
     * @brief 获取有效期结束时间戳
     * @return DftUInt64 有效期结束时间戳
     * @note
     */
    virtual DftUInt64 GetEndTime() = 0;

    /**
     * @brief 设置有效期结束时间戳
     * @return PDV_RESULT
     * @param[in] iEndTime 有效期结束时间戳
     * @note
     */
    virtual PDV_RESULT SetEndTime(const DftUInt64 &iEndTime) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
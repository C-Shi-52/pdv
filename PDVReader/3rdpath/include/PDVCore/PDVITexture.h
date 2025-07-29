/**
 * @file PDVITexture.h
 * @author yue.rui
 * @version 1.0
 * @date 2024-07-11
 * @brief 概述：纹理对象的接口声明
 * @details 详细说明
 */

#ifndef PDVITEXTURE_H
#define PDVITEXTURE_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 纹理放大过滤模式 */
enum TextureMagFilterType
{
    PDV_TEXTURE_MAGFILTER_NULL = 0,    ///< 未知
    PDV_TEXTURE_MAGFILTER_NEAREST = 1, ///< 临近过滤
    PDV_TEXTURE_MAGFILTER_LINEAR = 2   ///< 线性过滤
};

/** @brief 纹理缩小过滤模式 */
enum TextureMinFilterType
{
    PDV_TEXTURE_MINFILTER_NULL = 0,                   ///< 未知
    PDV_TEXTURE_MINFILTER_NEAREST = 1,                ///< 临近过滤
    PDV_TEXTURE_MINFILTER_LINEAR = 2,                 ///< 线性过滤
    PDV_TEXTURE_MINFILTER_NEAREST_MIPMAP_NEAREST = 3, ///< 使用最邻近的多级渐远纹理来匹配像素大小，并使用邻近插值进行纹理采样
    PDV_TEXTURE_MINFILTER_LINEAR_MIPMAP_NEAREST = 4,  ///< 使用最邻近的多级渐远纹理级别，并使用线性插值进行采样
    PDV_TEXTURE_MINFILTER_NEAREST_MIPMAP_LINEAR = 5,  ///< 在两个最匹配像素大小的多级渐远纹理之间进行线性插值，使用邻近插值进行采样
    PDV_TEXTURE_MINFILTER_LINEAR_MIPMAP_LINEAR = 6    ///< 在两个邻近的多级渐远纹理之间使用线性插值，并使用线性插值进行采样
};

/** @brief 纹理包裹模式 */
enum TextureWrapType
{
    PDV_TEXTURE_WRAP_NULL = 0,           ///< 未知
    PDV_TEXTURE_WRAP_REPEAT = 1,         ///< 重复纹理
    PDV_TEXTURE_WRAP_MIRROREDREPEAT = 2, ///< 镜像重复纹理
    PDV_TEXTURE_WRAP_CLAMP = 3           ///< 纹理截取
};

/** @brief 纹理的接口 */
class PDVCORE_API ITexture : public IDataObject
{
public:
    /**
     * @brief 获取纹理对象名称
     * @return PDV_RESULT
     * @param[out] oName 纹理对象名称
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString &oName) = 0;

    /**
     * @brief 设置纹理对象名称
     * @return PDV_RESULT
     * @param[in] iName 纹理对象名称
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString &iName) = 0;

    /**
     * @brief 获取纹理对象关联的图像资源ID
     * @return DftUInt64 图像资源ID
     * @note
     */
    virtual DftUInt64 GetImageID() = 0;

    /**
     * @brief 设置纹理对象关联的图像资源ID
     * @return PDV_RESULT
     * @param[in] iImageID 纹理对象关联的图像资源ID
     * @note
     */
    virtual PDV_RESULT SetImageID(const DftUInt64 &iImageID) = 0;

    /**
     * @brief 获取放大过滤模式
     * @return DftUInt8 见 TextureMagFilterType
     * @note
     */
    virtual DftUInt8 GetMagFilter() = 0;

    /**
     * @brief 设置放大过滤模式
     * @return PDV_RESULT
     * @param[in] iMagFilter 放大过滤模式，见 TextureMagFilterType
     * @note
     */
    virtual PDV_RESULT SetMagFilter(const DftUInt8 &iMagFilter) = 0;

    /**
     * @brief 获取缩小过滤模式
     * @return DftUInt8 见 TextureMinFilterType
     * @note
     */
    virtual DftUInt8 GetMinFilter() = 0;

    /**
     * @brief 设置缩小过滤模式
     * @return PDV_RESULT
     * @param[in] iMinFilter 缩小过滤模式，见 TextureMinFilterType
     * @note
     */
    virtual PDV_RESULT SetMinFilter(const DftUInt8 &iMinFilter) = 0;

    /**
     * @brief 获取纹理包裹模式
     * @return PDV_RESULT
     * @param[out] oWrapU U方向上的纹理包裹模式，详见 TextureWrapType
     * @param[out] oWrapV V方向上的纹理包裹模式
     * @note
     */
    virtual PDV_RESULT GetWrapType(DftUInt8 &oWrapU, DftUInt8 &oWrapV) = 0;

    /**
     * @brief 设置纹理包裹模式
     * @return PDV_RESULT
     * @param[in] iWrapU U方向上的纹理包裹模式，详见 TextureWrapType
     * @param[in] iWrapV V方向上的纹理包裹模式
     * @note
     */
    virtual PDV_RESULT SetWrapType(const DftUInt8 &iWrapU, const DftUInt8 &iWrapV) = 0;

    /**
     * @brief 获取图像裁剪偏移量
     * @return PDV_RESULT
     * @param[out] oOffsetU U方向上图像裁剪偏移量，取值范围为[0，1]
     * @param[out] oOffsetV V方向上图像裁剪偏移量，取值范围为[0，1]
     * @note
     */
    virtual PDV_RESULT GetClipOffset(DftFloat &oOffsetU, DftFloat &oOffsetV) = 0;

    /**
     * @brief 设置图像裁剪偏移量
     * @return PDV_RESULT
     * @param[in] iOffsetU U方向上图像裁剪偏移量，取值范围为[0，1]
     * @param[in] iOffsetV V方向上图像裁剪偏移量，取值范围为[0，1]
     * @note
     */
    virtual PDV_RESULT SetClipOffset(const DftFloat &iOffsetU, const DftFloat &iOffsetV) = 0;

    /**
     * @brief 获取图像裁剪长度
     * @return PDV_RESULT
     * @param[out] oScaleU U方向上图像裁剪长度，取值大于等于0
     * @param[out] oScaleV V方向上图像裁剪长度，取值大于等于0
     * @note
     */
    virtual PDV_RESULT GetClipScale(DftFloat &oScaleU, DftFloat &oScaleV) = 0;

    /**
     * @brief 设置图像裁剪长度
     * @return PDV_RESULT
     * @param[in] iScaleU U方向上图像裁剪长度，取值大于等于0
     * @param[in] iScaleV V方向上图像裁剪长度，取值大于等于0
     * @note
     */
    virtual PDV_RESULT SetClipScale(const DftFloat &iScaleU, const DftFloat &iScaleV) = 0;

    /**
     * @brief 获取旋转角度
     * @return DftFloat 旋转角度
     * @note
     */
    virtual DftFloat GetRotation() = 0;

    /**
     * @brief 设置旋转角度
     * @return PDV_RESULT
     * @param[in] iRotation 旋转角度
     * @note
     */
    virtual PDV_RESULT SetRotation(const DftFloat &iRotation) = 0;

    /**
     * @brief 获取旋转中心
     * @return PDV_RESULT
     * @param[out] oRotateCenterX 旋转中心X分量
     * @param[out] oRotateCenterY 旋转中心Y分量
     * @note
     */
    virtual PDV_RESULT GetRotateCenter(DftFloat &oRotateCenterX, DftFloat &oRotateCenterY) = 0;

    /**
     * @brief 设置旋转中心
     * @return PDV_RESULT
     * @param[in] iRotateCenterX 旋转中心X分量
     * @param[in] iRotateCenterY 旋转中心Y分量
     * @note
     */
    virtual PDV_RESULT SetRotateCenter(const DftFloat &iRotateCenterX, const DftFloat &iRotateCenterY) = 0;

    /**
     * @brief 获取图像重复值
     * @return PDV_RESULT
     * @param[out] oRepeatU U方向图像重复值
     * @param[out] oRepeatV V方向图像重复值
     * @note
     */
    virtual PDV_RESULT GetRepeat(DftFloat &oRepeatU, DftFloat &oRepeatV) = 0;

    /**
     * @brief 设置图像重复值
     * @return PDV_RESULT
     * @param[in] iRepeatU U方向图像重复值
     * @param[in] iRepeatV V方向图像重复值
     * @note
     */
    virtual PDV_RESULT SetRepeat(const DftFloat &iRepeatU, const DftFloat &iRepeatV) = 0;
};

} // namespace pdv

} // namespace kernel
#endif










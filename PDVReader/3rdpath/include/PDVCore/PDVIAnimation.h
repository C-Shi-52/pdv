/**
 * @file PDVIAnimation.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：动画的接口声明
 * @details 详细说明
 */

#ifndef PDVIANIMATION_H
#define PDVIANIMATION_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 动作片段的类型 */
enum ClipKeyType
{
    ANIMATION_CLIP_INVALID = 0,            ///< 无效类型
    ANIMATION_CLIP_TRANSLATION = 1,        ///< 平移
    ANIMATION_CLIP_ROTATION = 2,           ///< 旋转
    ANIMATION_CLIP_SCALE = 3,              ///< 缩放
    ANIMATION_CLIP_TRANSFORMATION = 4,     ///< 变换（含平移、旋转和缩放）
    ANIMATION_CLIP_MATERIAL = 5,           ///< 材质切换
    ANIMATION_CLIP_CAMERA = 6,             ///< 摄像机变换
    ANIMATION_CLIP_REVIEWDISPLAY = 7,      ///< 审阅隐藏或显示变化
    ANIMATION_CLIP_TRANSPARENCY = 8        ///< 透明度变化
};

/** @brief 平移关键帧 */
struct AnimationTranslationKey
{
    DftUInt _keyFrame;            ///< 平移动作的关键帧
    PDVVector3F _translationData; ///< 长方体的Y轴方向的长度

    /** 默认构造函数 */
    AnimationTranslationKey()
    {
        _keyFrame = 0;
        _translationData = PDVVector3F::Zero();
    }

    /** 参数化构造函数 */
    AnimationTranslationKey(DftUInt iKeyFrame, PDVVector3F iTranslationData)
    {
        _keyFrame = iKeyFrame;
        _translationData = iTranslationData;
    }

    /** 拷贝构造函数 */
    AnimationTranslationKey(const AnimationTranslationKey& iTranslationKey)
    {
        _keyFrame = iTranslationKey._keyFrame;
        _translationData = iTranslationKey._translationData;
    }

    /** 赋值运算符 */
    AnimationTranslationKey& operator=(const AnimationTranslationKey& iTranslationKey)
    {
        if (this != &iTranslationKey)
        {
            _keyFrame = iTranslationKey._keyFrame;
            _translationData = iTranslationKey._translationData;
        }
        return *this;
    }
};

/** @brief 旋转关键帧 */
struct AnimationRotationKey
{
    DftUInt _keyFrame;   ///< 旋转动作的关键帧
    PDVVector3F _origin; ///< 旋转原点（旋转轴上一点）的位置坐标
    PDVVector3F _axis;   ///< 旋转轴的向量
    DftFloat _value;     ///< 旋转弧度

    /** 默认构造函数 */
    AnimationRotationKey()
    {
        _keyFrame = 0;
        _origin = PDVVector3F::Zero();
        _axis = PDVVector3F::Zero();
        _value = 0.f;
    }

    /** 参数化构造函数 */
    AnimationRotationKey(DftUInt _iKeyFrame, PDVVector3F iOrigin, PDVVector3F iAxis, DftFloat iValue)
    {
        _keyFrame = _iKeyFrame;
        _origin = iOrigin;
        _axis = iAxis;
        _value = iValue;
    }

    /** 拷贝构造函数 */
    AnimationRotationKey(const AnimationRotationKey& iRotationKey)
    {
        _keyFrame = iRotationKey._keyFrame;
        _origin = iRotationKey._origin;
        _axis = iRotationKey._axis;
        _value = iRotationKey._value;
    }

    /** 赋值运算符 */
    AnimationRotationKey& operator=(const AnimationRotationKey& iRotationKey)
    {
        if (this != &iRotationKey)
        {
            _keyFrame = iRotationKey._keyFrame;
            _origin = iRotationKey._origin;
            _axis = iRotationKey._axis;
            _value = iRotationKey._value;
        }
        return *this;
    }
};

/** @brief 缩放关键帧 */
struct AnimationScaleKey
{
    DftUInt _keyFrame;  ///< 缩放动作的关键帧
    PDVVector3F _scale; ///< 依次表示相较于包围盒中心的缩放全局变换操作在X、Y、Z方向的分量

    /** 默认构造函数 */
    AnimationScaleKey()
    {
        _keyFrame = 0;
        _scale = PDVVector3F::Zero();
    }

    /** 参数化构造函数 */
    AnimationScaleKey(DftUInt iKeyFrame, PDVVector3F iScaleData)
    {
        _keyFrame = iKeyFrame;
        _scale = iScaleData;
    }

    /** 拷贝构造函数 */
    AnimationScaleKey(const AnimationScaleKey& iScaleKey)
    {
        _keyFrame = iScaleKey._keyFrame;
        _scale = iScaleKey._scale;
    }

    /** 赋值运算符 */
    AnimationScaleKey& operator=(const AnimationScaleKey& iScaleKey)
    {
        if (this != &iScaleKey)
        {
            _keyFrame = iScaleKey._keyFrame;
            _scale = iScaleKey._scale;
        }
        return *this;
    }
};

/** @brief 变换关键帧 */
struct AnimationTransformationKey
{
    DftUInt _keyFrame;           ///< 变换动作的关键帧
    PDVMatrix4D _transformation; ///< 相较于前一关键帧的全局变换操作

    /** 默认构造函数 */
    AnimationTransformationKey()
    {
        _keyFrame = 0;
        _transformation.SetIdentity();
    }

    /** 参数化构造函数 */
    AnimationTransformationKey(DftUInt iKeyFrame, PDVMatrix4D iTransformation)
    {
        _keyFrame = iKeyFrame;
        _transformation = iTransformation;
    }

    /** 拷贝构造函数 */
    AnimationTransformationKey(const AnimationTransformationKey& iTransformationKey)
    {
        _keyFrame = iTransformationKey._keyFrame;
        _transformation = iTransformationKey._transformation;
    }

    /** 赋值运算符 */
    AnimationTransformationKey& operator=(const AnimationTransformationKey& iTransformationKey)
    {
        if (this != &iTransformationKey)
        {
            _keyFrame = iTransformationKey._keyFrame;
            _transformation = iTransformationKey._transformation;
        }
        return *this;
    }
};

/** @brief 材质切换关键帧 */
struct AnimationMaterialKey
{
    DftUInt _keyFrame;     ///< 变换动作的关键帧
    DftUInt64 _materialID; ///< 材质对象ID

    /** 默认构造函数 */
    AnimationMaterialKey()
    {
        _keyFrame = 0;
        _materialID = DFT_INVALID_ID;
    }

    /** 参数化构造函数 */
    AnimationMaterialKey(DftUInt iKeyFrame, DftUInt64 iMaterialID)
    {
        _keyFrame = iKeyFrame;
        _materialID = iMaterialID;
    }

    /** 拷贝构造函数 */
    AnimationMaterialKey(const AnimationMaterialKey& iMaterialKey)
    {
        _keyFrame = iMaterialKey._keyFrame;
        _materialID = iMaterialKey._materialID;
    }

    /** 赋值运算符 */
    AnimationMaterialKey& operator=(const AnimationMaterialKey& iMaterialKey)
    {
        if (this != &iMaterialKey)
        {
            _keyFrame = iMaterialKey._keyFrame;
            _materialID = iMaterialKey._materialID;
        }
        return *this;
    }
};

/** @brief 摄像机变换关键帧 */
struct AnimationCameraKey
{
    DftUInt _keyFrame;   ///< 摄像机变换的关键帧
    DftUInt64 _cameraID; ///< 摄像机对象ID

    /** 默认构造函数 */
    AnimationCameraKey()
    {
        _keyFrame = 0;
        _cameraID = DFT_INVALID_ID;
    }

    /** 参数化构造函数 */
    AnimationCameraKey(DftUInt iKeyFrame, DftUInt64 iCameraID)
    {
        _keyFrame = iKeyFrame;
        _cameraID = iCameraID;
    }

    /** 拷贝构造函数 */
    AnimationCameraKey(const AnimationCameraKey& iCameraKey)
    {
        _keyFrame = iCameraKey._keyFrame;
        _cameraID = iCameraKey._cameraID;
    }

    /** 赋值运算符 */
    AnimationCameraKey& operator=(const AnimationCameraKey& iCameraKey)
    {
        if (this != &iCameraKey)
        {
            _keyFrame = iCameraKey._keyFrame;
            _cameraID = iCameraKey._cameraID;
        }
        return *this;
    }
};

/** @brief 审阅显示变换关键帧 */
struct AnimationReviewDisplayKey
{
    DftUInt _keyFrame;     ///< 审阅显示变换的关键帧
    DftUInt8 _displayMode; ///< 审阅对象是否显示

    /** 默认构造函数 */
    AnimationReviewDisplayKey()
    {
        _keyFrame = 0;
        _displayMode = 0;
    }

    /** 参数化构造函数 */
    AnimationReviewDisplayKey(DftUInt iKeyFrame, DftUInt8 iDisplayMode)
    {
        _keyFrame = iKeyFrame;
        _displayMode = iDisplayMode;
    }

    /** 拷贝构造函数 */
    AnimationReviewDisplayKey(const AnimationReviewDisplayKey& iReviewDisplayKey)
    {
        _keyFrame = iReviewDisplayKey._keyFrame;
        _displayMode = iReviewDisplayKey._displayMode;
    }

    /** 赋值运算符 */
    AnimationReviewDisplayKey& operator=(const AnimationReviewDisplayKey& iReviewDisplayKey)
    {
        if (this != &iReviewDisplayKey)
        {
            _keyFrame = iReviewDisplayKey._keyFrame;
            _displayMode = iReviewDisplayKey._displayMode;
        }
        return *this;
    }
};

/** @brief 透明度关键帧 */
struct AnimationTransparencyKey
{
    DftUInt _keyFrame;      ///< 透明度的关键帧
    DftUInt8 _transparency; ///< 透明度值

    /** 默认构造函数 */
    AnimationTransparencyKey()
    {
        _keyFrame = 0;
        _transparency = 0;
    }

    /** 参数化构造函数 */
    AnimationTransparencyKey(DftUInt iKeyFrame, DftUInt8 iTransparency)
    {
        _keyFrame = iKeyFrame;
        _transparency = iTransparency;
    }

    /** 拷贝构造函数 */
    AnimationTransparencyKey(const AnimationTransparencyKey& iTransparencyKey)
    {
        _keyFrame = iTransparencyKey._keyFrame;
        _transparency = iTransparencyKey._transparency;
    }

    /** 赋值运算符 */
    AnimationTransparencyKey& operator=(const AnimationTransparencyKey& iTransparencyKey)
    {
        if (this != &iTransparencyKey)
        {
            _keyFrame = iTransparencyKey._keyFrame;
            _transparency = iTransparencyKey._transparency;
        }
        return *this;
    }
};

/** @brief 动画片断的接口 */
class PDVCORE_API IClip
{
public:
    /**
     * @brief 获取动作片段的唯一标识
     * @return DftUInt64 动作片段的唯一标识
     * @note
     */
    virtual DftUInt64 GetID() = 0;

    /**
     * @brief 设置动作片段的唯一标识
     * @return PDV_RESULT
     * @param[in] iID 动作片段的唯一标识
     * @note
     */
    virtual PDV_RESULT SetID(const DftUInt64& iID) = 0;

    /**
     * @brief 获取动作片段的类型
     * @return DftUInt8 动作片段的类型，详见ClipKeyType
     * @note
     */
    virtual DftUInt8 GetType() = 0;

    /**
     * @brief 设置动作片段的类型
     * @return PDV_RESULT
     * @param[in] iType 动作片段的类型，详见ClipKeyType
     * @note
     */
    virtual PDV_RESULT SetType(const DftUInt8& iType) = 0;

    /**
     * @brief 获取动画片段的开始帧
     * @return DftUInt 动画片段的开始帧
     * @note
     */
    virtual DftUInt GetStartFrame() = 0;

    /**
     * @brief 设置动画片段的开始帧
     * @return PDV_RESULT
     * @param[in] iStartFrame 动画片段的开始帧
     * @note
     */
    virtual PDV_RESULT SetStartFrame(const DftUInt& iStartFrame) = 0;

    /**
     * @brief 获取动画片段的帧长度
     * @return DftUInt 动画片段的帧长度
     * @note
     */
    virtual DftUInt GetFrameLength() = 0;

    /**
     * @brief 设置动画片段的帧长度
     * @return PDV_RESULT
     * @param[in] iFrameLength 动画片段的帧长度
     * @note
     */
    virtual PDV_RESULT SetFrameLength(const DftUInt& iFrameLength) = 0;

    /**
     * @brief 获取动画片段关联的对象个数
     * @return DftUInt 动画片段关联的对象个数
     * @note
     */
    virtual DftUInt GetObjectCount() = 0;

    /**
     * @brief 获取动画片段关联的对象标识列表
     * @return PDV_RESULT
     * @param[out] oClippedNodeIDs 动画片段关联的对象标识列表
     * @note
     */
    virtual PDV_RESULT GetObjectIDs(std::vector<DftUInt64>& oObjectIDs) = 0;

    /**
     * @brief 设置动画片段关联的对象标识列表
     * @return PDV_RESULT
     * @param[in] iClippedNodeIDs 动画片段关联的对象标识列表
     * @note
     */
    virtual PDV_RESULT SetObjectIDs(const std::vector<DftUInt64>& iObjectIDs) = 0;

    /**
     * @brief 获取动画片段关键帧个数
     * @return DftUInt 动画片段关键帧个数
     * @note
     */
    virtual DftUInt GetKeyFrameCount() = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_TRANSLATION 时，获取平移关键帧列表
     * @return PDV_RESULT
     * @param[out] oTranslationKeyArray 平移关键帧列表
     * @note
     */
    virtual PDV_RESULT GetTranslationKeyArray(std::vector<AnimationTranslationKey>& oTranslationKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_TRANSLATION 时，设置平移关键帧列表
     * @return PDV_RESULT
     * @param[in] iTranslationKeyArray 平移关键帧列表
     * @note
     */
    virtual PDV_RESULT SetTranslationKeyArray(const std::vector<AnimationTranslationKey>& iTranslationKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_ROTATION 时，获取旋转关键帧列表
     * @return PDV_RESULT
     * @param[out] oRotationKeyArray 旋转关键帧列表
     * @note
     */
    virtual PDV_RESULT GetRotationKeyArray(std::vector<AnimationRotationKey>& oRotationKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_ROTATION 时，设置旋转关键帧列表
     * @return PDV_RESULT
     * @param[in] iRotationKeyArray 旋转关键帧列表
     * @note
     */
    virtual PDV_RESULT SetRotationKeyArray(const std::vector<AnimationRotationKey>& iRotationKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_SCALE 时，获取缩放关键帧列表
     * @return PDV_RESULT
     * @param[out] oScaleKeyArray 缩放关键帧列表
     * @note
     */
    virtual PDV_RESULT GetScaleKeyArray(std::vector<AnimationScaleKey>& oScaleKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_SCALE 时，设置缩放关键帧列表
     * @return PDV_RESULT
     * @param[in] iScaleKeyArray 缩放关键帧列表
     * @note
     */
    virtual PDV_RESULT SetScaleKeyArray(const std::vector<AnimationScaleKey>& iScaleKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_TRANSFORMATION 时，获取变换关键帧列表
     * @return PDV_RESULT
     * @param[out] oTransformationKeyArray 变换关键帧列表
     * @note
     */
    virtual PDV_RESULT GetTransformationKeyArray(std::vector<AnimationTransformationKey>& oTransformationKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_TRANSFORMATION 时，设置变换关键帧列表
     * @return PDV_RESULT
     * @param[in] iTransformationKeyArray 变换关键帧列表
     * @note
     */
    virtual PDV_RESULT SetTransformationKeyArray(const std::vector<AnimationTransformationKey>& iTransformationKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_MATERIAL 时，获取材质切换关键帧列表
     * @return PDV_RESULT
     * @param[out] oMaterialKeyArray 材质切换关键帧列表
     * @note
     */
    virtual PDV_RESULT GetMaterialKeyArray(std::vector<AnimationMaterialKey>& oMaterialKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_MATERIAL 时，设置材质切换关键帧列表
     * @return PDV_RESULT
     * @param[in] iMaterialKeyArray 材质切换关键帧列表
     * @note
     */
    virtual PDV_RESULT SetMaterialKeyArray(const std::vector<AnimationMaterialKey>& iMaterialKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_CAMERA 时，获取摄像机关键帧列表
     * @return PDV_RESULT
     * @param[out] oCameraKeyArray 摄像机关键帧列表
     * @note
     */
    virtual PDV_RESULT GetCameraKeyArray(std::vector<AnimationCameraKey>& oCameraKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_CAMERA 时，设置摄像机关键帧列表
     * @return PDV_RESULT
     * @param[in] iCameraKeyArray 摄像机关键帧列表
     * @note
     */
    virtual PDV_RESULT SetCameraKeyArray(const std::vector<AnimationCameraKey>& iCameraKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_REVIEWDISPLAY 时，获取审阅显示变换关键帧列表
     * @return PDV_RESULT
     * @param[out] oCameraKeyArray 审阅显示变换关键帧列表
     * @note
     */
    virtual PDV_RESULT GetReviewDisplayKeyArray(std::vector<AnimationReviewDisplayKey>& oReviewDisplayKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_REVIEWDISPLAY 时，设置审阅显示变换关键帧列表
     * @return PDV_RESULT
     * @param[in] iReviewDisplayKeyArray 审阅显示变换关键帧列表
     * @note
     */
    virtual PDV_RESULT SetReviewDisplayKeyArray(const std::vector<AnimationReviewDisplayKey>& iReviewDisplayKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_TRANSPARENCY 时，获取透明度变换关键帧列表
     * @return PDV_RESULT
     * @param[out] oTransparencyKeyArray 透明度变换关键帧列表
     * @note
     */
    virtual PDV_RESULT GetTransparencyKeyArray(std::vector<AnimationTransparencyKey>& oTransparencyKeyArray) = 0;

    /**
     * @brief 当动作片段的类型为 ANIMATION_CLIP_TRANSPARENCY 时，设置透明度变换关键帧列表
     * @return PDV_RESULT
     * @param[in] iTransparencyKeyArray 透明度变换关键帧列表
     * @note
     */
    virtual PDV_RESULT SetTransparencyKeyArray(const std::vector<AnimationTransparencyKey>& iTransparencyKeyArray) = 0;
};

/** @brief 动画的接口 */
class PDVCORE_API IAnimation : public IDataObject
{
public:
    /**
     * @brief 获取动画对象的命名
     * @return CUnicodeString 动画对象的命名
     * @note
     */
    virtual CUnicodeString GetName() = 0;

    /**
     * @brief 设置动画对象的命名
     * @return PDV_RESULT
     * @param[in] iName 动画对象的命名
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString& iName) = 0;

    /**
     * @brief 获取每秒播放的帧数
     * @return DftUInt 每秒播放的帧数
     * @note
     */
    virtual DftUInt GetSpeed() = 0;

    /**
     * @brief 设置每秒播放的帧数
     * @return PDV_RESULT
     * @param[in] iSpeed 每秒播放的帧数
     * @note
     */
    virtual PDV_RESULT SetSpeed(const DftUInt& iSpeed) = 0;

    /**
     * @brief 获取动画帧长度
     * @return DftUInt 动画帧长度
     * @note
     */
    virtual DftUInt GetFrameLength() = 0;

    /**
     * @brief 设置动画帧长度
     * @return PDV_RESULT
     * @param[in] iFrameLength 动画帧长度
     * @note
     */
    virtual PDV_RESULT SetFrameLength(const DftUInt& iFrameLength) = 0;

    /**
     * @brief 获取包含的动画片段的个数
     * @return DftUInt 包含的动画片段的个数
     * @note
     */
    virtual DftUInt GetClipCount() = 0;

    /**
     * @brief 获取动画片段数据列表
     * @return PDV_RESULT
     * @param[out] oClipArray 动画片段数据列表
     * @note
     */
    virtual PDV_RESULT GetClipArray(std::vector<IClip*>& oClipArray) = 0;

    /**
     * @brief 添加动画片段
     * @return IClip* 返回新加的动画片段
     * @note
     */
    virtual IClip* AddClip() = 0;

    /**
     * @brief 清空动画片段队列
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearClipArray() = 0;
};

} // namespace pdv

} // namespace kernel

#endif

/**
 * @file PDVILight.h
 * @author yue.rui
 * @version 1.0
 * @date 2024-07-05
 * @brief 概述：灯光的接口声明
 * @details 详细说明
 */

#ifndef PDVILIGHT_H
#define PDVILIGHT_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 灯光对象的类型 */
enum LightDataType
{
    PDV_LIGHT_NULL = 0,       ///< 未知
    PDV_LIGHT_AMBIENT = 1,    ///< 环境光
    PDV_LIGHT_PARALLEL = 2,   ///< 平行光
    PDV_LIGHT_POINT = 3,      ///< 点光源
    PDV_LIGHT_HEMISPHERE = 4, ///< 半球光
    PDV_LIGHT_SPOT = 100,     ///< 聚光灯
    PDV_LIGHT_RECTAREA = 101  ///< 平面光
};

/** @brief 环境光 */
struct PDVCORE_API AmbientLight
{
    RGBColor _color;     ///< 灯光颜色
    DftFloat _intensity; ///< 灯光亮度，取值范围[0，1]
    /** 默认构造函数 */
    AmbientLight() { Clear(); }
    /** 拷贝构造函数 */
    AmbientLight(const AmbientLight& iValue)
    {
        _color = iValue._color;
        _intensity = iValue._intensity;
    }
    /** 赋值运算符 */
    AmbientLight& operator=(const AmbientLight& iValue)
    {
        if (this != &iValue)
        {
            _color = iValue._color;
            _intensity = iValue._intensity;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _color = RGBColor();
        _intensity = 0.f;
    }
};

/** @brief 平行光 */
struct PDVCORE_API ParallelLight
{
    RGBColor _color;        ///< 灯光颜色
    DftFloat _intensity;    ///< 灯光亮度，取值范围[0，1]
    PDVVector3F _direction; ///< 平行光方向矢量
    /** 默认构造函数 */
    ParallelLight() { Clear(); }
    /** 拷贝构造函数 */
    ParallelLight(const ParallelLight& iValue)
    {
        _color = iValue._color;
        _intensity = iValue._intensity;
        _direction = iValue._direction;
    }
    /** 赋值运算符 */
    ParallelLight& operator=(const ParallelLight& iValue)
    {
        if (this != &iValue)
        {
            _color = iValue._color;
            _intensity = iValue._intensity;
            _direction = iValue._direction;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _color = RGBColor();
        _intensity = 0.f;
        _direction = PDVVector3F();
    }
};

/** @brief 点光源 */
struct PDVCORE_API PointLight
{
    RGBColor _color;             ///< 灯光颜色
    DftFloat _intensity;         ///< 灯光亮度，取值范围[0，1]
    PDVVector3F _position;       ///< 点光源光源位置
    DftFloat _attenuationFactor; ///< 点光源光线衰减系数，取值范围为[0，1]
    DftFloat _distance;          ///< 光源照射的最大距离
    /** 默认构造函数 */
    PointLight() { Clear(); }
    /** 拷贝构造函数 */
    PointLight(const PointLight& iValue)
    {
        _color = iValue._color;
        _intensity = iValue._intensity;
        _position = iValue._position;
        _attenuationFactor = iValue._attenuationFactor;
        _distance = iValue._distance;
    }
    /** 赋值运算符 */
    PointLight& operator=(const PointLight& iValue)
    {
        if (this != &iValue)
        {
            _color = iValue._color;
            _intensity = iValue._intensity;
            _position = iValue._position;
            _attenuationFactor = iValue._attenuationFactor;
            _distance = iValue._distance;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _color = RGBColor();
        _intensity = 0.f;
        _position = PDVVector3F();
        _attenuationFactor = 0.f;
        _distance = 0.f;
    }
};

/** @brief 半球光源 */
struct PDVCORE_API HemisphereLight
{
    DftFloat _intensity;   ///< 灯光亮度，取值范围[0，1]
    RGBColor _skyColor;    ///< 天空发出光线的颜色
    RGBColor _groundColor; ///< 地面发出光线的颜色
    PDVVector3F _position; ///< 世界坐标系下半球光位置
    /** 默认构造函数 */
    HemisphereLight() { Clear(); }
    /** 拷贝构造函数 */
    HemisphereLight(const HemisphereLight& iValue)
    {
        _intensity = iValue._intensity;
        _skyColor = iValue._skyColor;
        _groundColor = iValue._groundColor;
        _position = iValue._position;
    }
    /** 赋值运算符 */
    HemisphereLight& operator=(const HemisphereLight& iValue)
    {
        if (this != &iValue)
        {
            _intensity = iValue._intensity;
            _skyColor = iValue._skyColor;
            _groundColor = iValue._groundColor;
            _position = iValue._position;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _intensity = 0.f;
        _skyColor = RGBColor();
        _groundColor = RGBColor();
        _position = PDVVector3F();
    }
};

/** @brief 聚光灯 */
struct PDVCORE_API SpotLight
{
    RGBColor _color;             ///< 灯光颜色
    DftFloat _intensity;         ///< 灯光亮度，取值范围[0，1]
    DftFloat _distance;          ///< 光线照射的最大距离
    DftFloat _angle;             ///< 光线照射范围的角度，单位为弧度
    DftFloat _pennumbra;         ///< 聚光锥的半影衰减百分比
    DftFloat _attenuationFactor; ///< 点光源光线衰减系数，取值范围为[0，1]
    PDVVector3F _position;       ///< 世界坐标系下聚光灯位置
    PDVVector3F _target;         ///< 世界坐标系下聚光灯的照射点
    /** 默认构造函数 */
    SpotLight() { Clear(); }
    /** 拷贝构造函数 */
    SpotLight(const SpotLight& iValue)
    {
        _color = iValue._color;
        _intensity = iValue._intensity;
        _distance = iValue._distance;
        _angle = iValue._angle;
        _pennumbra = iValue._pennumbra;
        _attenuationFactor = iValue._attenuationFactor;
        _position = iValue._position;
        _target = iValue._target;
    }
    /** 赋值运算符 */
    SpotLight& operator=(const SpotLight& iValue)
    {
        if (this != &iValue)
        {
            _color = iValue._color;
            _intensity = iValue._intensity;
            _distance = iValue._distance;
            _angle = iValue._angle;
            _pennumbra = iValue._pennumbra;
            _attenuationFactor = iValue._attenuationFactor;
            _position = iValue._position;
            _target = iValue._target;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _color = RGBColor();
        _intensity = 0.f;
        _distance = 0.f;
        _angle = 0.f;
        _pennumbra = 0.f;
        _attenuationFactor = 0.f;
        _position = PDVVector3F();
        _target = PDVVector3F();
    }
};

/** @brief 平面光 */
struct PDVCORE_API RectAreaLight
{
    RGBColor _color;       ///< 灯光颜色
    DftFloat _intensity;   ///< 灯光亮度，取值范围[0，1]
    DftFloat _width;       ///< 光源宽度
    DftFloat _height;      ///< 光源高度
    PDVVector3F _position; ///< 世界坐标系下平面光位置
    PDVVector3F _target;   ///< 世界坐标系下平面光的照射点
    /** 默认构造函数 */
    RectAreaLight() { Clear(); }
    /** 拷贝构造函数 */
    RectAreaLight(const RectAreaLight& iValue)
    {
        _color = iValue._color;
        _intensity = iValue._intensity;
        _width = iValue._width;
        _height = iValue._height;
        _position = iValue._position;
        _target = iValue._target;
    }
    /** 赋值运算符 */
    RectAreaLight& operator=(const RectAreaLight& iValue)
    {
        if (this != &iValue)
        {
            _color = iValue._color;
            _intensity = iValue._intensity;
            _width = iValue._width;
            _height = iValue._height;
            _position = iValue._position;
            _target = iValue._target;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _color = RGBColor();
        _intensity = 0.f;
        _width = 0.f;
        _height = 0.f;
        _position = PDVVector3F();
        _target = PDVVector3F();
    }
};

/** @brief 灯光对象的接口 */
class PDVCORE_API ILight : public IDataObject
{
public:
    /**
     * @brief 获取灯光名称
     * @return PDV_RESULT
     * @param[out] oName 灯光名称
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString& oName) = 0;

    /**
     * @brief 设置灯光名称
     * @return PDV_RESULT
     * @param[in] iName 灯光名称
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString& iName) = 0;

    /**
     * @brief 获取灯光类型
     * @return DftUInt8 见 LightDataType
     * @note
     */
    virtual DftUInt8 GetType() = 0;

    /**
     * @brief 设置灯光类型
     * @return PDV_RESULT
     * @param[in] iType 灯光类型
     * @note
     */
    virtual PDV_RESULT SetType(const DftUInt8& iType) = 0;

    /**
     * @brief 获取环境光结构
     * @return PDV_RESULT
     * @param[out] oAmbientLight 环境光结构
     * @note
     */
    virtual PDV_RESULT GetAmbientLight(AmbientLight& oAmbientLight) = 0;

    /**
     * @brief 设置环境光结构
     * @return PDV_RESULT
     * @param[in] iAmbientLight 环境光结构
     * @note
     */
    virtual PDV_RESULT SetAmbientLight(const AmbientLight& iAmbientLight) = 0;

    /**
     * @brief 获取平行光结构
     * @return PDV_RESULT
     * @param[out] oParallelLight 平行光结构
     * @note
     */
    virtual PDV_RESULT GetParallelLight(ParallelLight& oParallelLight) = 0;

    /**
     * @brief 设置平行光结构
     * @return PDV_RESULT
     * @param[in] iParallelLight 平行光结构
     * @note
     */
    virtual PDV_RESULT SetParallelLight(const ParallelLight& iParallelLight) = 0;

    /**
     * @brief 获取点光源结构
     * @return PDV_RESULT
     * @param[out] oPointLight 点光源结构
     * @note
     */
    virtual PDV_RESULT GetPointLight(PointLight& oPointLight) = 0;

    /**
     * @brief 设置点光源结构
     * @return PDV_RESULT
     * @param[in] iPointLight 点光源结构
     * @note
     */
    virtual PDV_RESULT SetPointLight(const PointLight& iPointLight) = 0;

    /**
     * @brief 获取半球光源结构
     * @return PDV_RESULT
     * @param[out] oHemisphereLight 半球光源结构
     * @note
     */
    virtual PDV_RESULT GetHemisphereLight(HemisphereLight& oHemisphereLight) = 0;

    /**
     * @brief 设置半球光源结构
     * @return PDV_RESULT
     * @param[in] iHemisphereLight 半球光源结构
     * @note
     */
    virtual PDV_RESULT SetHemisphereLight(const HemisphereLight& iHemisphereLight) = 0;

    /**
     * @brief 获取聚光灯源结构
     * @return PDV_RESULT
     * @param[out] oSpotLight 聚光灯源结构
     * @note
     */
    virtual PDV_RESULT GetSpotLight(SpotLight& oSpotLight) = 0;

    /**
     * @brief 设置聚光灯源结构
     * @return PDV_RESULT
     * @param[in] iSpotLight 聚光灯源结构
     * @note
     */
    virtual PDV_RESULT SetSpotLight(const SpotLight& iSpotLight) = 0;

    /**
     * @brief 获取平面光源结构
     * @return PDV_RESULT
     * @param[out] oRectAreaLight 平面光源结构
     * @note
     */
    virtual PDV_RESULT GetRectAreaLight(RectAreaLight& oRectAreaLight) = 0;

    /**
     * @brief 设置平面光源结构
     * @return PDV_RESULT
     * @param[in] iHRectAreaLight 平面光源结构
     * @note
     */
    virtual PDV_RESULT SetRectAreaLight(const RectAreaLight& iHRectAreaLight) = 0;

    /**
     * @brief 获取当前灯光是否可用
     * @return DftUInt8 灯光是否可用
     * @note
     */
    virtual DftUInt8 GetEnable() = 0;

    /**
     * @brief 设置灯光是否可用
     * @return PDV_RESULT
     * @param[in] iEnable 灯光是否可用
     * @note
     */
    virtual PDV_RESULT SetEnable(DftUInt8 iEnable) = 0;
};

} // namespace pdv

} // namespace kernel

#endif










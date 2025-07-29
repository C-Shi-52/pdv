/**
 * @file PDVIMaterial.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：材质的接口声明
 * @details 详细说明
 */

#ifndef PDVIMATERIAL_H
#define PDVIMATERIAL_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{
/** @brief 渲染面的类型 */
enum RenderSideType
{
    RENDER_SIDE_NULL = 0,   ///< 未知
    RENDER_SIDE_FRONT = 1,  ///< 正面渲染
    RENDER_SIDE_BACK = 2,   ///< 背面渲染
    RENDER_SIDE_DOUBLE = 3, ///< 双面渲染
};

/** @brief 材质关联的几何图元类型 */
enum MaterialMeshType
{
    MATERIAL_MESHTYPE_NULL = 0,  ///< 无效类型
    MATERIAL_MESHTYPE_POINT = 1, ///< 点
    MATERIAL_MESHTYPE_LINE = 2,  ///< 线
    MATERIAL_MESHTYPE_MESH = 3   ///< 面
};

/** @brief 材质对象的类型 */
enum MaterialDataType
{
    MATERIALDATA_NULL = 0,  ///< 未知
    MATERIALDATA_RGB = 1,   ///< RGB纯色, 则MaterialData的数据类型为PDV_RGBData
    MATERIALDATA_PHONG = 2, ///< Phong光照模型, 则MaterialData的数据类型为PDV_PhongData
    MATERIALDATA_PBR = 3,   ///< 基于物理渲染光照模型, 则MaterialData的数据类型为PDV_PBRData
};

/** @brief PhongData掩码类型 */
enum PhongDataMaskType
{
    PHONGDATA_DIFFUSE = 1 << 0, ///< 关联漫反射贴图的纹理
    PHONGDATA_NORMAL = 1 << 1   ///< 关联法线贴图的纹理
};

/** @brief PBRData掩码类型 */
enum PBRDataMaskType
{
    PBRDATA_EMISSIVE_RGB = 1 << 0, ///< 自发光颜色和自发光强度
    PBRDATA_DIFFUSE = 1 << 1,      ///< 漫反射贴图纹理
    PBRDATA_NORMAL = 1 << 2,       ///< 法线贴图纹理
    PBRDATA_TRANSPARENCY = 1 << 3, ///< 透明度贴图纹理
    PBRDATA_EMISSIVE = 1 << 4,     ///< 自发光贴图纹理
    PBRDATA_ENVMAP = 1 << 5,       ///< 环境贴图纹理
    PBRDATA_LIGHTMAP = 1 << 6,     ///< 光照贴图纹理
    PBRDATA_METALLIC = 1 << 7,     ///< 金属度贴图纹理
    PBRDATA_ROUGHNESS = 1 << 8,    ///< 粗糙度贴图纹理
    PBRDATA_AOTEXTURE = 1 << 9     ///< 环境光遮蔽贴图纹理
};

/** @brief Blinn-PhongData */
struct PhongData
{
    DftUInt8 _bitMask;           ///< 内容标志, 第1位：是否关联漫反射贴图的纹理；第2位：是否关联法线贴图的纹理；第3-8位：保留使用
    RGBColor _diffuse;           ///< 漫反射光分量颜色
    RGBColor _ambient;           ///< 环境光分量颜色
    RGBColor _specular;          ///< 镜面反射光分量颜色
    RGBColor _emissive;          ///< 自发光颜色
    DftFloat _emissiveIntensity; ///< 自发光强度
    DftFloat _power;             ///< 镜面反射光的锐度。取值范围为[0，1]
    DftUInt64 _textureID;        ///< 漫反射贴图的纹理ID,BitMask的第1位取值为0，则该数据项不存在。
    DftUInt64 _normalTextureID;  ///< 法线贴图的纹理ID,BitMask的第2位取值为0，则该数据项不存在。
    /** 默认构造函数 */
    PhongData() { Clear(); }
    /** 拷贝构造函数 */
    PhongData(const PhongData& iValue)
    {
        _bitMask = iValue._bitMask;
        _diffuse = iValue._diffuse;
        _ambient = iValue._ambient;
        _specular = iValue._specular;
        _emissive = iValue._emissive;
        _emissiveIntensity = iValue._emissiveIntensity;
        _power = iValue._power;
        _textureID = iValue._textureID;
        _normalTextureID = iValue._normalTextureID;
    }
    /** 赋值运算符 */
    PhongData& operator=(const PhongData& iValue)
    {
        if (this != &iValue)
        {
            _bitMask = iValue._bitMask;
            _diffuse = iValue._diffuse;
            _ambient = iValue._ambient;
            _specular = iValue._specular;
            _emissive = iValue._emissive;
            _emissiveIntensity = iValue._emissiveIntensity;
            _power = iValue._power;
            _textureID = iValue._textureID;
            _normalTextureID = iValue._normalTextureID;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _bitMask = 0;
        _emissiveIntensity = 0.f;
        _power = 0.f;
        _textureID = DFT_INVALID_ID;
        _normalTextureID = DFT_INVALID_ID;
        _diffuse = RGBColor();
        _ambient = RGBColor();
        _specular = RGBColor();
        _emissive = RGBColor();
    }
};

/** @brief 基于物理渲染的数据结构 */
struct PBRData
{
    DftUInt16 _bitMask;               ///< 内容标志，见 PBRDataMaskType 第11-16位：保留使用
    RGBColor _diffuse;                ///< 漫反射光分量颜色
    RGBColor _ambient;                ///< 环境光分量颜色
    DftFloat _metallicFactor;         ///< 金属度，取值范围为[0，1]
    DftFloat _roughnessFactor;        ///< 粗糙度，取值范围为[0，1]
    RGBColor _emissive;               ///< 自发光颜色，BitMask的第1位取值为0，则该数据项不存在。
    DftFloat _emissiveIntensity;      ///< 自发光强度，BitMask的第1位取值为0，则该数据项不存在。
    DftUInt64 _diffuseTextureID;      ///< 漫反射贴图的纹理ID，BitMask的第2位取值为0，则该数据项不存在。
    DftUInt64 _normalTextureID;       ///< 法线贴图的纹理ID，BitMask的第3位取值为0，则该数据项不存在。
    DftUInt64 _transparencyTextureID; ///< 透明度贴图的纹理ID，BitMask的第4位取值为0，则该数据项不存在。
    DftUInt64 _emissiveTextureID;     ///< 漫反射贴图的纹理ID，BitMask的第5位取值为0，则该数据项不存在。
    DftUInt64 _envMapTextureID;       ///< 自发光贴图的纹理ID，BitMask的第6位取值为0，则该数据项不存在。
    DftUInt64 _lightMapTextureID;     ///< 光照贴图的纹理ID，BitMask的第7位取值为0，则该数据项不存在。
    DftUInt64 _metallicTextureID;     ///< 金属贴图的纹理ID，BitMask的第8位取值为0，则该数据项不存在。
    DftUInt64 _roughnessTextureID;    ///< 粗糙度贴图的纹理ID，BitMask的第9位取值为0，则该数据项不存在。
    DftUInt64 _AOTextureID;           ///< 环境光遮蔽贴图的纹理ID，BitMask的第10位取值为0，则该数据项不存在。
    /** 默认构造函数 */
    PBRData() { Clear(); }
    /** 拷贝构造函数 */
    PBRData(const PBRData& iValue)
    {
        _bitMask = iValue._bitMask;
        _diffuse = iValue._diffuse;
        _ambient = iValue._ambient;
        _metallicFactor = iValue._metallicFactor;
        _roughnessFactor = iValue._roughnessFactor;
        _emissive = iValue._emissive;
        _emissiveIntensity = iValue._emissiveIntensity;
        _diffuseTextureID = iValue._diffuseTextureID;
        _normalTextureID = iValue._normalTextureID;
        _transparencyTextureID = iValue._transparencyTextureID;
        _emissiveTextureID = iValue._emissiveTextureID;
        _envMapTextureID = iValue._envMapTextureID;
        _lightMapTextureID = iValue._lightMapTextureID;
        _metallicTextureID = iValue._metallicTextureID;
        _roughnessTextureID = iValue._roughnessTextureID;
        _AOTextureID = iValue._AOTextureID;
    }
    /** 赋值运算符 */
    PBRData& operator=(const PBRData& iValue)
    {
        if (this != &iValue)
        {
            _bitMask = iValue._bitMask;
            _diffuse = iValue._diffuse;
            _ambient = iValue._ambient;
            _metallicFactor = iValue._metallicFactor;
            _roughnessFactor = iValue._roughnessFactor;
            _emissive = iValue._emissive;
            _emissiveIntensity = iValue._emissiveIntensity;
            _diffuseTextureID = iValue._diffuseTextureID;
            _normalTextureID = iValue._normalTextureID;
            _transparencyTextureID = iValue._transparencyTextureID;
            _emissiveTextureID = iValue._emissiveTextureID;
            _envMapTextureID = iValue._envMapTextureID;
            _lightMapTextureID = iValue._lightMapTextureID;
            _metallicTextureID = iValue._metallicTextureID;
            _roughnessTextureID = iValue._roughnessTextureID;
            _AOTextureID = iValue._AOTextureID;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _bitMask = 0;
        _metallicFactor = 0.f;
        _roughnessFactor = 0.f;
        _emissiveIntensity = 0.f;
        _diffuseTextureID = DFT_INVALID_ID;
        _normalTextureID = DFT_INVALID_ID;
        _transparencyTextureID = DFT_INVALID_ID;
        _emissiveTextureID = DFT_INVALID_ID;
        _envMapTextureID = DFT_INVALID_ID;
        _lightMapTextureID = DFT_INVALID_ID;
        _metallicTextureID = DFT_INVALID_ID;
        _roughnessTextureID = DFT_INVALID_ID;
        _AOTextureID = DFT_INVALID_ID;
        _diffuse = RGBColor();
        _ambient = RGBColor();
        _emissive = RGBColor();
    }
};

/** @brief 材质的接口 */
class PDVCORE_API IMaterial : public IDataObject
{
public:
    /**
     * @brief 获取材质对象命名
     * @return PDV_RESULT
     * @param[out] oName 材质对象命名
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString& oName) = 0;

    /**
     * @brief 设置材质对象命名
     * @return PDV_RESULT
     * @param[in] iName 材质对象命名
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString& iName) = 0;

    /**
     * @brief 获取材质对象的类型
     * @return DftUInt 材质对象的类型，见 MaterialDataType
     * @note
     */
    virtual DftUInt GetType() = 0;

    /**
     * @brief 设置材质对象的类型
     * @return PDV_RESULT
     * @param[in] iType 材质对象的类型，见 MaterialDataType
     * @note
     */
    virtual PDV_RESULT SetType(const DftUInt& iType) = 0;

    /**
     * @brief 获取透明度值
     * @return DftUInt8 透明度值，取值范围为[0,255]，0表示完全透明，255表示不透明，默认值为255
     * @note
     */
    virtual DftUInt GetTransparency() = 0;

    /**
     * @brief 设置透明度值
     * @return PDV_RESULT
     * @param[in] iTransparency 透明度值，取值范围为[0,255]，0表示完全透明，255表示不透明，默认值为255
     * @note
     */
    virtual PDV_RESULT SetTransparency(const DftUInt& iTransparency) = 0;

    /**
     * @brief 获取颜色材质
     * @return PDV_RESULT
     * @param[out] oColor 颜色
     * @note 如果当前材质是 MATERIALDATA_RGB ，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MATERIAL_TYPE_ERROR
     */
    virtual PDV_RESULT GetPureColor(RGBColor& oColor) = 0;

    /**
     * @brief 设置颜色材质
     * @return PDV_RESULT
     * @param[in] iColor 颜色值
     * @note 如果当前材质是 MATERIALDATA_RGB ，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MATERIAL_TYPE_ERROR
     */
    virtual PDV_RESULT SetPureColor(const RGBColor& iColor) = 0;

    /**
     * @brief 获取自然材质
     * @return PDV_RESULT
     * @param[out] oData 冯氏渲染数据结构
     * @note 如果当前材质是 MATERIALDATA_PHONG ，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MATERIAL_TYPE_ERROR
     */
    virtual PDV_RESULT GetPhongData(PhongData& oData) = 0;

    /**
     * @brief 设置自然材质
     * @return PDV_RESULT
     * @param[in] iData 冯氏渲染数据结构
     * @note 如果当前材质是 MATERIALDATA_PHONG ，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MATERIAL_TYPE_ERROR
     */
    virtual PDV_RESULT SetPhongData(const PhongData& iData) = 0;

    /**
     * @brief 获取PBR材质
     * @return PDV_RESULT
     * @param[out] oData PBR数据结构
     * @note 如果当前材质是 MATERIALDATA_PHONG ，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MATERIAL_TYPE_ERROR
     */
    virtual PDV_RESULT GetPBRData(PBRData& oData) = 0;

    /**
     * @brief 设置PBR材质
     * @return PDV_RESULT
     * @param[in] iData PBR数据结构
     * @note 如果当前材质是 MATERIALDATA_PHONG ，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MATERIAL_TYPE_ERROR
     */
    virtual PDV_RESULT SetPBRData(const PBRData& iData) = 0;

    /**
     * @brief 获取材质对象的引用几何类型
     * @return DftUInt 材质对象的引用几何类型，见 MaterialMeshType
     * @note
     */
    virtual DftUInt GetRefGeometryType() = 0;

    /**
     * @brief 设置材质对象的引用几何类型
     * @return PDV_RESULT
     * @param[in] iRefGeometryType 材质对象的引用几何类型，见 MaterialMeshType
     * @note
     */
    virtual PDV_RESULT SetRefGeometryType(const DftUInt& iRefGeometryType) = 0;

    /**
     * @brief 获取材质对象是否开启透明度
     * @return DftUInt 材质对象是否开启透明度
     * @note
     */
    virtual DftUInt GetOpacityEnabled() = 0;

    /**
     * @brief 1表示开启 0表示不开启
     * @return PDV_RESULT
     * @param[in] iOpacityEnabled 材质对象是否开启透明度，1表示开启 0表示不开启
     * @note
     */
    virtual PDV_RESULT SetOpacityEnabled(const DftUInt& iOpacityEnabled) = 0;

    /**
     * @brief 获取材质对象的渲染面类型
     * @return DftUInt 材质对象的渲染面类型，见 RenderSideType
     * @note
     */
    virtual DftUInt GetRenderSide() = 0;

    /**
     * @brief 设置材质对象的渲染面类型
     * @return PDV_RESULT
     * @param[in] iRenderSide 材质对象的渲染面类型，见 RenderSideType
     * @note
     */
    virtual PDV_RESULT SetRenderSide(const DftUInt& iRenderSide) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
/**
 * @file PDVIPrimity.h
 * @author yuerui
 * @version 1.0
 * @date 2024-4-27
 * @brief 概述：基本体的接口声明
 * @details 详细说明
 */

#ifndef PDVIPRIMITY_H
#define PDVIPRIMITY_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 基本体类型 */
enum PrimityType
{
    PRIMITY_INVALID = 0,  ///< 未知
    PRIMITY_CUBOID = 1,   ///< 立方体
    PRIMITY_CYLINDER = 2, ///< 圆柱
    PRIMITY_CONE = 3,     ///< 圆台
    PRIMITY_TORUS = 4,    ///< 圆环体
    PRIMITY_FAN = 5,      ///< 扇环体
    PRIMITY_SPHERE = 6,   ///< 球体
    PRIMITY_SPHCROWN = 7  ///< 球冠
};

/** @brief  判断基本体是否包含特定的内容信息，1表示是，0表示否 */
enum PrimityBitMask
{
    PRIMITY_BITMASK_INVALID = 0, ///< 未知
    PRIMITY_BITMASK_MATEIRAL = 1 ///< 是否关联材质
};

/** @brief 立方体 */
struct CuboidPrimityData
{
    DftFloat _length;  ///< 长方体的X轴方向的长度
    DftFloat _width;   ///< 长方体的Y轴方向的长度
    DftFloat _height;  ///< 长方体的Z轴方向的长度
    /** 默认构造函数 */
    CuboidPrimityData()
    {
        _length = 0.f;
        _width = 0.f;
        _height = 0.f;
    }
    /** 带参构造函数 */
    CuboidPrimityData(DftFloat length, DftFloat width, DftFloat height) 
    {
        _length = length;
        _width = width;
        _height = height;
    }
    /** 带参构造函数 */
    CuboidPrimityData(CuboidPrimityData &cubiod)
    {
        _length = cubiod._length;
        _width = cubiod._width;
        _height = cubiod._height;
    }
    /** 赋值运算符 */
    CuboidPrimityData& operator=(const CuboidPrimityData &cubiod)
    {
        if (this != &cubiod)
        {
            _length = cubiod._length;
            _width = cubiod._width;
            _height = cubiod._height;
        }
        return *this;
    }
};

/** @brief 圆柱 */
struct CylinderPrimityData
{
    DftFloat _radius;      ///< 圆柱体的半径
    DftFloat _height;      ///< 圆柱体沿Z轴方向的高度
    /** 默认构造函数 */
    CylinderPrimityData()
    {
        _radius = 0.f;
        _height = 0.f;
    }
    /** 带参构造函数 */
    CylinderPrimityData(DftFloat radius, DftFloat height)
    {
        _radius = radius;
        _height = height;
    }
    /** 带参构造函数 */
    CylinderPrimityData(CylinderPrimityData &cylinder)
    {
        _radius = cylinder._radius;
        _height = cylinder._height;
    }
    /** 赋值运算符 */
    CylinderPrimityData& operator=(const CylinderPrimityData &cylinder)
    {
        if (this != &cylinder)
        {
            _radius = cylinder._radius;
            _height = cylinder._height;
        }
        return *this;
    }
};

/** @brief 圆台(包含圆锥) */
struct ConePrimityData
{
    DftFloat _height;          ///< 圆台的高度
    DftFloat _topRadius;       ///< 圆台的顶面半径。如果取值为0，则表示圆锥
    DftFloat _bottomRadius;    ///< 圆台的底面半径
    /** 默认构造函数 */
    ConePrimityData()
    {
        _height = 0.f;
        _topRadius = 0.f;
        _bottomRadius = 0.f;
    }
    /** 带参构造函数 */
    ConePrimityData(DftFloat height, DftFloat topRadius, DftFloat bottomRadius)
    {
        _height = height;
        _topRadius = topRadius;
        _bottomRadius = bottomRadius;
    }
    /** 带参构造函数 */
    ConePrimityData(ConePrimityData &cone)
    {
        _height = cone._height;
        _topRadius = cone._topRadius;
        _bottomRadius = cone._bottomRadius;
    }
    /** 赋值运算符 */
    ConePrimityData& operator=(const ConePrimityData &cone)
    {
        if (this != &cone)
        {
            _height = cone._height;
            _topRadius = cone._topRadius;
            _bottomRadius = cone._bottomRadius;
        }
        return *this;
    }
};

/** @brief 圆环体 */
struct TorusPrimityData
{
    DftFloat _torusRadius; ///< 圆环的主半径
    DftFloat _portRadius;  ///< 圆环的截面半径
    DftFloat _angle;       ///< 圆环的弧度，取值范围为（0，2PI] 
    /** 默认构造函数 */
    TorusPrimityData( )
    {
        _torusRadius = 0.f;
        _portRadius = 0.f;
        _angle = 0.f;
    }
    /** 带参构造函数 */
    TorusPrimityData(DftFloat torusRadius, DftFloat portRadius, DftFloat angle)
    {
        _torusRadius = torusRadius;
        _portRadius = portRadius;
        _angle = angle;
    }
    /** 带参构造函数 */
    TorusPrimityData(TorusPrimityData &torus)
    {
        _torusRadius = torus._torusRadius;
        _portRadius = torus._portRadius;
        _angle = torus._angle;
    }
    /** 赋值运算符 */
    TorusPrimityData& operator=(const TorusPrimityData &torus)
    {
        if (this != &torus)
        {
            _torusRadius = torus._torusRadius;
            _portRadius = torus._portRadius;
            _angle = torus._angle;
        }
        return *this;
    }
};

/** @brief 扇环体 */
struct FanPrimityData
{
    DftFloat _outerRadius; ///< 扇环体的外半径
    DftFloat _innerRadius; ///< 扇环体的内半径，内半径为0时，退化为扇体
    DftFloat _height;      ///< 扇环体的高度
    DftFloat _angle;       ///< 扇环体的弧度，取值范围为（0，2PI]
    /** 默认构造函数 */
    FanPrimityData( )
    {
        _outerRadius = 0.f;
        _innerRadius = 0.f;
        _height = 0.f;
        _angle = 0.f;
    }
    /** 带参构造函数 */
    FanPrimityData(DftFloat outerRadius, DftFloat innerRadius, DftFloat height, DftFloat angle)
    {
        _outerRadius = outerRadius;
        _innerRadius = innerRadius;
        _height = height;
        _angle = angle;
    }
    /** 带参构造函数 */
    FanPrimityData(FanPrimityData &fan)
    {
        _outerRadius = fan._outerRadius;
        _innerRadius = fan._innerRadius;
        _height = fan._height;
        _angle = fan._angle;
    }
    /** 赋值运算符 */
    FanPrimityData& operator=(const FanPrimityData &fan)
    {
        if (this != &fan)
        {
            _outerRadius = fan._outerRadius;
            _innerRadius = fan._innerRadius;
            _height = fan._height;
            _angle = fan._angle;
        }
        return *this;
    }
};

/** @brief 球体 */
struct SpherePrimityData
{
    DftFloat _radius;  ///< 球体半径
    /** 默认构造函数 */
    SpherePrimityData( )
    {
        _radius = 0.f;
    }
    /** 带参构造函数 */
    SpherePrimityData(DftFloat radius)
    {
        _radius = radius;
    }
    /** 带参构造函数 */
    SpherePrimityData(SpherePrimityData &sphere)
    {
        _radius = sphere._radius;
    }
    /** 赋值运算符 */
    SpherePrimityData& operator=(const SpherePrimityData &sphere)
    {
        if (this != &sphere)
        {
            _radius = sphere._radius;
        }
        return *this;
    }
};

/** @brief 球冠 */
struct SphCrownPrimityData
{
    DftFloat _radius;      ///< 球体半径
    DftFloat _zStartAngle; ///< 球冠曲面起始极角（弧度值）
    DftFloat _zEndAngle;   ///< 球冠曲面终止极角（弧度值）
    DftFloat _xyAngle;     ///< 球冠曲面扫过的方位角（弧度值）
    /** 默认构造函数 */
    SphCrownPrimityData( )
    {
        _radius = 0.f;
        _zStartAngle = 0.f;
        _zEndAngle = 0.f;
        _xyAngle = 0.f;
    }
    /** 带参构造函数 */
    SphCrownPrimityData(DftFloat radius, DftFloat zStartAngle, DftFloat zEndAngle, DftFloat xyAngle)
    {
        _radius = radius;
        _zStartAngle = zStartAngle;
        _zEndAngle = zEndAngle;
        _xyAngle = xyAngle;
    }
    /** 带参构造函数 */
    SphCrownPrimityData(SphCrownPrimityData &sphCrown)
    {
        _radius = sphCrown._radius;
        _zStartAngle = sphCrown._zStartAngle;
        _zEndAngle = sphCrown._zEndAngle;
        _xyAngle = sphCrown._xyAngle;
    }
    /** 赋值运算符 */
    SphCrownPrimityData& operator=(const SphCrownPrimityData &sphCrown)
    {
        if (this != &sphCrown)
        {
            _radius = sphCrown._radius;
            _zStartAngle = sphCrown._zStartAngle;
            _zEndAngle = sphCrown._zEndAngle;
            _xyAngle = sphCrown._xyAngle;
        }
        return *this;
    }
};

/** @brief 基本体的接口 */
class PDVCORE_API IPrimity : public IDataObject
{
public:
    /**
     * @brief 获取基本体的内容标识码
     * @return DftUInt8 基本体的内容标识码
     * @note
     */
    virtual DftUInt8 GetBitMask() = 0;

    /**
     * @brief 设置基本体的内容标识码
     * @return PDV_RESULT
     * @param[in] iBitMask 基本体的内容标识码
     * @note
     */
    virtual PDV_RESULT SetBitMask(DftUInt8 iBitMask) = 0;

    /**
     * @brief 获取基本体类型
     * @return DftUInt8 基本体的类型  详见 PrimityType
     * @note 1：长方体 2：圆柱体 3：圆台（含圆锥）4：圆环 5：扇环体 6：球体 7： 球冠
     */
    virtual DftUInt8 GetType() = 0;
    
    /**
     * @brief 设置基本体的类型
     * @return PDV_RESULT
     * @param[in] iType 基本体的类型
     * @note
     */
    virtual PDV_RESULT SetType(DftUInt8 iType) = 0;
    
    /**
      * @brief 获取基本体的材质ID
      * @return DftUInt64 基本体的材质ID
      * @note
      */
    virtual DftUInt64 GetMaterialID() = 0;
    
    /**
      * @brief 设置基本体的材质ID
      * @return PDV_RESULT
      * @param[in] iMaterialID 基本体的材质ID
      * @note
      */
    virtual PDV_RESULT SetMaterialID(DftUInt64 iMaterialID) = 0;
    
    /**
      * @brief 基本体的变换信息
      * @return PDV_RESULT
      * @param[out] oTransformation 返回变换信息
      * @note
      */
    virtual PDV_RESULT GetTransformation(PDVMatrix4F& oTransformation) = 0;
    
    /**
      * @brief 基本体的变换信息
      * @return PDV_RESULT
      * @param[in] iTransformation 变换信息
      * @note
      */
    virtual PDV_RESULT SetTransformation(const PDVMatrix4F& iTransformation) = 0;

    /**
      * @brief 基本体为长方体时的信息
      * @return PDV_RESULT
      * @param[out] oPrimityData 返回长方体信息
      * @note
      */
    virtual PDV_RESULT GetCubiodData(CuboidPrimityData &oPrimityData) = 0;

    /**
      * @brief 基本体为长方体时的信息
      * @return PDV_RESULT
      * @param[in] iPrimityData 长方体信息
      * @note
      */
    virtual PDV_RESULT SetCubiodData(const CuboidPrimityData &iPrimityData) = 0;

    /**
      * @brief 基本体为圆柱体时的信息
      * @return PDV_RESULT
      * @param[out] oPrimityData 返回圆柱体信息
      * @note
      */
    virtual PDV_RESULT GetCylinderData(CylinderPrimityData &oPrimityData) = 0;

    /**
      * @brief 基本体为圆柱体时的信息
      * @return PDV_RESULT
      * @param[in] iPrimityData 圆柱体信息
      * @note
      */
    virtual PDV_RESULT SetCylinderData(const CylinderPrimityData &iPrimityData) = 0;

    /**
      * @brief 基本体为圆台体时的信息
      * @return PDV_RESULT
      * @param[out] oPrimityData 返回圆台体信息
      * @note
      */
    virtual PDV_RESULT GetConeData(ConePrimityData &oPrimityData) = 0;

    /**
      * @brief 基本体为圆台体时的信息
      * @return PDV_RESULT
      * @param[in] iPrimityData 圆台体信息
      * @note
      */
    virtual PDV_RESULT SetConeData(const ConePrimityData &iPrimityData) = 0;

    /**
      * @brief 基本体为圆环体时的信息
      * @return PDV_RESULT
      * @param[out] oPrimityData 返回圆环体信息
      * @note
      */
    virtual PDV_RESULT GetTorusData(TorusPrimityData &oPrimityData) = 0;

    /**
      * @brief 基本体为圆环体时的信息
      * @return PDV_RESULT
      * @param[in] iPrimityData 圆环体信息
      * @note
      */
    virtual PDV_RESULT SetTorusData(const TorusPrimityData &iPrimityData) = 0;

    /**
      * @brief 基本体为扇环体时的信息
      * @return PDV_RESULT
      * @param[out] oPrimityData 返回扇环体信息
      * @note
      */
    virtual PDV_RESULT GetFanData(FanPrimityData &oPrimityData) = 0;

    /**
      * @brief 基本体为扇环体时的信息
      * @return PDV_RESULT
      * @param[in] iPrimityData 扇环体信息
      * @note
      */
    virtual PDV_RESULT SetFanData(const FanPrimityData &iPrimityData) = 0;

    /**
      * @brief 基本体为球体时的信息
      * @return PDV_RESULT
      * @param[out] oPrimityData 返回球体信息
      * @note
      */
    virtual PDV_RESULT GetSphereData(SpherePrimityData &oPrimityData) = 0;

    /**
      * @brief 基本体为球体时的信息
      * @return PDV_RESULT
      * @param[in] iPrimityData 球体信息
      * @note
      */
    virtual PDV_RESULT SetSphereData(const SpherePrimityData &iPrimityData) = 0;

    /**
      * @brief 基本体为球冠体时的信息
      * @return PDV_RESULT
      * @param[out] oPrimityData 返回球冠体信息
      * @note
      */
    virtual PDV_RESULT GetSphCrownData(SphCrownPrimityData& oPrimityData) = 0;

    /**
      * @brief 基本体为球冠体时的信息
      * @return PDV_RESULT
      * @param[in] iPrimityData 球冠体信息
      * @note
      */
    virtual PDV_RESULT SetSphCrownData(const SphCrownPrimityData& iPrimityData) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
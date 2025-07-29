/**
 * @file PDVMath.h
 * @author zhangheng
 * @version 1.0
 * @date 2025-02-20
 * @brief 概述：定义库中的基本数据类型
 * @details 详细说明
 */

#ifndef PDV_PDVMath_H
#define PDV_PDVMath_H

#include "DftBase.h"
#include <stdlib.h>
#include <string>

#ifdef _MSC_VER
#ifdef PDVCORE_EXPORTS
#define PDVMATH_API __declspec(dllexport)
#else
#define PDVMATH_API __declspec(dllimport)
#endif
#else
#define PDVMATH_API
#include <string.h>
#endif

/** @brief 整数二维向量 */
struct PDVMATH_API PDVVector2I
{
    DftInt _data[2]; ///< 向量数据
    /** 构造函数 */
    PDVVector2I() { memset(_data, 0, sizeof(_data)); }
    /** 带参的构造函数 */
    PDVVector2I(DftInt x, DftInt y)
    {
        _data[0] = x;
        _data[1] = y;
    }
    /** 拷贝构造函数 */
    PDVVector2I(const PDVVector2I& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVVector2I(const DftInt* input) { memcpy(_data, input, sizeof(_data)); }

    /** [] 运算符重载 */
    DftInt& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftInt& operator[](DftInt index) const { return _data[index]; }

    /** = 运算符重载 */
    PDVVector2I& operator=(const PDVVector2I& other)
    {
        if (this != &other)
        {
            _data[0] = other._data[0];
            _data[1] = other._data[1];
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVVector2I& other) const;
    /** 转换为 DftInt 数组 */
    operator DftInt*() { return (DftInt*)&_data[0]; }
    /** 转换为 DftInt 数组 */
    operator const DftInt*() const { return (const DftInt*)&_data[0]; }

    /** 访问 x 成员 */
    DftInt& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftInt& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftInt& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftInt& y() const { return _data[1]; }

    /** 零向量 */
    static const PDVVector2I& Zero();
    /** 单位 X 向量 */
    static const PDVVector2I& UnitX();
    /** 单位 Y 向量 */
    static const PDVVector2I& UnitY();

    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0;
        _data[1] = 0;
    }
    /** 设置为单位 X 向量 */
    void SetUnitX()
    {
        _data[0] = 1;
        _data[1] = 0;
    }
    /** 设置为单位 Y 向量 */
    void SetUnitY()
    {
        _data[0] = 0;
        _data[1] = 1;
    }
};

/** @brief 单精度浮点数三维向量 */
struct PDVMATH_API PDVVector3I
{
    DftInt _data[3]; ///< 向量数据

    /** 构造函数 */
    PDVVector3I() { memset(_data, 0, sizeof(_data)); }

    /** 带参数的构造函数 */
    PDVVector3I(DftInt x, DftInt y, DftInt z)
    {
        _data[0] = x;
        _data[1] = y;
        _data[2] = z;
    }
    /** 拷贝构造函数 */
    PDVVector3I(const PDVVector3I& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVVector3I(const DftInt* input) { memcpy(_data, input, sizeof(_data)); }

    /** [] 运算符重载 */
    DftInt& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftInt& operator[](DftInt index) const { return _data[index]; }

    /** = 运算符重载 */
    PDVVector3I& operator=(const PDVVector3I& other)
    {
        if (this != &other)
        {
            _data[0] = other._data[0];
            _data[1] = other._data[1];
            _data[2] = other._data[2];
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVVector3I& other) const;

    /** 转换为 DftInt 数组 */
    operator DftInt*() { return (DftInt*)&_data[0]; }
    /** 转换为 DftInt 数组 */
    operator const DftInt*() const { return (const DftInt*)&_data[0]; }

    /** 访问 x 成员 */
    DftInt& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftInt& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftInt& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftInt& y() const { return _data[1]; }

    /** 访问 z 成员 */
    DftInt& z() { return _data[2]; }

    /** 访问 z 成员 */
    const DftInt& z() const { return _data[2]; }
    /** 零向量 */
    static const PDVVector3I& Zero();
    /** 单位 X 向量 */
    static const PDVVector3I& UnitX();
    /** 单位 Y 向量 */
    static const PDVVector3I& UnitY();
    /** 单位 Z 向量 */
    static const PDVVector3I& UnitZ();

    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0;
        _data[1] = 0;
        _data[2] = 0;
    }

    /** 设置为单位 X 向量 */
    void SetUnitX()
    {
        _data[0] = 1;
        _data[1] = 0;
        _data[2] = 0;
    }

    /** 设置为单位 Y 向量 */
    void SetUnitY()
    {
        _data[0] = 0;
        _data[1] = 1;
        _data[2] = 0;
    }

    /** 设置为单位 Z 向量 */
    void SetUnitZ()
    {
        _data[0] = 0;
        _data[1] = 0;
        _data[2] = 1;
    }
};

/** @brief 整数四维向量 */
struct PDVMATH_API PDVVector4I
{
    DftInt _data[4]; ///<向量数据
    /** 构造函数 */
    PDVVector4I() { memset(_data, 0, sizeof(_data)); }
    /** 带参数的构造函数 */
    PDVVector4I(DftInt x, DftInt y, DftInt z, DftInt w)
    {
        _data[0] = x;
        _data[1] = y;
        _data[2] = z;
        _data[3] = w;
    }
    /** 拷贝构造函数 */
    PDVVector4I(const PDVVector4I& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVVector4I(const DftInt* input) { memcpy(_data, input, sizeof(_data)); }
    /** = 运算符重载 */
    PDVVector4I& operator=(const PDVVector4I& other)
    {
        if (this != &other)
        {
            memcpy(_data, other._data, sizeof(_data));
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVVector4I& other) const;
    /** [] 运算符重载 */
    DftInt& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftInt& operator[](DftInt index) const { return _data[index]; }
    /** 转换为 DftInt 数组 */
    operator DftInt*() { return (DftInt*)&_data[0]; }
    /** 转换为 DftInt 数组 */
    operator const DftInt*() const { return (const DftInt*)&_data[0]; }

    /** 访问 x 成员 */
    DftInt& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftInt& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftInt& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftInt& y() const { return _data[1]; }

    /** 访问 z 成员 */
    DftInt& z() { return _data[2]; }

    /** 访问 z 成员 */
    const DftInt& z() const { return _data[2]; }

    /** 访问 w 成员 */
    DftInt& w() { return _data[3]; }

    /** 访问 w 成员 */
    const DftInt& w() const { return _data[3]; }

    /** 零向量 */
    static const PDVVector4I& Zero();

    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0;
        _data[1] = 0;
        _data[2] = 0;
        _data[3] = 0;
    }
};

/** @brief 单精度浮点数二维向量 */
struct PDVMATH_API PDVVector2F
{
    DftVector2F _data; ///< 向量数据

    /** 构造函数 */
    PDVVector2F() { memset(_data, 0, sizeof(_data)); }
    /** 带参数的构造函数 */
    PDVVector2F(DftFloat x, DftFloat y)
    {
        _data[0] = x;
        _data[1] = y;
    }
    /** 拷贝构造函数 */
    PDVVector2F(const PDVVector2F& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVVector2F(const DftFloat* input) { memcpy(_data, input, sizeof(_data)); }

    /** [] 运算符重载 */
    DftFloat& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftFloat& operator[](DftInt index) const { return _data[index]; }

    /** = 运算符重载 */
    PDVVector2F& operator=(const PDVVector2F& other)
    {
        if (this != &other)
        {
            _data[0] = other._data[0];
            _data[1] = other._data[1];
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVVector2F& other) const;
    /** 转换为 DftFloat 数组 */
    operator DftFloat*() { return (DftFloat*)&_data[0]; }
    /** 转换为 DftFloat 数组 */
    operator const DftFloat*() const { return (const DftFloat*)&_data[0]; }

    /** 访问 x 成员 */
    DftFloat& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftFloat& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftFloat& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftFloat& y() const { return _data[1]; }

    /** 零向量 */
    static const PDVVector2F& Zero();
    /** 单位 X 向量 */
    static const PDVVector2F& UnitX();
    /** 单位 Y 向量 */
    static const PDVVector2F& UnitY();
    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0.0f;
        _data[1] = 0.0f;
    }
    /** 设置为单位 X 向量 */
    void SetUnitX()
    {
        _data[0] = 1.0f;
        _data[1] = 0.0f;
    }
    /** 设置为单位 Y 向量 */
    void SetUnitY()
    {
        _data[0] = 0.0f;
        _data[1] = 1.0f;
    }

    /** 长度 */
    DftFloat Length() const;
    /** 单位化 */
    void Normalize();

    /** 相加 */
    friend PDVMATH_API PDVVector2F operator+(const PDVVector2F& iVector1, const PDVVector2F& iVector2);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVVector2F& ioVector1, const PDVVector2F& iVector2);
    /** 相减 */
    friend PDVMATH_API PDVVector2F operator-(const PDVVector2F& iVector1, const PDVVector2F& iVector2);
    /** 相减 */
    friend PDVMATH_API void operator-=(PDVVector2F& ioVector1, const PDVVector2F& iVector2);
    /** 负号 */
    friend PDVMATH_API PDVVector2F operator-(const PDVVector2F& iVector);
    /** 缩放 */
    friend PDVMATH_API PDVVector2F operator*(const PDVVector2F& iVector, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API PDVVector2F operator*(DftFloat iScale, const PDVVector2F& iVector);
    /** 缩放 */
    friend PDVMATH_API void operator*=(PDVVector2F& iVector, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API PDVVector2F operator/(const PDVVector2F& iVector, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API void operator/=(PDVVector2F& iVector, DftFloat iScale);
    /** 点乘 */
    friend PDVMATH_API DftFloat operator*(const PDVVector2F& iVector1, const PDVVector2F& iVector2);
};

/** @brief 单精度浮点数二维点 */
struct PDVMATH_API PDVPoint2F
{
    DftPoint2F _data;  ///< 数据

    /** 构造函数 */
    PDVPoint2F() { memset(_data, 0, sizeof(_data)); }
    /** 带参数的构造函数 */
    PDVPoint2F(DftFloat x, DftFloat y)
    {
        _data[0] = x;
        _data[1] = y;
    }
    /** 拷贝构造函数 */
    PDVPoint2F(const PDVPoint2F& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVPoint2F(const DftFloat* input) { memcpy(_data, input, sizeof(_data)); }

    /** [] 运算符重载 */
    DftFloat& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftFloat& operator[](DftInt index) const { return _data[index]; }

    /** = 运算符重载 */
    PDVPoint2F& operator=(const PDVPoint2F& other)
    {
        if (this != &other)
        {
            _data[0] = other._data[0];
            _data[1] = other._data[1];
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVPoint2F& other) const;
    /** 转换为 DftFloat 数组 */
    operator DftFloat*() { return (DftFloat*)&_data[0]; }
    /** 转换为 DftFloat 数组 */
    operator const DftFloat*() const { return (const DftFloat*)&_data[0]; }

    /** 访问 x 成员 */
    DftFloat& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftFloat& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftFloat& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftFloat& y() const { return _data[1]; }

    /** 零向量 */
    static const PDVPoint2F& Zero();
    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0.0f;
        _data[1] = 0.0f;
    }

    /** 相加 */
    friend PDVMATH_API PDVPoint2F operator+(const PDVPoint2F& iPoint, const PDVVector2F& iVector);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVPoint2F& ioPoint, const PDVVector2F& iVector);
    /** 相加 */
    friend PDVMATH_API PDVPoint2F operator+(const PDVPoint2F& iPoint1, const PDVPoint2F& iPoint2);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVPoint2F& ioPoint1, const PDVPoint2F& iPoint2);
    /** 相减 */
    friend PDVMATH_API PDVPoint2F operator-(const PDVPoint2F& iPoint, const PDVVector2F& iVector);
    /** 相减 */
    friend PDVMATH_API void operator-=(PDVPoint2F& ioPoint, const PDVVector2F& iVector);
    /** 相减 */
    friend PDVMATH_API PDVVector2F operator-(const PDVPoint2F& iPoint1, const PDVPoint2F& iPoint2);
    /** 负号 */
    friend PDVMATH_API PDVPoint2F operator-(const PDVPoint2F& iPoint);
    /** 缩放 */
    friend PDVMATH_API PDVPoint2F operator*(const PDVPoint2F& iPoint, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API PDVPoint2F operator*(DftFloat iScale, const PDVPoint2F& iPoint);
    /** 缩放 */
    friend PDVMATH_API void operator*=(PDVPoint2F& iPoint, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API PDVPoint2F operator/(const PDVPoint2F& iPoint, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API void operator/=(PDVPoint2F& iPoint, DftFloat iScale);
};

/** @brief 单精度浮点数三维向量 */
struct PDVMATH_API PDVVector3F
{
    DftVector3F _data;  ///< 向量数据

    /** 构造函数 */
    PDVVector3F() { memset(_data, 0, sizeof(_data)); }
    /** 带参数的构造函数 */
    PDVVector3F(DftFloat x, DftFloat y, DftFloat z)
    {
        _data[0] = x;
        _data[1] = y;
        _data[2] = z;
    }
    /** 拷贝构造函数 */
    PDVVector3F(const PDVVector3F& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVVector3F(const DftFloat* input) { memcpy(_data, input, sizeof(_data)); }

    /** [] 运算符重载 */
    DftFloat& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftFloat& operator[](DftInt index) const { return _data[index]; }

    /** = 运算符重载 */
    PDVVector3F& operator=(const PDVVector3F& other)
    {
        if (this != &other)
        {
            _data[0] = other._data[0];
            _data[1] = other._data[1];
            _data[2] = other._data[2];
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVVector3F& other) const;

    /** 转换为 DftFloat 数组 */
    operator DftFloat*() { return (DftFloat*)&_data[0]; }
    /** 转换为 DftFloat 数组 */
    operator const DftFloat*() const { return (const DftFloat*)&_data[0]; }

    /** 访问 x 成员 */
    DftFloat& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftFloat& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftFloat& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftFloat& y() const { return _data[1]; }

    /** 访问 z 成员 */
    DftFloat& z() { return _data[2]; }

    /** 访问 z 成员 */
    const DftFloat& z() const { return _data[2]; }

    /** 零向量 */
    static const PDVVector3F& Zero();
    /** 单位 X 向量 */
    static const PDVVector3F& UnitX();
    /** 单位 Y 向量 */
    static const PDVVector3F& UnitY();
    /** 单位 Z 向量 */
    static const PDVVector3F& UnitZ();

    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0.0f;
        _data[1] = 0.0f;
        _data[2] = 0.0f;
    }
    /** 设置为单位 X 向量 */
    void SetUnitX()
    {
        _data[0] = 1.0f;
        _data[1] = 0.0f;
        _data[2] = 0.0f;
    }
    /** 设置为单位 Y 向量 */
    void SetUnitY()
    {
        _data[0] = 0.0f;
        _data[1] = 1.0f;
        _data[2] = 0.0f;
    }
    /** 设置为单位 Z 向量 */
    void SetUnitZ()
    {
        _data[0] = 0.0f;
        _data[1] = 0.0f;
        _data[2] = 1.0f;
    }

    /** 长度 */
    DftFloat Length() const;
    /** 单位化 */
    void Normalize();

    /** 相加 */
    friend PDVMATH_API PDVVector3F operator+(const PDVVector3F& iVector1, const PDVVector3F& iVector2);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVVector3F& ioVector1, const PDVVector3F& iVector2);
    /** 相减 */
    friend PDVMATH_API PDVVector3F operator-(const PDVVector3F& iVector1, const PDVVector3F& iVector2);
    /** 相减 */
    friend PDVMATH_API void operator-=(PDVVector3F& ioVector1, const PDVVector3F& iVector2);
    /** 负号 */
    friend PDVMATH_API PDVVector3F operator-(const PDVVector3F& iVector);
    /** 缩放 */
    friend PDVMATH_API PDVVector3F operator*(const PDVVector3F& iVector, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API PDVVector3F operator*(DftFloat iScale, const PDVVector3F& iVector);
    /** 缩放 */
    friend PDVMATH_API void operator*=(PDVVector3F& iVector, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API PDVVector3F operator/(const PDVVector3F& iVector, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API void operator/=(PDVVector3F& iVector, DftFloat iScale);
    /** 点乘 */
    friend PDVMATH_API DftFloat operator*(const PDVVector3F& iVector1, const PDVVector3F& iVector2);
    /** 叉乘 */
    friend PDVMATH_API PDVVector3F operator^(const PDVVector3F& iVector1, const PDVVector3F& iVector2);
};

/** @brief 单精度浮点数三维点 */
struct PDVMATH_API PDVPoint3F
{
    DftPoint3F _data;  ///< 数据

    /** 构造函数 */
    PDVPoint3F() { memset(_data, 0, sizeof(_data)); }
    /** 带参数的构造函数 */
    PDVPoint3F(DftFloat x, DftFloat y, DftFloat z)
    {
        _data[0] = x;
        _data[1] = y;
        _data[2] = z;
    }
    /** 拷贝构造函数 */
    PDVPoint3F(const PDVPoint3F& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVPoint3F(const DftFloat* input) { memcpy(_data, input, sizeof(_data)); }

    /** [] 运算符重载 */
    DftFloat& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftFloat& operator[](DftInt index) const { return _data[index]; }

    /** = 运算符重载 */
    PDVPoint3F& operator=(const PDVPoint3F& other)
    {
        if (this != &other)
        {
            _data[0] = other._data[0];
            _data[1] = other._data[1];
            _data[2] = other._data[2];
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVPoint3F& other) const;
    /** 转换为 DftFloat 数组 */
    operator DftFloat*() { return (DftFloat*)&_data[0]; }
    /** 转换为 DftFloat 数组 */
    operator const DftFloat*() const { return (const DftFloat*)&_data[0]; }

    /** 访问 x 成员 */
    DftFloat& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftFloat& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftFloat& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftFloat& y() const { return _data[1]; }

    /** 访问 z 成员 */
    DftFloat& z() { return _data[2]; }

    /** 访问 z 成员 */
    const DftFloat& z() const { return _data[2]; }
    /** 零向量 */
    static const PDVPoint3F& Zero();
    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0.0f;
        _data[1] = 0.0f;
        _data[2] = 0.0f;
    }

    /** 相加 */
    friend PDVMATH_API PDVPoint3F operator+(const PDVPoint3F& iPoint, const PDVVector3F& iVector);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVPoint3F& ioPoint, const PDVVector3F& iVector);
    /** 相加 */
    friend PDVMATH_API PDVPoint3F operator+(const PDVPoint3F& iPoint1, const PDVPoint3F& iPoint2);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVPoint3F& ioPoint1, const PDVPoint3F& iPoint2);
    /** 相减 */
    friend PDVMATH_API PDVPoint3F operator-(const PDVPoint3F& iPoint, const PDVVector3F& iVector);
    /** 相减 */
    friend PDVMATH_API void operator-=(PDVPoint3F& ioPoint, const PDVVector3F& iVector);
    /** 相减 */
    friend PDVMATH_API PDVVector3F operator-(const PDVPoint3F& iPoint1, const PDVPoint3F& iPoint2);
    /** 负号 */
    friend PDVMATH_API PDVPoint3F operator-(const PDVPoint3F& iPoint);
    /** 缩放 */
    friend PDVMATH_API PDVPoint3F operator*(const PDVPoint3F& iPoint, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API PDVPoint3F operator*(DftFloat iScale, const PDVPoint3F& iPoint);
    /** 缩放 */
    friend PDVMATH_API void operator*=(PDVPoint3F& iPoint, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API PDVPoint3F operator/(const PDVPoint3F& iPoint, DftFloat iScale);
    /** 缩放 */
    friend PDVMATH_API void operator/=(PDVPoint3F& iPoint, DftFloat iScale);
};

/** @brief 单精度浮点数四维向量 */
struct PDVMATH_API PDVVector4F
{
    DftVector4F _data; ///< 向量数据
    /** 构造函数 */
    PDVVector4F() { memset(_data, 0, sizeof(_data)); }
    /** 带参数的构造函数 */
    PDVVector4F(DftFloat x, DftFloat y, DftFloat z, DftFloat w)
    {
        _data[0] = x;
        _data[1] = y;
        _data[2] = z;
        _data[3] = w;
    }
    /** 拷贝构造函数 */
    PDVVector4F(const PDVVector4F& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVVector4F(const DftFloat* input) { memcpy(_data, input, sizeof(_data)); }
    /** = 运算符重载 */
    PDVVector4F& operator=(const PDVVector4F& other)
    {
        if (this != &other)
        {
            memcpy(_data, other._data, sizeof(_data));
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVVector4F& other) const;
    /** [] 运算符重载 */
    DftFloat& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftFloat& operator[](DftInt index) const { return _data[index]; }
    /** 转换为 DftFloat 数组 */
    operator DftFloat*() { return (DftFloat*)&_data[0]; }
    /** 转换为 DftFloat 数组 */
    operator const DftFloat*() const { return (const DftFloat*)&_data[0]; }

    /** 访问 x 成员 */
    DftFloat& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftFloat& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftFloat& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftFloat& y() const { return _data[1]; }

    /** 访问 z 成员 */
    DftFloat& z() { return _data[2]; }

    /** 访问 z 成员 */
    const DftFloat& z() const { return _data[2]; }

    /** 访问 w 成员 */
    DftFloat& w() { return _data[3]; }

    /** 访问 w 成员 */
    const DftFloat& w() const { return _data[3]; }
    /** 零向量 */
    static const PDVVector4F& Zero();
    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0.0f;
        _data[1] = 0.0f;
        _data[2] = 0.0f;
        _data[3] = 0.0f;
    }
};

/** @brief 单精度浮点数4X4矩阵 */
struct PDVMATH_API PDVMatrix4F
{
    DftMatrix4F _data;  ///< 矩阵数据
    /** 构造函数 */
    PDVMatrix4F() { memset(_data, 0, sizeof(_data)); }
    /** 从指针构造 */
    PDVMatrix4F(const DftFloat* input) { memcpy(_data, input, sizeof(_data)); }
    /** 拷贝构造函数 */
    PDVMatrix4F(const PDVMatrix4F& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** = 运算符重载 */
    PDVMatrix4F& operator=(const PDVMatrix4F& other)
    {
        if (this != &other)
        {
            memcpy(_data, other._data, sizeof(_data));
        }
        return *this;
    }

    /** [] 运算符重载用于访问矩阵的行 */
    DftFloat* operator[](DftInt row) { return _data[row]; }
    /** [] 运算符重载用于访问矩阵的行 */
    const DftFloat* operator[](DftInt row) const { return _data[row]; }
    /** 用于map的key比较排序 */
    bool operator<(const PDVMatrix4F& other) const;
    /** 单位矩阵 */
    static const PDVMatrix4F& Identity();

    /** 设置为单位矩阵 */
    void SetIdentity()
    {
        memset(_data, 0, sizeof(_data));
        for (DftInt i = 0; i < 4; ++i)
        {
            _data[i][i] = 1.0f;
        }
    }

    /** 逆矩阵 */
    void Inverse();
    /** 转置 */
    void Transpose();
    /** 相乘 */
    friend PDVMATH_API PDVMatrix4F operator*(const PDVMatrix4F& iMatrix1, const PDVMatrix4F& iMatrix2);
    /** 相等 */
    DftBool IsEqual(const PDVMatrix4F& other) const;
};

/** @brief 双精度浮点数二维向量 */
struct PDVMATH_API PDVVector2D
{
    DftVector2D _data;  ///< 向量数据

    /** 构造函数 */
    PDVVector2D() { memset(_data, 0, sizeof(_data)); }
    /** 带参数的构造函数 */
    PDVVector2D(DftDouble x, DftDouble y)
    {
        _data[0] = x;
        _data[1] = y;
    }
    /** 拷贝构造函数 */
    PDVVector2D(const PDVVector2D& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVVector2D(const DftDouble* input) { memcpy(_data, input, sizeof(_data)); }

    /** [] 运算符重载 */
    DftDouble& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftDouble& operator[](DftInt index) const { return _data[index]; }

    /** = 运算符重载 */
    PDVVector2D& operator=(const PDVVector2D& other)
    {
        if (this != &other)
        {
            _data[0] = other._data[0];
            _data[1] = other._data[1];
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVVector2D& other) const;
    /** 转换为 DftDouble 数组 */
    operator DftDouble*() { return (DftDouble*)&_data[0]; }
    /** 转换为 DftDouble 数组 */
    operator const DftDouble*() const { return (const DftDouble*)&_data[0]; }

    /** 访问 x 成员 */
    DftDouble& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftDouble& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftDouble& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftDouble& y() const { return _data[1]; }
    /** 零向量 */
    static const PDVVector2D& Zero();
    /** 单位 X 向量 */
    static const PDVVector2D& UnitX();
    /** 单位 Y 向量 */
    static const PDVVector2D& UnitY();
    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0.0;
        _data[1] = 0.0;
    }
    /** 设置为单位 X 向量 */
    void SetUnitX()
    {
        _data[0] = 1.0;
        _data[1] = 0.0;
    }
    /** 设置为单位 Y 向量 */
    void SetUnitY()
    {
        _data[0] = 0.0;
        _data[1] = 1.0;
    }

    /** 长度 */
    DftDouble Length() const;
    /** 单位化 */
    void Normalize();

    /** 相加 */
    friend PDVMATH_API PDVVector2D operator+(const PDVVector2D& iVector1, const PDVVector2D& iVector2);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVVector2D& ioVector1, const PDVVector2D& iVector2);
    /** 相减 */
    friend PDVMATH_API PDVVector2D operator-(const PDVVector2D& iVector1, const PDVVector2D& iVector2);
    /** 相减 */
    friend PDVMATH_API void operator-=(PDVVector2D& ioVector1, const PDVVector2D& iVector2);
    /** 负号 */
    friend PDVMATH_API PDVVector2D operator-(const PDVVector2D& iVector);
    /** 缩放 */
    friend PDVMATH_API PDVVector2D operator*(const PDVVector2D& iVector, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API PDVVector2D operator*(DftDouble iScale, const PDVVector2D& iVector);
    /** 缩放 */
    friend PDVMATH_API void operator*=(PDVVector2D& iVector, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API PDVVector2D operator/(const PDVVector2D& iVector, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API void operator/=(PDVVector2D& iVector, DftDouble iScale);
    /** 点乘 */
    friend PDVMATH_API DftDouble operator*(const PDVVector2D& iVector1, const PDVVector2D& iVector2);
};

/** @brief 双精度浮点数二维点 */
struct PDVMATH_API PDVPoint2D
{
    DftPoint2D _data; ///< 数据

    /** 构造函数 */
    PDVPoint2D() { memset(_data, 0, sizeof(_data)); }
    /** 带参数的构造函数 */
    PDVPoint2D(DftDouble x, DftDouble y)
    {
        _data[0] = x;
        _data[1] = y;
    }
    /** 拷贝构造函数 */
    PDVPoint2D(const PDVPoint2D& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVPoint2D(const DftDouble* input) { memcpy(_data, input, sizeof(_data)); }

    /** [] 运算符重载 */
    DftDouble& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftDouble& operator[](DftInt index) const { return _data[index]; }

    /** = 运算符重载 */
    PDVPoint2D& operator=(const PDVPoint2D& other)
    {
        if (this != &other)
        {
            _data[0] = other._data[0];
            _data[1] = other._data[1];
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVPoint2D& other) const;
    /** 转换为 DftDouble 数组 */
    operator DftDouble*() { return (DftDouble*)&_data[0]; }
    /** 转换为 DftDouble 数组 */
    operator const DftDouble*() const { return (const DftDouble*)&_data[0]; }

    /** 访问 x 成员 */
    DftDouble& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftDouble& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftDouble& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftDouble& y() const { return _data[1]; }
    /** 零向量 */
    static const PDVPoint2D& Zero();
    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0.0;
        _data[1] = 0.0;
    }

    /** 相加 */
    friend PDVMATH_API PDVPoint2D operator+(const PDVPoint2D& iPoint, const PDVVector2D& iVector);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVPoint2D& ioPoint, const PDVVector2D& iVector);
    /** 相加 */
    friend PDVMATH_API PDVPoint2D operator+(const PDVPoint2D& iPoint1, const PDVPoint2D& iPoint2);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVPoint2D& ioPoint1, const PDVPoint2D& iPoint2);
    /** 相减 */
    friend PDVMATH_API PDVPoint2D operator-(const PDVPoint2D& iPoint, const PDVVector2D& iVector);
    /** 相减 */
    friend PDVMATH_API void operator-=(PDVPoint2D& ioPoint, const PDVVector2D& iVector);
    /** 相减 */
    friend PDVMATH_API PDVVector2D operator-(const PDVPoint2D& iPoint1, const PDVPoint2D& iPoint2);
    /** 负号 */
    friend PDVMATH_API PDVPoint2D operator-(const PDVPoint2D& iPoint);
    /** 缩放 */
    friend PDVMATH_API PDVPoint2D operator*(const PDVPoint2D& iPoint, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API PDVPoint2D operator*(DftDouble iScale, const PDVPoint2D& iPoint);
    /** 缩放 */
    friend PDVMATH_API void operator*=(PDVPoint2D& iPoint, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API PDVPoint2D operator/(const PDVPoint2D& iPoint, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API void operator/=(PDVPoint2D& iPoint, DftDouble iScale);
};

/** @brief 双精度浮点数三维向量 */
struct PDVMATH_API PDVVector3D
{
    DftVector3D _data; ///< 向量数据

    /** 构造函数 */
    PDVVector3D() { memset(_data, 0, sizeof(_data)); }
    /** 带参数的构造函数 */
    PDVVector3D(DftDouble x, DftDouble y, DftDouble z)
    {
        _data[0] = x;
        _data[1] = y;
        _data[2] = z;
    }
    /** 拷贝构造函数 */
    PDVVector3D(const PDVVector3D& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVVector3D(const DftDouble* input) { memcpy(_data, input, sizeof(_data)); }

    /** [] 运算符重载 */
    DftDouble& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftDouble& operator[](DftInt index) const { return _data[index]; }

    /** = 运算符重载 */
    PDVVector3D& operator=(const PDVVector3D& other)
    {
        if (this != &other)
        {
            _data[0] = other._data[0];
            _data[1] = other._data[1];
            _data[2] = other._data[2];
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVVector3D& other) const;
    /** 转换为 DftDouble 数组 */
    operator DftDouble*() { return (DftDouble*)&_data[0]; }
    /** 转换为 DftDouble 数组 */
    operator const DftDouble*() const { return (const DftDouble*)&_data[0]; }

    /** 访问 x 成员 */
    DftDouble& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftDouble& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftDouble& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftDouble& y() const { return _data[1]; }

    /** 访问 z 成员 */
    DftDouble& z() { return _data[2]; }

    /** 访问 z 成员 */
    const DftDouble& z() const { return _data[2]; }
    /** 零向量 */
    static const PDVVector3D& Zero();
    /** 单位 X 向量 */
    static const PDVVector3D& UnitX();
    /** 单位 Y 向量 */
    static const PDVVector3D& UnitY();
    /** 单位 Z 向量 */
    static const PDVVector3D& UnitZ();
    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0.0;
        _data[1] = 0.0;
        _data[2] = 0.0;
    }
    /** 设置为单位 X 向量 */
    void SetUnitX()
    {
        _data[0] = 1.0;
        _data[1] = 0.0;
        _data[2] = 0.0;
    }
    /** 设置为单位 Y 向量 */
    void SetUnitY()
    {
        _data[0] = 0.0;
        _data[1] = 1.0;
        _data[2] = 0.0;
    }
    /** 设置为单位 Z 向量 */
    void SetUnitZ()
    {
        _data[0] = 0.0;
        _data[1] = 0.0;
        _data[2] = 1.0;
    }

    /** 长度 */
    DftDouble Length() const;
    /** 单位化 */
    void Normalize();

    /** 相加 */
    friend PDVMATH_API PDVVector3D operator+(const PDVVector3D& iVector1, const PDVVector3D& iVector2);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVVector3D& ioVector1, const PDVVector3D& iVector2);
    /** 相减 */
    friend PDVMATH_API PDVVector3D operator-(const PDVVector3D& iVector1, const PDVVector3D& iVector2);
    /** 相减 */
    friend PDVMATH_API void operator-=(PDVVector3D& ioVector1, const PDVVector3D& iVector2);
    /** 负号 */
    friend PDVMATH_API PDVVector3D operator-(const PDVVector3D& iVector);
    /** 缩放 */
    friend PDVMATH_API PDVVector3D operator*(const PDVVector3D& iVector, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API PDVVector3D operator*(DftDouble iScale, const PDVVector3D& iVector);
    /** 缩放 */
    friend PDVMATH_API void operator*=(PDVVector3D& iVector, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API PDVVector3D operator/(const PDVVector3D& iVector, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API void operator/=(PDVVector3D& iVector, DftDouble iScale);
    /** 点乘 */
    friend PDVMATH_API DftDouble operator*(const PDVVector3D& iVector1, const PDVVector3D& iVector2);
    /** 叉乘 */
    friend PDVMATH_API PDVVector3D operator^(const PDVVector3D& iVector1, const PDVVector3D& iVector2);
};

/** @brief 双精度浮点数三维点 */
struct PDVMATH_API PDVPoint3D
{
    DftPoint3D _data;  ///< 数据

    /** 构造函数 */
    PDVPoint3D() { memset(_data, 0, sizeof(_data)); }
    /** 带参数的构造函数 */
    PDVPoint3D(DftDouble x, DftDouble y, DftDouble z)
    {
        _data[0] = x;
        _data[1] = y;
        _data[2] = z;
    }
    /** 拷贝构造函数 */
    PDVPoint3D(const PDVPoint3D& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVPoint3D(const DftDouble* input) { memcpy(_data, input, sizeof(_data)); }

    /** [] 运算符重载 */
    DftDouble& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftDouble& operator[](DftInt index) const { return _data[index]; }

    /** = 运算符重载 */
    PDVPoint3D& operator=(const PDVPoint3D& other)
    {
        if (this != &other)
        {
            _data[0] = other._data[0];
            _data[1] = other._data[1];
            _data[2] = other._data[2];
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVPoint3D& other) const;
    /** 转换为 DftDouble 数组 */
    operator DftDouble*() { return (DftDouble*)&_data[0]; }
    /** 转换为 DftDouble 数组 */
    operator const DftDouble*() const { return (const DftDouble*)&_data[0]; }

    /** 访问 x 成员 */
    DftDouble& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftDouble& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftDouble& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftDouble& y() const { return _data[1]; }

    /** 访问 z 成员 */
    DftDouble& z() { return _data[2]; }

    /** 访问 z 成员 */
    const DftDouble& z() const { return _data[2]; }

    /** 零向量 */
    static const PDVPoint3D& Zero();

    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0.0;
        _data[1] = 0.0;
        _data[2] = 0.0;
    }

    /** 相加 */
    friend PDVMATH_API PDVPoint3D operator+(const PDVPoint3D& iPoint, const PDVVector3D& iVector);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVPoint3D& ioPoint, const PDVVector3D& iVector);
    /** 相加 */
    friend PDVMATH_API PDVPoint3D operator+(const PDVPoint3D& iPoint1, const PDVPoint3D& iPoint2);
    /** 相加 */
    friend PDVMATH_API void operator+=(PDVPoint3D& ioPoint1, const PDVPoint3D& iPoint2);
    /** 相减 */
    friend PDVMATH_API PDVPoint3D operator-(const PDVPoint3D& iPoint, const PDVVector3D& iVector);
    /** 相减 */
    friend PDVMATH_API void operator-=(PDVPoint3D& ioPoint, const PDVVector3D& iVector);
    /** 相减 */
    friend PDVMATH_API PDVVector3D operator-(const PDVPoint3D& iPoint1, const PDVPoint3D& iPoint2);
    /** 负号 */
    friend PDVMATH_API PDVPoint3D operator-(const PDVPoint3D& iPoint);
    /** 缩放 */
    friend PDVMATH_API PDVPoint3D operator*(const PDVPoint3D& iPoint, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API PDVPoint3D operator*(DftDouble iScale, const PDVPoint3D& iPoint);
    /** 缩放 */
    friend PDVMATH_API void operator*=(PDVPoint3D& iPoint, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API PDVPoint3D operator/(const PDVPoint3D& iPoint, DftDouble iScale);
    /** 缩放 */
    friend PDVMATH_API void operator/=(PDVPoint3D& iPoint, DftDouble iScale);
};

/** @brief 双精度浮点数四维向量 */
struct PDVMATH_API PDVVector4D
{
    DftVector4D _data;  ///< 向量数据
    /** 构造函数 */
    PDVVector4D() { memset(_data, 0, sizeof(_data)); }
    /** 带参数的构造函数 */
    PDVVector4D(DftDouble x, DftDouble y, DftDouble z, DftDouble w)
    {
        _data[0] = x;
        _data[1] = y;
        _data[2] = z;
        _data[3] = w;
    }
    /** 拷贝构造函数 */
    PDVVector4D(const PDVVector4D& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** 从指针构造 */
    PDVVector4D(const DftDouble* input) { memcpy(_data, input, sizeof(_data)); }
    /** = 运算符重载 */
    PDVVector4D& operator=(const PDVVector4D& other)
    {
        if (this != &other)
        {
            memcpy(_data, other._data, sizeof(_data));
        }
        return *this;
    }
    /** 相等 */
    DftBool IsEqual(const PDVVector4D& other) const;
    /** [] 运算符重载 */
    DftDouble& operator[](DftInt index) { return _data[index]; }
    /** [] 运算符重载 */
    const DftDouble& operator[](DftInt index) const { return _data[index]; }
    /** 转换为 DftInt 数组 */
    operator DftDouble*() { return (DftDouble*)&_data[0]; }
    /** 转换为 DftInt 数组 */
    operator const DftDouble*() const { return (const DftDouble*)&_data[0]; }

    /** 访问 x 成员 */
    DftDouble& x() { return _data[0]; }

    /** 访问 x 成员 */
    const DftDouble& x() const { return _data[0]; }

    /** 访问 y 成员 */
    DftDouble& y() { return _data[1]; }

    /** 访问 y 成员 */
    const DftDouble& y() const { return _data[1]; }

    /** 访问 z 成员 */
    DftDouble& z() { return _data[2]; }

    /** 访问 z 成员 */
    const DftDouble& z() const { return _data[2]; }

    /** 访问 w 成员 */
    DftDouble& w() { return _data[3]; }

    /** 访问 w 成员 */
    const DftDouble& w() const { return _data[3]; }
    /** 零向量 */
    static const PDVVector4D& Zero();
    /** 设置为零向量 */
    void SetZero()
    {
        _data[0] = 0.0;
        _data[1] = 0.0;
        _data[2] = 0.0;
        _data[3] = 0.0;
    }
};

/** @brief 双精度浮点数4X4矩阵 */
struct PDVMATH_API PDVMatrix4D
{
    DftMatrix4D _data; ///< 矩阵数据
    /** 构造函数 */
    PDVMatrix4D() { memset(_data, 0, sizeof(_data)); }
    /** 从指针构造 */
    PDVMatrix4D(const DftDouble* input) { memcpy(_data, input, sizeof(_data)); }
    /** 拷贝构造函数 */
    PDVMatrix4D(const PDVMatrix4D& other) { memcpy(_data, other._data, sizeof(_data)); }
    /** = 运算符重载 */
    PDVMatrix4D& operator=(const PDVMatrix4D& other)
    {
        if (this != &other)
        {
            memcpy(_data, other._data, sizeof(_data));
        }
        return *this;
    }

    /** [] 运算符重载用于访问矩阵的行 */
    DftDouble* operator[](DftInt row) { return _data[row]; }
    /** [] 运算符重载用于访问矩阵的行 */
    const DftDouble* operator[](DftInt row) const { return _data[row]; }
    /** 用于map的key比较排序 */
    bool operator<(const PDVMatrix4D& other) const;
    /** 单位矩阵 */
    static const PDVMatrix4D& Identity();

    /** 设置为单位矩阵 */
    void SetIdentity()
    {
        memset(_data, 0, sizeof(_data));
        for (DftInt i = 0; i < 4; ++i)
        {
            _data[i][i] = 1.0;
        }
    }

    /** 逆矩阵 */
    void Inverse();
    /** 转置 */
    void Transpose();
    /** 相乘 */
    friend PDVMATH_API PDVMatrix4D operator*(const PDVMatrix4D& iMatrix1, const PDVMatrix4D& iMatrix2);
    /** 相等 */
    DftBool IsEqual(const PDVMatrix4D& other) const;
};

#endif
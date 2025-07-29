/**
 * @file PDVAnnotationDef.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2025-03-05
 * @brief 概述：pdv标注数据定义
 * @details 详细说明：包括线框数据、图形数据等的定义
 */

#ifndef PDVANNOTATIONDEF_H
#define PDVANNOTATIONDEF_H

#include "PDVBase.h"

//===================================================================================================

struct cJSON;

namespace kernel
{

namespace pdv
{

/** @brief 线框数据标识 */
enum WireFrameBitMask
{
    WIRE_MASK_CLOSE = 0x0001,  ///< 闭合的线框，线框的首尾数据点应该被相连
    WIRE_MASK_FILLED = 0x0002, ///< 线框被填充表示
    WIRE_MASK_COLORED = 0x0004 ///< 线框包含颜色数据
};

/** @brief 线框数据 */
struct PDVCORE_API WireFrameData
{
    DftByte _bitMasks;                ///< 线框数据标识符，见WireFrameBitMask
    std::vector<PDVVector3F> _points; ///< 线框点集（表达经过一系列点的折线）
    RGBColor _color;                  ///< 线框的颜色

    /** 默认构造函数 */
    WireFrameData() { _bitMasks = 0; }
    /** 拷贝构造函数 */
    WireFrameData(const WireFrameData& iData)
    {
        _bitMasks = iData._bitMasks;
        _points = iData._points;
        _color = iData._color;
    }
    /** 赋值运算符 */
    WireFrameData& operator=(const WireFrameData& iData)
    {
        if (&iData != this)
        {
            _bitMasks = iData._bitMasks;
            _points = iData._points;
            _color = iData._color;
        }
        return *this;
    }
    /** 输出数据 */
    void Output(DftJson iJsonNode) const;
};

/** @brief 二维线框数据 */
struct PDVCORE_API WireFrame2DData
{
    DftByte _bitMasks;                ///< 线框数据标识符，见WireFrameBitMask
    std::vector<PDVVector2F> _points; ///< 线框点集（表达经过一系列点的折线）
    RGBColor _color;                  ///< 线框的颜色
    DftUInt8 _lineStyle;              ///< 线型，见LineStyle

    /** 默认构造函数 */
    WireFrame2DData()
    {
        _lineStyle = LINESTYLE_THIN_SOLID_LINE;
        _bitMasks = 0;
    }
    /** 拷贝构造函数 */
    WireFrame2DData(const WireFrame2DData& iData)
    {
        _bitMasks = iData._bitMasks;
        _points = iData._points;
        _color = iData._color;
        _lineStyle = iData._lineStyle;
    }
    /** 赋值运算符 */
    WireFrame2DData& operator=(const WireFrame2DData& iData)
    {
        if (&iData != this)
        {
            _bitMasks = iData._bitMasks;
            _points = iData._points;
            _color = iData._color;
            _lineStyle = iData._lineStyle;
        }
        return *this;
    }
    /** 输出数据 */
    void Output(DftJson iJsonNode) const;
};

/** @brief 标注图形数据 */
struct PDVCORE_API AnnotationGraphicData
{
    std::vector<PDVVector3F> _points;   ///< 顶点数据集
    std::vector<DftUInt> _pointIndexes; ///< 顶点索引集，代表顶点数据
    std::vector<DftUInt> _facetIndexes; ///< 三角形顶点索引集
    std::vector<WireFrameData> _wires;  ///< 线框数据（每个图元集合代表经过一系列点的折线）
    RGBColor _color;                    ///< 颜色
    DftUInt8 _transparency;             ///< 透明度，取值范围为[0,255]，0表示完全透明，255表示不透明，默认值为255

    /** 默认构造函数 */
    AnnotationGraphicData() { _transparency = 255; }
    /** 拷贝构造函数 */
    AnnotationGraphicData(const AnnotationGraphicData& iData)
    {
        _points = iData._points;
        _pointIndexes = iData._pointIndexes;
        _facetIndexes = iData._facetIndexes;
        _wires = iData._wires;
        _color = iData._color;
        _transparency = iData._transparency;
    }
    /** 赋值运算符 */
    AnnotationGraphicData& operator=(const AnnotationGraphicData& iData)
    {
        if (&iData != this)
        {
            _points = iData._points;
            _pointIndexes = iData._pointIndexes;
            _facetIndexes = iData._facetIndexes;
            _wires = iData._wires;
            _color = iData._color;
            _transparency = iData._transparency;
        }
        return *this;
    }
    /** 清空数据 */
    void Clear()
    {
        _points.clear();
        _pointIndexes.clear();
        _facetIndexes.clear();
        _wires.clear();
        _color._red = _color._green = _color._blue = 0;
        _transparency = 255;
    }
    /** 输出数据 */
    void Output(DftJson jsonNode) const;
};

} // namespace pdv

} // namespace kernel

#endif

/**
 * @file PDVIRenderVertex.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-02-24
 * @brief 概述：PDVIRenderVertex的接口声明
 * @details 详细说明
 */

#ifndef PDVIRENDERVERTEX_H
#define PDVIRENDERVERTEX_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{
/** @brief 顶点标识位定义 */
enum RenderVertexBitMask
{
    RENDER_VERTEX_MASK_NULL = 0,                ///< 未知
    RENDER_VERTEX_MASK_POSITION = 0x0001,       ///< 是否包含位置数据
    RENDER_VERTEX_MASK_NORMAL = 0x0002,         ///< 是否包含法线数据
    RENDER_VERTEX_MASK_UV = 0x0004,             ///< 是否包含UV数据
    RENDER_VERTEX_MASK_COLOR_OPACITY = 0x0008,  ///< 是否包含颜色信息数据
    RENDER_VERTEX_MASK_INDEX = 0x0080           ///< 是否包含索引数据
};

/** @brief 顶点数据结构定义 */
struct VertexData
{
    PDVVector3F _position;              ///< 顶点坐标数据
    PDVVector3F _normal;                ///< 顶点法向矢量数据，如果是点和线，则不包含该数据
    PDVVector2F _uv;                    ///< 顶点纹理数据，顺序存储矢量坐标的u/v分量，纹理坐标取值范围为[0-1]，如果是点和线，则不包含该数据
    RGBColor _color;                    ///< 颜色
    DftUInt8 _opacity;                  ///< 透明度
    DftUInt32 _index;                   ///< 索引

    /** 默认构造函数 */
    VertexData() { Clear(); }
    
    /** 拷贝构造函数 */
    VertexData(const VertexData& iData)
    {
        _position = iData._position;
        _normal = iData._normal;
        _uv = iData._uv;
        _color = iData._color;
        _opacity = iData._opacity;
        _index = iData._index;
    }

    /** 赋值运算符 */
    VertexData& operator=(const VertexData& iData)
    {
        if (&iData != this)
        {
            _position = iData._position;
            _normal = iData._normal;
            _uv = iData._uv;
            _color = iData._color;
            _opacity = iData._opacity;
            _index = iData._index;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _position.SetZero();
        _normal.SetZero();
        _uv.SetZero();
        _color = RGBColor();
        _opacity = 0;
        _index = 0;
    }
};

/** @brief 顶点数据的接口 */
class PDVCORE_API IRenderVertex : public IDataObject
{
public:
    /**
     * @brief 获取顶点个数
     * @return DftUInt 顶点个数
     * @note
     */
    virtual DftUInt GetVertexCount() const = 0;

    /**
     * @brief 获取顶点坐标数据
     * @return PDV_RESULT
     * @param[out] oVertexes 顶点坐标数据
     * @note
     */
    virtual PDV_RESULT GetVertexes(std::vector<VertexData> &oVertexes) = 0;

    /**
     * @brief 设置顶点坐标数据
     * @return PDV_RESULT
     * @param[in] iVertexes 顶点坐标数据
     * @note
     */
    virtual PDV_RESULT SetVertexes(const std::vector<VertexData> &iVertexes) = 0;

    /**
     * @brief 添加顶点坐标数据
     * @return PDV_RESULT
     * @param[in] iVertexes 顶点坐标数据
     * @note
     */
    virtual PDV_RESULT AddVertexes(const std::vector<VertexData>& iVertexes) = 0;

    /**
     * @brief 获取顶点坐标数据流
     * @return PDV_RESULT
     * @param[out] oVertexesBuffer 顶点坐标数据流
     * @param[out] oSize 顶点坐标数据个数
     * @note
     */
    virtual PDV_RESULT GetVertexesBuffer(DftByte*& oVertexesBuffer, DftUInt32& oSize) = 0;

    /**
     * @brief 设置顶点坐标数据流
     * @return PDV_RESULT
     * @param[in] iVertexesBuffer 顶点坐标数据流
     * @param[in] iSize 顶点坐标数据个数
     * @note
     */
    virtual PDV_RESULT SetVertexesBuffer(DftByte* iVertexesBuffer, DftUInt32 iSize) = 0;

    /**
     * @brief 获取标识位
     * @return DftUInt64 标识位
     * @note
     */
    virtual DftUInt8 GetVertexMask() = 0;

    /**
     * @brief 设置标识位
     * @return PDV_RESULT
     * @param[in] iVertexMask 标识位
     * @note
     */
    virtual PDV_RESULT SetVertexMask(const DftUInt8 &iVertexMask) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
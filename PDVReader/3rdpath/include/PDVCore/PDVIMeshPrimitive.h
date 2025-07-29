/**
 * @file PDVIMeshPrimitive.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：网格图元的接口声明
 * @details 详细说明
 */

#ifndef PDVIMESHPRIMITIVE_H
#define PDVIMESHPRIMITIVE_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

/** @brief 图元类型标识符 */
enum PrimitiveType
{
    PRIMITIVETYPE_NULL = 0,          ///< 未知
    PRIMITIVETYPE_POINTLIST = 1,     ///< 点图元
    PRIMITIVETYPE_LINELIST = 2,      ///< 线图元
    PRIMITIVETYPE_LINESTRIP = 3,     ///< 线段条带图元
    PRIMITIVETYPE_TRIANGLELIST = 4,  ///< 三角形图元
    PRIMITIVETYPE_TRIANGLESTRIP = 5, ///< 三角形带图元
    PRIMITIVETYPE_TRIANGLEFAN = 6,   ///< 三角形扇图元
    PRIMITIVETYPE_QUADLIST = 7,      ///< 四边形图元
    PRIMITIVETYPE_QUADSTRIP = 8,     ///< 四边形带图元
};

/** @brief 网格图元的接口 */
class PDVCORE_API IMeshPrimitive
{
public:
    /**
     * @brief 获取网格顶点数据
     * @return PDV_RESULT
     * @param[out] oPrimitiveType 图元类型
     * @param[out] oCoordIndexArray 顶点坐标索引数据
     * @param[out] oNormalIndexArray 顶点法向矢量索引数据
     * @param[out] oTextureIndexArray 顶点纹理索引数据
     * @note
     */
    virtual PDV_RESULT GetData(DftUInt& oPrimitiveType, std::vector<DftUInt>& oCoordIndexArray, std::vector<DftUInt>& oNormalIndexArray,
                               std::vector<DftUInt>& oTextureIndexArray) = 0;

    /**
     * @brief 设置网格顶点数据
     * @return PDV_RESULT
     * @param[in] iPrimitiveType 图元类型
     * @param[in] iCoordIndexArray 顶点坐标索引数据
     * @param[in] iNormalIndexArray 顶点法向矢量索引数据
     * @param[in] iTextureIndexArray 顶点纹理索引数据
     * @note
     */
    virtual PDV_RESULT SetData(DftUInt iPrimitiveType, const std::vector<DftUInt>& iCoordIndexArray, const std::vector<DftUInt>& iNormalIndexArray,
                               const std::vector<DftUInt>& iTextureIndexArray) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
/**
 * @file PDVIMeshVertex.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：网格顶点的接口声明
 * @details 详细说明
 */

#ifndef PDVIMESHVERTEX_H
#define PDVIMESHVERTEX_H

#include "PDVBase.h"
struct cJSON;

namespace kernel
{

namespace pdv
{

/** @brief 分析结果物理量类型 */
enum AnalysisQuantityType
{
    ANALYSIS_QUANTITY_TYPE_SCALAR = 1,  ///< 标量
    ANALYSIS_QUANTITY_TYPE_VECTOR = 2   ///< 矢量
};

/** @brief 分析结果物理量数据 */
struct PDVCORE_API AnalysisQuantity
{
    DftUInt8 _type;                    ///< 物理量的类型，见 AnalysisQuantityType
    CUnicodeString _name;               ///< 物理量的名称
    std::vector<DftFloat> _scalars;    ///< 顶点标量数据，类型为标量时有效
    std::vector<PDVVector3F> _vectors;     ///< 顶点矢量数据，类型为矢量时有效
    /** 默认构造函数 */
    AnalysisQuantity()
    {
        Clear();
    }
    /** 拷贝构造函数 */
    AnalysisQuantity(const AnalysisQuantity& iData)
    {
        _type = iData._type;
        _name = iData._name;
        _scalars = iData._scalars;
        _vectors = iData._vectors;
    }
    /** 赋值运算符 */
    AnalysisQuantity& operator=(const AnalysisQuantity& iData)
    {
        if (&iData != this)
        {
            _type = iData._type;
            _name = iData._name;
            _scalars = iData._scalars;
            _vectors = iData._vectors;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _type = 0;
        _name = DFT_L_CWCHAR("");
        _scalars.clear();
        _vectors.clear();
    }
    /** 输出数据 */
    void Output(DftJson iJsonNode) const;
};

/** @brief 分析结果物理量数据集 */
typedef std::vector<AnalysisQuantity> AnalysisQuantityArray;

/** @brief 网格顶点的接口 */
class PDVCORE_API IMeshVertex
{
public:
    /**
     * @brief 获取网格顶点坐标个数
     * @return DftUInt 网格顶点坐标个数
     * @note
     */
    virtual DftUInt GetCoordCount() = 0;

    /**
     * @brief 获取网格顶点法向矢量个数
     * @return DftUInt 网格顶点法向矢量个数
     * @note
     */
    virtual DftUInt GetNormalCount() = 0;

    /**
     * @brief 获取网格顶点纹理坐标个数
     * @return DftUInt 网格顶点纹理坐标个数
     * @note
     */
    virtual DftUInt GetTextureCount() = 0;

    /**
     * @brief 获取网格顶点坐标数据
     * @return std::vector< \ref PDVVector3F >& 网格顶点坐标数据的引用
     * @note
     */
    virtual std::vector<PDVVector3F>& GetCoordArray() = 0;

    /**
     * @brief 获取网格顶点法向矢量数据
     * @return std::vector< \ref PDVVector3F >& 网格网格顶点法向矢量数据的引用
     * @note
     */
    virtual std::vector<PDVVector3F>& GetNormalArray() = 0;

    /**
     * @brief 获取顶点纹理坐标数据
     * @return std::vector< \ref PDVVector2F >& 网格顶点纹理坐标数据的引用
     * @note
     */
    virtual std::vector<PDVVector2F>& GetTextureArray() = 0;

    /**
     * @brief 获取网格顶点数据
     * @return PDV_RESULT
     * @param[out] oCoordArray 网格顶点坐标数据
     * @param[out] oNormalArray 网格顶点法向矢量数据
     * @param[out] oTextureArray 网格顶点纹理坐标数据
     * @note
     */
    virtual PDV_RESULT GetData(std::vector<PDVVector3F>& oCoordArray, std::vector<PDVVector3F>& oNormalArray,
                               std::vector<PDVVector2F>& oTextureArray) = 0;

    /**
     * @brief 设置网格顶点数据
     * @return PDV_RESULT
     * @param[in] iCoordArray 网格顶点坐标数据
     * @param[in] iNormalArray 网格顶点法向矢量数据
     * @param[in] iTextureArray 网格顶点纹理坐标数据
     * @note
     */
    virtual PDV_RESULT SetData(const std::vector<PDVVector3F>& iCoordArray, const std::vector<PDVVector3F>& iNormalArray,
        const std::vector<PDVVector2F>& iTextureArray) = 0;

    /**
     * @brief 清空网格顶点数据
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT Clear() = 0;

    /**
     * @brief 添加网格顶点坐标数据
     * @return PDV_RESULT
     * @param[in] iCoordArray 网格顶点坐标数据
     * @note
     */
    virtual PDV_RESULT AddCoordArray(const std::vector<PDVVector3F> &iCoordArray) = 0;

    /**
     * @brief 添加网格顶点法向矢量数据
     * @return PDV_RESULT
     * @param[in] iNormalArray 网格顶点法向矢量数据
     * @note
     */
    virtual PDV_RESULT AddNormalArray(const std::vector<PDVVector3F> &iNormalArray) = 0;

    /**
     * @brief 添加网格顶点纹理坐标数据
     * @return PDV_RESULT
     * @param[in] iTextureArray 网格顶点纹理坐标数据
     * @note
     */
    virtual PDV_RESULT AddTextureArray(const std::vector<PDVVector2F> &iTextureArray) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
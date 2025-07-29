/**
 * @file PDVIAnalysisResult.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-2-24
 * @brief 概述：分析结果的接口声明
 * @details 详细说明
 */

#ifndef PDVIANALYSISRESULT_H
#define PDVIANALYSISRESULT_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 物理量标识数据 */
struct PhysicalQuantityIdentity
{
    DftUInt64 _physicalQuantityID; ///< 物理量ID
    CUnicodeString _name;          ///< 名称
    DftUInt8 _type;                ///< 类型，参见 PhysicalQuantityType
    DftUInt8 _primitiveType;       ///< 图元类型，参见 PhysicalQuantityPrimitiveType
    /** 默认构造函数 */
    PhysicalQuantityIdentity() { Clear(); }
    /** 拷贝构造函数 */
    PhysicalQuantityIdentity(const PhysicalQuantityIdentity& data)
    {
        _physicalQuantityID = data._physicalQuantityID;
        _name = data._name;
        _type = data._type;
        _primitiveType = data._primitiveType;
    }
    /** 赋值运算符 */
    PhysicalQuantityIdentity& operator=(const PhysicalQuantityIdentity& data)
    {
        if (&data != this)
        {
            _physicalQuantityID = data._physicalQuantityID;
            _name = data._name;
            _type = data._type;
            _primitiveType = data._primitiveType;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _physicalQuantityID = DFT_INVALID_ID;
        _name = DFT_L_CWCHAR("");
        _type = 0;
        _primitiveType = 0;
    }
};

/** @brief 物理量标识集 */
typedef std::vector<PhysicalQuantityIdentity> PhysicalQuantityIdentityArray;

/** @brief 分析物理量数据信息 */
struct AnalysisResultRenderData
{
    DftUInt64 _renderBodyID;                                   ///< 模型ID
    Statistics _statistics;                                    ///< 统计数据
    PhysicalQuantityIdentityArray _physicalQuantityIdentities; ///< 物理量标识数据
    /** 默认构造函数 */
    AnalysisResultRenderData() { Clear(); }
    /** 拷贝构造函数 */
    AnalysisResultRenderData(const AnalysisResultRenderData& data)
    {
        _renderBodyID = data._renderBodyID;
        _statistics = data._statistics;
        _physicalQuantityIdentities = data._physicalQuantityIdentities;
    }
    /** 赋值运算符 */
    AnalysisResultRenderData& operator=(const AnalysisResultRenderData& data)
    {
        if (&data != this)
        {
            _renderBodyID = data._renderBodyID;
            _statistics = data._statistics;
            _physicalQuantityIdentities = data._physicalQuantityIdentities;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _renderBodyID = DFT_INVALID_ID;
        _statistics = Statistics();
        _physicalQuantityIdentities.clear();
    }
};

/** @brief 分析结果项 */
typedef std::vector<AnalysisResultRenderData> AnalysisResultItem;

/** @brief 分析结果的接口 */
class PDVCORE_API IAnalysisResult : public IDataObject
{
public:
    /**
     * @brief 获取分析结果项列表
     * @return PDV_RESULT
     * @param[out] oAnalysisResultItems 分析结果项列表
     * @note
     */
    virtual PDV_RESULT GetAnalysisResultItems(std::vector<AnalysisResultItem>& oAnalysisResultItems) = 0;

    /**
     * @brief 设置分析结果项列表
     * @return PDV_RESULT
     * @param[in] iIAnalysisResultItem 分析结果项列表
     * @note
     */
    virtual PDV_RESULT SetAnalysisResultItems(const std::vector<AnalysisResultItem>& iAnalysisResultItems) = 0;

    /**
     * @brief 获取渲染主体列表
     * @return PDV_RESULT
     * @param[out] oRenderBodies 渲染主体列表
     * @note
     */
    virtual PDV_RESULT GetRenderBodies(std::vector<IRenderBody*>& oRenderBodies) = 0;

    /**
     * @brief 添加渲染主体
     * @return PDV_RESULT
     * @param[in] oNewBody 渲染主体列表
     * @note
     */
    virtual PDV_RESULT AddRenderBody(IRenderBody*& oNewBody) = 0;

    /**
     * @brief 清空渲染主体列表
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearRenderBodies() = 0;
};

} // namespace pdv

} // namespace kernel

#endif

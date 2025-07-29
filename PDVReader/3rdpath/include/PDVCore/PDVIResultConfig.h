/**
 * @file PDVIResultConfig.h
 * @author Ray.Yue
 * @version 1.0
 * @date 2025-2-24
 * @brief 概述：IResultConfig的接口声明
 * @details 详细说明
 */

#ifndef PDVIRESULTCONFIG_H
#define PDVIRESULTCONFIG_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{
    /** @brief 物理量区间信息 */
    struct QuantityConfig
    {
        CUnicodeString _name;            ///< 名称
        DftUInt8 _type;                 ///< 类型, 见 PhysicalQuantityType
        DftUInt8 _primitiveType;        ///< 图元类型，见 PhysicalQuantityPrimitiveType
        DftFloat _minValue;             ///< 最小值
        DftFloat _maxValue;             ///< 最大值
        /** 默认构造函数 */
        QuantityConfig()
        {
            Clear();
        }
        /** 拷贝构造函数 */
        QuantityConfig(const QuantityConfig& iData)
        {
            _name = iData._name;
            _type = iData._type;
            _primitiveType = iData._primitiveType;
            _minValue = iData._minValue;
            _maxValue = iData._maxValue;
        }
        /** 赋值运算符 */
        QuantityConfig& operator=(const QuantityConfig& iData)
        {
            if (&iData != this)
            {
                _name = iData._name;
                _type = iData._type;
                _primitiveType = iData._primitiveType;
                _minValue = iData._minValue;
                _maxValue = iData._maxValue;
            }
            return *this;
        }
        /** 清除数据 */
        void Clear()
        {
            _name = DFT_L_CWCHAR("");
            _type = 0;
            _primitiveType = 0;
            _minValue = _maxValue = 0.f;
        }
    };

/** @brief 物理量区间信息列表 */
typedef std::vector<QuantityConfig> QuantityConfigArray;

/** @brief 分析结果配置的接口 */
class PDVCORE_API IResultConfig : public IDataObject
{
public:

    /**
     * @brief 获取步骤动画个数
     * @return DftUInt32 步骤动画个数
     * @note
     */
    virtual DftUInt32 GetStepCount() = 0;

    /**
     * @brief 设置步骤动画个数
     * @return PDV_RESULT
     * @param[in] iStepCount 步骤动画个数
     * @note
     */
    virtual PDV_RESULT SetStepCount(const DftUInt32 iStepCount) = 0;

    /**
     * @brief 获取物理量范围列表
     * @return PDV_RESULT
     * @param[out] oQuantityConfigArray 物理量范围列表
     * @note
     */
    virtual PDV_RESULT GetQuantityConfigArray(QuantityConfigArray &oQuantityConfigArray) = 0;

    /**
     * @brief 设置物理量范围列表
     * @return PDV_RESULT
     * @param[in] iQuantityConfigArray 物理量范围列表
     * @note
     */
    virtual PDV_RESULT SetQuantityConfigArray(const QuantityConfigArray &iQuantityConfigArray) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
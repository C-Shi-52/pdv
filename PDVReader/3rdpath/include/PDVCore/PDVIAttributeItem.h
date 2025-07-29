/**
 * @file PDVIAttributeItem.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：属性项的接口声明
 * @details 详细说明
 */

#ifndef PDVIATTRIBUTEITEM_H
#define PDVIATTRIBUTEITEM_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

/** @brief 属性项值的数据类型 */
enum AttributeDataType
{
    DATATYPE_INT32 = 1,    ///< 整数类型
    DATATYPE_FLOAT = 2,    ///< 单精度浮点类型
    DATATYPE_DOUBLE = 3,   ///< 双精度浮点类型
    DATATYPE_STRING = 4,   ///< 字符串类型
    DATATYPE_VECTOR3F = 5, ///< 三维向量，单精度浮点类型
    DATATYPE_VECTOR3D = 6, ///< 三维向量，双精度浮点类型
    DATATYPE_BOOL = 7,     ///< 布尔类型
};

/** @brief 属性项的接口 */
class PDVCORE_API IAttributeItem
{
public:
    /**
     * @brief 获取属性项键值
     * @return PDV_RESULT
     * @param[out] oKey 属性项键值
     * @note
     */
    virtual PDV_RESULT GetKey(CUnicodeString &oKey) = 0;

    /**
     * @brief 设置属性项键值
     * @return PDV_RESULT
     * @param[in] iKey 属性项键值
     * @note
     */
    virtual PDV_RESULT SetKey(const CUnicodeString &iKey) = 0;

    /**
     * @brief 获取属性项值的数据类型
     * @return DftUInt 属性项值的数据类型，见 DataType
     * @note
     */
    virtual DftUInt GetValueType() = 0;

    /**
     * @brief 设置属性项值的数据类型
     * @return PDV_RESULT
     * @param[in] iValueType 属性项值的数据类型，见 DataType
     * @note
     */
    virtual PDV_RESULT SetValueType(const DftUInt &iValueType) = 0;

    /**
     * @brief 获取属性项的布尔值
     * @return PDV_RESULT
     * @param[out] oBoolean 属性项的布尔值
     * @note 如果属性项是布尔类型，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT GetBoolean(DftBool &oBoolean) = 0;

    /**
     * @brief 设置属性项的布尔值
     * @return PDV_RESULT
     * @param[in] iBoolean 属性项的布尔值
     * @note 如果属性项是布尔类型，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT SetBoolean(const DftBool &iBoolean) = 0;

    /**
     * @brief 获取属性项的整型值
     * @return PDV_RESULT
     * @param[out] oInteger 属性项的整型值
     * @note 如果属性项是整型，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT GetInteger(DftInt &oInteger) = 0;

    /**
     * @brief 设置属性项的整型值
     * @return PDV_RESULT
     * @param[in] iInteger 属性项的整型值
     * @note 如果属性项是整型，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT SetInteger(const DftInt &iInteger) = 0;

    /**
     * @brief 获取属性项的浮点数值
     * @return PDV_RESULT
     * @param[out] oFloat 属性项的浮点数值
     * @note 如果属性项是单精度浮点型，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT GetFloat(DftFloat &oFloat) = 0;

    /**
     * @brief 设置属性项的浮点数值
     * @return PDV_RESULT
     * @param[in] iFloat 属性项的浮点数值
     * @note 如果属性项是单精度浮点型，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT SetFloat(const DftFloat &iFloat) = 0;

    /**
     * @brief 获取属性项的双精度浮点数值
     * @return PDV_RESULT
     * @param[out] oDouble 属性项的双精度浮点数值
     * @note 如果属性项是双精度浮点型，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT GetDouble(DftDouble &oDouble) = 0;

    /**
     * @brief 设置属性项的双精度浮点数值
     * @return PDV_RESULT
     * @param[in] iDouble 属性项的双精度浮点数值
     * @note 如果属性项是双精度浮点型，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT SetDouble(const DftDouble &iDouble) = 0;

    /**
     * @brief 获取属性项的浮点数三维向量值
     * @return PDV_RESULT
     * @param[out] oVectorFloat3 属性项的浮点数三维向量值
     * @note 如果属性项是单精度浮点型三维向量，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT GetVectorFloat3(PDVVector3F &oVectorFloat3) = 0;

    /**
     * @brief 设置属性项的浮点数三维向量值
     * @return PDV_RESULT
     * @param[in] iVectorFloat3 属性项的浮点数三维向量值
     * @note 如果属性项是单精度浮点型三维向量，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT SetVectorFloat3(const PDVVector3F &iVectorFloat3) = 0;

    /**
     * @brief 获取属性项的双精度浮点数三维向量值
     * @return PDV_RESULT
     * @param[out] oVectorDouble3 属性项的双精度浮点数三维向量值
     * @note 如果属性项是双精度浮点型三维向量，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT GetVectorDouble3(PDVVector3D &oVectorDouble3) = 0;

    /**
     * @brief 设置属性项的双精度浮点数三维向量值
     * @return PDV_RESULT
     * @param[in] iVectorDouble3 属性项的双精度浮点数三维向量值
     * @note 如果属性项是双精度浮点型三维向量，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT SetVectorDouble3(const PDVVector3D &iVectorDouble3) = 0;

    /**
     * @brief 获取属性项的字符串值
     * @return PDV_RESULT
     * @param[out] oString 属性项的字符串值
     * @note 如果属性项是字符串，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT GetString(CUnicodeString &oString) = 0;

    /**
     * @brief 设置属性项的字符串值
     * @return PDV_RESULT
     * @param[in] iString 属性项的字符串值
     * @note 如果属性项是字符串，则返回 \ref PDV_RESULT_NO_ERROR ，否则返回 \ref PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR
     */
    virtual PDV_RESULT SetString(const CUnicodeString &iString) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
/**
 * @file PDVIAttributeGroup.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：属性组的接口声明
 * @details 详细说明
 */

#ifndef PDVIATTRIBUTEGROUP_H
#define PDVIATTRIBUTEGROUP_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

class IAttribute;
class IAttributeItem;

/** @brief 属性组的接口 */
class PDVCORE_API IAttributeGroup
{
public:
    /**
     * @brief 获取属性组对象唯一标识
     * @return DftUInt64 属性组对象唯一标识
     * @note
     */
    virtual DftUInt64 GetID() = 0;

    /**
     * @brief 获取属性组命名
     * @return PDV_RESULT
     * @param[out] oName 属性组命名
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString &oName) = 0;

    /**
     * @brief 设置属性组命名
     * @return PDV_RESULT
     * @param[in] iName 属性组命名
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString &iName) = 0;

    /**
     * @brief 获取所属属性对象
     * @return IAttribute * 所属属性对象
     * @note
     */
    virtual IAttribute* GetOwner() = 0;

    /**
     * @brief 增加布尔类型属性项
     * @return PDV_RESULT
     * @param[in] iKey 属性项键值
     * @param[in] iValue 属性项布尔数值
     * @param[out] oNewAttributeItem 新的属性项对象
     * @note
     */
    virtual PDV_RESULT AddBooleanAttributeItem(const CUnicodeString &iKey, DftBool iValue, IAttributeItem *&oNewAttributeItem) = 0;

    /**
     * @brief 增加整型属性项
     * @return PDV_RESULT
     * @param[in] iKey 属性项键值
     * @param[in] iValue 属性项整型数值
     * @param[out] oNewAttributeItem 新的属性项对象
     * @note
     */
    virtual PDV_RESULT AddIntegerAttributeItem(const CUnicodeString &iKey, DftInt iValue, IAttributeItem *&oNewAttributeItem) = 0;

    /**
     * @brief 增加单精度浮点型属性项
     * @return PDV_RESULT
     * @param[in] iKey 属性项键值
     * @param[in] iValue 属性项单精度浮点型数值
     * @param[out] oNewAttributeItem 新的属性项对象
     * @note
     */
    virtual PDV_RESULT AddFloatAttributeItem(const CUnicodeString &iKey, DftFloat iValue, IAttributeItem *&oNewAttributeItem) = 0;

    /**
     * @brief 增加双精度浮点型属性项
     * @return PDV_RESULT
     * @param[in] iKey 属性项键值
     * @param[in] iValue 属性项双精度浮点型数值
     * @param[out] oNewAttributeItem 新的属性项对象
     * @note
     */
    virtual PDV_RESULT AddDoubleAttributeItem(const CUnicodeString &iKey, DftDouble iValue, IAttributeItem *&oNewAttributeItem) = 0;

    /**
     * @brief 增加单精度浮点三维向量属性项
     * @return PDV_RESULT
     * @param[in] iKey 属性项键值
     * @param[in] iValue 属性项单精度浮点三维向量数值
     * @param[out] oNewAttributeItem 新的属性项对象
     * @note
     */
    virtual PDV_RESULT AddVectorFloat3AttributeItem(const CUnicodeString &iKey, const PDVVector3F &iValue, IAttributeItem *&oNewAttributeItem) = 0;

    /**
     * @brief 增加双精度浮点三维向量属性项
     * @return PDV_RESULT
     * @param[in] iKey 属性项键值
     * @param[in] iValue 属性项双精度浮点三维向量数值
     * @param[out] oNewAttributeItem 新的属性项对象
     * @note
     */
    virtual PDV_RESULT AddVectorDouble3AttributeItem(const CUnicodeString &iKey, const PDVVector3D &iValue, IAttributeItem *&oNewAttributeItem) = 0;

    /**
     * @brief 增加字符串属性项
     * @return PDV_RESULT
     * @param[in] iKey 属性项键值
     * @param[in] iValue 属性项字符串属性项数值
     * @param[out] oNewAttributeItem 新的属性项对象
     * @note
     */
    virtual PDV_RESULT AddStringAttributeItem(const CUnicodeString &iKey, const CUnicodeString &iValue, IAttributeItem *&oNewAttributeItem) = 0;

    /**
     * @brief 清空属性组
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearAttributeItem() = 0;

	/**
	 * @brief 获取属性项的数量
	 * @return DftUInt 返回Item的数量
	 * @note
	 */
	virtual DftUInt GetAttributeItemCount() = 0;

    /**
     * @brief 获取属性项的数组
     * @return PDV_RESULT
     * @param[out] oAttributeItemArray 返回Item的数组
     * @note
     */
	virtual PDV_RESULT GetAttributeItemArray(std::vector<IAttributeItem*> &oAttributeItemArray) = 0;
};

} // namespace pdv

} // namespace kernel

#endif
/**
 * @file PDVIAttribute.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：属性的接口声明
 * @details 详细说明
 */

#ifndef PDVIATTRIBUTE_H
#define PDVIATTRIBUTE_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

class IAttributeGroup;

/** @brief 属性的接口 */
class PDVCORE_API IAttribute : public IDataObject
{
public:
    /**
     * @brief 获取属性组的个数
     * @return DftUInt 属性组的个数
     * @note
     */
    virtual DftUInt GetAttributeGroupCount() = 0;

    /**
     * @brief 增加属性组
     * @return PDV_RESULT
     * @param[in] iGroupName 属性组命名
     * @param[out] oNewAttributeGroup 新的属性组对象
     * @note
     */
    virtual PDV_RESULT AddAttributeGroup(const CUnicodeString &iGroupName, IAttributeGroup *&oNewAttributeGroup) = 0;

    /**
     * @brief 清空属性组
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearAttributeGroup() = 0;

    /**
     * @brief 获取属性组
     * @return PDV_RESULT
     * @param[out] oAttributeGroupArray 属性组
     * @note
     */
    virtual PDV_RESULT GetAttributeGroupArray(std::vector<IAttributeGroup*>& oAttributeGroupArray) = 0;

    /**
     * @brief 从二进制数据流中读取数据信息
     * @return DftInt64 数据长度
     * @param[in] iStreamBuffer 数据流
     * @param[in] iBufferLength 数据流长度
     * @note
     */
    virtual DftInt64 ReadData(const PDV_CHAR* iStreamBuffer, DftInt64 iBufferLength) = 0;

    /**
     * @brief 向二进制数据流中写入数据信息
     * @return DftInt64 数据长度
     * @param[in,out] ioStreamBuffer 数据流
     * @param[in] iBufferLength 数据流长度
     * @note
     */
    virtual DftInt64 WriteData(PDV_CHAR* ioStreamBuffer, DftInt64 iBufferLength) const = 0;
};

} // namespace pdv

} // namespace kernel

#endif
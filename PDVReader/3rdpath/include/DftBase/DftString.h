/**
 * @file DftString.h
 * @author liqiang
 * @version 1.0
 * @date 2025-01-20
 * @brief 概述：字符串处理
 * @details 详细说明：提供不同字符编码之间的转换
 */

#ifndef DFT_STRING_H
#define DFT_STRING_H

#include "DftBase.h"

/** @brief 编码类型 */
enum DFT_MULTIBYTE_TYPE
{
    DFT_MULITBYTE_UNKNOWN = 0, ///< 未知编码 (使用系统配置)
    DFT_MULTIBYTE_ZH_CN = 936, ///< 简体中文（GBK/GB2312）
    DFT_MULTIBYTE_ZH_TW = 950, ///< 繁体中文（BIG5）
};

/**
 * @brief 获取UTF8字符串长度
 * @return DftUInt 字符串长度
 * @param[in] iUTF8Buffer UTF8字符串
 * @note
 */
DFT_PUBLIC(DftUInt) LengthOfUTF8String(const DftUTF8Char* iUTF8Buffer);

/**
 * @brief 获取UTF8字节长度
 * @return DftUInt 字节长度
 * @param[in] iUTF8Buffer UTF8字符串
 * @note
 */
DFT_PUBLIC(DftUInt) LengthOfUTF8Byte(const DftUTF8Char* iUTF8Buffer);

/**
 * @brief 获取UTF16字符串长度
 * @return DftUInt 字符串长度
 * @param[in] iUTF8Buffer UTF16字符串
 * @note
 */
DFT_PUBLIC(DftUInt) LengthOfUTF16String(const DftUniChar* iUTF8Buffer);

/**
 * @brief 获取UTF16字节长度
 * @return DftUInt 字节长度
 * @param[in] iUTF8Buffer UTF16字符串
 * @note
 */
DFT_PUBLIC(DftUInt) LengthOfUTF16Byte(const DftUniChar* iUTF16Buffer);

/**
 * @brief 获取GB2312字符串长度
 * @return DftUInt 字符串长度
 * @param[in] iGB2312Buffer GB2312字符串
 * @note
 */
DFT_PUBLIC(DftUInt) LengthOfGB2312String(const char* iGB2312Buffer);

/**
 * @brief 获取GB2312字节长度
 * @return DftUInt 字节长度
 * @param[in] iGB2312Buffer GB2312字符串
 * @note
 */
DFT_PUBLIC(DftUInt) LengthOfGB2312Byte(const char* iGB2312Buffer);

/**
 * @brief UTF8 转 UTF16
 * @return DftUInt 字节长度
 * @param[in] iUTF8Buffer UTF8 字符串
 * @param[out] oUTF16Buffer UTF16 字符串
 * @note
 */
DFT_PUBLIC(DftUInt) ConvertUTF8ToUTF16(DftUTF8Char* iUTF8Buffer, DftUniChar** oUTF16Buffer);

/**
 * @brief UTF16 转 UTF8
 * @return DftUInt 字节长度
 * @param[in] iUTF16Buffer UTF16 字符串
 * @param[out] oUTF8Buffer UTF8 字符串
 * @note
 */
DFT_PUBLIC(DftUInt) ConvertUTF16ToUTF8(DftUniChar* iUTF16Buffer, DftUTF8Char** oUTF8Buffer);

/**
 * @brief GB2312 转 UTF8
 * @return DftUInt 字节长度
 * @param[in] iGB2312Buffer GB2312 字符串
 * @param[out] oUTF8Buffer UTF8 字符串
 * @note
 */
DFT_PUBLIC(DftUInt) ConvertGB2312ToUTF8(const char* iGB2312Buffer, DftUTF8Char** oUTF8Buffer);

/**
 * @brief UTF8 转 GB2312
 * @return DftUInt 字节长度
 * @param[in] iUTF8Buffer UTF8 字符串
 * @param[out] oGB2312Buffer GB2312 字符串
 * @note
 */
DFT_PUBLIC(DftUInt) ConvertUTF8ToGB2312(const DftUTF8Char* iUTF8Buffer, char** oGB2312Buffer);

/**
 * @brief ANSI 转 UTF8
 * @return DftUInt 字节长度
 * @param[in] iANSIBuffer ANSI 字符串
 * @param[out] oUTF8Buffer UTF8 字符串
 * @note
 */
DFT_PUBLIC(DftUInt) ConvertANSIToUTF8(const char* iANSIBuffer, DftUTF8Char** oUTF8Buffer);

/**
 * @brief UTF8 转 ANSI
 * @return DftUInt 字节长度
 * @param[in] iUTF8Buffer UTF8 字符串
 * @param[out] oANSIBuffer ANSI 字符串
 * @note
 */
DFT_PUBLIC(DftUInt) ConvertUTF8ToANSI(const DftUTF8Char* iUTF8Buffer, char** oANSIBuffer);

/**
 * @brief 截取字符串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in] iStr 源字符串
 * @param[out] oSubString 截取到的字符串
 * @param[in] iStart 起始位置
 * @param[in] iLen 截取长度
 * @note
 */
DFT_PUBLIC(DftStatus) SubString(DftUTF8Char* iStr, DftUTF8Char** oSubString, const DftInt iStart, const DftInt iLen);

/**
 * @brief 查找字符串
 * @return DftInt 字符串出现的位置
 * @param[in] iStr 源字符串
 * @param[in] iFindStr 需要查找的字符串
 * @param[in] iStart 起始位置
 * @note
 */
DFT_PUBLIC(DftInt) FindSubString(DftUTF8Char* iStr, DftUTF8Char* iFindStr, const DftInt iStart);

/**
 * @brief 内存释放
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in,out] ioStrPtr 释放的字符串指针
 * @note
 */
DFT_PUBLIC(DftStatus) DftSafeDeleteString(DftUTF8Char** ioStrPtr);

/**
 * @brief 反向查找字符串
 * @return DftInt 字符串出现的位置
 * @param[in,out] ioStr 源字符串
 * @param[in] iFindStr 需要查找的字符串
 * @note
 */
DFT_PUBLIC(DftInt) DftStringReverseFind(DftUTF8Char* ioStr, DftUTF8Char* iFindStr);

/**
 * @brief 去掉字符串末尾的指定字符串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in,out] ioStr 源字符串
 * @param[in] iTargetStr 去掉的字符串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringTrimRight(DftUTF8Char* ioStr, const DftUTF8Char* iTargetStr);

/**
 * @brief 去掉字符串开头的指定字符串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in,out] ioStr 源字符串
 * @param[in] iTargetStr 去掉的字符串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringTrimLeft(DftUTF8Char* ioStr, const DftUTF8Char* iTargetStr);

/**
 * @brief 获取UTF8字符长度
 * @return DftInt UTF8字符长度
 * @param[in] iChar UTF8字符
 * @note
 */
DFT_PUBLIC(DftInt) LengthOfUTF8Char(const DftUTF8Char* iChar);

/**
 * @brief 替换字符串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in,out] ioStr 源字符串
 * @param[in] iOld 被替换的字符串
 * @param[in] iNew 替换的新字符串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringReplace(DftUTF8Char** ioStr, const DftUTF8Char* iOld, const DftUTF8Char* iNew);

/**
 * @brief 删除指定位置的字符串
 * @return DftUInt 删除字节数
 * @param[in,out] ioStr 源字符串
 * @param[in] iIndex 位置
 * @param[in] iCount 删除长度
 * @note
 */
DFT_PUBLIC(DftUInt) DftStringDelete(DftUTF8Char* ioStr, const DftUInt iIndex, const DftUInt iCount);

/**
 * @brief 在指定位置插入字符串
 * @return DftUInt 插入字节数
 * @param[in,out] ioStr 源字符串
 * @param[in] iInsertStr 插入的字符串
 * @param[in] iIndex 位置
 * @note
 */
DFT_PUBLIC(DftUInt) DftStringInsert(DftUTF8Char* ioStr, const DftUTF8Char* iInsertStr, const DftUInt iIndex);

/**
 * @brief 反转字符串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in,out] ioStr 源字符串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringReverse(DftUTF8Char** ioStr);

/**
 * @brief 将字符串转为大写
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in,out] ioStr 源字符串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringMakeUpper(DftUTF8Char* ioStr);

/**
 * @brief 将字符串转为小写
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in,out] ioStr 源字符串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringMakeLower(DftUTF8Char* ioStr);

/**
 * @brief 比较字符串是否相等
 * @return DftInt 0：相等，非0：不相等
 * @param[in] iStr1 字符串1
 * @param[in] iStr2 字符串2
 * @note
 */
DFT_PUBLIC(DftInt) DftStringCompare(const DftUTF8Char* iStr1, const DftUTF8Char* iStr2);

/**
 * @brief 比较字符串是否相等（不区分大小写）
 * @return DftInt 0：相等，非0：不相等
 * @param[in] iStr1 字符串1
 * @param[in] iStr2 字符串2
 * @note
 */
DFT_PUBLIC(DftInt) DftStringCompareNoCase(const DftUTF8Char* iStr1, const DftUTF8Char* iStr2);

/**
 * @brief 格式化字符串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in,out] ioStr 目标字符串
 * @param[in] iFormat 格式字符串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringFomat(DftUTF8Char* ioStr, const DftUTF8Char* iFormat, ...);

/**
 * @brief 追加格式化字符串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in,out] ioStr 源字符串
 * @param[in] iFormat 追加格式字符串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringAppendFormat(DftUTF8Char* ioStr, const DftUTF8Char* iFormat, ...);

/**
 * @brief 获取子串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in] iStr 源字符串
 * @param[in] iChar 分隔符
 * @param[out] oArray 输出子串数组
 * @param[out] oLen 输出数组长度
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringSpan(const DftUTF8Char* iStr, DftUTF8Char* iChar, DftUTF8Char*** oArray, DftUInt* oLen);

/**
 * @brief 清空字符串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in,out] ioStr 源字符串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringEmpty(DftUTF8Char* ioStr);

/**
 * @brief 判断字符串是否为空
 * @return DftBool TRUE为空，FALSE非空
 * @param[in] iStr 源字符串
 * @note
 */
DFT_PUBLIC(DftBool) DftStringIsEmpty(const DftUTF8Char* iStr);

/**
 * @brief 取中间子串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in] iStr 源字符串
 * @param[in] iStart 开始位置
 * @param[in] iCount 数量
 * @param[out] oStr 输出子串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringMid(DftUTF8Char* iStr, const DftUInt iStart, const DftUInt iCount, DftUTF8Char** oStr);

/**
 * @brief 取右侧子串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in] iStr 源字符串
 * @param[in] iCount 数量
 * @param[out] oStr 输出子串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringRight(DftUTF8Char* iStr, const DftUInt iCount, DftUTF8Char** oStr);

/**
 * @brief 取左侧子串
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in] iStr 源字符串
 * @param[in] iCount 数量
 * @param[out] oStr 输出子串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringLeft(DftUTF8Char* iStr, const DftUInt iCount, DftUTF8Char** oStr);

/**
 * @brief 字符串拼接
 * @return DftStatus 成功返回 \ref DFT_SUCCESS
 * @param[in,out] ioStr 源字符串
 * @param[in] iAppendStr 拼接串
 * @note
 */
DFT_PUBLIC(DftStatus) DftStringAppend(DftUTF8Char* ioStr, DftUTF8Char* iAppendStr);

#endif

#ifndef DFTFILESTREAM_H
#define DFTFILESTREAM_H

/**
 * @file DftFileStream.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2025-01-18
 * @brief 概述：文件流操作
 * @details 详细说明
 */

#include "DftBase.h"
#include "DftBufferStream.h"

/** @brief 文件流对象 */
typedef DftHandle DftFileStream;

/**
 * @brief 创建文件流对象
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_INVALID_PARAM 参数错误
 * @param[in] iFileStreamPath 文件路径
 * @param[in] iOpenMode 打开方式，见 DftOpenMode
 * @param[out] oFileStream 文件流对象
 * @note
 */
DFT_PUBLIC(DftStatus) DftFileStreamCreate(const DftUTF8Char* iFileStreamPath, DftInt iOpenMode, DftFileStream* oFileStream);

/**
 * @brief 文件流定位
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_INVALID_PARAM 参数错误
 * @param[in] iFileStream 文件流
 * @param[in] iOffset 数据偏移字节数
 * @param[in] iSeekMode 检索方式，见 DftSeekMode
 * @note
 */
DFT_PUBLIC(DftStatus) DftFileStreamSeek(DftFileStream iFileStream, DftInt64 iOffset, DftInt iSeekMode);

/**
 * @brief 获取文件流长度
 * @return DftInt64 文件流长度，错误时返回-1
 * @param[in] iFileStream 文件流
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamGetLength(DftFileStream iFileStream);

/**
 * @brief 获取文件流当前位置
 * @return DftInt64 文件流位置，错误时返回-1
 * @param[in] iFileStream 文件流
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamGetCurrentPos(DftFileStream iFileStream);

/**
 * @brief 从文件流中读取8位整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 8位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt8(DftFileStream iFileStream, DftInt8* oValue);

/**
 * @brief 从文件流中读取8位无符号整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 8位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt8(DftFileStream iFileStream, DftUInt8* oValue);

/**
 * @brief 从文件流中读取16位整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 16位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt16(DftFileStream iFileStream, DftInt16* oValue);

/**
 * @brief 从文件流中读取16位无符号整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 16位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt16(DftFileStream iFileStream, DftUInt16* oValue);

/**
 * @brief 从文件流中读取32位整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 32位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt32(DftFileStream iFileStream, DftInt32* oValue);

/**
 * @brief 从文件流中读取32位无符号整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 32位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt32(DftFileStream iFileStream, DftUInt32* oValue);

/**
 * @brief 从文件流中读取64位整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 64位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt64(DftFileStream iFileStream, DftInt64* oValue);

/**
 * @brief 从文件流中读取64位无符号整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 64位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt64(DftFileStream iFileStream, DftUInt64* oValue);

/**
 * @brief 从文件流中读取单精度浮点数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 单精度浮点数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadFloat(DftFileStream iFileStream, DftFloat* oValue);

/**
 * @brief 从文件流中读取双精度浮点数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 双精度浮点数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadDouble(DftFileStream iFileStream, DftDouble* oValue);

/**
 * @brief 从文件流中读取单精度浮点型二维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 单精度浮点型二维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadVector2F(DftFileStream iFileStream, DftVector2F oValue);

/**
 * @brief 从文件流中读取单精度浮点型三维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 单精度浮点型三维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadVector3F(DftFileStream iFileStream, DftVector3F oValue);

/**
 * @brief 从文件流中读取单精度浮点型四维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 单精度浮点型四维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadVector4F(DftFileStream iFileStream, DftVector4F oValue);

/**
 * @brief 从文件流中读取单精度浮点型4X4矩阵
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 单精度浮点型4X4矩阵
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadMatrix4F(DftFileStream iFileStream, DftMatrix4F oValue);

/**
 * @brief 从文件流中读取双精度浮点型二维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 双精度浮点型二维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadVector2D(DftFileStream iFileStream, DftVector2D oValue);

/**
 * @brief 从文件流中读取双精度浮点型三维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 双精度浮点型三维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadVector3D(DftFileStream iFileStream, DftVector3D oValue);

/**
 * @brief 从文件流中读取双精度浮点型四维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 双精度浮点型四维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadVector4D(DftFileStream iFileStream, DftVector4D oValue);

/**
 * @brief 从文件流中读取双精度浮点型4X4矩阵
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 双精度浮点型4X4矩阵
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadMatrix4D(DftFileStream iFileStream, DftMatrix4D oValue);

/**
 * @brief 从文件流中读取 ULEB128 数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue ULEB128数据
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadULEB128(DftFileStream iFileStream, DftUInt64* oValue);

/**
 * @brief 从文件流中读取字符串，连续读取字符，直到'\0'为止
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadStringByNull(DftFileStream iFileStream, DftUTF8Char** oValue);

/**
 * @brief 从文件流中读取字符串，先读取 DftUInt32 作为字节长度length，再读取length个字符(不包含'\0')
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadStringByLength(DftFileStream iFileStream, DftUTF8Char** oValue);

/**
 * @brief 从文件流中读取字符串，先读取 ULEB128 作为字节长度length，再读取length个字符(不包含'\0')
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadStringByULEB128Length(DftFileStream iFileStream, DftUTF8Char** oValue);

/**
 * @brief 从文件流中读取8位整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 8位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt8Array(DftFileStream iFileStream, DftInt8** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取8位无符号整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 8位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt8Array(DftFileStream iFileStream, DftUInt8** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取16位整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 16位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt16Array(DftFileStream iFileStream, DftInt16** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取16位无符号整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 16位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt16Array(DftFileStream iFileStream, DftUInt16** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取32位整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 32位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt32Array(DftFileStream iFileStream, DftInt32** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取32位无符号整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 32位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt32Array(DftFileStream iFileStream, DftUInt32** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取64位整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 64位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt64Array(DftFileStream iFileStream, DftInt64** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取64位无符号整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 64位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt64Array(DftFileStream iFileStream, DftUInt64** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取8位整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 8位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt8ArrayULEB128(DftFileStream iFileStream, DftInt8** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取8位无符号整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 8位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt8ArrayULEB128(DftFileStream iFileStream, DftUInt8** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取16位整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 16位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt16ArrayULEB128(DftFileStream iFileStream, DftInt16** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取16位无符号整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 16位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt16ArrayULEB128(DftFileStream iFileStream, DftUInt16** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取32位整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 32位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt32ArrayULEB128(DftFileStream iFileStream, DftInt32** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取32位无符号整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 32位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt32ArrayULEB128(DftFileStream iFileStream, DftUInt32** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取64位整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 64位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadInt64ArrayULEB128(DftFileStream iFileStream, DftInt64** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取64位无符号整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[out] oValues 64位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadUInt64ArrayULEB128(DftFileStream iFileStream, DftUInt64** oValues, DftUInt* oLength);

/**
 * @brief 从文件流中读取字节流，长度为iLength
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iLength 字节流长度
 * @param[out] oBytes 字节流数据
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamReadBytes(DftFileStream iFileStream, DftUInt64 iLength, DftByte** oBytes);

/**
 * @brief 向文件流中写入8位整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 8位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt8(DftFileStream iFileStream, DftInt8 iValue);

/**
 * @brief 向文件流中写入8位无符号整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 8位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt8(DftFileStream iFileStream, DftUInt8 iValue);

/**
 * @brief 向文件流中写入16位整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 16位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt16(DftFileStream iFileStream, DftInt16 iValue);

/**
 * @brief 向文件流中写入16位无符号整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 16位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt16(DftFileStream iFileStream, DftUInt16 iValue);

/**
 * @brief 向文件流中写入32位整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 32位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt32(DftFileStream iFileStream, DftInt32 iValue);

/**
 * @brief 向文件流中写入32位无符号整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 32位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt32(DftFileStream iFileStream, DftUInt32 iValue);

/**
 * @brief 向文件流中写入64位整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 64位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt64(DftFileStream iFileStream, DftInt64 iValue);

/**
 * @brief 向文件流中写入64位无符号整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 64位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt64(DftFileStream iFileStream, DftUInt64 iValue);

/**
 * @brief 向文件流中写入单精度浮点数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 单精度浮点数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteFloat(DftFileStream iFileStream, DftFloat iValue);

/**
 * @brief 向文件流中写入双精度浮点数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 双精度浮点数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteDouble(DftFileStream iFileStream, DftDouble iValue);

/**
 * @brief 向文件流中写入单精度浮点型二维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 单精度浮点型二维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteVector2F(DftFileStream iFileStream, DftVector2F iValue);

/**
 * @brief 向文件流中写入单精度浮点型三维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 单精度浮点型三维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteVector3F(DftFileStream iFileStream, DftVector3F iValue);

/**
 * @brief 向文件流中写入单精度浮点型四维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 单精度浮点型四维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteVector4F(DftFileStream iFileStream, DftVector4F iValue);

/**
 * @brief 向文件流中写入单精度浮点型4X4矩阵
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 单精度浮点型4X4矩阵
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteMatrix4F(DftFileStream iFileStream, DftMatrix4F iValue);

/**
 * @brief 向文件流中写入双精度浮点型二维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 双精度浮点型二维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteVector2D(DftFileStream iFileStream, DftVector2D iValue);

/**
 * @brief 向文件流中写入双精度浮点型三维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 双精度浮点型三维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteVector3D(DftFileStream iFileStream, DftVector3D iValue);

/**
 * @brief 向文件流中写入双精度浮点型四维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 双精度浮点型四维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteVector4D(DftFileStream iFileStream, DftVector4D iValue);

/**
 * @brief 向文件流中写入双精度浮点型4X4矩阵
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 双精度浮点型4X4矩阵
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteMatrix4D(DftFileStream iFileStream, DftMatrix4D iValue);

/**
 * @brief 向文件流中写入 ULEB128 数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue ULEB128 数据
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteULEB128(DftFileStream iFileStream, DftUInt64 iValue);

/**
 * @brief 向文件流中写入字符串，连续写入字符，直到'\0'为止
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteStringByNull(DftFileStream iFileStream, const DftUTF8Char* iValue);

/**
 * @brief 向文件流中写入字符串，先写入 DftUInt32 作为字节长度length，再写入length个字符(不包含'\0')
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteStringByLength(DftFileStream iFileStream, const DftUTF8Char* iValue);

/**
 * @brief 向文件流中写入字符串，先写入 ULEB128 作为字节长度length，再写入length个字符(不包含'\0')
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteStringByULEB128Length(DftFileStream iFileStream, const DftUTF8Char* iValue);

/**
 * @brief 向文件流中写入8位整数数组，先写入 DftUInt32 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 8位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt8Array(DftFileStream iFileStream, DftInt8* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入8位无符号整数数组，先写入 DftUInt32 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 8位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt8Array(DftFileStream iFileStream, DftUInt8* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入16位整数数组，先写入 DftUInt32 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 16位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt16Array(DftFileStream iFileStream, DftInt16* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入16位无符号整数数组，先写入 DftUInt32 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 16位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt16Array(DftFileStream iFileStream, DftUInt16* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入32位整数数组，先写入 DftUInt32 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 32位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt32Array(DftFileStream iFileStream, DftInt32* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入32位无符号整数数组，先写入 DftUInt32 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 32位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt32Array(DftFileStream iFileStream, DftUInt32* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入64位整数数组，先写入 DftUInt32 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 64位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt64Array(DftFileStream iFileStream, DftInt64* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入64位无符号整数数组，先写入 DftUInt32 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 64位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt64Array(DftFileStream iFileStream, DftUInt64* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入8位整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 8位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt8ArrayULEB128(DftFileStream iFileStream, DftInt8* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入8位无符号整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 8位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt8ArrayULEB128(DftFileStream iFileStream, DftUInt8* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入16位整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 16位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt16ArrayULEB128(DftFileStream iFileStream, DftInt16* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入16位无符号整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 16位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt16ArrayULEB128(DftFileStream iFileStream, DftUInt16* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入32位整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 32位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt32ArrayULEB128(DftFileStream iFileStream, DftInt32* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入32位无符号整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 32位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt32ArrayULEB128(DftFileStream iFileStream, DftUInt32* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入64位整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 64位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteInt64ArrayULEB128(DftFileStream iFileStream, DftInt64* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入64位无符号整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iValues 64位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteUInt64ArrayULEB128(DftFileStream iFileStream, DftUInt64* iValues, DftUInt iLength);

/**
 * @brief 向文件流中写入字节流，长度为iLength
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iFileStream 文件流对象
 * @param[in] iBytes 字节流数据
 * @param[in] iLength 字节流长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftFileStreamWriteBytes(DftFileStream iFileStream, DftByte* iBytes, DftUInt64 iLength);

/**
 * @brief 释放文件流对象，并把该对象置空
 * @return DftStatus \ref DFT_SUCCESS  执行成功；其他值，执行失败
 * @param[in,out] ioFileStream 文件流对象
 * @note
 */
DFT_PUBLIC(DftStatus) DftFileStreamRelease(DftFileStream* ioFileStream);

#endif

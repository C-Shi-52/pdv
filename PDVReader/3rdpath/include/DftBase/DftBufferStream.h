
#ifndef DFTBUFFERSTREAM_H
#define DFTBUFFERSTREAM_H

/**
 * @file DftBufferStream.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2025-01-18
 * @brief 概述：数据流操作
 * @details 详细说明
 */

#include "DftBase.h"
#include "DftTypes.h"
#include "DftDefine.h"

/** @brief 数据流对象 */
typedef DftHandle DftBufferStream;

/** @brief 打开方式 */
enum DftOpenMode
{
    OPENMODE_NULL = 0,      ///< 未知模式
    OPENMODE_READ = 1,      ///< 只读模式
    OPENMODE_CREATE = 2,    ///< 创建模型
    OPENMODE_READWRITE = 3, ///< 读写模式
};

/** @brief 偏移模式 */
enum DftSeekMode
{
    SEEKMODE_BEGIN = 0,   ///< 起始位置偏移
    SEEKMODE_CURRENT = 1, ///< 当前位置偏移
    SEEKMODE_END = 2,     ///< 结束位置偏移
};

/**
 * @brief 创建数据流对象
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iBuffer 数据流
 * @param[in] iBufferSize 数据流大小
 * @param[in] iOpenMode 打开方式，见 DftOpenMode
 * @param[out] oBufferStream 数据流对象
 * @note
 */
DFT_PUBLIC(DftStatus) DftBufferStreamCreate(DftUTF8Char* iBuffer, DftInt64 iBufferSize, DftInt iOpenMode, DftBufferStream* oBufferStream);

/**
 * @brief 数据流定位
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iBufferStream 数据流
 * @param[in] iOffset 数据偏移字节数
 * @param[in] iSeekMode 检索方式，见 DftSeekMode
 * @note
 */
DFT_PUBLIC(DftStatus) DftBufferStreamSeek(DftBufferStream iBufferStream, DftInt64 iOffset, DftInt iSeekMode);

/**
 * @brief 获取数据流长度
 * @return DftInt64 数据流长度，错误时返回-1
 * @param[in] iBufferStream 数据流
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamGetLength(DftBufferStream iBufferStream);

/**
 * @brief 获取数据流当前位置
 * @return DftInt64 数据流位置，错误时返回-1
 * @param[in] iBufferStream 数据流
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamGetCurrentPos(DftBufferStream iBufferStream);

/**
 * @brief 获取数据流首地址
 * @return DftUTF8Char * 获取数据流首地址，错误时返回NULL
 * @param[in] iBufferStream 数据流
 * @note
 */
DFT_PUBLIC(DftUTF8Char*) DftBufferStreamGetBuffer(DftBufferStream iBufferStream);

/**
 * @brief 从数据流中读取8位整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 8位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt8(DftBufferStream iBufferStream, DftInt8* oValue);

/**
 * @brief 从数据流中读取8位无符号整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 8位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt8(DftBufferStream iBufferStream, DftUInt8* oValue);

/**
 * @brief 从数据流中读取16位整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 16位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt16(DftBufferStream iBufferStream, DftInt16* oValue);

/**
 * @brief 从数据流中读取16位无符号整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 16位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt16(DftBufferStream iBufferStream, DftUInt16* oValue);

/**
 * @brief 从数据流中读取32位整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 32位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt32(DftBufferStream iBufferStream, DftInt32* oValue);

/**
 * @brief 从数据流中读取32位无符号整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 32位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt32(DftBufferStream iBufferStream, DftUInt32* oValue);

/**
 * @brief 从数据流中读取64位整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 64位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt64(DftBufferStream iBufferStream, DftInt64* oValue);

/**
 * @brief 从数据流中读取64位无符号整数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 64位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt64(DftBufferStream iBufferStream, DftUInt64* oValue);

/**
 * @brief 从数据流中读取单精度浮点数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 单精度浮点数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadFloat(DftBufferStream iBufferStream, DftFloat* oValue);

/**
 * @brief 从数据流中读取双精度浮点数
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 双精度浮点数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadDouble(DftBufferStream iBufferStream, DftDouble* oValue);

/**
 * @brief 从数据流中读取单精度浮点型二维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 单精度浮点型二维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadVector2F(DftBufferStream iBufferStream, DftVector2F oValue);

/**
 * @brief 从数据流中读取单精度浮点型三维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 单精度浮点型三维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadVector3F(DftBufferStream iBufferStream, DftVector3F oValue);

/**
 * @brief 从数据流中读取单精度浮点型四维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 单精度浮点型四维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadVector4F(DftBufferStream iBufferStream, DftVector4F oValue);

/**
 * @brief 从数据流中读取单精度浮点型4X4矩阵
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 单精度浮点型4X4矩阵
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadMatrix4F(DftBufferStream iBufferStream, DftMatrix4F oValue);

/**
 * @brief 从数据流中读取双精度浮点型二维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 双精度浮点型二维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadVector2D(DftBufferStream iBufferStream, DftVector2D oValue);

/**
 * @brief 从数据流中读取双精度浮点型三维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 双精度浮点型三维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadVector3D(DftBufferStream iBufferStream, DftVector3D oValue);

/**
 * @brief 从数据流中读取双精度浮点型四维向量
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 双精度浮点型四维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadVector4D(DftBufferStream iBufferStream, DftVector4D oValue);

/**
 * @brief 从数据流中读取双精度浮点型4X4矩阵
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 双精度浮点型4X4矩阵
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadMatrix4D(DftBufferStream iBufferStream, DftMatrix4D oValue);

/**
 * @brief 从数据流中读取 ULEB128 数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue ULEB128 数据
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadULEB128(DftBufferStream iBufferStream, DftUInt64* oValue);

/**
 * @brief 从数据流中读取字符串，连续读取字符，直到'\0'为止
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadStringByNull(DftBufferStream iBufferStream, DftUTF8Char** oValue);

/**
 * @brief 从数据流中读取字符串，先读取 DftUInt32 作为字节长度length，再读取length个字符(不包含'\0')
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadStringByUInt32Length(DftBufferStream iBufferStream, DftUTF8Char** oValue);

/**
 * @brief 从数据流中读取字符串，先读取 ULEB128 作为字节长度length，再读取length个字符(不包含'\0')
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadStringByULEB128Length(DftBufferStream iBufferStream, DftUTF8Char** oValue);

/**
 * @brief 从数据流中读取8位整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 8位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt8Array(DftBufferStream iBufferStream, DftInt8** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取8位无符号整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 8位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt8Array(DftBufferStream iBufferStream, DftUInt8** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取16位整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 16位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt16Array(DftBufferStream iBufferStream, DftInt16** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取16位无符号整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 16位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt16Array(DftBufferStream iBufferStream, DftUInt16** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取32位整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 32位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt32Array(DftBufferStream iBufferStream, DftInt32** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取32位无符号整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 32位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt32Array(DftBufferStream iBufferStream, DftUInt32** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取64位整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 64位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt64Array(DftBufferStream iBufferStream, DftInt64** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取64位无符号整数数组，先读取 DftUInt32 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 64位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt64Array(DftBufferStream iBufferStream, DftUInt64** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取8位整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 8位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt8ArrayULEB128(DftBufferStream iBufferStream, DftInt8** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取8位无符号整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 8位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt8ArrayULEB128(DftBufferStream iBufferStream, DftUInt8** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取16位整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 16位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt16ArrayULEB128(DftBufferStream iBufferStream, DftInt16** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取16位无符号整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 16位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt16ArrayULEB128(DftBufferStream iBufferStream, DftUInt16** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取32位整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 32位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt32ArrayULEB128(DftBufferStream iBufferStream, DftInt32** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取32位无符号整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 32位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt32ArrayULEB128(DftBufferStream iBufferStream, DftUInt32** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取64位整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 64位整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadInt64ArrayULEB128(DftBufferStream iBufferStream, DftInt64** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取64位无符号整数数组，先读取 ULEB128 作为数组长度length，再读取length个数据
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[out] oValues 64位无符号整数数组
 * @param[out] oLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadUInt64ArrayULEB128(DftBufferStream iBufferStream, DftUInt64** oValues, DftUInt* oLength);

/**
 * @brief 从数据流中读取字节流，长度为iLength
 * @return DftInt64 读取字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iLength 字节流长度
 * @param[out] oBytes 字节流数据
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamReadBytes(DftBufferStream iBufferStream, DftUInt64 iLength, DftByte** oBytes);

/**
 * @brief 向数据流中写入8位整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 8位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt8(DftBufferStream iBufferStream, DftInt8 iValue);

/**
 * @brief 向数据流中写入8位无符号整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 8位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt8(DftBufferStream iBufferStream, DftUInt8 iValue);

/**
 * @brief 向数据流中写入16位整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 16位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt16(DftBufferStream iBufferStream, DftInt16 iValue);

/**
 * @brief 向数据流中写入16位无符号整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 16位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt16(DftBufferStream iBufferStream, DftUInt16 iValue);

/**
 * @brief 向数据流中写入32位整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 32位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt32(DftBufferStream iBufferStream, DftInt32 iValue);

/**
 * @brief 向数据流中写入32位无符号整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 32位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt32(DftBufferStream iBufferStream, DftUInt32 iValue);

/**
 * @brief 向数据流中写入64位整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 64位整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt64(DftBufferStream iBufferStream, DftInt64 iValue);

/**
 * @brief 向数据流中写入64位无符号整数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 64位无符号整数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt64(DftBufferStream iBufferStream, DftUInt64 iValue);

/**
 * @brief 向数据流中写入单精度浮点数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 单精度浮点数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteFloat(DftBufferStream iBufferStream, DftFloat iValue);

/**
 * @brief 向数据流中写入双精度浮点数
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 双精度浮点数值
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteDouble(DftBufferStream iBufferStream, DftDouble iValue);

/**
 * @brief 向数据流中写入单精度浮点型二维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 单精度浮点型二维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteVector2F(DftBufferStream iBufferStream, DftVector2F iValue);

/**
 * @brief 向数据流中写入单精度浮点型三维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 单精度浮点型三维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteVector3F(DftBufferStream iBufferStream, DftVector3F iValue);

/**
 * @brief 向数据流中写入单精度浮点型四维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 单精度浮点型四维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteVector4F(DftBufferStream iBufferStream, DftVector4F iValue);

/**
 * @brief 向数据流中写入单精度浮点型4X4矩阵
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 单精度浮点型4X4矩阵
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteMatrix4F(DftBufferStream iBufferStream, DftMatrix4F iValue);

/**
 * @brief 向数据流中写入双精度浮点型二维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 双精度浮点型二维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteVector2D(DftBufferStream iBufferStream, DftVector2D iValue);

/**
 * @brief 向数据流中写入双精度浮点型三维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 双精度浮点型三维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteVector3D(DftBufferStream iBufferStream, DftVector3D iValue);

/**
 * @brief 向数据流中写入双精度浮点型四维向量
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 双精度浮点型四维向量
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteVector4D(DftBufferStream iBufferStream, DftVector4D iValue);

/**
 * @brief 向数据流中写入双精度浮点型 4X4 矩阵
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 双精度浮点型 4X4 矩阵
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteMatrix4D(DftBufferStream iBufferStream, DftMatrix4D iValue);

/**
 * @brief 向数据流中写入 ULEB128 数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue ULEB128 数据
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteULEB128(DftBufferStream iBufferStream, DftUInt64 iValue);

/**
 * @brief 向数据流中写入字符串，连续写入字符，直到'\0'为止
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteStringByNull(DftBufferStream iBufferStream, const DftUTF8Char* iValue);

/**
 * @brief 向数据流中写入字符串，先写入 DftUInt32 作为字节长度 length，再写入 length 个字符(不包含'\0')
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteStringByUInt32Length(DftBufferStream iBufferStream, const DftUTF8Char* iValue);

/**
 * @brief 向数据流中写入字符串，先写入 ULEB128 作为字节长度 length，再写入 length 个字符(不包含'\0')
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValue 字符串
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteStringByULEB128Length(DftBufferStream iBufferStream, const DftUTF8Char* iValue);

/**
 * @brief 向数据流中写入 8 位整数数组，先写入 DftUInt32 作为数组长度 length，再写入 length 个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 8 位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt8Array(DftBufferStream iBufferStream, DftInt8* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入 8 位无符号整数数组，先写入 DftUInt32 作为数组长度 length，再写入 length 个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 8 位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt8Array(DftBufferStream iBufferStream, DftUInt8* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入 16 位整数数组，先写入 DftUInt32 作为数组长度 length，再写入 length 个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 16 位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt16Array(DftBufferStream iBufferStream, DftInt16* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入 16 位无符号整数数组，先写入 DftUInt32 作为数组长度 length，再写入 length 个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 16 位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt16Array(DftBufferStream iBufferStream, DftUInt16* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入 32 位整数数组，先写入 DftUInt32 作为数组长度 length，再写入 length 个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 32 位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt32Array(DftBufferStream iBufferStream, DftInt32* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入 32 位无符号整数数组，先写入 DftUInt32 作为数组长度 length，再写入 length 个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 32 位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt32Array(DftBufferStream iBufferStream, DftUInt32* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入 64 位整数数组，先写入 DftUInt32 作为数组长度 length，再写入 length 个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 64 位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt64Array(DftBufferStream iBufferStream, DftInt64* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入 64 位无符号整数数组，先写入 DftUInt32 作为数组长度 length，再写入 length 个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 64 位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt64Array(DftBufferStream iBufferStream, DftUInt64* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入 8 位整数数组，先写入 ULEB128 作为数组长度 length，再写入 length 个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 8 位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt8ArrayULEB128(DftBufferStream iBufferStream, DftInt8* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入 8 位无符号整数数组，先写入 ULEB128 作为数组长度 length，再写入 length 个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 8 位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt8ArrayULEB128(DftBufferStream iBufferStream, DftUInt8* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入 16 位整数数组，先写入 ULEB128 作为数组长度 length，再写入 length 个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 16 位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt16ArrayULEB128(DftBufferStream iBufferStream, DftInt16* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入16位无符号整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 16位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt16ArrayULEB128(DftBufferStream iBufferStream, DftUInt16* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入32位整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 32位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt32ArrayULEB128(DftBufferStream iBufferStream, DftInt32* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入32位无符号整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 32位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt32ArrayULEB128(DftBufferStream iBufferStream, DftUInt32* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入64位整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 64位整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteInt64ArrayULEB128(DftBufferStream iBufferStream, DftInt64* iValues, DftUInt iLength);

/**
 * @brief 向数据流中写入64位无符号整数数组，先写入 ULEB128 作为数组长度length，再写入length个数据
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in] iBufferStream 数据流对象
 * @param[in] iValues 64位无符号整数数组
 * @param[in] iLength 数组长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteUInt64ArrayULEB128(DftBufferStream iBufferStream, DftUInt64* iValues, DftUInt iLength);

/**
 * @brief 获取 ULEB128 数据所占字节数
 * @return DftInt64 数据所占字节数，错误时返回-1
 * @param[in] iValue ULEB128 数据
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamBytesULEB128(DftUInt64 iValue);

/**
 * @brief 获取字符串所占字节数
 * @return DftInt64 字符串所占字节数，错误时返回-1
 * @param[in] iValue 字符串，存储方式为 连续写入字符，直到'\0'为止
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamBytesStringByNull(const DftUTF8Char* iValue);

/**
 * @brief 获取字符串所占字节数
 * @return DftInt64 字符串所占字节数，错误时返回-1
 * @param[in] iValue 字符串，存储方式为 先写入 DftUInt32 作为字节长度 length，再写入 length 个字符(不包含'\0')
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamBytesStringByUInt32Length(const DftUTF8Char* iValue);

/**
 * @brief 获取字符串所占字节数
 * @return DftInt64 字符串所占字节数，错误时返回-1
 * @param[in] iValue 字符串，存储方式为 先写入 ULEB128 作为字节长度 length，再写入 length 个字符(不包含'\0')
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamBytesByULEB128Length(const DftUTF8Char* iValue);

/**
 * @brief 向文件流中写入字节流，长度为iLength
 * @return DftInt64 写入字节数，错误时返回-1
 * @param[in,out] ioBufferStream 数据流对象
 * @param[in] iBytes 字节流数据
 * @param[in] iLength 字节流长度
 * @note
 */
DFT_PUBLIC(DftInt64) DftBufferStreamWriteBytes(DftBufferStream iBufferStream, DftByte* iBytes, DftUInt64 iLength);

/**
 * @brief 释放数据流对象，并把该对象置空
 * @return DftStatus \ref DFT_SUCCESS 执行成功；其他值，执行失败
 * @param[in,out] ioBufferStream 数据流对象
 * @note
 */
DFT_PUBLIC(DftStatus) DftBufferStreamRelease(DftBufferStream* ioBufferStream);

#endif

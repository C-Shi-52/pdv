
/**
 * @file DftTypes.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2025-01-18
 * @brief 概述：定义DftBase库中的基本数据类型
 * @details 详细说明
 */

#ifndef DFT_TYPES_H
#define DFT_TYPES_H

#include <cwchar>

#if defined(x64)
/** @brief 指针 */
typedef long long DftIntptr;
/** @brief 指向指针的指针 */
typedef long long* DftPIntptr;
/** @brief 无符号指针 */
typedef unsigned long long DftUIntptr;
/** @brief 指向无符号指针的指针 */
typedef unsigned long long* DftPUIntptr;
#else
/** @brief 指针 */
typedef int DftIntptr;
/** @brief 指向指针的指针 */
typedef int* DftPIntptr;
/** @brief 无符号指针 */
typedef unsigned int DftUIntptr;
/** @brief 指向无符号指针的指针 */
typedef unsigned int* DftPUIntptr;
#endif
/** @brief void */
typedef void DftVoid;
/** @brief 句柄 */
typedef void* DftHandle;
/** @brief 布尔型 */
typedef int DftBool;
/** @brief 字节 */
typedef unsigned char DftByte;
/** @brief 字 */
typedef unsigned short DftWord;
/** @brief 整数 */
typedef int DftInt;
/** @brief 无符号整数 */
typedef unsigned int DftUInt;
/** @brief 8位整数 */
typedef char DftInt8;
/** @brief 8位无符号整数 */
typedef unsigned char DftUInt8;
/** @brief 16位整数 */
typedef short DftInt16;
/** @brief 16位无符号整数 */
typedef unsigned short DftUInt16;
/** @brief 32位整数 */
typedef int DftInt32;
/** @brief 32位无符号整数 */
typedef unsigned int DftUInt32;
/** @brief 64位整数 */
typedef long long DftInt64;
/** @brief 64位无符号整数 */
typedef unsigned long long DftUInt64;
/** @brief 单精度浮点数 */
typedef float DftFloat;
/** @brief 双精度浮点数 */
typedef double DftDouble;
/** @brief 64位有符号长整型 */
typedef long long DftLong64;
/** @brief DftLong64对应指针 */
typedef long long* DftPLong64;
/** @brief 64位无符号长整型 */
typedef unsigned long long DftULong64;
/** @brief DftULong64对应指针 */
typedef unsigned long long* DftPULong64;
/** @brief 64位无符号双字类型 */
typedef unsigned long long DftDWord64;
/** @brief DftDWord64对应指针 */
typedef unsigned long long* DftPDWord64;
#ifdef __unix__
/** @brief 无符号双字类型 */
typedef unsigned int DftDWord;
/** @brief 长整型 */
typedef int DftLong;
/** @brief 宽字符类型 */
typedef unsigned short DftWChar;
#else
/** @brief 无符号双字类型 */
typedef unsigned long DftDWord;
/** @brief 长整型 */
typedef long DftLong;
/** @brief 宽字符类型 */
typedef wchar_t DftWChar;
#endif
/** @brief utf-8字符 */
typedef char DftUTF8Char;
#if defined _UNICODE || defined UNICODE
/** @brief unicode字符 */
typedef wchar_t DftUniChar;
#else
/** @brief unicode字符 */
typedef char DftUniChar;
#endif
/** @brief 单精度浮点型二维向量 */
typedef float DftVector2F[2];
/** @brief 单精度浮点型二维点 */
typedef float DftPoint2F[2];
/** @brief 单精度浮点型三维向量 */
typedef float DftVector3F[3];
/** @brief 单精度浮点型三维点 */
typedef float DftPoint3F[3];
/** @brief 单精度浮点型四维向量 */
typedef float DftVector4F[4];
/** @brief 单精度浮点型4X4矩阵 */
typedef float DftMatrix4F[4][4];
/** @brief 双精度浮点型二维向量 */
typedef double DftVector2D[2];
/** @brief 双精度浮点型二维点 */
typedef double DftPoint2D[2];
/** @brief 双精度浮点型三维向量 */
typedef double DftVector3D[3];
/** @brief 双精度浮点型三维点 */
typedef double DftPoint3D[3];
/** @brief 双精度浮点型四维向量 */
typedef double DftVector4D[4];
/** @brief 双精度浮点型4X4矩阵 */
typedef double DftMatrix4D[4][4];
/** @brief XML 文档句柄 */
typedef void* DftXmlHandle;
/** @brief XML 节点句柄 */
typedef void* DftXmlNodeHandle;

#endif
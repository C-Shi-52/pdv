/**
 * @file PDVTypes.h
 * @author 
 * @version 1.0
 * @date 
 * @brief 概述：定义数据类型
 * @details 详细说明
 */

#ifndef PDVTYPES_H
#define PDVTYPES_H

#ifdef __unix__
/** @brief 宽字符 */
typedef unsigned short PDV_WCHAR;
/** @brief 宽字符串 */
typedef unsigned short* LPDKWSTR;
/** @brief 宽字符常量字符串 */
typedef const unsigned short* LPCDKWSTR;
/** @brief 宽字符 */
typedef PDV_WCHAR DK_WCHAR;
#else
/** @brief 宽字符 */
typedef wchar_t PDV_WCHAR;
#endif
/** @brief 字符 */
typedef char PDV_CHAR;
#endif
#pragma once

/**
 * @file DftDefine.h
 * @author
 * @version 1.0
 * @date
 * @brief 概述：类型定义
 * @details 详细说明
 */

#include "DftTypes.h"

#ifdef __unix__
#include "stdlib.h"
#include <stdarg.h>
#endif

// clang-format off
#ifndef SAFE_DELETE
#define SAFE_DELETE(p) {if(p) {delete (p);(p)=NULL;}}
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) {if(p) {delete[] (p);(p)=NULL;}}
#endif

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p) {if(p) {(p)->Release();(p)=NULL;}}
#endif

#ifndef SAFE_SETPDATA
#define SAFE_SETPDATA(pDst, pSrc) {if(pDst&&pSrc) *pDst=*pSrc;}
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef ASSERT
#define ASSERT(exp) ((void)0)
#endif

#define DFT_INVALID_ID DftUInt64(0)

#define DFT_MIN_FLOAT (-3.402823466e+38F)
#define DFT_MAX_FLOAT (3.402823466e+38F)
#define DFT_MIN_DOUBLE (-1.7976931348623158e+308)
#define DFT_MAX_DOUBLE (1.7976931348623158e+308)

#define DFT_ZERO (0.000001f)
#define DFT_D_ZERO (0.000001)
#define DFT_EPSILON (0.001f)
#define DFT_D_EPSILON (0.001)
#define DFT_PI (3.141592654f)
#define DFT_D_PI (3.14159265358979323846)

#ifndef DEGREE_TO_RADIAN_F
#define DEGREE_TO_RADIAN_F(degree) ((degree) * (DFT_PI / 180.0f))
#endif
#ifndef REDIAN_TO_DEGREE_F
#define REDIAN_TO_DEGREE_F(radian) ((radian) * (180.0f / DFT_PI))
#endif
#ifndef DEGREE_TO_RADIAN_D
#define DEGREE_TO_RADIAN_D(degree) ((degree) * (DFT_D_PI / 180.0))
#endif
#ifndef RADIAN_TO_DEGREE_D
#define RADIAN_TO_DEGREE_D(radian) ((radian) * (180.0 / DFT_D_PI))
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

// 文件路径长度最大值
#define DFT_MAX_PATH 260

// 常用字符串
// 结束符
#define DFT_STRING_NULL '\0'

// 控制符
#define DFT_SPACE ' '
#define DFT_FULL_SPACE '\x3000'
#define DFT_TAB '\t'
#define DFT_LF '\n'
#define DFT_CR '\r'

// 符号
#define DFT_EXCLAMATION_MARK '!'
#define DFT_QUOTATION_MARK '\"'
#define DFT_SHARP '#'
#define DFT_AMPERSAND '&'
#define DFT_ASTERISK '*'
#define DFT_PLUS '+'
#define DFT_MINUS '-'
#define DFT_DOT '.'
#define DFT_SLASH '/'
#define DFT_COLON ':'
#define DFT_LESS_THAN_SIGN '<'
#define DFT_GREATER_THAN_SIGN '>'
#define DFT_QUESTION_MARK '\?'
#define DFT_AT '@'
#define DFT_LEFT_SQUARE_BRACKET '['
#define DFT_BACKSLASH '\\'
#define DFT_RIGHT_SQUARE_BRACKET ']'
#define DFT_VERTICAL_LINE '|'
#define DFT_POWER '^'
#define DFT_SINGLE_QUOTATION_MARK '\''
#define DFT_SEMICOLON_MARK ';'
#define DFT_COMMA_MARK ','
#define DFT_LEFT_BRACKET '('
#define DFT_RIGHT_BRACKET ')'
#define DFT_PERCENT_MARK '%'
#define DFT_LEFT_BRACE '{'
#define DFT_RIGHT_BRACE '}'

#ifdef _MSC_VER
#define DFT_SYS_PATH_SEPARATOR_CHAR '\\'
#else
#define DFT_SYS_PATH_SEPARATOR_CHAR '/'
#endif

// 是否是字符串结束符
#define DFT_IsNull(ch) ((ch) == DFT_STRING_NULL)
// 是否是字符串结束符
#define DFT_IsCR(ch) ((ch) == DFT_CR)
// 是否是一行的结束符
#define DFT_IsEOL(ch) ((ch) == DFT_LF)
// 是否是空格
#define DFT_IsSpace(ch) (((ch) == DFT_SPACE) || ((ch) == DFT_FULL_SPACE))
// 是否是Tab制表符
#define DFT_IsTab(ch) ((ch) == DFT_TAB)
// 是否是可见字符
#define DFT_IsVisibleChar(ch) (!DFT_IsEOL(ch) && !DFT_IsSpace(ch) && !DFT_IsTab(ch) && !DFT_IsCR(ch))
// 是否是数字
#define DFT_IsDigit(ch) (((ch) >= '0') && ((ch) <= '9'))
// 是否是英文字母
#define DFT_IsLetter(ch) ((((ch) >= 'a') && ((ch) <= 'b')) || (((ch) >= 'A') && ((ch) <= 'B')))

#ifdef _MSC_VER
#define dft_memcpy_s memcpy_s
#define dft_memmove_s memmove_s

#define dft_strcpy_s(strDest, bufferSize, strSource) strcpy_s(strDest, bufferSize, strSource)
#define dft_strcat_s(strDest, bufferSize, strSource) strcat_s(strDest, bufferSize, strSource)

#define dft_fopen(file, path, mode) fopen_s(&file, path, mode)

#define dft_stricmp _stricmp
#define dft_strnicmp _strnicmp

#define dft_strtok_s strtok_s

#define dft_sscanf_s sscanf_s
#define dft_sprintf_s sprintf_s
#define dft_vsprintf_s vsprintf_s

#else

#define dft_memcpy_s(dest, destcount, src, srccount) memcpy(dest, src, srccount)
#define dft_memmove_s(dest, destcount, src, srccount) memmove(dest, src, srccount)

#define dft_strcpy_s(strDest, bufferSize, strSource) strncpy(strDest, strSource, bufferSize)
#define dft_strcat_s(strDest, bufferSize, strSource) strncat(strDest, strSource, bufferSize)

#define dft_fopen(file, path, mode) (file = fopen(path, mode))

#define dft_stricmp strcasecmp
#define dft_strnicmp strncasecmp

#define dft_strtok_s(strToken, strDelimit, context) strtok(strToken, strDelimit)

#define dft_sscanf_s sscanf
#define dft_sprintf_s sprintf
#define dft_vsprintf_s vsnprintf

#endif // #ifdef _MSC_VER

#define dft_memset memset
#define dft_memcmp memcmp
#define dft_memcpy memcpy
#define dft_memmove memmove

#define dft_strlen strlen
#define dft_strcmp strcmp


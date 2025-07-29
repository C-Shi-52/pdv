/**
 * @file UnicodeString.h
 * @author
 * @version 1.0
 * @date
 * @brief 概述：unicode字符的接口声明
 * @details 详细说明
 */

#ifndef UNICODESTRING_H
#define UNICODESTRING_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <memory>
#include "DftDefine.h"

#ifdef _MSC_VER

#define dft_wtof _wtof
#define dft_wtoi _wtoi
#ifdef PDVCORE_EXPORTS
#define UNICODESTRING_API __declspec(dllexport)
#else
#define UNICODESTRING_API __declspec(dllimport)
#endif
#else
#define UNICODESTRING_API
/** @brief 宽字符串转float */
DftFloat ConvertWCSToFloat(const DftWChar* szValue);
/** @brief 宽字符串转int */
DftInt ConvertWCSToInt(const DftWChar* szData);
#define dft_wtof ConvertWCSToFloat
#define dft_wtoi ConvertWCSToInt
#endif

#define CM_STRING_DOT DFT_L_CWCHAR(".")
#define CM_STRING_DOUBLE_DOTS DFT_L_CWCHAR("..")

#ifdef __unix__
#define CM_SYS_PATH_SEPARATOR DFT_L_CWCHAR('/')
#define CM_SYS_PATH_SEPARATOR_STRING DFT_L_CWCHAR("/")
#else
#define CM_SYS_PATH_SEPARATOR DFT_L_CWCHAR('\\')
#define CM_SYS_PATH_SEPARATOR_STRING DFT_L_CWCHAR("\\")
#endif

/** @brief 多字节字符串的编码方式 */
enum CM_MULTIBYTE_TYPE
{
    CM_MULTIBYTE_SYSDEFAULT = 0, ///< 采用系统设置
    CM_MULTIBYTE_UTF8 = 1,       ///< UTF-8
    CM_MULTIBYTE_ZH_CN = 936,    ///< 简体中文(GBK/GB2312)
    CM_MULTIBYTE_ZH_TW = 950,    ///< 繁体中文(BIG5)
};
/** @brief 编码转换类型 */
enum CM_CODECONVERT_TYPE
{
    CM_CODECONVERT_SYS_TO_WCHART = 0,  ///< 将系统默认编码转换为宽字符（wchar_t）
    CM_CODECONVERT_GBK_TO_WCHART,      ///< 将 GBK 编码转换为宽字符（wchar_t）
    CM_CODECONVERT_BIG5_TO_WCHART,     ///< 将 BIG5 编码转换为宽字符（wchar_t）
    CM_CODECONVERT_UTF8_TO_WCHART,     ///< 将 UTF-8 编码转换为宽字符（wchar_t）

    CM_CODECONVERT_WCHART_TO_SYS,      ///< 将宽字符（wchar_t）转换为系统默认编码
    CM_CODECONVERT_WCHART_TO_GBK,      ///< 将宽字符（wchar_t）转换为 GBK 编码
    CM_CODECONVERT_WCHART_TO_BIG5,     ///< 将宽字符（wchar_t）转换为 BIG5 编码
    CM_CODECONVERT_WCHART_TO_UTF8,     ///< 将宽字符（wchar_t）转换为 UTF-8 编码

    CM_CODECONVERT_SYS_TO_UTF8,        ///< 将系统默认编码转换为 UTF-8
    CM_CODECONVERT_SYS_TO_UTF16,       ///< 将系统默认编码转换为 UTF-16

    CM_CODECONVERT_MAXCOUNT,           ///< 最大值
};

/** @brief Unicode字符操作接口 */
class UNICODESTRING_API CUnicodeString
{
public:
    /** 构造函数 */
    CUnicodeString();
    /** 带参构造函数 */
    CUnicodeString(const DftWChar* pstrString);
    /** 带参构造函数 */
    CUnicodeString(const DftUTF8Char* pstrString, CM_MULTIBYTE_TYPE type = CM_MULTIBYTE_SYSDEFAULT);
    /** 拷贝构造函数 */
    CUnicodeString(const CUnicodeString& strString);
    /** 析构函数 */
    ~CUnicodeString();

public:
    /** @brief 查找输入字符串中的任意字符在当前字符串中第一次出现的位置 */
    DftInt FindOneOf(const DftUTF8Char* lpszCharSet) const;
    /** @brief 查找输入字符串中的任意字符在当前字符串中第一次出现的位置 */
    DftInt FindOneOf(const DftWChar* lpszCharSet) const;
    /** @brief 反向查找字符 */
    DftInt ReverseFind(DftUTF8Char ch) const;
    /** @brief 反向查找字符 */
    DftInt ReverseFind(DftWChar ch) const;
    /** @brief 查找字符 */
    DftInt Find(DftUTF8Char ch, DftUInt nStart = 0) const;
    /** @brief 查找字符 */
    DftInt Find(DftWChar ch, DftUInt nStart = 0) const;
    /** @brief 查找字符串 */
    DftInt Find(const DftUTF8Char* lpszSub, DftUInt nStart = 0) const;
    /** @brief 查找字符串 */
    DftInt Find(const DftWChar* lpszSub, DftUInt nStart = 0) const;
    /** @brief 去掉字符串末尾的特定字符，该字符为输入字符串中的任意字符 */
    void TrimRight(const DftUTF8Char* lpszTargets);
    /** @brief 去掉字符串末尾的特定字符，该字符为输入字符串中的任意字符 */
    void TrimRight(const DftWChar* lpszTargets);
    /** @brief 去掉字符串末尾的指定字符 */
    void TrimRight(DftUTF8Char chTarget);
    /** @brief 去掉字符串末尾的指定字符 */
    void TrimRight(DftWChar chTarget);
    /** @brief 去掉字符串末尾的空白 */
    void TrimRight();
    /** @brief 去掉字符串开头的特定字符，该字符为输入字符串中的任意字符 */
    void TrimLeft(const DftUTF8Char* lpszTargets);
    /** @brief 去掉字符串开头的特定字符，该字符为输入字符串中的任意字符 */
    void TrimLeft(const DftWChar* lpszTargets);
    /** @brief 去掉字符串开头的指定字符 */
    void TrimLeft(DftUTF8Char chTarget);
    /** @brief 去掉字符串开头的指定字符 */
    void TrimLeft(DftWChar chTarget);
    /** @brief 去掉字符串开头的空白 */
    void TrimLeft();
    /** @brief 替换字符 */
    void Replace(DftWChar chOld, DftWChar chNew);
    /** @brief 删除字符 */
    DftUInt Delete(DftUInt nIndex, DftUInt nCount = 1);
    /** @brief 在指定位置插入字符串 */
    DftUInt Insert(DftUInt nIndex, const DftUTF8Char* pstr);
    /** @brief 在指定位置插入字符串 */
    DftUInt Insert(DftUInt nIndex, const DftWChar* pstr);
    /** @brief 在指定位置插入字符 */
    DftUInt Insert(DftUInt nIndex, DftUTF8Char ch);
    /** @brief 在指定位置插入字符 */
    DftUInt Insert(DftUInt nIndex, DftWChar ch);
    /** @brief 移除指定字符 */
    DftUInt Remove(DftUTF8Char ch);
    /** @brief 移除指定字符 */
    DftUInt Remove(DftWChar ch);
    /** @brief 反转字符串 */
    void MakeReverse();
    /** @brief 将当前字符串转换为小写 */
    void MakeLower();
    /** @brief 将当前字符串转换为大写 */
    void MakeUpper();
    /** @brief 获取从开头开始不包含输入字符串中的任意字符的最大前缀 */
    CUnicodeString SpanExcluding(const DftUTF8Char* lpszCharSet);
    /** @brief 获取从开头开始不包含输入字符串中的任意字符的最大前缀 */
    CUnicodeString SpanExcluding(const DftWChar* lpszCharSet);
    /** @brief 获取从开头开始包含输入字符串中的任意字符的最大前缀 */
    CUnicodeString SpanIncluding(const DftUTF8Char* lpszCharSet);
    /** @brief 获取从开头开始包含输入字符串中的任意字符的最大前缀 */
    CUnicodeString SpanIncluding(const DftWChar* lpszCharSet);
    /** @brief 基于本地化设置locale以不区分大小写的方式比较当前字符串和输入字符串, 返回0时两字符串相等 */
    DftInt CollateNoCase(const DftUTF8Char* lpsz) const;
    /** @brief 基于本地化设置locale以不区分大小写的方式比较当前字符串和输入字符串, 返回0时两字符串相等 */
    DftInt CollateNoCase(const DftWChar* lpsz) const;
    /** @brief 基于本地化设置locale以区分大小写的方式比较当前字符串和输入字符串, 返回0时两字符串相等 */
    DftInt Collate(const DftUTF8Char* lpsz) const;
    /** @brief 基于本地化设置locale以区分大小写的方式比较当前字符串和输入字符串, 返回0时两字符串相等 */
    DftInt Collate(const DftWChar* lpsz) const;
    /** @brief 以不区分大小写的方式比较当前字符串和输入字符串, 返回0时两字符串相等 */
    DftInt CompareNoCase(const DftUTF8Char* lpsz) const;
    /** @brief 以不区分大小写的方式比较当前字符串和输入字符串, 返回0时两字符串相等 */
    DftInt CompareNoCase(const DftWChar* lpsz) const;
    /** @brief 以区分大小写的方式比较当前字符串和输入字符串, 返回0时两字符串相等 */
    DftInt Compare(const DftUTF8Char* lpsz) const;
    /** @brief 以区分大小写的方式比较当前字符串和输入字符串, 返回0时两字符串相等 */
    DftInt Compare(const DftWChar* lpsz) const;
    /** @brief 设置指定位置的字符 */
    void SetAt(DftUInt dwPos, DftUTF8Char ch);
    /** @brief 设置指定位置的字符 */
    void SetAt(DftUInt dwPos, DftWChar ch);
    /** @brief 清空当前字符串 */
    void Empty();
    /** @brief 返回当前字符串是否为空 */
    bool IsEmpty() const;
    /** @brief 返回当前字符串的宽字符指针 */
    DftWChar* GetBuffer() const;
    /** @brief 复制字符串并返回字符数组，内存由调用者负责释放 */
    DftWChar* DuplicateBuffer() const;
    /** @brief 获取从指定位置开始指定个数的子字符串 */
    CUnicodeString Mid(DftUInt dwStart, DftUInt dwCount) const;
    /** @brief 获取从末尾开始指定个数的子字符串 */
    CUnicodeString Right(DftUInt dwCount) const;
    /** @brief 获取从开头开始指定个数的子字符串 */
    CUnicodeString Left(DftUInt dwCount) const;
    /** @brief 获取以输入字符串中任意字符为分隔符将当前字符串拆分后的第nCount个子字符串 */
    DftInt GetSubStringBy(const DftUTF8Char* lpsz, DftInt nCount, CUnicodeString& strSub);
    /** @brief 获取以输入字符串中任意字符为分隔符将当前字符串拆分后的第nCount个子字符串 */
    DftInt GetSubStringBy(const DftWChar* lpsz, DftInt nCount, CUnicodeString& strSub);
    /** @brief 将格式化的数据写入字符串 */
    void Format(const DftWChar* pstrFormat, ...);
    /** @brief 将格式化的数据写入字符串 */
    void Format(const DftUTF8Char* pstrFormat, ...);
    /** @brief 在当前字符串的末尾追加格式化数据 */
    void AppendFormat(const DftWChar* pstrFormat, ...);
    /** @brief 在当前字符串的末尾追加格式化数据 */
    void AppendFormat(const DftUTF8Char* pstrFormat, ...);
    /** @brief 获取当前宽字节字符串的长度 */
    DftUInt GetLength() const { return m_Length; }
    /** @brief 赋值运算符 */
    CUnicodeString& operator=(const CUnicodeString& strString);
    /** @brief 赋值运算符 */
    CUnicodeString& operator=(const DftWChar* pstrString);
    /** @brief 赋值运算符 */
    CUnicodeString& operator=(const DftUTF8Char* pstrString);
    /** @brief 赋值运算符 */
    CUnicodeString& operator=(DftWChar ch);
    /** @brief 赋值运算符 */
    CUnicodeString& operator=(DftUTF8Char ch);
    /** @brief 追加运算符 */
    void operator+=(const CUnicodeString& usString);
    /** @brief 追加运算符 */
    void operator+=(const DftWChar* pstrString);
    /** @brief 追加运算符 */
    void operator+=(const DftUTF8Char* pstrString);
    /** @brief 追加运算符 */
    void operator+=(DftWChar wch);
    /** @brief 追加运算符 */
    void operator+=(DftUTF8Char ch);

    /** @brief 加法运算符 */
    friend UNICODESTRING_API CUnicodeString operator+(const CUnicodeString& s1, const CUnicodeString& s2);
    /** @brief 加法运算符 */
    friend UNICODESTRING_API CUnicodeString operator+(const CUnicodeString& s, const DftUTF8Char* pstrString);
    /** @brief 加法运算符 */
    friend UNICODESTRING_API CUnicodeString operator+(const DftUTF8Char* pstrString, const CUnicodeString& s);
    /** @brief 加法运算符 */
    friend UNICODESTRING_API CUnicodeString operator+(const CUnicodeString& s, const DftUTF8Char ch);
    /** @brief 加法运算符 */
    friend UNICODESTRING_API CUnicodeString operator+(const DftUTF8Char ch, const CUnicodeString& s);
    /** @brief 加法运算符 */
    friend UNICODESTRING_API CUnicodeString operator+(const CUnicodeString& s, const DftWChar* pstrString);
    /** @brief 加法运算符 */
    friend UNICODESTRING_API CUnicodeString operator+(const DftWChar* pstrString, const CUnicodeString& s);
    /** @brief 加法运算符 */
    friend UNICODESTRING_API CUnicodeString operator+(const CUnicodeString& s, const DftWChar ch);
    /** @brief 加法运算符 */
    friend UNICODESTRING_API CUnicodeString operator+(const DftWChar ch, const CUnicodeString& s);

    /** @brief 是否相等 */
    friend UNICODESTRING_API bool operator==(const CUnicodeString& s1, const CUnicodeString& s2);
    /** @brief 是否相等 */
    friend UNICODESTRING_API bool operator==(const CUnicodeString& s1, const DftWChar* s2);
    /** @brief 是否相等 */
    friend UNICODESTRING_API bool operator==(const CUnicodeString& s1, const DftUTF8Char* s2);
    /** @brief 是否相等 */
    friend UNICODESTRING_API bool operator==(const DftWChar* s1, const CUnicodeString& s2);
    /** @brief 是否相等 */
    friend UNICODESTRING_API bool operator==(const DftUTF8Char* s1, const CUnicodeString& s2);
    /** @brief 是否不等 */
    friend UNICODESTRING_API bool operator!=(const CUnicodeString& s1, const CUnicodeString& s2);
    /** @brief 是否不等 */
    friend UNICODESTRING_API bool operator!=(const CUnicodeString& s1, const DftWChar* s2);
    /** @brief 是否不等 */
    friend UNICODESTRING_API bool operator!=(const CUnicodeString& s1, const DftUTF8Char* s2);
    /** @brief 是否不等 */
    friend UNICODESTRING_API bool operator!=(const DftWChar* s1, const CUnicodeString& s2);
    /** @brief 是否不等 */
    friend UNICODESTRING_API bool operator!=(const DftUTF8Char* s1, const CUnicodeString& s2);

    /** @brief 按位置取字符 */
    DftWChar GetAt(DftUInt dwPos) const;

    /** @brief 转换为DftWChar类型 */
    operator const DftWChar*() const { return m_Buffer; }
    /** @brief 转换为DftUTF8Char类型 */
    operator const DftUTF8Char*() { return ToMultiByte(CM_MULTIBYTE_SYSDEFAULT); }

    /** @brief 从UTF8字符串赋值 */
    CUnicodeString& AssignUTF8(const DftUTF8Char* pstrString);
    /** @brief 转为UTF8字符串 */
    const DftUTF8Char* AsUTF8() const { return ToMultiByte(CM_MULTIBYTE_UTF8); }
    /** @brief 转换为单字节字符 */
    const DftUTF8Char* ToMultiByte(CM_MULTIBYTE_TYPE type = CM_MULTIBYTE_SYSDEFAULT) const;

    /** @brief 从UTF16字节数组赋值 */
    CUnicodeString& AssignUTF16(const DftByte* iDataBuffer, DftUInt iDataLength);

    /** @brief 字符串分割 */
    void SpanString(const CUnicodeString& strDelimit, std::vector<CUnicodeString>& arrText);

protected:
    /** @brief 从宽字符字符串初始化对象 */
    bool InitializeFromWideString(const DftWChar* pstrString);
    /** @brief 从utf8字符串初始化对象 */
    bool InitializeFromString(const DftUTF8Char* pstrString, CM_MULTIBYTE_TYPE type);
    /** @brief 初始化对象 */
    void Init()
    {
        // m_Buffer = &m_chNil;
        m_Buffer = (DftWChar*)malloc(sizeof(DftWChar));
        m_Buffer[0] = '\0';
        // m_Buffer = NULL;
    }

protected:
    /** @brief 释放缓冲区内存 */
    inline void ReleaseBuffer()
    {
        if (m_Buffer != NULL)
        {
            free(m_Buffer);
            m_Buffer = NULL;
        }
    }
    /** @brief 释放临时缓冲区内存 */
    inline void ReleaseTempBuffer()
    {
        if (m_TempBuff != NULL)
        {
            free(m_TempBuff);
            m_TempBuff = NULL;
        }
    }

protected:
    DftUInt m_Length;         ///< 长度
    DftWChar* m_Buffer;       ///< 宽字符串
    DftUTF8Char* m_TempBuff;  ///< utf8字符串

public:
    // static DftWChar m_chNil;
};

#ifdef _MSC_VER
#define DFT_L_CWCHAR(s) L##s
#else
/** @brief utf8转宽字符 */
DftWChar DFTUtf8ToWChar(DftUTF8Char szSrc);
/** @brief utf8转宽字符 */
CUnicodeString DFTUtf8ToWChar(const DftUTF8Char *szSrc);
#define DFT_L_CWCHAR(s) (DFTUtf8ToWChar(s))
#endif

#define CM_STRING_DOT DFT_L_CWCHAR(".")
#define CM_STRING_DOUBLE_DOTS DFT_L_CWCHAR("..")

#ifdef __unix__
#define CM_SYS_PATH_SEPARATOR DFT_L_CWCHAR('/')
#define CM_SYS_PATH_SEPARATOR_STRING DFT_L_CWCHAR("/")
#else
#define CM_SYS_PATH_SEPARATOR DFT_L_CWCHAR('\\')
#define CM_SYS_PATH_SEPARATOR_STRING DFT_L_CWCHAR("\\")
#endif

#endif

/**
 * @file DftBase.h
 * @author liqiang
 * @version 1.0
 * @date 2025-01-18
 * @brief 概述：DftBase基础头文件
 * @details 详细说明：提供导出库定义
 */

#ifdef __cplusplus
#define DFT_C_API_ATTRS extern "C"
#else
#define DFT_C_API_ATTRS
#endif

#ifdef _MSC_VER
#define DFT_C_API_CALL __stdcall
#ifdef DFTBASE_EXPORTS
#define DFTBASE_API __declspec(dllexport)
#else
#define DFTBASE_API __declspec(dllimport)
#endif
#else
#define DFT_C_API_CALL
#if (__GNUC__ >= 4)
#define DFTBASE_API __attribute__((visibility("default")))
#else
#define DFTBASE_API
#endif
#endif

#undef DFT_PUBLIC
#define DFT_PUBLIC(type) DFT_C_API_ATTRS DFTBASE_API type DFT_C_API_CALL

#include "DftTypes.h"
#include "DftDefine.h"
#include "DftStatus.h"

/**
 * @brief 指针内存释放
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] p 待删除指针
 * @note
 */
DFT_PUBLIC(DftStatus) DftSafeDelete(void** p);

/**
 * @brief 数组内存释放
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] p 待删除数组
 * @note
 */
DFT_PUBLIC(DftStatus) DftSafeDeleteArray(void** p);

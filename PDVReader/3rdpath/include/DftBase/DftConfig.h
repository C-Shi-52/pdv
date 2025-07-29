
#ifndef DFT_CONFIG_H
#define DFT_CONFIG_H

/**
 * @file DftConfig.h
 * @author tian.zhao
 * @version 1.0
 * @date 2025-04-08
 * @brief 概述：DftConfig头文件
 * @details 详细说明：封装解析ini配置文件的接口
 */

#include "DftTypes.h"
#include "DftBase.h"

/**
 * @brief 根据节和键获取ini配置文件对应的值
 * @return DftStatus \ref DFT_SUCCESS 成功，非 \ref DFT_SUCCESS 失败
 * @param[in] iConfigFilePath ini文件的路径
 * @param[in] iSectionName 节的名字
 * @param[in] iKeyName 键的名字
 * @param[out] oValue 输出配置的值，用完需要 \ref DftSafeDelete 释放
 * @note
 */
DFT_PUBLIC(DftStatus)
DftConfigGetDataBySectionAndKey(const DftUTF8Char* iConfigFilePath, const DftUTF8Char* iSectionName, const DftUTF8Char* iKeyName,
                                DftUTF8Char** oValue);
#endif
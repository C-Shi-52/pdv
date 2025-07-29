/**
 * @file DftPath.h
 * @author liqiang
 * @version 1.0
 * @date 2025-01-18
 * @brief 概述：路径处理
 * @details 详细说明：提供兼容不同平台的路径处理，包含路径拼接，路径分割，路径获取等操作
 */

#ifndef DFT_PATH_H
#define DFT_PATH_H

#include "DftBase.h"
/**
 * @brief 格式化路径分隔符（使用linux下的路径分隔符表示"/"）
 * @return DftStatus 0代表成功
 * @param[in] iInputPath 传入路径
 * @param[out] oOutputParth 传出路径
 * @note
 */
DFT_PUBLIC(DftStatus) DftPathFormat(const char* iInputPath, char** oOutputPath);

#endif
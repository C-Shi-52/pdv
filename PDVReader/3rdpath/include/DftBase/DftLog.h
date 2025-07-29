/**
 * @file DftLog.h
 * @author yue.rui
 * @version 1.0
 * @date 2025-01-18
 * @brief 概述：日志操作接口
 * @details 详细说明
 */

#include "DftTypes.h"
#include "DftBase.h"

#ifndef DFT_FEATUREMAKERLOG_H
#define DFT_FEATUREMAKERLOG_H

/** @brief 日志级别 */
enum DFTLEVEL
{
    DFT_LEVEL_INFO = 0,    ///< 信息
    DFT_LEVEL_DEBUG = 1,   ///< 调试
    DFT_LEVEL_WARNING = 2, ///< 警告
    DFT_LEVEL_ERROR = 3,   ///< 错误
    DFT_LEVEL_FATAL = 4    ///< 致命
};

/** @brief 通用日志Key */
enum DFTLOGINFOKEY
{
    /*******************************************************************************
     *
     *  通用日志Key
     *
     *******************************************************************************/
    DFT_CUSTOM = 0,  ///< 自定义
    DFT_VERSION = 1, ///< 软件版本标识

    /*******************************************************************************
     *
     *  转换器通用日志Key
     *
     *******************************************************************************/
    DFT_ORIGIN_CAD = 1001,                           ///< 原始模型CAD工具名称
    DFT_ORIGIN_CAD_VERSION = 1002,                   ///< 原始模型CAD工具版本
    DFT_ORIGIN_MODEL_NAME = 1003,                    ///< 原始CAD模型名
    DFT_ORIGIN_MODEL_PATH = 1004,                    ///< 原始CAD模型存储路径
    DFT_CONVERTER_CONFIG_ISHIDDENBODY = 1010,        ///< 是否导出隐藏BODY
    DFT_CONVERTER_CONFIG_ISHIDDENPART = 1011,        ///< 是否导出隐藏零部件
    DFT_CONVERTER_CONFIG_ISCOLOR = 1012,             ///< 是否导出颜色材质
    DFT_CONVERTER_CONFIG_ISATTRIBUTES = 1013,        ///< 是否导出属性参数
    DFT_CONVERTER_CONFIG_ISWIREFRAMES = 1014,        ///< 是否导出线框
    DFT_CONVERTER_CONFIG_ISGEOMETRY = 1015,          ///< 是否导出几何信息
    DFT_CONVERTER_CONFIG_ISPMI = 1016,               ///< 是否导出PMI信息
    DFT_CONVERTER_STAGE_FLAG = 1020,                 ///< 模型转换阶段标识，可选值为LOAD/CONVERT/EXPORT
    DFT_CONVERTER_LOAD_TIME = 1021,                  ///< 模型打开/加载时间，单位为秒
    DFT_CONVERTER_CONVERT_TIME = 1022,               ///< 模型转换时间，单位为秒
    DFT_CONVERTER_CONVERT_NODE_NAME = 1030,          ///< 当前开始转换的模型节点名
    DFT_CONVERTER_CONVERT_NODE_FILE_NAME = 1031,     ///< 当前开始转换的模型对象关联的物理文件
    DFT_CONVERTER_CONVERT_CONVERT_PERCENTAGE = 1032, ///< 模型转换进度，单位为百分比
    DFT_CONVERTER_EXPORT_TIME = 1040,                ///< 模型导出时间，单位为秒
    DFT_CONVERTER_EXPORT_FILE_NAME = 1041,           ///< 模型导出名

    DFT_CONVERTER_SUMMARY_ORIGIN_SIZE = 1050,        ///< 原始模型大小，单位为MB
    DFT_CONVERTER_SUMMARY_NODE_COUNT = 1051,         ///< 模型节点数
    DFT_CONVERTER_SUMMARY_PART_COUNT = 1052,         ///< 模型零件数
    DFT_CONVERTER_SUMMARY_CLE_SIZE = 1053,           ///< 导出CLE后大小，单位为MB
    DFT_CONVERTER_SUMMARY_PDV_SIZE = 1054,           ///< 导出CLE后大小，单位为MB
    DFT_CONVERTER_SUMMARY_COMPRESS_PERCENTAGE = 1055 ///< 压缩转换率，单位为'%'
};

/**
 * @brief 初始化
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iName 日志文件名
 * @note
 */
DFT_PUBLIC(DftStatus) DftLogInit(const DftUTF8Char* iName);

/**
 * @brief 释放对象
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @note
 */
DFT_PUBLIC(DftStatus) DftLogUnInit();

/**
 * @brief 设置日志存放路径
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iPath 日志存放路径
 * @note
 */
DFT_PUBLIC(DftStatus) DftLogSetLogDestination(const DftUTF8Char* iPath);

/**
 * @brief 设置错误日志存放路径
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iPath 错误日志存放路径
 * @note
 */
DFT_PUBLIC(DftStatus) DftLogSetErrorDestination(const DftUTF8Char* iPath);

/**
 * @brief 设置记录间隔时间，单位为秒
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iTime 记录间隔时间
 * @note
 */
DFT_PUBLIC(DftStatus) DftLogSetLogBufferSecs(const DftUInt iTime);

/**
 * @brief 日志记录信息
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iKey 日志类型
 * @param[in] iCh 日志内容
 * @param[in] iCustomKey 自定义日志类型
 * @note
 */
DFT_PUBLIC(DftStatus) DftLogInfo(const DFTLOGINFOKEY iKey, const DftUTF8Char* iCh, const DftUTF8Char* iCustomKey = NULL);

/**
 * @brief 日志记录警告信息
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iKey 日志类型
 * @param[in] iCh 日志内容
 * @param[in] iCustomKey 自定义日志类型
 * @note
 */
DFT_PUBLIC(DftStatus) DftLogWarning(const DFTLOGINFOKEY iKey, const DftUTF8Char* iCh, const DftUTF8Char* iCustomKey = NULL);

/**
 * @brief 日志记录错误信息
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iKey 日志类型
 * @param[in] iCh 日志内容
 * @param[in] iCustomKey 自定义日志类型
 * @note
 */
DFT_PUBLIC(DftStatus) DftLogError(const DFTLOGINFOKEY iKey, const DftUTF8Char* iCh, const DftUTF8Char* iCustomKey = NULL);

#endif

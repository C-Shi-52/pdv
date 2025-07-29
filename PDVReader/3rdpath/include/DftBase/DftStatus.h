
#ifndef __DFT_STATUS_H
#define __DFT_STATUS_H

/**
 * @file DftStatus.h
 * @author
 * @version 1.0
 * @date
 * @brief 概述：状态码定义
 * @details 详细说明
 */

/** @brief 状态码 */
typedef enum
{
    /*******************************************************************************
     *
     *  GENERAL ERROR CODES
     *
     *******************************************************************************/
    DFT_SUCCESS = 0,         ///< No error
    DFT_ERROR = -1,          ///< General error
    DFT_INVALID_PARAM = -2,  ///< Invalid parameter
    DFT_MEMORY_ERROR = -100, ///< Memory error

    /*******************************************************************************
     *
     *  XML ERROR CODES
     *
     *******************************************************************************/
    DFT_XML_ERROR = -2000,                         ///< XML一般错误
    DFT_XML_PARSE_ERROR = -2001,                   ///< 解析XML文件失败
    DFT_XML_DECLARATION_ERROR = -2002,             ///< XML声明不存在
    DFT_XML_NODE_ERROR = -2010,                    ///< XML节点错误
    DFT_XML_NODE_NAME_ERROR = -2011,               ///< XML节点名错误
    DFT_XML_NODE_NAME_BOUNDS_ERROR = -2012,        ///< XML节点命名数组越界
    DFT_XML_NODE_ATTRIBUTE_NOTEXIST_ERROR = -2013, ///< XML节点属性不存在
    DFT_XML_NODE_CREATE_ERROR = -2014,             ///< 创建XML节点失败
    DFT_XML_NODE_NOTEXIST_ERROR = -2015,           ///< XML节点不存在
    DFT_XML_SAVE_ERROR = -2020,                    ///< 保存XML文件失败

    /*******************************************************************************
     *
     *  LZMA ERROR CODES
     *
     *******************************************************************************/
    DFT_LZMA_NEEDS_MORE_MEMORY = -3000, ///< 需要更多的内存

} DftStatus;

#endif // __DFT_STATUS_H

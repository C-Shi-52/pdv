/**
 * @file DftXml.h
 * @author liuchang
 * @version 1.0
 * @date 2025-01-19
 * @brief 概述：XML文档操作接口
 * @details
 * 详细说明：提供XML文档的基本操作功能，包括：XML文档的加载和保存、XML节点的增删改查、XML节点属性的设置和获取、XML节点文本的设置和获取、支持XML节点的遍历和查找
 */

#ifndef DFT_XML_H
#define DFT_XML_H

#include "DftBase.h"
#include "DftTypes.h"
#include "DftStatus.h"

/**
 * @brief 从文件加载 XML 内容
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlFileName XML 文件的路径
 * @param[out] oXmlHandle 加载的 XML 文档对象
 * @note 确保文件路径正确且文件存在
 */
DFT_PUBLIC(DftStatus) DftXmlLoadFromFile(const char* iXmlFileName, DftXmlHandle* oXmlHandle);

/**
 * @brief 从字符串加载 XML 内容
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlString XML 字符串
 * @param[out] oXmlHandle 加载的 XML 文档对象
 * @note 确保字符串不为空
 */
DFT_PUBLIC(DftStatus) DftXmlLoadFromString(const char* iXmlString, DftXmlHandle* oXmlHandle);

/**
 * @brief 输出 XML 文档内容
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlHandle XML 文档对象
 * @param[out] oXmlString XML 文档内容
 * @note 使用后需要明确调用释放 oXmlString
 */
DFT_PUBLIC(DftStatus) DftXmlOutputToString(DftXmlHandle iXmlHandle, char** oXmlString);

/**
 * @brief 保存 XML 文档到文件
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlHandle XML 文档对象
 * @param[in] iXmlFileName XML 文件路径
 * @note 确保文件路径正确且文件存在
 */
DFT_PUBLIC(DftStatus) DftXmlSaveToFile(DftXmlHandle iXmlHandle, const char* iXmlFileName);

/**
 * @brief 获取 XML 文档编码
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlHandle XML 文档对象
 * @param[out] oEncoding XML 文档编码
 * @note 使用后需要明确调用释放 oEncoding
 */
DFT_PUBLIC(DftStatus) DftXmlGetEncoding(DftXmlHandle iXmlHandle, char** oEncoding);

/**
 * @brief 释放 XML 文档对象
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlHandle XML 文档对象
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlReleaseHandle(DftXmlHandle* iXmlHandle);

/**
 * @brief 获取 XML 根节点
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlHandle XML 文档对象
 * @param[out] oRootNode XML 根节点
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlGetRootNode(DftXmlHandle iXmlHandle, DftXmlNodeHandle* oRootNode);

/**
 * @brief 获取 XML 文档对象
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[out] oXmlHandle XML 文档对象
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlGetHandle(DftXmlNodeHandle iXmlNode, DftXmlHandle* oXmlHandle);

/**
 * @brief 获取 XML 节点的父节点
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[out] oParentNode 父节点
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlGetParentNode(DftXmlNodeHandle iXmlNode, DftXmlNodeHandle* oParentNode);

/**
 * @brief 获取 XML 节点的第一个子节点
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[out] oChildNode 子节点
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlGetFirstChildNode(DftXmlNodeHandle iXmlNode, DftXmlNodeHandle* oChildNode);

/**
 * @brief 获取 XML 节点的最后一个子节点
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[out] oLastChildNode 最后一个子节点
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlGetLastChildNode(DftXmlNodeHandle iXmlNode, DftXmlNodeHandle* oLastChildNode);

/**
 * @brief 追加 XML 子节点
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[in] iNodeName 节点名
 * @param[out] oChildNode 子节点
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlInsertEndChildNode(DftXmlNodeHandle iXmlNode, const char* iNodeName, DftXmlNodeHandle* oChildNode);

/**
 * @brief 删除 XML 子节点
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlRemoveChildNode(DftXmlNodeHandle iXmlNode);

/**
 * @brief 获取 XML 节点的下一个兄弟节点
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[out] oNextSiblingNode 下1个兄弟节点
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlGetNextSiblingNode(DftXmlNodeHandle iXmlNode, DftXmlNodeHandle* oNextSiblingNode);

/**
 * @brief 获取 XML 节点的上一个兄弟节点
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[out] oPreviousSiblingNode 上一个兄弟节点
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlGetPreviousSiblingNode(DftXmlNodeHandle iXmlNode, DftXmlNodeHandle* oPreviousSiblingNode);

/**
 * @brief 追加 XML 兄弟节点
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[in] iNodeName 节点名
 * @param[out] oSiblingNode 兄弟节点
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlInsertEndSiblingNode(DftXmlNodeHandle iXmlNode, const char* iNodeName, DftXmlNodeHandle* oSiblingNode);

/**
 * @brief 按节点名和节点属性查找 XML 节点
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[in] iNodeName 节点名
 * @param[in] iAttributeName 属性名
 * @param[in] iAttributeValue 属性值
 * @param[out] oNode 查找到的节点
 * @note
 */
DFT_PUBLIC(DftStatus)
DftXmlFindNode(DftXmlNodeHandle iXmlNode, const char* iNodeName, const char* iAttributeName, const char* iAttributeValue, DftXmlNodeHandle* oNode);

/**
 * @brief 获取 XML 节点名
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[out] oNodeName 节点名
 * @note 使用后需要明确调用释放 oNodeName
 */
DFT_PUBLIC(DftStatus) DftXmlGetNodeName(DftXmlNodeHandle iXmlNode, char** oNodeName);

/**
 * @brief 设置 XML 节点名
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[in] iNodeName 节点名
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlSetNodeName(DftXmlNodeHandle iXmlNode, const char* iNodeName);

/**
 * @brief 获取 XML 节点文本
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[out] oNodeText 节点文本
 * @note 使用后需要明确调用释放 oNodeName
 */
DFT_PUBLIC(DftStatus) DftXmlGetNodeText(DftXmlNodeHandle iXmlNode, char** oNodeName);

/**
 * @brief 设置 XML 节点文本
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[in] iNodeText 节点文本
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlSetNodeText(DftXmlNodeHandle iXmlNode, const char* iNodeText);

/**
 * @brief 获取 XML 节点属性值
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[in] iAttributeName 属性名
 * @param[out] oAttributeValue 属性值
 * @note 使用后需要明确调用释放 oAttributeValue
 */
DFT_PUBLIC(DftStatus) DftXmlGetNodeAttribute(DftXmlNodeHandle iXmlNode, const char* iAttributeName, char** oAttributeValue);

/**
 * @brief 设置 XML 节点属性值
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[in] iAttributeName 属性名
 * @param[in] iAttributeValue 属性值
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlSetNodeAttribute(DftXmlNodeHandle iXmlNode, const char* iAttributeName, const char* iAttributeValue);

/**
 * @brief 获取 XML 节点的子节点数量
 * @return DftStatus 0 代表成功，非 0 代表失败
 * @param[in] iXmlNode XML 节点
 * @param[out] oCount 子节点数量
 * @note
 */
DFT_PUBLIC(DftStatus) DftXmlGetChidrenNodeCount(DftXmlNodeHandle iXmlNode, DftUInt32* oCount);

#endif // DFT_XML_H

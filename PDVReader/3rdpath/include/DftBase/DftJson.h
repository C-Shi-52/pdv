
#ifndef DFT_JSON_H
#define DFT_JSON_H

/**
 * @file DftJson.h
 * @author yue.rui
 * @version 1.0
 * @date 2025-01-18
 * @brief 概述：json文件操作接口
 * @details 详细说明
 */

#include "DftTypes.h"
#include "DftBase.h"

/** @brief json节点对象 */
typedef void* DftJson;

/**
 * @brief 将字符串解析为json节点
 * @return DftJson 返回json节点对象
 * @param[in] iValue 具备json格式的字符串
 * @note 调用者将要负责管理解析创建出的对象内存，调用对应的内存析构接口
 */
DFT_PUBLIC(DftJson) DftJsonParse(const DftUTF8Char* iValue);

/**
 * @brief 将json节点解析为字符串
 * @return DftUTF8Char *，返回具备json格式的字符串
 * @param[in] iItem json节点对象
 * @note
 */
DFT_PUBLIC(DftUTF8Char*) DftJsonPrint(const DftJson iItem);

/**
 * @brief 删除节点，释放内存
 * @return DftStatus \ref DFT_SUCCESS 执行成功；其他值，执行失败
 * @param[in] iItem json节点对象
 * @note
 */
DFT_PUBLIC(DftStatus) DftJsonDelete(DftJson* iItem);

/**
 * @brief 返回队列节点的数量
 * @return DftInt 队列节点的数量
 * @param[in] iArray json队列节点
 * @note
 */
DFT_PUBLIC(DftInt) DftJsonGetArraySize(const DftJson iArray);

/**
 * @brief 从队列节点中检索json节点
 * @return DftJson 返回检索到的节点对象，如果不成功则返回NULL
 * @param[in] iArray json队列节点
 * @param[in] iIndex 索引
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonGetArrayItem(const DftJson iArray, DftInt iIndex);

/**
 * @brief 从对象节点中检索对应的字符串json节点
 * @return DftJson 返回检索到的节点对象，如果不成功则返回NULL，该接口为大小写不敏感
 * @param[in] iObject 对象节点
 * @param[in] iString 对象属性名称
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonGetObjectItem(const DftJson iObject, const DftUTF8Char* const iString);

/**
 * @brief 判断对象节点中是否存在对应的字符串json节点
 * @return DftBool TRUE表示存在，FALSE表示不存在
 * @param[in] iObject 对象节点
 * @param[in] iString 对象属性名称
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonHasObjectItem(const DftJson iObject, const DftUTF8Char* iString);

/**
 * @brief 获取对象节点中是对应的字符串json节点的值
 * @return DftUTF8Char * 返回字符串对象的值
 * @param[in] iItem 对象节点
 * @note
 */
DFT_PUBLIC(DftUTF8Char*) DftJsonGetStringValue(const DftJson iItem);

/**
 * @brief 获取对象节点中是对应的数值json节点的值
 * @return DftDouble 返回字符串对象的值
 * @param[in] iItem 对象节点
 * @note
 */
DFT_PUBLIC(DftDouble) DftJsonGetNumberValue(const DftJson iItem);

/**
 * @brief 判断对象节点是否有效
 * @return DftBool 返回判断结果，TRUE代表节点无效，FALSE代表有效
 * @param[in] iItem 对象节点
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonIsInvalid(const DftJson iItem);

/**
 * @brief 判断对象节点是否为false
 * @return DftBool 返回判断结果
 * @param[in] iItem 对象节点
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonIsFalse(const DftJson iItem);

/**
 * @brief 判断对象节点是否为true
 * @return DftBool 返回判断结果
 * @param[in] iItem 对象节点
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonIsTrue(const DftJson iItem);

/**
 * @brief 判断对象节点是否为 DftBool 类型
 * @return DftBool 返回判断结果
 * @param[in] iItem 对象节点
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonIsBool(const DftJson iItem);

/**
 * @brief 判断对象节点是否为空
 * @return DftBool 返回判断结果
 * @param[in] iItem 对象节点
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonIsNull(const DftJson iItem);

/**
 * @brief 判断对象节点是否为数值
 * @return DftBool 返回判断结果
 * @param[in] iItem 对象节点
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonIsNumber(const DftJson iItem);

/**
 * @brief 判断对象节点是否为字符串
 * @return DftBool 返回判断结果
 * @param[in] iItem 对象节点
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonIsString(const DftJson iItem);

/**
 * @brief 判断对象节点是否为队列
 * @return DftBool 返回判断结果
 * @param[in] iItem 对象节点
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonIsArray(const DftJson iItem);

/**
 * @brief 判断对象节点是否为对象
 * @return DftBool 返回判断结果
 * @param[in] iItem 对象节点
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonIsObject(const DftJson iItem);

/**
 * @brief 创建空节点
 * @return DftJson 返回创建节点对象
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonCreateNull();

/**
 * @brief 创建值为boolean的布尔节点
 * @return DftJson 返回创建节点对象
 * @param[in] iBoolean 节点信息
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonCreateBool(DftBool iBoolean);

/**
 * @brief 创建值为num的数字节点
 * @return DftJson 返回创建节点对象
 * @param[in] iNum 节点信息
 * @return 说明 返回创建节点对象
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonCreateNumber(DftDouble iNum);

/**
 * @brief 创建值为iString的字符串节点
 * @return DftJson 返回创建节点对象
 * @param[in] iString 节点信息
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonCreateString(const DftUTF8Char* iString);

/**
 * @brief 创建队列节点
 * @return DftJson 返回创建节点对象
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonCreateArray();

/**
 * @brief 创建对象节点
 * @return DftJson 返回创建节点对象
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonCreateObject();

/**
 * @brief 将iItem节点添加到iArray队列中
 * @return DftBool 返回添加是否成功
 * @param[in] iArray 要创建的节点信息
 * @param[in] iItem 创建个数
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonAddItemToArray(DftJson iArray, DftJson iItem);

/**
 * @brief 将iItem节点添加到iObject属性中
 * @return DftBool 返回创建节点对象是否成功
 * @param[in] iObject 基础节点对象
 * @param[in] iString 属性名称
 * @param[in] iItem 添加的节点
 * @note
 */
DFT_PUBLIC(DftBool) DftJsonAddItemToObject(DftJson iObject, const DftUTF8Char* iString, DftJson iItem);

/**
 * @brief 将数字添加到iObject中
 * @return DftJson 返回添加的节点对象，如果创建或者添加失败则返回NULL
 * @param[in] iObject 基础节点对象
 * @param[in] iName 添加节点名称
 * @param[in] iValue 添加数值
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonAddNumberToObject(DftJson iObject, const DftUTF8Char* iName, DftDouble iValue);

/**
 * @brief 将字符串添加到iObject中
 * @return DftJson 返回添加的节点对象，如果创建或者添加失败则返回NULL
 * @param[in] iObject 基础节点对象
 * @param[in] iName 添加节点名称
 * @param[in] iString 添加字符串内容
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonAddStringToObject(DftJson iObject, const DftUTF8Char* iName, const DftUTF8Char* iString);

/**
 * @brief 给iObject对象添加一个名为name的对象节点属性
 * @return DftJson 返回添加的节点对象，如果创建或者添加失败则返回NULL
 * @param[in] iObject 要创建的节点信息
 * @param[in] iName 要添加的属性名称
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonAddObjectToObject(DftJson iObject, const DftUTF8Char* const iName);

/**
 * @brief 给iObject对象添加一个名为name的队列节点属性
 * @return DftJson 返回添加的节点对象，如果创建或者添加失败则返回NULL
 * @param[in] iObject 要创建的节点信息
 * @param[in] iName 要添加的属性名称
 * @note
 */
DFT_PUBLIC(DftJson) DftJsonAddArrayToObject(DftJson iObject, const DftUTF8Char* const iName);

#endif
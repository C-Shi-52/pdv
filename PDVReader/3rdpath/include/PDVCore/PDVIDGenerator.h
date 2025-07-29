/**
 * @file PDVIDGenerator.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2025-01-02
 * @brief 概述：ID生成器
 * @details 详细说明
 */

#ifndef PDVIDGENERATOR_H
#define PDVIDGENERATOR_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

/** @brief ID生成器接口 */
class PDVCORE_API IDGenerator
{
public:
    /**
     * @brief 新建对象ID
     * @return DftUInt64
     * @param[in] iType 对象类型，见 OBJTYPE
     * @note
     */
    static DftUInt64 NewObjectID(DftUInt iType);

    /**
     * @brief 创建字符串的UUID
     * @return DftUTF8Char
     * @note 该UUID不含连接符‘-’，字符串长度为32
     */
    static DftUTF8Char* NewUUIDString();
};

} // namespace pdv

} // namespace kernel

#endif
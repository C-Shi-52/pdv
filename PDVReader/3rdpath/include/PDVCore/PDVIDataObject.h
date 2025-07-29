/**
 * @file PDVIDataObject.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-17
 * @brief 概述：IDataObject，数据对象接口类
 * @details 详细说明
 */

#ifndef PDVIDATAOBJECT_H
#define PDVIDATAOBJECT_H

#include "PDVBase.h"
#include "PDVISceneData.h"

namespace kernel
{

namespace pdv
{

/** @brief 数据对象接口类 */
class PDVCORE_API IDataObject
{
public:
    /**
     * @brief 获取对象ID
     * @return DftUInt64 对象ID
     * @note
     */
    virtual DftUInt64 GetID() = 0;

    /**
     * @brief 获取所属场景数据对象接口
     * @return ISceneData 所属场景数据对象接口
     * @note
     */
    virtual ISceneData* GetOwner() = 0;

    /**
     * @brief 设置所属场景数据对象接口
     * @return PDV_RESULT
     * @param[in] iSceneData 所属场景数据对象接口
     * @note
     */
    virtual PDV_RESULT SetOwner(ISceneData *iSceneData) = 0;

    /**
    * @brief 传出数据长度
    * @return DftLong64 见返回数据大小
    * @note
    */
    virtual DftInt64 GetDataLength() const = 0;

    /**
    * @brief 从二进制数据流中读取数据信息
    * @return DftInt64 数据长度
    * @param[in] iStreamBuffer 数据流
    * @param[in] iBufferLength 数据流长度
    * @note
    */
    virtual DftInt64 ReadData(const PDV_CHAR *iStreamBuffer, DftInt64 iBufferLength) = 0;

    /**
    * @brief 向二进制数据流中写入数据信息
    * @return DftInt64 数据长度
    * @param[in,out] ioStreamBuffer 数据流
    * @param[in] iBufferLength 数据流长度
    * @note
    */
    virtual DftInt64 WriteData(PDV_CHAR *ioStreamBuffer, DftInt64 iBufferLength) const = 0;

    /**
    * @brief 输出数据信息到json文件中
    * @param[in] iJsonNode json指针
    * @note
    */
    virtual void Output(DftJson iJsonNode) const = 0;
};

} // namespace pdv

} // namespace kernel

#endif
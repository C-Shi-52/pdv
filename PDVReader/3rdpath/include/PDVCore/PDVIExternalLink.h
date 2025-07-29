/**
 * @file PDVIExternalLink.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：外部链接对象的接口声明
 * @details 详细说明
 */

#ifndef PDVIEXTERNALLINK_H
#define PDVIEXTERNALLINK_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief PDV数据对象标识映射的接口 */
class PDVCORE_API IIDMap
{
public:
    /**
     * @brief 获取当前文件内的ID标识
     * @return DftUInt64 当前文件内的ID标识
     * @note
     */
    virtual DftUInt64 GetID() = 0;

    /**
     * @brief 设置当前文件内的ID标识
     * @return PDV_RESULT
     * @param[in] iID 当前文件内的ID标识
     * @note
     */
    virtual PDV_RESULT SetID(const DftUInt64 &iID) = 0;

    /**
     * @brief 获取外部PDV文件的ID标识
     * @return DftUInt64 外部PDV文件的ID标识
     * @note
     */
    virtual DftUInt64 GetExternalID() = 0;

    /**
     * @brief 设置外部PDV文件的ID标识
     * @return PDV_RESULT
     * @param[in] iExternalID 外部PDV文件的ID标识
     * @note
     */
    virtual PDV_RESULT SetExternalID(const DftUInt64 &iExternalID) = 0;
};

/** @brief PDV文件链接的接口 */
class PDVCORE_API IFileMap
{
public:
    /**
     * @brief 获取外部PDV文件路径，采用当前文件路径的相对路径表达
     * @return CUnicodeString 外部PDV文件路径
     * @note
     */
    virtual CUnicodeString GetPath() = 0;

    /**
     * @brief 设置外部PDV文件路径
     * @return PDV_RESULT
     * @param[in] iPath 外部PDV文件路径
     * @note
     */
    virtual PDV_RESULT SetPath(const CUnicodeString &iPath) = 0;

    /**
     * @brief 获取外部PDV文件链接的数据对象标识映射数据
     * @return PDV_RESULT
     * @param[out] oObjIDMapArray 外部PDV文件链接的数据对象标识映射数据
     * @note
     */
    virtual PDV_RESULT GetObjectIDMapArray(std::vector<IIDMap *> &oObjIDMapArray) = 0;

    /**
     * @brief 添加外部PDV文件链接的数据对象标识映射数据
     * @return IIDMap * 外部PDV文件链接的数据对象标识映射数据
     * @note
     */
    virtual IIDMap *AddObjectIDMap() = 0;

    /**
     * @brief 清除外部PDV文件链接的数据对象标识映射数据
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearObjectIDMapArray() = 0;
};

/** @brief 外部链接对象的接口 */
class PDVCORE_API IExternalLink : public IDataObject
{
public:
    /**
     * @brief 获取外部文件个数
     * @return DftUInt 外部文件个数
     * @note
     */
    virtual DftUInt GetFileMapCount() = 0;

    /**
     * @brief 获取外部PDV文件链接数据
     * @return PDV_RESULT
     * @param[out] oFileMapArray 外部PDV文件链接数据
     * @note
     */
    virtual PDV_RESULT GetFileMapArray(std::vector<IFileMap *> &oFileMapArray) = 0;

    /**
     * @brief 添加外部PDV文件链接数据
     * @return IFileMap * 外部PDV文件链接数据
     * @note
     */
    virtual IFileMap *AddFileMap() = 0;

    /**
     * @brief 清除外部PDV文件链接数据
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT ClearFileMapArray() = 0;
};

} // namespace pdv

} // namespace kernel

#endif
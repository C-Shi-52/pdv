/**
 * @file PDVIResource.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-17
 * @brief 概述：IResource的接口声明
 * @details 详细说明
 */

#ifndef PDVIRESOURCE_H
#define PDVIRESOURCE_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 资源文件的类型 */
enum ResourceType
{
    RESOURCETYPE_NULL = 0,              ///< 未知
    RESOURCETYPE_IMAGE = 1,             ///< 图像类型
    RESOURCETYPE_AUDIO = 2,             ///< 音频类型
    RESOURCETYPE_VIDEO = 3,             ///< 视频类型
    RESOURCETYPE_FONT = 4,              ///< 字体类型
    RESOURCETYPE_DOCUMENT = 5,          ///< 文档类型
    RESOURCETYPE_OTHER = 6,             ///< 其他附件
    RESOURCETYPE_VIEWDATA = 101,        ///< 视图数据
    RESOURCETYPE_FRAMEANIMATIONDATA = 102,    ///< 帧动画数据
    RESOURCETYPE_MATERIALDATA = 103,          ///< 材质应用数据
    RESOURCETYPE_SECTIONDATA = 104,           ///< 剖切补面数据
    RESOURCETYPE_VIEWLISTDATA = 105,          ///< 视图列表数据
    RESOURCETYPE_ANIMATIONDATA = 106,         ///< 动画数据
    RESOURCETYPE_ANIMATIONCLIPDATA = 107,     ///< 动画片段数据
    RESOURCETYPE_COLORBARCONFIG = 108,        ///< colorBar配置
    RESOURCETYPE_TABLEDATA = 109              ///< 标签数据
};

/** @brief 资源的接口 */
class PDVCORE_API IResource : public IDataObject
{
public:
    /**
     * @brief 获取资源文件名
     * @return PDV_RESULT
     * @param[out] oName 资源文件名
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString &oName) = 0;

    /**
     * @brief 设置资源文件名
     * @return PDV_RESULT
     * @param[in] iName 资源文件名
     * @param[in] iNneedRead 是否需要读取文件
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString &iName, DftBool iNeedRead = FALSE) = 0;

    /**
     * @brief 获取资源文件的类型
     * @return DftUInt 资源文件的类型，见 ResourceType
     * @note
     */
    virtual DftUInt GetType() = 0;

    /**
     * @brief 设置资源文件的类型
     * @return PDV_RESULT
     * @param[in] iType 资源文件的类型，见 ResourceType
     * @note
     */
    virtual PDV_RESULT SetType(const DftUInt &iType) = 0;

    /**
     * @brief 获取资源文件的格式
     * @return PDV_RESULT
     * @param[out] oFormat 资源文件的格式
     * @note
     */
    virtual PDV_RESULT GetFormat(CUnicodeString &oFormat) = 0;

    /**
     * @brief 设置资源文件的格式
     * @return PDV_RESULT
     * @param[in] iFormat 资源文件的格式
     * @note
     */
    virtual PDV_RESULT SetFormat(const CUnicodeString &iFormat) = 0;

    /**
     * @brief 获取资源文件数据，和其二进制数据长度
     * @return PDV_RESULT
     * @param[out] oFileData 资源文件数据
     * @param[out] oLength 资源文件二进制数据长度
     * @note
     */
    virtual PDV_RESULT GetFileData(DftByte *&oFileData, DftUInt64 &oLength) = 0;

    /**
     * @brief 设置资源文件数据，和其二进制数据长度
     * @return PDV_RESULT
     * @param[in] iFileData 资源文件数据
     * @param[in] iLength 资源文件二进制数据长度
     * @note
     */
    virtual PDV_RESULT SetFileData(const DftByte *iFileData, const DftUInt64 &iLength) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
/**
 * @file DftArchive.h
 * @author tian.zhao
 * @version 1.0
 * @date 2025-01-22
 * @brief 概述：DftArchive头文件
 * @details 详细说明：封装压缩相关接口
 */

#ifndef DFT_ARCHIVE_H
#define DFT_ARCHIVE_H

#include "DftTypes.h"
#include "DftBase.h"

/**
 * @brief 把文件夹中的文件全部压缩成zip
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iFolderPath 文件夹的路径
 * @param[in] iDestZipFile 输出的压缩文件路径
 * @note
 */
DFT_PUBLIC(DftStatus) DftArchiveCompressFolderInZip(const DftUTF8Char* iFolderPath, const DftUTF8Char* iDestZipFile);

/**
 * @brief 把传入的所有文件进行压缩成zip
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iFilesPath 字符串数组，存放所有要压缩的文件的路径
 * @param[in] iFileCount 要压缩的文件的数量
 * @param[in] iDestZipFile 输出的压缩文件路径
 * @note
 */
DFT_PUBLIC(DftStatus) DftArchiveCompressFilesInZip(DftUTF8Char** iFilesPath, DftInt iFileCount, const DftUTF8Char* iDestZipFile);

/**
 * @brief 解压缩zip文件
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iZipFilePath 压缩文件路径
 * @param[in] iDestUncompressFolder 解压后的文件所在的文件夹路径
 * @note
 */
DFT_PUBLIC(DftStatus) DftArchiveUncompressFilesInZip(const DftUTF8Char* iZipFilePath, const DftUTF8Char* iDestUncompressFolder);

/**
 * @brief 把传入的缓存数据进行压缩
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iSourceBuffer 传入的缓存数据
 * @param[in] iSourceLen 传入的缓存数据的长度
 * @param[out] oDestBuffer 压缩后的缓存数据
 * @param[out] oDestLen 压缩后的缓存数据的长度
 * @note
 */
DFT_PUBLIC(DftStatus) DftArchiveCompressBufferInZip(const DftByte* iSourceBuffer, DftUInt64 iSourceLen, DftByte** oDestBuffer, DftUInt64* oDestLen);

/**
 * @brief 把传入的缓存数据进行解压缩
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iSourceBuffer 传入的缓存数据
 * @param[in] iSourceLen 传入的缓存数据的长度
 * @param[out] oDestBuffer 解压缩后的缓存数据
 * @param[out] oDestLen  解压缩后的缓存数据的长度
 * @note
 */
DFT_PUBLIC(DftStatus) DftArchiveUncompressBufferInZip(const DftByte* iSourceBuffer, DftUInt64 iSourceLen, DftByte** oDestBuffer, DftUInt64* oDestLen);

/**
 * @brief 把传入的缓存数据进行压缩
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iSourceBuffer 未压缩的数据
 * @param[in] iSourceLen 未压缩的数据长度
 * @param[out] oDestBuffer 压缩后的数据，需要初始化成iSorceLen*2
 * @param[out] oDestLen  压缩后的数据长度（包含属性(5Byte)+数据区长度(8Byte)）
 * @note
 */
DFT_PUBLIC(DftStatus) DftArchiveCompressBufferIn7z(const DftByte* iSourceBuffer, DftUInt64 iSourceLen, DftByte* oDestBuffer, DftUInt64* oDestLen);

/**
 * @brief 把传入的缓存数据进行解压缩
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iSourceBuffer 压缩数据
 * @param[in] iSourceLen 压缩数据的长度（包含属性(5Byte)+数据区长度(8Byte)）
 * @param[out] oDestBuffer 解压缩后的数据
 * @param[out] oDestLen  解压缩后的数据的长度
 * @note
 */
DFT_PUBLIC(DftStatus) DftArchiveUncompressBufferIn7z(const DftByte* iSourceBuffer, DftUInt64 iSourceLen, DftByte* oDestBuffer, DftUInt64* oDestLen);

/**
 * @brief 获取lzma解压缩后的数据长度
 * @return DftUInt64 失败返回值小于0
 * @param[in] iSourceBuffer lzma压缩后的数据
 * @param[in] iSourceLen lzma压缩后的数据长度
 * @note
 */
DFT_PUBLIC(DftUInt64) GetUncompressBufferSizeIn7z(const DftByte* iSourceBuffer, DftUInt64 iSourceLen);
#endif

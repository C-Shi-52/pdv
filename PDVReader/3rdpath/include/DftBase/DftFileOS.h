/**
 * @file DftFileOS.h
 * @author zhangheng
 * @version 1.0
 * @date 2025-01-19
 * @brief 概述：路径处理
 * @details 详细说明：提供兼容不同平台的路径处理，包含路径拼接，路径分割，路径获取等操作
 */

#ifndef DFT_DftFileOS_H
#define DFT_DftFileOS_H
#include "DftBase.h"

#include "DftDefine.h"
#include "DftTypes.h"

/** @brief 文件路径信息 */
struct Dft_FOLDER_PATHINFO;

/**
 * @brief 判断文件路径是否存在
 * @return DftBool TRUE表示文件路径存在，FALSE表示不存在
 * @param[in] iFilename 传入文件路径
 * @note
 */
DFT_PUBLIC(DftBool) DftIsFileExist(const DftUTF8Char* iFilename);

/**
 * @brief 创建一个文件夹，如果父文件夹不存在，则递归创建
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[in] iPath 传入文件夹路径
 * @note
 */
DFT_PUBLIC(DftStatus) DftRecursiveCreateDirectoryByPath(const DftUTF8Char* iPath);

/**
 * @brief 获取可执行文件路径
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[out] oStrPathOut 输出路径，用完需要 \ref DftSafeDelete 释放
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetExecutablePath(DftUTF8Char** oStrPathOut);

/**
 * @brief 获取文件大小
 * @return DftInt 文件大小 (字节)
 * @param[in] iFilePath 传入文件路径
 * @note
 */
DFT_PUBLIC(DftInt) DftGetFileSize(const DftUTF8Char* iFilePath);

/**
 * @brief 规范化路径字符串
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[in] iStrPathIn 传入路径字符串
 * @param[out] oStrPathOut 规范化后的路径字符串, 用完需要 \ref DftSafeDelete 释放;
 * @note
 */
DFT_PUBLIC(DftStatus) DftNormalizePathString(const DftUTF8Char* iStrPathIn, DftUTF8Char** oStrPathOut);

/**
 * @brief 比较两个路径是否相同
 * @return DftBool TRUE表示文件路径存在，FALSE表示不存在
 * @param[in] iStrPath1 第一个路径字符串
 * @param[in] iStrPath2 第二个路径字符串
 * @note
 */
DFT_PUBLIC(DftBool) DftIsPathEqual(const DftUTF8Char* iStrPath1, const DftUTF8Char* iStrPath2);

/**
 * @brief 通过全路径获取父目录
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[in] iStrFullPath 全路径字符串
 * @param[out] oStrPathOut 返回父级路径，用完需要 \ref DftSafeDelete 释放
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetParentDirectoryByPath(const DftUTF8Char* iStrFullPath, DftUTF8Char** oStrPathOut);

/**
 * @brief 通过路径获取文件名(包含文件名和扩展名，不包含所在文件夹的路径；可输入非全路径)
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[in] iStrFullPath 路径字符串
 * @param[out] oFileNameOut 返回文件名称，用完需要 \ref DftSafeDelete 释放
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetFileNameByPath(const DftUTF8Char* iStrFullPath, DftUTF8Char** oFileNameOut);

/**
 * @brief 获取文件名，不包含扩展名
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[in] iStrFullPath 路径字符串
 * @param[out] oFileName 返回文件名称，用完需要 \ref DftSafeDelete 释放
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetFileNameNoExtByPath(const DftUTF8Char* iStrFullPath, DftUTF8Char** oFileName);

/**
 * @brief 通过路径获取文件所在目录
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[in] iStrFullPath 路径字符串
 * @param[out] oDirPath 返回文路径，用完需要 \ref DftSafeDelete 释放
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetDirectoryByPath(const DftUTF8Char* iStrFullPath, DftUTF8Char** oDirPath);

/**
 * @brief 通过路径获取文件扩展名(只包含扩展名，不包含文件名；可输入非全路径)
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[in] iStrFullPath 路径字符串
 * @param[out] oExtName 文件扩展名，用完需要 \ref DftSafeDelete 释放
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetFileExtByPath(const DftUTF8Char* iStrFullPath, DftUTF8Char** oExtName);

/**
 * @brief 创建文件夹路径信息对象
 * @return Dft_FOLDER_PATHINFO * 指向新创建的文件夹路径信息对象的指针
 * @note
 */
DFT_PUBLIC(Dft_FOLDER_PATHINFO*) DftCreateFolderPathInfo();

/**
 * @brief 销毁文件夹路径信息对象
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[in] iFolderPahtInfo 指向要销毁的文件夹路径信息对象的指针
 * @note
 */
DFT_PUBLIC(DftStatus) DftDestroyFolderPathInfo(Dft_FOLDER_PATHINFO* iFolderPahtInfo);

/**
 * @brief 获取子文件数量
 * @return DftInt 子文件数量
 * @param[in] iFolderPahtInfo 指向文件夹路径信息对象的指针
 * @note
 */
DFT_PUBLIC(DftInt) DftGetSubFileCount(const Dft_FOLDER_PATHINFO* iFolderPahtInfo);

/**
 * @brief 获取指定索引的子文件路径
 * @return const DftUTF8Char * 子文件路径字符串
 * @param[in] iFolderPahtInfo 指向文件夹路径信息对象的指针
 * @param[out] oIndex 子文件索引
 * @note
 */
DFT_PUBLIC(const DftUTF8Char*) DftGetSubFilePath(const Dft_FOLDER_PATHINFO* iFolderPahtInfo, size_t oIndex);

/**
 * @brief 获取子文件夹数量
 * @return DftInt 子文件夹数量
 * @param[in] iFolderPahtInfo 指向文件夹路径信息对象的指针
 * @note
 */
DFT_PUBLIC(DftInt) DftGetSubFolderCount(const Dft_FOLDER_PATHINFO* iFolderPahtInfo);

/**
 * @brief 获取指定索引的子文件夹信息
 * @return const Dft_FOLDER_PATHINFO * 指向子文件夹路径信息对象的指针
 * @param[in] iFolderPahtInfo 指向文件夹路径信息对象的指针
 * @param[out] oIndex 子文件夹索引
 * @note
 */
DFT_PUBLIC(const Dft_FOLDER_PATHINFO*) DftGetSubFolderInfo(const Dft_FOLDER_PATHINFO* iFolderPahtInfo, size_t oIndex);

/**
 * @brief 获取文件夹路径
 * @return const DftUTF8Char * 文件夹路径字符串
 * @param[in] iFolderPahtInfo 指向文件夹路径信息对象的指针
 * @note
 */
DFT_PUBLIC(const DftUTF8Char*) DftGetFolderPath(const Dft_FOLDER_PATHINFO* iFolderPahtInfo);

/**
 * @brief 获取指定路径下的所有文件和文件夹
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[in] iStrFolderPath 文件夹路径字符串
 * @param[in] iStuFolderInfo 文件列表信息
 * @param[in] iCurrentFolderOnly 是否只列出当前文件夹下的内容 (0 为否，1 为是)
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetFileFolderList(const DftUTF8Char* iStrFolderPath, Dft_FOLDER_PATHINFO* iStuFolderInfo, DftBool iCurrentFolderOnly);

/**
 * @brief 获取指定路径下的所有文件和文件夹
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[in] inputPath 文件夹路径字符串
 * @param[out] oVecFileList 文件列表
 * @param[out] oFileCount 文件列表数量
 * @param[out] oVecFolderList 文件夹列表
 * @param[out] oFolderCount 文件夹列表数量
 * @param[in] iCurrentFolderOnly 是否只列出当前文件夹下的内容 (0 为否，1 为是)
 * @note
 */
DFT_PUBLIC(DftStatus)
DftGetAllFileFolderList(DftUTF8Char* inputPath, DftUTF8Char*** iVecFileList, DftInt32* oFileCount, DftUTF8Char*** oVecFolderList,
                        DftInt32* oFolderCount, DftBool iCurrentFolderOnly);

/**
 * @brief 删除指定目录下的文件(不清除文件夹)
 * @return DftStatus \ref DFT_SUCCESS  成功，非\ref DFT_SUCCESS  失败
 * @param[in] iStrFolderName 文件夹路径字符串
 * @note
 */
DFT_PUBLIC(DftStatus) DftDeleteFilesOfDirectory(const DftUTF8Char* iStrFolderName);

/**
 * @brief 删除一个文件夹
 * @return DftStatus 0：成功，非0：失败
 * @param[in] iPath 传入文件夹路径
 * @note
 */
DFT_PUBLIC(DftStatus) DftDeleteDirectoryByPath(const DftUTF8Char* iPath);

/**
 * @brief 删除一个文件
 * @return DftStatus 0：成功，非0：失败
 * @param[in] iPath 传入文件路径
 * @note
 */
DFT_PUBLIC(DftStatus) DftDeleteFileByPath(const DftUTF8Char* iPath);

/**
 * @brief 复制一个文件夹及其下所有文件
 * @return DftStatus 0：成功，非0：失败
 * @param[in] iStrSrcFolderPath 源文件夹路径字符串
 * @param[in] iStrDstFolderPath 目标文件夹路径字符串
 * @note
 */
DFT_PUBLIC(DftStatus) DftSVCopyDirectoryFiles(DftUTF8Char* iStrSrcFolderPath, DftUTF8Char* iStrDstFolderPath);

/**
 * @brief 获取当前路径
 * @return DftStatus 0：成功，非0：失败
 * @param[out] oDirPath 当前路径，用完需要 \ref DftSafeDelete 释放
 * @note
 */
DFT_PUBLIC(DftStatus) GetCurrentDir(DftUTF8Char** oDirPath);

/**
 * @brief 获取临时路径
 * @return DftStatus 0：成功，非0：失败
 * @param[out] oDirPath 临时路径，用完需要 \ref DftSafeDelete 释放
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetTempDir(DftUTF8Char** oDirPath);

/**
 * @brief 创建临时路径
 * @return DftStatus 0：成功，非0：失败
 * @param[out] oDirPath 临时路径，用完需要 \ref DftSafeDelete 释放
 * @note
 */
DFT_PUBLIC(DftStatus) DftCreateTempDirectory(DftUTF8Char** oDirPath);

#endif
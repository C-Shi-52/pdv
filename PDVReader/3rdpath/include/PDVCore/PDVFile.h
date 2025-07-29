/**
 * @file PDVFile.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-26
 * @brief 概述：pdv文件数据处理接口
 * @details 详细说明
 */

#ifndef PDVFILE_H
#define PDVFILE_H

#include "PDVBase.h"
#include "PDVISceneData.h"

namespace kernel
{

namespace pdv
{

class ISceneData;

/** @brief pdv文件处理服务类 */
class PDVCORE_API PDVFileServices
{
public:
    /**
     * @brief 保存ISceneData数据至pdv文件
     * @return PDV_RESULT
     * @param[in] iSceneData 场景数据接口
     * @param[in] iPDVFilePath pdv文件路径
     * @param[in] isOutStdPdv 是否导出标准格式的PDV文件
     * @note
     */
    static PDV_RESULT SaveSceneData(ISceneData* iSceneData, const CUnicodeString& iPDVFilePath, DftBool isOutStdPdv = FALSE);

    /**
     * @brief 从pdv文件读取ISceneData数据
     * @return PDV_RESULT
     * @param[in] iSceneData 场景数据接口
     * @param[in] iPDVFilePath pdv文件路径
     * @note
     */
    static PDV_RESULT LoadSceneData(ISceneData* iSceneData, const CUnicodeString& iPDVFilePath);

    /**
     * @brief 从数据流读取ISceneData数据
     * @return PDV_RESULT
     * @param[in] iSceneData 场景数据接口
     * @param[in] iDataBuffer 数据流
     * @param[in] iDataLength 数据流长度
     * @note
     */
    static PDV_RESULT LoadSceneData(ISceneData* iSceneData, const DftByte* iDataBuffer, DftLong64 iDataLength);

    /**
     * @brief 根据ISceneData数据生成pdvdata文件
     * @return PDV_RESULT
     * @param[in] iSceneData 场景数据接口
     * @param[in] iPDVDataFolder 要生成的pdvdata文件所在文件夹路径
     * @param[in] iCountMax pdvdata文件包含的对象的最大数量
     * @param[in] iSizeMax pdvdata文件的体积的最大值，单位为 M（兆）
     * @param[in] iNeedCompress 是否需要压缩pdvdata文件，1是压缩，0是不压缩
     * @note
     */
    static PDV_RESULT SavePDVData(ISceneData* iSceneData, const CUnicodeString& iPDVDataFolder,
        DftInt iCountMax, DftInt iSizeMax, DftInt iNeedCompress);
};

} // namespace pdv

} // namespace kernel

#endif

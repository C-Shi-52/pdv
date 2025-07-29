/**
* @file PDVIBRep.h
* @author wei.li
* @version 1.0
* @date 2024-02-21
* @brief 概述：几何拓扑数据的接口声明
* @details 详细说明
*/

#ifndef PDVIBREP_H
#define PDVIBREP_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

class ITopo;
class IGeomPointData;
class IGeomCurveData;
class IGeomSurfaceData;

/** @brief 几何拓扑数据的接口 */
class PDVCORE_API IBRep : public IDataObject
{
public:
    /**
    * @brief 清空拓扑数据
    * @return PDV_RESULT
    * @note
    */
    virtual PDV_RESULT ClearTopo() = 0;

    /**
    * @brief 获取拓扑对象的数量
    * @return DftUInt 返回数量
    * @note
    */
    virtual DftUInt GetTopoCount() = 0;

    /**
    * @brief 获取拓扑数据
    * @return PDV_RESULT
    * @param[in] oTopos 拓扑数组
    * @note
    */
    virtual PDV_RESULT GetTopoArray(std::vector<ITopo*>& oTopos) = 0;

    /**
    * @brief 设置拓扑数据
    * @return PDV_RESULT
    * @param[in] iTopos 拓扑数组
    * @note
    */
    virtual PDV_RESULT SetTopoArray(const std::vector<ITopo*>& iTopos) = 0;

    /**
    * @brief 清空几何点数据
    * @return PDV_RESULT
    * @note
    */
    virtual PDV_RESULT ClearGeomPointData() = 0;

    /**
    * @brief 获取几何点的数量
    * @return DftUInt 返回数量
    * @note
    */
    virtual DftUInt GetGeomPointDataCount() = 0;

    /**
    * @brief 获取几何点数据
     * @return PDV_RESULT
     * @param[in] oGeomPoints 几何点数据数组
    * @note
    */
    virtual PDV_RESULT GetGeomPointDataArray(std::vector<IGeomPointData*>& oGeomPoints) = 0;

    /**
     * @brief 设置几何点数据
     * @return PDV_RESULT
     * @param[in] iGeomPoints 几何点数据数组
     * @note
     */
    virtual PDV_RESULT SetGeomPointDataArray(const std::vector<IGeomPointData*>& iGeomPoints) = 0;

    /**
    * @brief 清空几何曲线数据
    * @return PDV_RESULT
    * @note
    */
    virtual PDV_RESULT ClearGeomCurveData() = 0;

    /**
    * @brief 获取几何曲线的数量
    * @return DftUInt 返回数量
    * @note
    */
    virtual DftUInt GetGeomCurveDataCount() = 0;

    /**
    * @brief 获取几何曲线数据
     * @return PDV_RESULT
     * @param[in] oGeomCurves 几何曲线数据数组
     * @note
    */
    virtual PDV_RESULT GetGeomCurveDataArray(std::vector<IGeomCurveData*>& oGeomCurves) = 0;

    /**
     * @brief 设置几何曲线数据
     * @return PDV_RESULT
     * @param[in] iGeomCurves 几何曲线数据数组
     * @note
     */
    virtual PDV_RESULT SetGeomCurveDataArray(const std::vector<IGeomCurveData*>& iGeomCurves) = 0;

        /**
    * @brief 清空几何曲面数据
    * @return PDV_RESULT
    * @note
    */
    virtual PDV_RESULT ClearGeomSurfaceData() = 0;

    /**
    * @brief 获取几何曲面的数量
    * @return DftUInt 返回数量
    * @note
    */
    virtual DftUInt GetGeomSurfaceDataCount() = 0;

    /**
    * @brief 获取几何曲面数据
     * @return PDV_RESULT
     * @param[in] oGeomSurfaces 几何曲面数据数组
    * @note
    */
    virtual PDV_RESULT GetGeomSurfaceDataArray(std::vector<IGeomSurfaceData*>& oGeomSurfaces) = 0;

    /**
     * @brief 设置几何曲面数据
     * @return PDV_RESULT
     * @param[in] iGeomSurfaces 几何曲面数据数组
     * @note
     */
    virtual PDV_RESULT SetGeomSurfaceDataArray(const std::vector<IGeomSurfaceData*>& iGeomSurfaces) = 0;

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
    virtual DftInt64 ReadData(const PDV_CHAR* iStreamBuffer, DftInt64 iBufferLength) = 0;

    /**
     * @brief 向二进制数据流中写入数据信息
     * @return DftInt64 数据长度
     * @param[in,out] ioStreamBuffer 数据流
     * @param[in] iBufferLength 数据流长度
     * @note
     */
    virtual DftInt64 WriteData(PDV_CHAR* ioStreamBuffer, DftInt64 iBufferLength) const = 0;

    /**
     * @brief 输出Json数据
     * @return DftLong64 见返回数据大小
     * @param[in] pJson cJSON对象
     * @note
     */
    virtual void Output(DftJson jsonNode) const = 0;
};

} // namespace pdv

} // namespace kernel

#endif
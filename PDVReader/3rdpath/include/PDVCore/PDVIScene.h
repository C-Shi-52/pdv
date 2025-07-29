/**
 * @file PDVIScene.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-15
 * @brief 概述：IScene的接口声明
 * @details 详细说明
 */

#ifndef PDVISCENE_H
#define PDVISCENE_H

#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

/** @brief 场景时间单位 */
enum LengthUnitType
{
    LENGTHUNIT_NULL = 0, ///< 未知
    LENGTHUNIT_MM = 1,   ///< 毫米
    LENGTHUNIT_CM = 2,   ///< 厘米
    LENGTHUNIT_M = 3,    ///< 米
    LENGTHUNIT_KM = 4,   ///< 千米
    LENGTHUNIT_INCH = 5, ///< 英寸
    LENGTHUNIT_DM = 6,   ///< 分米
    LENGTHUNIT_FOOT = 7, ///< 英尺
    LENGTHUNIT_YARD = 8, ///< 码   1YARD=3FOOT=0.9144m
    LENGTHUNIT_MILE = 9, ///< 英里
};

/** @brief 场景质量单位 */
enum MassUnitType
{
    MASSUNIT_NULL = 0, ///< 未知
    MASSUNIT_MG = 1,   ///< 毫克
    MASSUNIT_G = 2,    ///< 克
    MASSUNIT_KG = 3,   ///< 千克
    MASSUNIT_T = 4,    ///< 吨
};

/** @brief 场景数据的接口 */
class PDVCORE_API IScene : public IDataObject
{
public:
    /**
     * @brief 获取场景默认视图ID
     * @return DftUInt64 默认视图ID
     * @note
     */
    virtual DftUInt64 GetDefaultViewID() = 0;

    /**
     * @brief 设置场景默认视图ID
     * @return PDV_RESULT
     * @param[in] iViewID 场景默认视图ID
     * @note
     */
    virtual PDV_RESULT SetDefaultViewID(const DftUInt64 &iViewID) = 0;

    /**
     * @brief 获取场景默认相机ID
     * @return DftUInt64 默认相机ID
     * @note
     */
    virtual DftUInt64 GetDefaultCameraID() = 0;

    /**
     * @brief 设置场景默认相机ID
     * @return PDV_RESULT
     * @param[in] iCameraID 场景默认相机ID
     * @note
     */
    virtual PDV_RESULT SetDefaultCameraID(const DftUInt64 &iCameraID) = 0;

    /**
     * @brief 获取场景长度单位
     * @return DftUInt 场景长度单位，见 LengthUnitType
     * @note
     */
    virtual DftUInt GetLengthUnit() = 0;

    /**
     * @brief 设置场景长度单位
     * @return PDV_RESULT
     * @param[in] iLengthUnit 场景长度单位，见 LengthUnitType
     * @note
     */
    virtual PDV_RESULT SetLengthUnit(const DftUInt &iLengthUnit) = 0;

    /**
     * @brief 获取场景质量单位
     * @return DftUInt 场景质量单位，见 MassUnitType
     * @note
     */
    virtual DftUInt GetMassUnit() = 0;

    /**
     * @brief 设置场景质量单位
     * @return PDV_RESULT
     * @param[in] iMassUnit 场景质量单位，见 MassUnitType
     * @note
     */
    virtual PDV_RESULT SetMassUnit(const DftUInt &iMassUnit) = 0;

    /**
     * @brief 获取场景全局变换矩阵
     * @return DftMatrix4D 全局变换矩阵
     * @note
     */
    virtual PDVMatrix4D GetGlobalTransformation() = 0;

    /**
     * @brief 设置场景全局变换矩阵
     * @return PDV_RESULT
     * @param[in] iGlobalTransformation 场景全局变换矩阵
     * @note
     */
    virtual PDV_RESULT SetGlobalTransformation(const PDVMatrix4D &iGlobalTransformation) = 0;

    /**
     * @brief 获取数据的长度
     * @return DftInt64 数据长度
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
};

} // namespace pdv

} // namespace kernel
#endif
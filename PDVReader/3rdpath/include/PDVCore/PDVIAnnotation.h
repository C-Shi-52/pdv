/**
 * @file PDVIAnnotation.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：标注的接口声明
 * @details 详细说明
 */

#ifndef PDVIANNOTATION_H
#define PDVIANNOTATION_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

class IAnnotationItem;
class IAnnotationView;
class IAnnotationGeometry;

/** @brief 标注的接口 */
class PDVCORE_API IAnnotation : public IDataObject
{
public:
    /**
     * @brief 获取标注项个数
     * @return DftUInt 标注项个数
     * @note
     */
    virtual DftUInt GetAnnotationItemCount() = 0;

    /**
     * @brief 根据索引获取标注项数据接口
     * @param[in] iIndex 标注索引
     * @return IAnnotationItem * 标注项数据接口
     * @note
     */
    virtual IAnnotationItem* GetAnnotationItemByIndex(DftUInt iIndex) = 0;

    /**
     * @brief 根据ID获取标注项数据接口
     * @param[in] iID 标注ID
     * @return IAnnotationItem * 标注项数据接口
     * @note
     */
    virtual IAnnotationItem* GetAnnotationItemByID(DftUInt64 iID) = 0;

    /**
     * @brief 添加标注项
     * @return IAnnotationItem * 标注项数据接口
     * @note
     */
    virtual IAnnotationItem* AddAnnotationItem() = 0;

    /**
     * @brief 获取标注视图个数
     * @return DftUInt 标注视图个数
     * @note
     */
    virtual DftUInt GetAnnotationViewCount() = 0;

    /**
     * @brief 根据索引获取标注视图数据接口
     * @param[in] iIndex 视图索引
     * @return IAnnotationView * 标注视图数据接口
     * @note
     */
    virtual IAnnotationView* GetAnnotationViewByIndex(DftUInt iIndex) = 0;

    /**
     * @brief 根据ID获取标注视图数据接口
     * @param[in] iID 视图ID
     * @return IAnnotationView * 标注视图数据接口
     * @note
     */
    virtual IAnnotationView* GetAnnotationViewByID(DftUInt64 iID) = 0;

    /**
     * @brief 添加标注视图
     * @return IAnnotationView * 标注视图数据接口
     * @note
     */
    virtual IAnnotationView* AddAnnotationView() = 0;

    /**
     * @brief 获取标注辅助几何个数
     * @return DftUInt 标注辅助几何个数
     * @note
     */
    virtual DftUInt GetAnnotationGeometryCount() = 0;

    /**
     * @brief 根据索引获取标注辅助几何数据接口
     * @param[in] iIndex 标注辅助几何索引
     * @return IAnnotationGeometry * 标注辅助几何数据接口
     * @note
     */
    virtual IAnnotationGeometry* GetAnnotationGeometryByIndex(DftUInt iIndex) = 0;

    /**
     * @brief 根据ID获取标注辅助几何数据接口
     * @param[in] iID 标注辅助几何ID
     * @return IAnnotationGeometry * 标注辅助几何数据接口
     * @note
     */
    virtual IAnnotationGeometry* GetAnnotationGeometryByID(DftUInt64 iID) = 0;

    /**
     * @brief 添加标注辅助几何
     * @return IAnnotationGeometry * 标注辅助几何数据接口
     * @note
     */
    virtual IAnnotationGeometry* AddAnnotationGeometry() = 0;

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
    virtual DftInt64 ReadData(const PDV_CHAR* iStreamBuffer, DftInt64 iBufferLength) = 0;

    /**
     * @brief 向二进制数据流中写入数据信息
     * @return DftInt64 数据长度
     * @param[in,out] ioStreamBuffer 数据流
     * @param[in] iBufferLength 数据流长度
     * @note
     */
    virtual DftInt64 WriteData(PDV_CHAR* ioStreamBuffer, DftInt64 iBufferLength) const = 0;
};

} // namespace pdv

} // namespace kernel

#endif
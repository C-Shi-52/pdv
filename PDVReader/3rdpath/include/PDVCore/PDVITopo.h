/**
 * @file PDVITopo.h
 * @author yuerui
 * @version 1.0
 * @date 2024-05-30
 * @brief 概述：TOPO类的接口声明
 * @details 详细说明
 */

#ifndef PDVITOPO_H
#define PDVITOPO_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{
namespace pdv
{

/** @brief 拓扑对象内容标识 */
enum TopoMask
{
    TOPO_MASK_PERSISTENTID = 0x01, ///< 是否包含原生格式中拓扑对象标识，1表示包含，0表示不包含
    TOPO_MASK_ORIENTATION = 0x02,  ///< 是否包含拓扑方向，1表示包含，0表示不包含
    TOPO_MASK_GEOMETRY = 0x04,     ///< 是否关联几何对象（点、线、面），1表示关联，0表示不关联
    TOPO_MASK_TOPODATA = 0x08      ///< 是否关联其他拓扑对象，1表示关联，0表示不关联
};

/** @brief 拓扑对象类型 */
enum TOPOTYPE
{
    TOPOTYPE_NULL = 0,     ///< 未知
    TOPOTYPE_COMPOUND = 1, ///< 拓扑复合体
    TOPOTYPE_SOLID = 2,    ///< 拓扑实体
    TOPOTYPE_SHELL = 3,    ///< 拓扑壳
    TOPOTYPE_FACE = 4,     ///< 拓扑面
    TOPOTYPE_LOOP = 5,     ///< 拓扑环
    TOPOTYPE_COEDGE = 6,   ///< 拓扑共边
    TOPOTYPE_EDGE = 7,     ///< 拓扑边
    TOPOTYPE_VERTEX = 8,   ///< 拓扑顶点
};

/** @brief 拓扑对象的方向 */
enum ORIENTATION
{
    ORIENTATION_FORWARD = 0,  ///< 相同方向
    ORIENTATION_REVERSED = 1, ///< 相反方向
    ORIENTATION_UNKNOWN = 2,  ///< 未知方向
};

/** @brief 拓扑对象关联的几何类型 */
enum GEOMTYPE
{
    GEOMTYPE_NULL = 0,    ///< 未知
    GEOMTYPE_POINT = 1,   ///< 点
    GEOMTYPE_CURVE = 2,   ///< 线
    GEOMTYPE_SURFACE = 3, ///< 面
};

/** @brief 拓扑的接口 */
class PDVCORE_API ITopo : public IDataObject
{
public:
    /**
     * @brief 获取拓扑对象的内容标识
     * @return DftUInt8 拓扑对象的内容标识
     * @note
     */
    virtual DftUInt8 GetBitMask() const = 0;

    /**
     * @brief 设置拓扑对象的内容标识
     * @return PDV_RESULT
     * @param[in] iMask 拓扑对象的内容标识
     * @note
     */
    virtual PDV_RESULT SetBitMask(const DftUInt8 &iMask) = 0;

    /**
     * @brief 获取拓扑对象的类型
     * @return DftUInt8 拓扑对象的类型
     * @note
     */
    virtual DftUInt8 GetTopoType() const = 0;

    /**
     * @brief 设置拓扑对象的类型
     * @return PDV_RESULT
     * @param[in] iType 拓扑对象的类型
     * @note
     */
    virtual PDV_RESULT SetTopoType(const DftUInt8 &iType) = 0;

    /**
     * @brief 获取原始数据的拓扑对象标识
     * @return CUnicodeString 原始数据的拓扑对象标识
     * @note
     */
    virtual CUnicodeString GetOriginalID()const = 0;

    /**
     * @brief 设置原始数据的拓扑对象标识
     * @return PDV_RESULT
     * @param[in] iOriginalID 原始数据的拓扑对象标识
     * @note
     */
    virtual PDV_RESULT SetOriginalID(const CUnicodeString &iOriginalID) = 0;

    /**
     * @brief 获取拓扑对象的拓扑方向
     * @return DftUInt8 拓扑对象的拓扑方向
     * @note
     */
    virtual DftUInt8 GetOrientation()const = 0;

    /**
     * @brief 设置拓扑对象的拓扑方向
     * @return PDV_RESULT
     * @param[in] iOrientation 拓扑对象的拓扑方向
     * @note
     */
    virtual PDV_RESULT SetOrientation(const DftUInt8 &iOrientation) = 0;

    /**
     * @brief 获取拓扑对象关联的几何对象类型
     * @return DftUInt8 拓扑对象关联的几何对象类型
     * @note
     */
    virtual DftUInt8 GetGeometryType()const = 0;

    /**
     * @brief 设置拓扑对象关联的几何对象类型
     * @return PDV_RESULT
     * @param[in] iGeometryType 拓扑对象关联的几何对象类型
     * @note
     */
    virtual PDV_RESULT SetGeometryType(const DftUInt8 &iGeometryType) = 0;

    /**
     * @brief 获取关联的几何对象标识
     * @return DftUInt64 关联的几何对象标识
     * @note
     */
    virtual DftUInt64 GetGeometryID()const = 0;

    /**
     * @brief 设置关联的几何对象标识
     * @return PDV_RESULT
     * @param[in] iGeometryID 关联的几何对象标识
     * @note
     */
    virtual PDV_RESULT SetGeometryID(const DftUInt64 &iGeometryID) = 0;

    /**
     * @brief 获取包含的其他拓扑对象数量
     * @return DftUInt 包含的其他拓扑对象数量
     * @note
     */
    virtual DftUInt GetTopoCount()const = 0;

    /**
     * @brief 设置/获取包含的拓扑对象ID
     * @return std::vector< \ref DftUInt64 > 包含的拓扑对象ID队列引用
     * @note
     */
    virtual const std::vector<DftUInt64>& GetTopoIDs()const = 0;

    /**
    * @brief 添加包含的拓扑对象ID
    * @return PDV_RESULT
    * @param[in] iID 包含的拓扑对象ID
    * @note
    */
    virtual PDV_RESULT AddSubTopoIDs(DftUInt64 iID) = 0;
};
} // namespace pdv

} // namespace kernel
#endif
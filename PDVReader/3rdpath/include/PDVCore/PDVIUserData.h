/**
 * @file PDVIUserData.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：用户自定义对象的接口声明
 * @details 详细说明
 */

#ifndef PDVIUSERDATA_H
#define PDVIUSERDATA_H

#include "PDVBase.h"
#include "PDVIDataObject.h"
#include "DftBufferStream.h"

namespace kernel
{

namespace pdv
{

/** @brief 用户数据类型 */
enum UserDataType
{
    USER_DATA_TYPE_TREE_NODE_MATERIAL = 1,           ///< 模型树节点材质数据
    USER_DATA_TYPE_TREE_NODE_AUXILIARY_GEOMETRY = 2, ///< 模型树节点辅助几何对象数据
    USER_DATA_TYPE_ANALYSISQUANTITYARRAY = 3,        ///< VTK物理量数据
    USER_DATA_TYPE_GEOMTOPO_CURVEONSURFACE = 4,      ///< 几何拓扑对象的pCurve数据
    USER_DATA_TYPE_ANNOTATIONAUXILIARYARRAY = 5      ///< 标注辅助几何数据
};

/** @brief 用户数据索引项 */
struct PDVCORE_API UserDataIndexItem
{
    DftUInt8  _dataType;               ///< 数据类型，见 UserDataType
    DftUInt32 _dataOffset;             ///< 数据起始偏移字节数
    DftUInt32 _nextIndexItemOffset;    ///< 下一索引项偏移字节数，如果为0，则下一索引项不存在
    /** 默认构造函数 */
    UserDataIndexItem()
    {
        Clear();
    }
    /** 拷贝构造函数 */
    UserDataIndexItem(const UserDataIndexItem& iData)
    {
        _dataType = iData._dataType;
        _dataOffset = iData._dataOffset;
        _nextIndexItemOffset = iData._nextIndexItemOffset;
    }
    /** 赋值运算符 */
    UserDataIndexItem& operator=(const UserDataIndexItem& iData)
    {
        if (&iData != this)
        {
            _dataType = iData._dataType;
            _dataOffset = iData._dataOffset;
            _nextIndexItemOffset = iData._nextIndexItemOffset;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _dataType = 0;
        _dataOffset = 0;
        _nextIndexItemOffset = 0;
    }
    /** 读取数据 */
    DftInt64 ReadData(DftByte* iData, DftInt64 iLength);
    /** 存储数据 */
    DftInt64 WriteData(DftByte* iData, DftInt64 iLength) const;
    /** 覆写数据 */
    DftInt64 OverWriteData(DftByte* iData, DftInt64 iLength) const;
    /** 获取数据长度 */
    DftInt64 GetDataLength() const;
    /** 输出数据 */
    void Output(DftJson iJsonNode) const;
};

/** @brief 用户数据索引项集 */
typedef std::vector<UserDataIndexItem> UserDataIndexItemArray;

/** @brief 用户数据索引表 */
struct PDVCORE_API UserDataIndexTable
{
    UserDataIndexItemArray _indexItems; ///< 索引项集
    /** 默认构造函数 */
    UserDataIndexTable()
    {
        Clear();
    }
    /** 拷贝构造函数 */
    UserDataIndexTable(const UserDataIndexTable& iData)
    {
        _indexItems = iData._indexItems;
    }
    /** 赋值运算符 */
    UserDataIndexTable& operator=(const UserDataIndexTable& iData)
    {
        if (&iData != this)
        {
            _indexItems = iData._indexItems;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _indexItems.clear();
    }
    /** 读取数据 */
    DftInt64 ReadData(DftByte* iData, DftInt64 iLength);
    /** 覆写数据 */
    DftInt64 OverWriteData(DftByte* iData, DftInt64 iLength) const;
    /** 获取数据长度 */
    DftInt64 GetDataLength() const;
    /** 输出数据 */
    void Output(DftJson iJsonNode) const;
};


/** @brief 用户自定义对象的接口 */
class PDVCORE_API IUserData : public IDataObject
{
public:
    /**
     * @brief 生成新ID
     * @note PDVCWrap专用
     */
    virtual void AssignID() = 0;

    /**
     * @brief 获取规定用户自定义对象的用户或企业标识
     * @return PDV_RESULT
     * @param[out] oProducer 规定用户自定义对象的用户或企业标识
     * @note
     */
    virtual PDV_RESULT GetProducer(CUnicodeString &oProducer) = 0;

    /**
     * @brief 设置规定用户自定义对象的用户或企业标识
     * @return PDV_RESULT
     * @param[in] iProducer 规定用户自定义对象的用户或企业标识
     * @note
     */
    virtual PDV_RESULT SetProducer(const CUnicodeString &iProducer) = 0;

    /**
     * @brief 获取规定用户自定义对象的软件版本号
     * @return PDV_RESULT
     * @param[out] oProducerVersion 规定用户自定义对象的软件版本号
     * @note
     */
    virtual PDV_RESULT GetProducerVersion(CUnicodeString &oProducerVersion) = 0;

    /**
     * @brief 设置规定用户自定义对象的软件版本号
     * @return PDV_RESULT
     * @param[in] iProducerVersion 规定用户自定义对象的软件版本号
     * @note
     */
    virtual PDV_RESULT SetProducerVersion(const CUnicodeString &iProducerVersion) = 0;

    /**
     * @brief 获取用户自定义数据
     * @return PDV_RESULT
     * @param[out] oDataLength 数据长度
     * @param[out] oData 数据
     * @note
     */
    virtual PDV_RESULT GetData(DftUInt& oDataLength, DftByte*& oData) = 0;

    /**
     * @brief 设置用户自定义数据
     * @return PDV_RESULT
     * @param[in] iDataLength 数据长度
     * @param[in] iData 数据
     * @note
     */
    virtual PDV_RESULT SetData(DftUInt iDataLength, DftByte* iData) = 0;

    /**
     * @brief 追加用户自定义数据
     * @return PDV_RESULT
     * @param[in] iDataLength 数据长度
     * @param[in] iData 数据
     * @note
     */
    virtual PDV_RESULT AddData(DftUInt iDataLength, DftByte* iData) = 0;

    /**
     * @brief 追加用户自定义数据（PDVCWrap专用）
     * @return PDV_RESULT
     * @param[in] iDataLength 数据长度
     * @param[in] iData 数据
     * @note
     */
    virtual PDV_RESULT AppendData(DftUInt iDataLength, DftByte* iData) = 0;

};

} // namespace pdv

} // namespace kernel
#endif
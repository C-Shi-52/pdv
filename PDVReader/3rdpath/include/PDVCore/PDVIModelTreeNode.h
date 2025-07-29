/**
 * @file PDVIModelTreeNode.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：模型树节点的接口声明
 * @details 详细说明
 */

#ifndef PDVIMODELTREENODE_H
#define PDVIMODELTREENODE_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

class IModelTree;
class IModel;
class IAttribute;
class IMaterial;
class IAnnotation;

/** @brief 模型树节点内容标志 */
enum ModelTreeNodeMask
{
    MODELTREENODE_MASK_NULL = 0,             ///< 未知
    MODELTREENODE_MASK_MODEL = 0x01,         ///< 是否关联模型, 1表示关联, 0表示不关联
    MODELTREENODE_MASK_ORIGINALID = 0x02,    ///< 是否关联原始模型ID, 1表示关联, 0表示不关联
    MODELTREENODE_MASK_LOCALTRANS = 0x04,    ///< 是否包含局部变换信息, 1表示包含, 0表示不包含
    MODELTREENODE_MASK_WORLDTRANS = 0x08,    ///< 是否包含全部变换信息, 1表示包含, 0表示不包含
    MODELTREENODE_MASK_ATTRIBUTE = 0x10,     ///< 是否关联属性对象, 1表示关联, 0表示不关联
    MODELTREENODE_MASK_MATERIAL = 0x20,      ///< 是否关联材质对象, 1表示关联, 0表示不关联
    MODELTREENODE_MASK_LINE_MATERIAL = 0x40  ///< 是否关联线材质对象, 1表示包含, 0表示不包含
};

/** @brief 模型树节点属性 */
enum ModelTreeNodeAttr
{
    MODELTREENODE_ATTR_NULL = 0,          ///< 未知
    MODELTREENODE_ATTR_ROOT = 0x01,       ///< 是否根节点, 1表示为根节点, 0表示非根节点
    MODELTREENODE_ATTR_VISIBLE = 0x02     ///< 是否可见, 1表示显示, 0表示隐藏
};

/** @brief 材质属性标识 */
enum ModelTreeNodeMaterialAttr
{
    MODELTREENODE_MAT_ATTR_NULL = 0,            ///< 空
    MODELTREENODE_MAT_ATTR_COLOR = 0x01,       ///< 是否包含颜色数据, 1表示包含, 0表示不包含
    MODELTREENODE_MAT_ATTR_OPACITY = 0x02    ///< 是否包含透明度数据, 1表示包含, 0表示不包含
};

/** @brief 材质属性信息 */
struct MaterialAttribute
{
    DftUInt8 _bitMask;               ///< 标识位
    RGBColor _color;                  ///< 颜色，若bitmask中第1位设置为0，则该项不存在
    DftUInt8 _opacity;                 ///< 透明度值, 取值范围为[0,255], 0表示完全透明, 255表示不透明, 默认值为255；若bitmask中第2位设置为0，则该项不存在
    /** 默认构造函数 */
    MaterialAttribute() { Clear(); }
    /** 拷贝构造函数 */
    MaterialAttribute(const MaterialAttribute& iData)
    {
        _bitMask = iData._bitMask;
        _color = iData._color;
        _opacity = iData._opacity;
    }
    /** 赋值运算符 */
    MaterialAttribute& operator=(const MaterialAttribute& iData)
    {
        if (&iData != this)
        {
            _bitMask = iData._bitMask;
            _color = iData._color;
            _opacity = iData._opacity;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _bitMask = MODELTREENODE_MAT_ATTR_NULL;
        _color._red = 0;
        _color._green = 0;
        _color._blue = 0;
        _opacity = 0;
    }
    /** 日志输出 */
    void Output(DftJson iJsonNode) const;
};

/** @brief 模型树节点的接口 */
class PDVCORE_API IModelTreeNode
{
public:
    /**
     * @brief 获取对象ID
     * @return DftUInt64 对象ID
     * @note
     */
    virtual DftUInt64 GetID() = 0;

    /**
     * @brief 设置对象ID
     * @return PDV_RESULT
     * @param[in] iID 模型树节点ID
     * @note
     */
    virtual PDV_RESULT SetID(DftUInt64 iID) = 0;

    /**
     * @brief 获取所属模型树对象
     * @return IModelTree * 所属模型树对象接口
     * @note
     */
    virtual IModelTree* GetOwner() = 0;

    /**
     * @brief 获取模型树节点名称
     * @return PDV_RESULT
     * @param[out] oName 模型树节点名称
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString &oName) = 0;

    /**
     * @brief 设置模型树节点名称
     * @return PDV_RESULT
     * @param[in] iName 模型树节点名称
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString &iName) = 0;

    /**
     * @brief 获取模型树节点原始数据的节点ID
     * @return PDV_RESULT
     * @param[out] oOriginID 模型树节点原始数据的节点ID
     * @note
     */
    virtual PDV_RESULT GetOriginID(CUnicodeString &oOriginID) = 0;

    /**
     * @brief 设置模型树节点原始数据的节点ID
     * @return PDV_RESULT
     * @param[in] iOriginID 模型树节点原始数据的节点ID
     * @note
     */
    virtual PDV_RESULT SetOriginID(const CUnicodeString &iOriginID) = 0;

    /**
     * @brief 获取模型树节点原始数据的节点命名
     * @return PDV_RESULT
     * @param[out] oOriginName 模型树节点原始数据的节点命名
     * @note
     */
    virtual PDV_RESULT GetOriginName(CUnicodeString &oOriginName) = 0;

    /**
     * @brief 设置模型树节点原始数据的节点命名
     * @return PDV_RESULT
     * @param[in] iOriginName 模型树节点原始数据的节点命名
     * @note
     */
    virtual PDV_RESULT SetOriginName(const CUnicodeString &iOriginName) = 0;

    /**
     * @brief 返回是否是根节点
     * @return DftBool 是否是根节点
     * @note
     */
    virtual DftBool IsRootNode() = 0;

    /**
     * @brief 设置模型树节点是否为根节点
     * @return PDV_RESULT
     * @param[in] iRootNode 模型树节点是否是根节点
     * @note
     */
    virtual PDV_RESULT SetRootNode(DftBool iRootNode) = 0;

    /**
     * @brief 获取模型树节点是否可见
     * @return DftBool 模型树节点是否可见
     * @note
     */
    virtual DftBool GetVisible() = 0;

    /**
     * @brief 设置模型树节点是否可见
     * @return PDV_RESULT
     * @param[in] iVisible 模型树节点是否可见
     * @note
     */
    virtual PDV_RESULT SetVisible(DftBool iVisible) = 0;

    /**
     * @brief 获取是否关联模型标志
     * @return DftBool 是否关联模型标志，TRUE说明关联模型，FALSE说明不关联模型
     * @note
     */
    virtual DftBool GetModelFlag() = 0;

    /**
     * @brief 设置是否关联模型标志
     * @return PDV_RESULT
     * @param[in] iModelFlag 是否关联模型标志，TRUE说明关联模型，FALSE说明不关联模型
     * @note
     */
    virtual PDV_RESULT SetModelFlag(DftBool iModelFlag) = 0;

    /**
     * @brief 获取是否包含局部变换信息标志
     * @return DftBool 是否包含局部变换信息标志，TRUE说明存在局部变换信息，FALSE说明不存在局部变换信息
     * @note
     */
    virtual DftBool GetLocalTransformFlag() = 0;

    /**
     * @brief 设置是否包含局部变换信息标志
     * @return PDV_RESULT
     * @param[in] iLocalTransformFlag 是否包含局部变换信息标志，TRUE说明存在局部变换信息，FALSE说明不存在局部变换信息
     * @note
     */
    virtual PDV_RESULT SetLocalTransformFlag(DftBool iLocalTransformFlag) = 0;

    /**
     * @brief 获取是否包含全局变换信息标志
     * @return DftBool 是否包含全局变换信息标志，TRUE说明存在全局变换信息，FALSE说明不存在全局变换信息
     * @note
     */
    virtual DftBool GetWorldTransformFlag() = 0;

    /**
     * @brief 设置是否包含全局变换信息标志
     * @return PDV_RESULT
     * @param[in] iWorldTransformFlag 是否包含全局变换信息标志，TRUE说明存在全局变换信息，FALSE说明不存在全局变换信息
     * @note
     */
    virtual PDV_RESULT SetWorldTransformFlag(DftBool iWorldTransformFlag) = 0;

    /**
     * @brief 获取是否关联属性对象标志
     * @return DftBool 是否关联属性对象标志，TRUE说明关联属性对象，FALSE说明不关联属性对象
     * @note
     */
    virtual DftBool GetAttributeFlag() = 0;

    /**
     * @brief 设置是否关联属性对象标志
     * @return PDV_RESULT
     * @param[in] iAttributeFlag 是否关联属性对象标志，TRUE说明关联属性对象，FALSE说明不关联属性对象
     * @note
     */
    virtual PDV_RESULT SetAttributeFlag(DftBool iAttributeFlag) = 0;

    /**
     * @brief 获取是否关联材质对象标志
     * @return DftBool 是否关联材质对象标志，TRUE说明关联材质对象，FALSE说明不关联材质对象
     * @note
     */
    virtual DftBool GetMaterialFlag() = 0;

    /**
     * @brief 设置是否关联材质对象标志
     * @return PDV_RESULT
     * @param[in] iMaterialFlag 是否关联材质对象标志，TRUE说明关联材质对象，FALSE说明不关联材质对象
     * @note
     */
    virtual PDV_RESULT SetMaterialFlag(DftBool iMaterialFlag) = 0;

    /**
     * @brief 获取局部变换信息
     * @return PDV_RESULT
     * @param[out] oLocalTransform 局部变换信息
     * @note 如果包含局部变换信息，则返回 \ref PDV_RESULT_NO_ERROR，否则返回 \ref PDV_RESULT_MODELTREENODE_NO_LOCAL_TRANSFORM
     */
    virtual PDV_RESULT GetLocalTransform(PDVMatrix4F &oLocalTransform) = 0;

    /**
     * @brief 设置局部变换信息
     * @return PDV_RESULT
     * @param[in] iLocalTransform: 局部变换信息
     * @note 如果包含局部变换信息，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODELTREENODE_NO_LOCAL_TRANSFORM
     */
    virtual PDV_RESULT SetLocalTransform(const PDVMatrix4F &iLocalTransform) = 0;

    /**
     * @brief 设置全局坐标变换信息
     * @return PDV_RESULT
     * @param[in] iWorldTransform: 全局坐标变换信息
     * @note 如果包含全局坐标变换信息，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODELTREENODE_NO_WORLD_TRANSFORM
     */
    virtual PDV_RESULT SetWorldTransform(const PDVMatrix4F &iWorldTransform) = 0;

    /**
     * @brief 获取全局坐标变换信息
     * @return PDV_RESULT
     * @param[out] oWorldTransform 全局坐标变换信息
     * @note 如果包含全局坐标变换信息，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODELTREENODE_NO_WORLD_TRANSFORM
     */
    virtual PDV_RESULT GetWorldTransform(PDVMatrix4F &oWorldTransform) = 0;

    /**
     * @brief 获取关联模型对象接口
     * @return IModel * 关联模型对象接口
     * @note 如果关联模型对象，则返回关联模型对象接口，否则返回NULL
     */
    virtual IModel* GetModel() = 0;

    /**
     * @brief 获取关联模型ID
     * @return DftUInt64 关联模型ID
     * @note 如果关联模型对象，则返回关联模型ID，否则返回 \ref DFT_INVALID_ID
     */
    virtual DftUInt64 GetModelID() const = 0;

    /**
     * @brief 设置关联模型ID
     * @return PDV_RESULT
     * @param[in] iModelID 关联模型ID
     * @note 如果关联模型对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODELTREENODE_NO_MODEL
     */
    virtual PDV_RESULT SetModelID(DftUInt64 iModelID) = 0;

    /**
     * @brief 获取关联属性对象接口
     * @return IAttribute * 关联属性对象接口
     * @note 如果关联属性对象，则返回关联属性对象接口，否则返回NULL
     */
    virtual IAttribute* GetAttribute() = 0;

    /**
     * @brief 获取关联属性ID
     * @return DftUInt64 关联属性ID
     * @note 如果关联属性对象，则返回关联属性ID，否则返回 \ref DFT_INVALID_ID
     */
    virtual DftUInt64 GetAttributeID() const = 0;

    /**
     * @brief 设置关联属性ID
     * @return PDV_RESULT
     * @param[in] iAttributeID 关联属性ID
     * @note 如果关联属性对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODELTREENODE_NO_ATTRIBUTE
     */
    virtual PDV_RESULT SetAttributeID(DftUInt64 iAttributeID) = 0;

    /**
     * @brief 获取关联材质对象接口
     * @return IMaterial * 关联材质对象接口
     * @note 如果关联材质对象，则返回关联属性对象接口，否则返回NULL
     */
    virtual IMaterial* GetMaterial() = 0;

    /**
     * @brief 获取关联材质ID
     * @return DftUInt64 关联材质ID
     * @note 如果关联材质对象，则返回关联材质ID，否则返回DFT_INVALID_ID
     */
    virtual DftUInt64 GetMaterialID() const = 0;

    /**
     * @brief 设置关联材质ID
     * @return PDV_RESULT
     * @param[in] iMaterialID 关联材质ID
     * @note 如果关联材质对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODELTREENODE_NO_MATERIAL
     */
    virtual PDV_RESULT SetMaterialID(DftUInt64 iMaterialID) = 0;

	/**
     * @brief 获取父节点
     * @return PDV_RESULT
     * @param[out] oParentNode 父节点
     * @note
     */
    virtual PDV_RESULT GetParent(IModelTreeNode *&oParentNode) = 0;

	/**
     * @brief 获取父节点ID
     * @return DftUInt64 父节点ID
     * @note 如果该节点没有父节点，返回 \ref DFT_INVALID_ID
     */
    virtual DftUInt64 GetParentID() const = 0;

    /**
     * @brief 设置父节点ID
     * @return PDV_RESULT
     * @param[in] iParentID 父节点ID
     * @note 返回 \ref PDV_RESULT_NO_ERROR
     */
    virtual PDV_RESULT SetParentID(const DftUInt64 iParentID) = 0;

    /**
     * @brief 获取子节点
     * @return PDV_RESULT
     * @param[out] oChildren 子节点
     * @note
     */
    virtual PDV_RESULT GetChildren(std::vector<IModelTreeNode*> &oChildren) = 0;
    
    /**
     * @brief 获取是否关联线材质对象标志
     * @return DftBool 是否关联线材质对象标志，TRUE说明关联线材质对象，FALSE说明不关联线材质对象
     * @note
     */
    virtual DftBool GetLineMaterialFlag() = 0;

    /**
     * @brief 设置是否关联线材质对象标志
     * @return PDV_RESULT
     * @param[in] iMaterialFlag 是否关联线材质对象标志，TRUE说明关联线材质对象，FALSE说明不关联线材质对象
     * @note
     */
    virtual PDV_RESULT SetLineMaterialFlag(DftBool iMaterialFlag) = 0;

    /**
     * @brief 获取操作杆局部坐标系矩阵
     * @return PDV_RESULT
     * @param[out] oLeverMatrix 操作杆局部坐标系矩阵
     * @note 如果包含操作杆局部坐标系矩阵，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODELTREENODE_NO_EXTENDINFO
     */
    virtual PDV_RESULT GetLeverMatrix(PDVMatrix4F& oLeverMatrix) = 0;

    /**
     * @brief 设置操作杆局部坐标系矩阵
     * @return PDV_RESULT
     * @param[in] iLeverMatrix 操作杆局部坐标系矩阵
     * @note 如果包含操作杆局部坐标系矩阵，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODELTREENODE_NO_EXTENDINFO
     */
    virtual PDV_RESULT SetLeverMatrix(const PDVMatrix4F& iLeverMatrix) = 0;

    /**
     * @brief 获取关联线材质ID
     * @return DftUInt64 关联线材质ID
     * @note 如果关联线材质对象，则返回关联线材质ID，否则返回 \ref DFT_INVALID_ID
     */
    virtual DftUInt64 GetLineMaterialID() const = 0;

    /**
     * @brief 设置关联线材质ID
     * @return PDV_RESULT
     * @param[in] iLineMaterialID 关联线材质ID
     * @note 如果关联材质对象，则返回 \ref PDV_RESULT_NO_ERROR 否则返回 \ref PDV_RESULT_MODELTREENODE_NO_EXTENDINFO
     */
    virtual PDV_RESULT SetLineMaterialID(DftUInt64 iLineMaterialID) = 0;

    /**
     * @brief 设置兄弟节点ID
     * @return PDV_RESULT
     * @param[in] iSiblingID 兄弟节点ID，第一个节点的siblingID为0
     * @note 返回 \ref PDV_RESULT_NO_ERROR
     */
    virtual PDV_RESULT SetSiblingID(DftUInt64 iSiblingID) = 0;

    /**
     * @brief 获取兄弟节点ID
     * @return DftUInt64 兄弟节点ID
     * @note
     */
    virtual DftUInt64 GetSiblingID() const = 0;
};

} // namespace pdv

} // namespace kernel
#endif


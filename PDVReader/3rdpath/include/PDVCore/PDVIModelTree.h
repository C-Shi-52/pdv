/**
 * @file PDVIModelTree.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-22
 * @brief 概述：模型树的接口声明
 * @details 详细说明
 */

#ifndef PDVIMODELTREE_H
#define PDVIMODELTREE_H

#include "PDVBase.h"
#include "PDVIDataObject.h"

namespace kernel
{

namespace pdv
{

class IModelTreeNode;

/** @brief 模型树的接口 */
class PDVCORE_API IModelTree : public IDataObject
{
public:
    /**
     * @brief 获取模型树名称
     * @return PDV_RESULT
     * @param[out] oName 模型树名称
     * @note
     */
    virtual PDV_RESULT GetName(CUnicodeString &oName) = 0;

    /**
     * @brief 设置模型树名称
     * @return PDV_RESULT
     * @param[in] iName 模型树名称
     * @note
     */
    virtual PDV_RESULT SetName(const CUnicodeString &iName) = 0;

    /**
     * @brief 获取节点个数
     * @return DftUInt 节点个数
     * @note
     */
    virtual DftUInt GetNodeCount() = 0;

    /**
     * @brief 添加模型树节点
     * @return PDV_RESULT
     * @param[in] iNodeName 模型树节点名称
     * @param[in] iParent 模型树节点的父节点
     * @param[out] oNewNode 新的模型树节点
     * @note 如果iParent为空，添加模型树的根节点；否则添加iParent的子节点
     */
    virtual PDV_RESULT AddNode(const CUnicodeString &iNodeName, IModelTreeNode *iParent, IModelTreeNode *&oNewNode) = 0;

    /**
     * @brief 插入模型树节点
     * @return PDV_RESULT
     * @param[in] iNodeName 模型树节点名称
     * @param[in] iNode 需要插入的位置节点
     * @param[out] oNewNode 新的模型树节点
     */
    virtual PDV_RESULT InsertNode(const CUnicodeString &iNodeName, IModelTreeNode *iNode, IModelTreeNode *&oNewNode) = 0;

    /**
     * @brief 删除树节点
     * @return PDV_RESULT
     * @param[in] iNode 需要删除的节点
     */
    virtual PDV_RESULT DeleteNode(IModelTreeNode *iNode) = 0;

    /**
     * @brief 获取根节点
     * @return PDV_RESULT
     * @param[out] oRootNode 根节点
     * @note 如果有根节点则返回 \ref PDV_RESULT_NO_ERROR
     */
    virtual PDV_RESULT GetRootNode(IModelTreeNode *&oRootNode) = 0;

    /**
     * @brief 根据ID获取节点
     * @return PDV_RESULT
     * @param[in] iNodeID 节点ID
     * @param[out] oNode 节点
     * @note 如果不存在oNode为空
     */
    virtual PDV_RESULT GetTreeNodeByID(DftUInt64 iNodeID, IModelTreeNode *&oNode) = 0;

    /**
     * @brief 获取模型树子全部子节点
     * @return PDV_RESULT
     * @param[out] oChildrenArray 模型树子节点
     * @note
     */
    virtual PDV_RESULT GetChildrenNodes(std::vector<IModelTreeNode *> &oChildrenArray) = 0;

    /**
     * @brief 根据最大层级数合并子节点
     * @return PDV_RESULT
     * @param[in] iMaxLevel 最大层级数，根节点表示0级，以此类推
     * @note
     */
    virtual PDV_RESULT MergeChildNodeByMaxLevel(DftInt iMaxLevel) = 0;

    /**
     * @brief 根据节点ID合并子节点
     * @return PDV_RESULT
     * @param[in] iNodeID 节点ID
     * @note
     */
    virtual PDV_RESULT MergeChildNodeByNodeID(DftUInt64 iNodeID) = 0;
};

} // namespace pdv

} // namespace kernel

#endif

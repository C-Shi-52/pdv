/**
 * @file PDVCWrap2CGo.h
 * @author zhangheng
 * @version 1.0
 * @date 2025-05-27
 * @brief 概述: c封装的接口, 用于go调用
 * @details 详细说明
 */

#ifndef PDVCWrap2CGo_H
#define PDVCWrap2CGo_H

#ifdef __cplusplus
extern "C"
{
#endif
    typedef void* SceneDataHandle; // 场景数据对象
    // 结构树节点信息
    struct TreeNodeInfo
    {
        const char* _nodeName;
        unsigned long long _nodeID;
        unsigned long long _parentNodeID;
        float _boundingBoxMin[3];
        float _boundingBoxMax[3];
        float _localTransform[16];
        struct TreeNodeInfo** _children;
        int _childCount;
    };

    SceneDataHandle CreateSceneData();
    void DestroySceneData(SceneDataHandle iHandle);
    void CallBuildTileSetToCGo(SceneDataHandle iHandle, TreeNodeInfo* iNode, unsigned long long* oLength, unsigned char** buffer);
    void FreeTreeNodeInfo(TreeNodeInfo** ioNode);

#ifdef __cplusplus
}
#endif

#endif

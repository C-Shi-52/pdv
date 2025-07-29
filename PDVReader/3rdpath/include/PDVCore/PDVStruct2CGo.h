#ifndef TREE_NODE_DEF_H
#define TREE_NODE_DEF_H

#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct _TreeNodeInfo
    {
        const char* _nodeName;
        unsigned long long _nodeID;
        unsigned long long _parentNodeID;
        float _boundingBoxMin[3];
        float _boundingBoxMax[3];
        float _localTransform[16];
        struct _TreeNodeInfo** _children;
        int _childCount;
    } TreeNodeInfo;

#ifdef __cplusplus
}
#endif

#endif // TREE_NODE_DEF_H

/**
 * @file PDVISceneData.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-15
 * @brief 概述：包含SceneData的接口声明
 * @details 详细说明
 */

#ifndef PDVISCENEDATA_H
#define PDVISCENEDATA_H

#include "PDVBase.h"

struct TreeNodeInfo;

namespace kernel
{

namespace pdv
{

class IDataObject;
class IScene;
class ITileSet;
class IModelTree;
class IModel;
class IMesh;
class IAttribute;
class ICamera;
class IAnnotation;
class IReview;
class IView;
class IMaterial;
class IAnimation;
class IResource;
class ISecurity;
class IUserData;
class IExternalLink;
class IBRep;
class IAnimation;
class IPrimity;
class ILight;
class ITexture;
class IReview;
class IPhysicalQuantity;
class IRenderBodySubset;
class IRenderBody;
class IRenderVertex;
class IRenderGeometry;
class IResultConfig;
class IRenderMesh;
class IReferenceGeometryGroup;
class INodeSubsetMaterial;
class IInstancedMesh;
class IBatchedMesh;
class IAnalysisResult;

/** @brief 外部文件标志类型（占位） */
enum ExternalFlagType
{
    EXTERNAL_FLAG_MESH = 0x0001,        ///< 网格对象标志位
    EXTERNAL_FLAG_ATTRIBUTE = 0x0002,   ///< 属性对象标志位
    EXTERNAL_FLAG_ANNOTATION = 0x0004,  ///< 标注对象标志位
    EXTERNAL_FLAG_MATERIAL = 0x0008,    ///< 材质对象标志位
    EXTERNAL_FLAG_RESOURCE = 0x0010,    ///< 资源对象标志位
    EXTERNAL_FLAG_BREP = 0x0012,        ///< 几何拓扑对象标志位
};

/** @brief 索引数据类型 */
enum SceneDataType
{
    SCENE_DATA_TYPE_NONE = 0,                 ///< 初始类型，不代表任何数据类型
    SCENE_DATA_TYPE_SCENE = 101,              ///< 场景
    SCENE_DATA_TYPE_MODELTREE = 102,          ///< 产品结构树
    SCENE_DATA_TYPE_MODEL = 103,              ///< 模型
    SCENE_DATA_TYPE_MATERIAL = 108,           ///< 材质
    SCENE_DATA_TYPE_TEXTURE = 109,            ///< 纹理
    SCENE_DATA_TYPE_CAMERA = 110,             ///< 相机
    SCENE_DATA_TYPE_LIGHT = 111,              ///< 灯光
    SCENE_DATA_TYPE_RESOURCE = 116,           ///< 资源文件
    SCENE_DATA_TYPE_EXTERNALLINK = 118,       ///< 外部链接
    SCENE_DATA_TYPE_TILE = 150,               ///< 瓦片
    SCENE_DATA_TYPE_RESULTCONFIG = 151,       ///< 分析结果配置
    SCENE_DATA_TYPE_NODESUBSETMATERIAL = 152, ///< 节点面材质
    SCENE_DATA_TYPE_RENDERBODY = 153,         ///< 渲染主体
    SCENE_DATA_TYPE_RENDERMESH = 154,         ///< 渲染网格
    SCENE_DATA_TYPE_BATCHEDMESH = 155,        ///< 批处理网格
    SCENE_DATA_TYPE_INSTANCEDMESH = 156,      ///< 实例化网格
};

/** @brief 场景数据接口 */
class PDVCORE_API ISceneData
{
public:
    /**
     * @brief 清空数据
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT Clear() = 0;

    /**
     * @brief 释放内存
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT Release() = 0;

    /**
     * @brief 获取场景对象接口
     * @return IScene * 场景对象接口
     * @note
     */
    virtual IScene* GetScene() = 0;

    /**
     * @brief 获取瓦块对象接口
     * @return ITileSet * 瓦块对象接口
     * @note
     */
    virtual ITileSet* GetTileSet() = 0;

    /**
     * @brief 创建内部瓦片数据
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT BuildTileSet() = 0;

    /**
     * @brief 创建内部瓦片数据
     * @return CGo调用
     * @param[in] iTreeNodeInfoData 模型节点信息数据
     * @param[out] oLength oStreamBuffer的长度
     * @param[out] oStreamBuffer 构建的瓦片数据流
     * @note
     */
    virtual PDV_RESULT BuildTileSetToCGo(TreeNodeInfo* iTreeNodeInfoData, DftUInt64& oLength, DftByte*& oStreamBuffer) = 0;

    /**
     * @brief 获取模型树对象接口集
     * @return PDV_RESULT
     * @param[out] oModelTreeArray 模型树对象接口集
     * @note
     */
    virtual PDV_RESULT GetModelTreeArray(std::vector<IModelTree*> &oModelTreeArray) = 0;

    /**
     * @brief 获取模型对象接口集
     * @return PDV_RESULT
     * @param[out] oModelArray 模型对象接口集
     * @note
     */
    virtual PDV_RESULT GetModelArray(std::vector<IModel*> &oModelArray) = 0;

    /**
     * @brief 获取网格对象接口集
     * @return PDV_RESULT
     * @param[out] oMeshArray 网格对象接口集
     * @note
     */
    virtual PDV_RESULT GetMeshArray(std::vector<IMesh*> &oMeshArray) = 0;

     /**
     * @brief 获取几何拓扑对象接口集
     * @return PDV_RESULT
     * @param[out] oBRepArray 几何拓扑象接口集
     * @note
     */
    virtual PDV_RESULT GetBRepArray(std::vector<IBRep*> &oBRepArray) = 0;

    /**
     * @brief 获取属性对象接口集
     * @return PDV_RESULT
     * @param[out] oAttributeArray 属性对象接口集
     * @note
     */
    virtual PDV_RESULT GetAttributeArray(std::vector<IAttribute*> &oAttributeArray) = 0;

    /**
     * @brief 获取摄像机对象接口集
     * @return PDV_RESULT
     * @param[out] oCameraArray 摄像机对象接口集
     * @note
     */
    virtual PDV_RESULT GetCameraArray(std::vector<ICamera*> &oCameraArray) = 0;

    /**
     * @brief 获取标注对象接口集
     * @return PDV_RESULT
     * @param[out] oAnnotationArray 标注对象接口集
     * @note
     */
    virtual PDV_RESULT GetAnnotationArray(std::vector<IAnnotation*> &oAnnotationArray) = 0;

    /**
     * @brief 获取审阅对象接口集
     * @return PDV_RESULT
     * @param[out] oReviewArray 审阅对象接口集
     * @note
     */
    virtual PDV_RESULT GetReviewArray(std::vector<IReview*> &oReviewArray) = 0;

    /**
     * @brief 获取视图对象接口集
     * @return PDV_RESULT
     * @param[out] oViewArray 视图对象接口集
     * @note
     */
    virtual PDV_RESULT GetViewArray(std::vector<IView*> &oViewArray) = 0;

    /**
     * @brief 获取材质对象接口集
     * @return PDV_RESULT
     * @param[out] oMaterialArray 材质对象接口集
     * @note
     */
    virtual PDV_RESULT GetMaterialArray(std::vector<IMaterial*> &oMaterialArray) = 0;

    /**
     * @brief 获取动画对象接口集
     * @return PDV_RESULT
     * @param[out] oAnimationArray 动画对象接口集
     * @note
     */
    virtual PDV_RESULT GetAnimationArray(std::vector<IAnimation*> &oAnimationArray) = 0;

    /**
    * @brief 获取基本体对象接口集
    * @return PDV_RESULT
    * @param[out] oPrimityArray 基本体象接口集
    * @note
    */
    virtual PDV_RESULT GetPrimityArray(std::vector<IPrimity*> &oPrimityArray) = 0;

    /**
    * @brief 获取灯光对象接口集
    * @return PDV_RESULT
    * @param[out] oLightArray 灯光对象接口集
    * @note
    */
    virtual PDV_RESULT GetLightArray(std::vector<ILight*> &oLightArray) = 0;

    /**
    * @brief 获取纹理对象接口集
    * @return PDV_RESULT
    * @param[out] oTextureArray 纹理对象接口集
    * @note
    */
    virtual PDV_RESULT GetTextureArray(std::vector<ITexture*> &oTextureArray) = 0;
    
    /**
     * @brief 获取资源文件对象接口集
     * @return PDV_RESULT
     * @param[out] oResourceArray 资源文件对象接口集
     * @note
     */
    virtual PDV_RESULT GetResourceArray(std::vector<IResource*> &oResourceArray) = 0;

    /**
     * @brief 获取物理量对象接口集
     * @return PDV_RESULT
     * @param[out] oPhysicalQuantityArray 物理量对象接口集
     * @note
     */
    virtual PDV_RESULT GetPhysicalQuantityArray(std::vector<IPhysicalQuantity*>& oPhysicalQuantityArray) = 0;

    /**
     * @brief 获取渲染主体对象接口集
     * @return PDV_RESULT
     * @param[out] oRenderBodyArray 渲染主体对象接口集
     * @note
     */
    virtual PDV_RESULT GetRenderBodyArray(std::vector<IRenderBody*> &oRenderBodyArray) = 0;

    /**
     * @brief 获取渲染主体子集对象接口集
     * @return PDV_RESULT
     * @param[out] oRenderBodySubsetArray 渲染主体子集对象接口集
     * @note
     */
    virtual PDV_RESULT GetRenderBodySubsetArray(std::vector<IRenderBodySubset*>& oRenderBodySubsetArray) = 0;

    /**
     * @brief 获取渲染几何顶点对象接口集
     * @return PDV_RESULT
     * @param[out] oRenderVertexArray 渲染几何顶点对象接口集
     * @note
     */
    virtual PDV_RESULT GetRenderVertexArray(std::vector<IRenderVertex*> &oRenderVertexArray) = 0;

    /**
     * @brief 获取渲染几何体对象接口集
     * @return PDV_RESULT
     * @param[out] oRenderGeometryArray 渲染几何体对象接口集
     * @note
     */
    virtual PDV_RESULT GetRenderGeometryArray(std::vector<IRenderGeometry*> &oRenderGeometryArray) = 0;

    /**
     * @brief 获取分析结果配置对象接口集
     * @return PDV_RESULT
     * @param[out] oResultConfigArray 分析结果配置对象接口集
     * @note
     */
    virtual PDV_RESULT GetResultConfigArray(std::vector<IResultConfig*> &oResultConfigArray) = 0;

    /**
     * @brief 获取渲染网格对象接口集
     * @return PDV_RESULT
     * @param[out] oRenderMeshArray 渲染网格对象接口集
     * @note
     */
    virtual PDV_RESULT GetRenderMeshArray(std::vector<IRenderMesh*> &oRenderMeshArray) = 0;

    /**
     * @brief 获取辅助几何对象接口集
     * @return PDV_RESULT
     * @param[out] oReferenceGeometryGroupArray 辅助几何对象接口集
     * @note
     */
    virtual PDV_RESULT GetReferenceGeometryGroupArray(std::vector<IReferenceGeometryGroup*> &oReferenceGeometryGroupArray) = 0;

    /**
     * @brief 获取节点面材质对象接口集
     * @return PDV_RESULT
     * @param[out] oNodeSubsetMaterialArray 节点面材质对象接口集
     * @note
     */
    virtual PDV_RESULT GetNodeSubsetMaterialArray(std::vector<INodeSubsetMaterial*> &oNodeSubsetMaterialArray) = 0;

    /**
     * @brief 获取实例化网格对象接口集
     * @return PDV_RESULT
     * @param[out] oInstancedMeshArray 实例化网格对象接口集
     * @note
     */
    virtual PDV_RESULT GetInstancedMeshArray(std::vector<IInstancedMesh*> &oInstancedMeshArray) = 0;

    /**
     * @brief 获取批处理网格对象接口集
     * @return PDV_RESULT
     * @param[out] oBatchedMeshArray 批处理网格对象接口集
     * @note
     */
    virtual PDV_RESULT GetBatchedMeshArray(std::vector<IBatchedMesh*> &oBatchedMeshArray) = 0;

    /**
     * @brief 获取分析结果对象接口集
     * @return PDV_RESULT
     * @param[out] oAnalysisResultArray 分析结果对象接口集
     * @note
     */
    virtual PDV_RESULT GetAnalysisResultArray(std::vector<IAnalysisResult*> &oAnalysisResultArray) = 0;

    /**
     * @brief 获取安全控制数据接口
     * @return ISecurity * 安全控制数据接口
     * @note
     */
    virtual ISecurity* GetSecurity() = 0;

    /**
     * @brief 获取用户自定义对象接口
     * @return IUserData * 用户自定义对象接口
     * @note
     */
    virtual IUserData* GetUserData() = 0;

    /**
     * @brief 获取外部链接对象接口
     * @return IExternalLink * 外部链接对象接口
     * @note
     */
    virtual IExternalLink* GetExternalLink() = 0;

    /**
     * @brief 根据ID查找模型树对象
     * @return IModelTree * 模型树对象
     * @param[in] iID 模型树对象ID
     * @note 如果找不到模型树对象，函数返回NULL
     */
    virtual IModelTree* FindModelTreeByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找模型对象
     * @return IModel * 模型对象
     * @param[in] iID 模型对象ID
     * @note 如果找不到模型对象，函数返回NULL
     */
    virtual IModel* FindModelByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找网格对象
     * @return IMesh * 网格对象
     * @param[in] iID 网格对象ID
     * @note 如果找不到网格对象，函数返回NULL
     */
    virtual IMesh* FindMeshByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找几何拓扑对象
     * @return IBRep * 几何拓扑对象
     * @param[in] iID 几何拓扑对象ID
     * @note 如果找不到几何拓扑对象，函数返回NULL
     */
    virtual IBRep* FindBRepByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找属性对象
     * @return IAttribute * 属性对象
     * @param[in] iID 属性对象ID
     * @note 如果找不到属性对象，函数返回NULL
     */
    virtual IAttribute* FindAttributeByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找摄像机对象
     * @return ICamera * 摄像机对象
     * @param[in] iID 摄像机对象ID
     * @note 如果找不到摄像机对象，函数返回NULL
     */
    virtual ICamera* FindCameraByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找标注对象
     * @return IAnnotation * 标注对象
     * @param[in] iID 标注对象ID
     * @note 如果找不到标注对象，函数返回NULL
     */
    virtual IAnnotation* FindAnnotationByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找审阅对象
     * @return IReview * 审阅对象
     * @param[in] iID 审阅对象ID
     * @note 如果找不到审阅对象，函数返回NULL
     */
    virtual IReview* FindReviewByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找视图对象
     * @return IView * 视图对象
     * @param[in] iID 视图对象ID
     * @note 如果找不到视图对象，函数返回NULL
     */
    virtual IView* FindViewByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找材质对象
     * @return IMaterial * 材质对象
     * @param[in] iID 材质对象ID
     * @note 如果找不到材质对象，函数返回NULL
     */
    virtual IMaterial* FindMaterialByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找动画对象
     * @return IAnimation * 动画对象
     * @param[in] iID 动画对象ID
     * @note 如果找不到动画对象，函数返回NULL
     */
    virtual IAnimation* FindAnimationByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找资源文件对象
     * @return IResource * 资源文件对象
     * @param[in] iID 资源文件对象ID
     * @note 如果找不到资源文件对象，函数返回NULL
     */
    virtual IResource* FindResourceByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找基本体对象
     * @return IPrimity * 基本体对象
     * @param[in] iID 基本体对象ID
     * @note 如果找不到基本体对象，函数返回NULL
     */
    virtual IPrimity* FindPrimityByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找灯光对象
     * @return ILight * 灯光对象
     * @param[in] iID 灯光对象ID
     * @note 如果找不到灯光对象，函数返回NULL
     */
    virtual ILight* FindLightByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找纹理对象
     * @return ITexture * 纹理对象
     * @param[in] iID 纹理对象ID
     * @note 如果找不到纹理对象，函数返回NULL
     */
    virtual ITexture* FindTextureByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找物理量对象
     * @return PDVIPhysicalQuantity * 物理量对象
     * @param[in] iID 物理量对象ID
     * @note 如果找不到物理量对象，函数返回NULL
     */
    virtual IPhysicalQuantity* FindPhysicalQuantityByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找渲染主体对象
     * @return IRenderBody * 渲染主体对象
     * @param[in] iID 渲染主体对象ID
     * @note 如果找不到渲染主体对象，函数返回NULL
     */
    virtual IRenderBody* FindRenderBodyByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找渲染主体子集对象
     * @return IRenderBodySubset * 渲染主体子集对象
     * @param[in] iID 渲染主体子集对象ID
     * @note 如果找不到渲染主体子集对象，函数返回NULL
     */
    virtual IRenderBodySubset* FindRenderBodySubsetByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找渲染几何顶点对象
     * @return IRenderVertex * 渲染几何顶点对象
     * @param[in] iID 渲染几何顶点对象ID
     * @note 如果找不到渲染几何顶点对象，函数返回NULL
     */
    virtual IRenderVertex* FindRenderVertexByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找渲染几何体对象
     * @return IRenderGeometry * 渲染几何体对象
     * @param[in] iID 渲染几何体对象ID
     * @note 如果找不到渲染几何体对象，函数返回NULL
     */
    virtual IRenderGeometry* FindRenderGeometryByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找分析结果配置对象
     * @return IResultConfig * 分析结果配置对象
     * @param[in] iID 分析结果配置对象ID
     * @note 如果找不到分析结果配置对象，函数返回NULL
     */
    virtual IResultConfig* FindResultConfigByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找渲染网格对象
     * @return IRenderMesh * 渲染网格对象
     * @param[in] iID 渲染网格对象ID
     * @note 如果找不到渲染网格对象，函数返回NULL
     */
    virtual IRenderMesh* FindRenderMeshByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找辅助几何对象
     * @return IReferenceGeometryGroup * 辅助几何对象
     * @param[in] iID 辅助几何对象ID
     * @note 如果找不到辅助几何对象，函数返回NULL
     */
    virtual IReferenceGeometryGroup* FindReferenceGeometryGroupByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找节点面材质对象
     * @return INodeSubsetMaterial * 节点面材质对象
     * @param[in] iID 节点面材质对象ID
     * @note 如果找不到节点面材质对象，函数返回NULL
     */
    virtual INodeSubsetMaterial* FindNodeSubsetMaterialByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找实例化网格对象
     * @return IInstancedMesh * 实例化网格对象
     * @param[in] iID 实例化网格对象ID
     * @note 如果找不到实例化网格对象，函数返回NULL
     */
    virtual IInstancedMesh* FindInstancedMeshByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找批处理网格对象
     * @return IBatchedMesh * 批处理网格对象
     * @param[in] iID 批处理网格对象ID
     * @note 如果找不到批处理网格对象，函数返回NULL
     */
    virtual IBatchedMesh* FindBatchedMeshByID(DftUInt64 iID) = 0;

    /**
     * @brief 根据ID查找分析结果对象
     * @return IAnalysisResult * 分析结果对象
     * @param[in] iID 分析结果对象ID
     * @note 如果找不到分析结果对象，函数返回NULL
     */
    virtual IAnalysisResult* FindAnalysisResultByID(DftUInt64 iID) = 0;

    /**
     * @brief 改变对象ID
     * @return PDV_RESULT
     * @param[in] iObject 对象
     * @param[in] iNewID 对象
     * @note
     */
    virtual PDV_RESULT ChangeObjectID(IDataObject *iObject, DftUInt64 iNewID) = 0;

    /**
     * @brief 优化网格数据
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT OptimizeMesh() = 0;

    /**
     * @brief 删除未被引用的网格数据
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT DeleteUnreferencedMesh() = 0;

    /**
     * @brief 并根据需要创建新节点
     * @return PDV_RESULT
     * @param[in] iNodeID 节点ID
     * @param[in] iPDVPaths pdv路径
     * @param[in] iMatrices 追加之后节点的世界矩阵
     * @param[in] iNewNodeNames 新节点名称，如果为空，则不创建新节点
     * @note
     */
    virtual PDV_RESULT AddPDV(DftUInt64 iNodeID, const std::vector<CUnicodeString>& iPDVPaths, const std::vector<PDVMatrix4F>& iMatrices,
                              const std::vector<CUnicodeString>& iNewNodeNames) = 0;

    /**
     * @brief 获取文件属性的文档标识接口集
     * @return CUnicodeString 文件属性的文档标识
     */
    virtual CUnicodeString GetDocInfoDocID() = 0;

    /**
     * @brief 获取文件属性的文档标题接口集
     * @return CUnicodeString 文件属性的文档标题
     */
    virtual CUnicodeString GetDocInfoTitle() = 0;

    /**
     * @brief 获取文件属性的文档作者接口集
     * @return CUnicodeString 文件属性的文档作者
     */
    virtual CUnicodeString GetDocInfoAuthor() = 0;

    /**
     * @brief 获取文件属性的文档版权声明接口集
     * @return CUnicodeString 文件属性的文档版权声明
     */
    virtual CUnicodeString GetDocInfoCopyright() = 0;

    /**
     * @brief 获取文件属性的文档创建时间接口集
     * @return DftUInt64 文件属性的文档创建时间
     */
    virtual DftUInt64 GetDocInfoCreationDate() = 0;

    /**
     * @brief 获取文件属性的文档创建程序名称接口集
     * @return CUnicodeString 文件属性的文档创建程序名称
     */
    virtual CUnicodeString GetDocInfoProducer() = 0;

    /**
     * @brief 获取文件属性的原始数据的创建程序接口集
     * @return CUnicodeString 文件属性的原始数据的创建程序
     */
    virtual CUnicodeString GetDocInfoCreator() = 0;

    /**
     * @brief 设置文件属性的文档标识接口集
     * @return PDV_RESULT
     * @param[in] iDocID 文件属性的文档标识
     */
    virtual PDV_RESULT SetDocInfoDocID(CUnicodeString iDocID) = 0;

    /**
     * @brief 获取文件属性的文档标题接口集
     * @return PDV_RESULT
     * @param[in] iTitle 文件属性的文档标题
     */
    virtual PDV_RESULT SetDocInfoTitle(CUnicodeString iTitle) = 0;

    /**
     * @brief 获取文件属性的文档作者接口集
     * @return PDV_RESULT
     * @param[in] iAuthor 文件属性的文档作者
     */
    virtual PDV_RESULT SetDocInfoAuthor(CUnicodeString iAuthor) = 0;

    /**
     * @brief 获取文件属性的文档版权声明接口集
     * @return PDV_RESULT
     * @param[in] iCopyright 文件属性的文档版权声明
     */
    virtual PDV_RESULT SetDocInfoCopyright(CUnicodeString iCopyright) = 0;

    /**
     * @brief 获取文件属性的文档创建时间接口集
     * @return PDV_RESULT
     * @param[in] iCreationDate 文件属性的文档创建时间
     */
    virtual PDV_RESULT SetDocInfoCreationDate(DftUInt64 iCreationDate) = 0;

    /**
     * @brief 获取文件属性的文档创建程序名称接口集
     * @return PDV_RESULT
     * @param[in] iProducer 文件属性的文档创建程序名称
     */
    virtual PDV_RESULT SetDocInfoProducer(CUnicodeString iProducer) = 0;

    /**
     * @brief 获取文件属性的原始数据的创建程序接口集
     * @return PDV_RESULT
     * @param[in] iCreator 文件属性的原始数据的创建程序
     */
    virtual PDV_RESULT SetDocInfoCreator(CUnicodeString iCreator) = 0;

    /**
     * @brief 将pdv数据导出至XML
     * @return PDV_RESULT
     * @param[in] iExportAttr 是否导出属性
     * @param[in] iXMLPath XML路径
     * @note
     */
    virtual PDV_RESULT ExportXML(DftBool iExportAttr, const CUnicodeString& iXMLPath) = 0;

    /**
     * @brief 构建节点面材质数据
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT BuildNodeSubsetMaterial() = 0;

    /**
     * @brief 将renderMesh数据进行合批和实例化处理
     * @return PDV_RESULT
     * @param[in] iInstancedMinVertexCount 实例化时，限制实例渲染顶点数的最小值
     * @param[in] iInstancedVertexCompareDecimalPlaces 二次实例化算法中比较顶点数据时，涉及到小数点后的位数
     * @param[in] iBatchedMaxVertexCount 合批时，限制合批的顶点数据上限
     * @param[in] iBatchedOctreeNodeReserveDepth 合批时，限制合批节点八叉树的层级深度
     * @note
     */
    virtual PDV_RESULT RunBatchedAndInstanced(DftUInt iInstancedMinVertexCount, DftInt iInstancedVertexCompareDecimalPlaces,
        DftUInt iBatchedMaxVertexCount, DftUInt iBatchedOctreeNodeReserveDepth) = 0;

    /**
     * @brief 将renderMesh数据进行合批和实例化处理，合批前把节点下的body全部合并
     * @return PDV_RESULT
     * @param[in] iInstancedMinVertexCount 实例化时，限制实例渲染顶点数的最小值
     * @param[in] iInstancedVertexCompareDecimalPlaces 二次实例化算法中比较顶点数据时，涉及到小数点后的位数
     * @param[in] iBatchedMaxVertexCount 合批时，限制合批的顶点数据上限
     * @param[in] iBatchedOctreeNodeReserveDepth 合批时，限制合批节点八叉树的层级深度
     * @note
     */
    virtual PDV_RESULT RunBatchedAndInstanced2(DftUInt iInstancedMinVertexCount, DftInt iInstancedVertexCompareDecimalPlaces,
        DftUInt iBatchedMaxVertexCount, DftUInt iBatchedOctreeNodeReserveDepth) = 0;

    /**
     * @brief 将合批和实例化后的renderMesh数据进行还原
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT RevertBatchedAndInstanced() = 0;

    /**
     * @brief 对输入的每个节点进行合并，将其子节点都合并到当前节点，并保留所有Body
     * @return PDV_RESULT
     * @param[in] iNodeIDs 要合并的节点的ID数组
     * @note
     */
    virtual PDV_RESULT MergeModeltreeNodesWithMultiBody(const std::vector<DftUInt64>& iNodeIDs) = 0;

    /**
     * @brief 对输入的每个节点进行合并，将其子节点都合并到当前节点，并合并所有Body为1个
     * @return PDV_RESULT
     * @param[in] iNodeIDs 要合并的节点的ID数组
     * @note
     */
    virtual PDV_RESULT MergeModeltreeNodesWithOneBody(const std::vector<DftUInt64>& iNodeIDs) = 0;

    /**
     * @brief 移除未被引用的数据
     * @return PDV_RESULT
     * @note
     */
    virtual PDV_RESULT RemoveUnReferenceData() = 0;

    /**
     * @brief 统计渲染数据的数量
     * @return PDV_RESULT
     * @param[out] oInfo 输出的统计结果
     * @note
     */
    virtual PDV_RESULT StatisticsRenderDataCount(CUnicodeString& oInfo) = 0;

    /**
     * @brief 根据包围盒设置默认相机数据
     * @return PDV_RESULT
     * @param[in] iBox 场景包围盒
     * @param[in] iCameraType 摄像机类型
     * @param[in] iUpDir 上方向
     * @param[in] iRightDir 右方向
     * @note
     */
    virtual PDV_RESULT SetDefaultCameraByBox(const BoundingBox& iBox, DftUInt8 iCameraType, const PDVVector3F& iUpDir,
                                             const PDVVector3F& iRightDir) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
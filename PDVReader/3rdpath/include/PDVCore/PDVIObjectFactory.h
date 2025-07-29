/**
 * @file PDVIObjectFactory.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-15
 * @brief 概述：PDV数据工厂接口，包含构建PDV数据接口的声明
 * @details 详细说明
 */

#ifndef PDVIOBJECTFACTORY_H
#define PDVIOBJECTFACTORY_H

#include "PDVBase.h"
#include "PDVISceneData.h"
#include "PDVIMaterial.h"
#include "PDVIModel.h"
#include "PDVIMesh.h"
#include "PDVIAttribute.h"
#include "PDVICamera.h"
#include "PDVIAnnotation.h"
#include "PDVIBRep.h"
#include "PDVIPrimity.h"
#include "PDVILight.h"
#include "PDVITexture.h"
#include "PDVIReview.h"
#include "PDVIAnimation.h"
#include "PDVIExternalLink.h"
#include "PDVIRenderBody.h"
#include "PDVIRenderMesh.h"
#include "PDVIRenderGeometry.h"
#include "PDVIRenderBodySubset.h"
#include "PDVIPhysicalQuantity.h"
#include "PDVIRenderVertex.h"
#include "PDVIResultConfig.h"
#include "PDVIReferenceGeometry.h"
#include "PDVINodeSubsetMaterial.h"
#include "PDVIInstancedMesh.h"
#include "PDVIBatchedMesh.h"
#include "PDVIAnalysisResult.h"

namespace kernel
{

namespace pdv
{

/** @brief PDV数据工厂接口 */
class PDVCORE_API IObjectFactory
{
public:
    /**
     * @brief 获取 IObjectFactory 接口类
     * @return IObjectFactory * IObjectFactory 接口类
     * @note
     */
    static IObjectFactory* GetObjectFactory();

    /**
     * @brief 创建 ISceneData 接口类
     * @return PDV_RESULT
     * @param[out] oSceneData ISceneData 接口类
     * @note
     */
    virtual PDV_RESULT CreateSceneData(ISceneData *&oSceneData) = 0;

    /**
     * @brief 创建 IModelTree 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IModelTree 的所属场景对象
     * @param[out] oModelTree IModelTree 接口类
     * @note
     */
    virtual PDV_RESULT CreateModelTree(ISceneData *iOwner, IModelTree *&oModelTree) = 0;

    /**
     * @brief 创建 IModel 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IModel 的所属场景对象
     * @param[out] oModel IModel 接口类
     * @note
     */
    virtual PDV_RESULT CreateModel(ISceneData *iOwner, IModel *&oModel) = 0;

    /**
     * @brief 创建 IMesh 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IMesh 的所属场景对象
     * @param[out] oMesh IMesh 接口类
     * @note
     */
    virtual PDV_RESULT CreateMesh(ISceneData *iOwner, IMesh *&oMesh) = 0;

     /**
     * @brief 创建 IBRep 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IBRep 的所属场景对象
     * @param[out] oBRep IBRep 接口类
     * @note
     */
    virtual PDV_RESULT CreateBRep(ISceneData *iOwner, IBRep *&oBRep) = 0;

    /**
     * @brief 创建 IAttribute 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IAttribute 的所属场景对象
     * @param[out] oAttribute IAttribute 接口类
     * @note
     */
    virtual PDV_RESULT CreateAttribute(ISceneData *iOwner, IAttribute *&oAttribute) = 0;

    /**
     * @brief 创建 ICamera 接口类
     * @return PDV_RESULT
     * @param[in] iOwner ICamera 的所属场景对象
     * @param[out] oCamera ICamera 接口类
     * @note
     */
    virtual PDV_RESULT CreateCamera(ISceneData *iOwner, ICamera *&oCamera) = 0;

    /**
     * @brief 创建 IMaterial 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IMaterial 的所属场景对象
     * @param[out] oMaterial IMaterial 接口类
     * @note
     */
    virtual PDV_RESULT CreateMaterial(ISceneData *iOwner, IMaterial *&oMaterial) = 0;

    /**
     * @brief 创建 IAnnotation 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IAnnotation 的所属场景对象
     * @param[out] oAnnotation IAnnotation 接口类
     * @note
     */
    virtual PDV_RESULT CreateAnnotation(ISceneData *iOwner, IAnnotation *&oAnnotation) = 0;

	/**
	 * @brief 创建 IView 接口类
	 * @return PDV_RESULT
	 * @param[in] iOwner IView 的所属场景对象
	 * @param[out] oView IView 接口类
	 * @note
	 */
	virtual PDV_RESULT CreateView(ISceneData *iOwner, IView *&oView) = 0;

    /**
     * @brief 创建 IAnimation 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IAnimation 的所属场景对象
     * @param[out] oAnimation IAnimation 接口类
     * @note
     */
    virtual PDV_RESULT CreateAnimation(ISceneData *iOwner, IAnimation *&oAnimation) = 0;

    /**
     * @brief 创建 IPrimity 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IPrimity 的所属场景对象
     * @param[out] oPrimity IPrimity 接口类
     * @note
     */
    virtual PDV_RESULT CreatePrimity(ISceneData *iOwner, IPrimity *&oPrimity) = 0;

    /**
     * @brief 创建 ILight 接口类
     * @return PDV_RESULT
     * @param[in] iOwner ILight 的所属场景对象
     * @param[out] oLight ILight 接口类
     * @note
     */
    virtual PDV_RESULT CreateLight(ISceneData *iOwner, ILight *&oLight) = 0;

    /**
     * @brief 创建 ITexture 接口类
     * @return PDV_RESULT
     * @param[in] iOwner ITexture 的所属场景对象
     * @param[out] oTexture ITexture 接口类
     * @note
     */
    virtual PDV_RESULT CreateTexture(ISceneData *iOwner, ITexture *&oTexture) = 0;

    /**
     * @brief 创建 IResource 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IResource 的所属场景对象
     * @param[out] oResource IResource 接口类
     * @note
     */
    virtual PDV_RESULT CreateResource(ISceneData *iOwner, IResource *&oResource) = 0;

    /**
     * @brief 创建 IReview 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IReview 的所属场景对象
     * @param[out] oReview IReview 接口类
     * @note
     */
    virtual PDV_RESULT CreateReview(ISceneData *iOwner, IReview *&oReview) = 0;

    /**
     * @brief 创建 IRenderBody 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IRenderBody 的所属场景对象
     * @param[out] oRenderBody IRenderBody 接口类
     * @note
     */
    virtual PDV_RESULT CreateRenderBody(ISceneData* iOwner, IRenderBody*& oRenderBody) = 0;

    /**
     * @brief 创建 IRenderMesh 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IRenderMesh 的所属场景对象
     * @param[out] oRenderMesh IRenderMesh 接口类
     * @note
     */
    virtual PDV_RESULT CreateRenderMesh(ISceneData* iOwner, IRenderMesh*& oRenderMesh) = 0;

    /**
     * @brief 创建 IRenderVertex 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IRenderVertex 的所属场景对象
     * @param[out] oRenderVertex IRenderVertex 接口类
     * @note
     */
    virtual PDV_RESULT CreateRenderVertex(ISceneData* iOwner, IRenderVertex*& oRenderVertex) = 0;

    /**
     * @brief 创建 IRenderGeometry 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IRenderGeometry 的所属场景对象
     * @param[out] oRenderGeometry IRenderGeometry 接口类
     * @note
     */
    virtual PDV_RESULT CreateRenderGeometry(ISceneData* iOwner, IRenderGeometry*& oRenderGeometry) = 0;

    /**
     * @brief 创建 IRenderBodySubset 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IRenderBodySubset 的所属场景对象
     * @param[out] oResultConfig IRenderBodySubset 接口类
     * @note
     */
    virtual PDV_RESULT CreateRenderBodySubset(ISceneData* iOwner, IRenderBodySubset*& oResultConfig) = 0;

    /**
     * @brief 创建 IPhysicalQuantity 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IPhysicalQuantity 的所属场景对象
     * @param[out] oPhysicalQuantity IPhysicalQuantity 接口类
     * @note
     */
    virtual PDV_RESULT CreatePhysicalQuantity(ISceneData* iOwner, IPhysicalQuantity*& oPhysicalQuantity) = 0;

    /**
     * @brief 创建 IResultConfig 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IResultConfig 的所属场景对象
     * @param[out] oResultConfig IResultConfig 接口类
     * @note
     */
    virtual PDV_RESULT CreateResultConfig(ISceneData* iOwner, IResultConfig*& oResultConfig) = 0;

    /**
     * @brief 创建 IReferenceGeometryGroup 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IReferenceGeometryGroup 的所属场景对象
     * @param[out] oReferenceGeometryGroup IReferenceGeometryGroup 接口类
     * @note
     */
    virtual PDV_RESULT CreateReferenceGeometryGroup(ISceneData* iOwner, IReferenceGeometryGroup*& oReferenceGeometryGroup) = 0;

    /**
     * @brief 创建 INodeSubsetMaterial 接口类
     * @return PDV_RESULT
     * @param[in] iOwner INodeSubsetMaterial 的所属场景对象
     * @param[out] oNodeSubsetMaterial INodeSubsetMaterial 接口类
     * @note
     */
    virtual PDV_RESULT CreateNodeSubsetMaterial(ISceneData* iOwner, INodeSubsetMaterial*& oNodeSubsetMaterial) = 0;

    /**
     * @brief 创建 IInstancedMesh 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IInstancedMesh 的所属场景对象
     * @param[out] oInstancedMesh IInstancedMesh 接口类
     * @note
     */
    virtual PDV_RESULT CreateInstancedMesh(ISceneData* iOwner, IInstancedMesh*& oInstancedMesh) = 0;

    /**
     * @brief 创建 IBatchedMesh 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IBatchedMesh 的所属场景对象
     * @param[out] oBatchedMesh IBatchedMesh 接口类
     * @note
     */
    virtual PDV_RESULT CreateBatchedMesh(ISceneData* iOwner, IBatchedMesh*& oBatchedMesh) = 0;

    /**
     * @brief 创建 IAnalysisResult 接口类
     * @return PDV_RESULT
     * @param[in] iOwner IAnalysisResult 的所属场景对象
     * @param[out] oAnalysisResult IAnalysisResult 接口类
     * @note
     */
    virtual PDV_RESULT CreateAnalysisResult(ISceneData* iOwner, IAnalysisResult*& oAnalysisResult) = 0;
};

} // namespace pdv

} // namespace kernel
#endif
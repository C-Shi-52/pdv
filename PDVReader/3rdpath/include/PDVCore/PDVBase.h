/**
 * @file PDVBase.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-17
 * @brief 概述：pdv的基本数据定义
 * @details 详细说明
 */

#ifndef PDVBASE_H
#define PDVBASE_H

#include "DftBase.h"
#include "DftJson.h"
#include "UnicodeString.h"
#include "PDVTypes.h"
#include "PDVMath.h"
#include "DftMath.h"
#include "DftFileOS.h"

#ifdef _MSC_VER
#pragma warning(disable : 4201) ///< nonstandard extension used: nameless struct/union
#pragma warning(disable : 4127) ///< conditional expression is constant
#pragma warning(disable : 4251) ///< class __declspec( dllexport ) Test{} 

#ifdef PDVCORE_EXPORTS
#define PDVCORE_API __declspec(dllexport)
#else
#define PDVCORE_API __declspec(dllimport)
#endif
#else
#define PDVCORE_API
#endif

struct cJSON;

namespace kernel
{

namespace iostream
{
    class IStream;
}

namespace pdv
{

/** @brief 函数返回结果类型 */
enum PDV_RESULT
{
    PDV_RESULT_NO_ERROR = 0,      ///< 无错误
    PDV_RESULT_GENERAL_ERROR = 1, ///< 一般错误
    PDV_RESULT_INITIAL_ERROR = 2, ///< 初始化错误
    PDV_RESULT_INPUT_ERROR = 3,   ///< 输入错误

    PDV_RESULT_SCENE_ERROR = 100, ///< 场景对象错误

    PDV_RESULT_MODELTREE_ERROR = 200,                  ///< 模型树对象错误
    PDV_RESULT_MODELTREENODE_NO_MODEL = 201,           ///< 模型树节点无关联模型
    PDV_RESULT_MODELTREENODE_NO_LOCAL_TRANSFORM = 202, ///< 模型树节点无局部变换信息
    PDV_RESULT_MODELTREENODE_NO_ATTRIBUTE = 203,       ///< 模型树节点无关联属性对象
    PDV_RESULT_MODELTREENODE_NO_MATERIAL = 204,        ///< 模型树节点无关联材质对象
    PDV_RESULT_MODELTREENODE_NO_ANNOTATION = 205,      ///< 模型树节点无关联标注对象
    PDV_RESULT_MODELTREENODE_NO_WORLD_TRANSFORM = 206, ///< 模型树节点无全局变换信息
    PDV_RESULT_MODELTREENODE_NO_EXTERNAL_PDV = 207,    ///< 模型树节点无关联外部pdv对象
    PDV_RESULT_MODELTREENODE_NO_EXTENDINFO = 208,      ///< 模型树节点无扩展数据

    PDV_RESULT_MODEL_ERROR = 300,         ///< 模型对象错误
    PDV_RESULT_MODEL_NO_PROPERTY = 301,   ///< 网格图元集合模型无全局坐标变换信息
    PDV_RESULT_MODEL_NO_MESH = 302,       ///< 模型无网格数据
    PDV_RESULT_MODEL_NO_PRIMITY = 303,    ///< 模型无基本体数据
    PDV_RESULT_MODEL_NO_TOPO = 304,       ///< 模型无拓扑数据
    PDV_RESULT_MODEL_NO_ANNOTATION = 305, ///< 模型无标注数据
    PDV_RESULT_MODEL_NO_ATTRIBUTE = 306,  ///< 模型无属性数据
    PDV_RESULT_MODEL_NO_EXTENDINFO = 307, ///< 模型无拓展属性数据

    PDV_RESULT_MESH_ERROR = 400,                        ///< 网格对象错误
    PDV_RESULT_MESH_NO_PRIMCOLLECTION = 401,            ///< 网格无图元集合数据
    PDV_RESULT_MESH_NO_MASS_PROPERTY = 402,             ///< 网格无质量特性数据
    PDV_RESULT_MESH_NO_MATERIAL = 403,                  ///< 网格无颜色透明度数据
    PDV_RESULT_MESHPRIMCOLLECTION_NO_MATERIAL = 404,    ///< 网格图元集合无颜色透明度数据
    PDV_RESULT_MESHPRIMCOLLECTION_NO_BOUNDINGBOX = 405, ///< 网格图元集合无包围盒数据
    PDV_RESULT_MESHPRIMCOLLECTION_TYPE_ERROR = 406,     ///< 网格图元集合类型错误
    PDV_RESULT_MESHPRIMCOLLECTION_NO_TOPO = 407,        ///< 网格图元集合类型错误

    PDV_RESULT_LIGHT_WRONGTYPE = 450, ///< 灯光类型错误

    PDV_RESULT_ATTRIBUTE_ERROR = 500,            ///< 属性对象错误
    PDV_RESULT_ATTRIBUTE_VALUE_TYPE_ERROR = 501, ///< 属性类型错误

    PDV_RESULT_CAMERA_ERROR = 600, ///< 摄像机对象错误

    PDV_RESULT_ANNOTATION_ERROR = 700,          ///< 标注对象错误
    PDV_RESULT_ANNOTATIONITEM_TYPE_ERROR = 701, ///< 标注项类型错误

    PDV_RESULT_REVIEW_ERROR = 800,       ///< 审阅对象错误
    PDV_RESULT_REVIEW_TYPE_ERROR = 801,  ///< 审阅对象类型错误
    PDV_RESULT_VIEW_ERROR = 900,         ///< 视图对象错误
    PDV_RESULT_VIEW_BKGTYPE_ERROR = 901, ///< 视图对象背景类型错误

    PDV_RESULT_MATERIAL_ERROR = 1000,           ///< 材质对象错误
    PDV_RESULT_MATERIAL_TYPE_ERROR = 1001,      ///< 材质类型错误
    PDV_RESULT_MATERIAL_NO_COLOR = 1002,        ///< 材质对象无颜色数据
    PDV_RESULT_MATERIAL_NO_TRANSPARENCY = 1003, ///< 材质对象无透明度数据

    PDV_RESULT_ANIMATION_ERROR = 1100,          ///< 动画对象错误
    PDV_RESULT_ANIMATION_CLIPTYPE_ERROR = 1101, ///< 动画动作片段的类型错误
    PDV_RESULT_SCENEEVENT_ERROR = 1200,         ///< 场景事件对象错误
    PDV_RESULT_RESOURCE_ERROR = 1300,           ///< 资源文件对象错误

    PDV_RESULT_SECURITY_ERROR = 1400,                     ///< 安全控制对象错误
    PDV_RESULT_SECURITY_NO_ADMINISTRATOR_PASSWORD = 1401, ///< 安全控制不存在管理员密码数据
    PDV_RESULT_SECURITY_NO_USER_PASSWORD = 1402,          ///< 安全控制不存在用户密码数据
    PDV_RESULT_SECURITY_NO_PERMISSION = 1403,             ///< 安全控制不存在权限数据
    PDV_RESULT_SECURITY_NO_TIME_LIMIT = 1404,             ///< 安全控制不存在有效期数据

    PDV_RESULT_USERDATA_ERROR = 1500,     ///< 用户自定义对象错误
    PDV_RESULT_EXTERNALLINK_ERROR = 1600, ///< 外部链接对象错误
};

/** @brief 函数返回结果是否成功 */
#define PDV_SUCCEEDED(res) ((res) == PDV_RESULT_NO_ERROR)

/** @brief 文档对象类型 */
enum OBJTYPE_OLD
{
    OBJTYPE_UNKNOWN_OLD = 0,                    ///< 未知类型
    OBJTYPE_SCENE_OLD = 1,                      ///< 场景对象
    OBJTYPE_MODEL_TREE_OLD = 2,                 ///< 模型树对象
    OBJTYPE_MODEL_OLD = 3,                      ///< 模型对象
    OBJTYPE_MESH_OLD = 4,                       ///< 网格对象
    OBJTYPE_ATTRIBUTE_OLD = 5,                  ///< 属性对象
    OBJTYPE_ANNOTATION_OLD = 6,                 ///< 标注对象
    OBJTYPE_REVIEW_OLD = 7,                     ///< 审阅对象
    OBJTYPE_CAMERA_OLD = 8,                     ///< 摄像机对象
    OBJTYPE_VIEW_OLD = 9,                       ///< 视图对象
    OBJTYPE_MATERIAL_OLD = 10,                  ///< 材质对象
    OBJTYPE_ANIMATION_OLD = 11,                 ///< 动画对象
    OBJTYPE_SCENE_EVENT_OLD = 12,               ///< 场景事件对象
    OBJTYPE_RESOURCE_OLD = 13,                  ///< 资源文件对象
    OBJTYPE_SECURITY_OLD = 14,                  ///< 安全控制对象
    OBJTYPE_USER_DATA_OLD = 15,                 ///< 用户自定义对象
    OBJTYPE_EXTERNAL_LINK_OLD = 16,             ///< 外部链接对象
    OBJTYPE_MODEL_TREE_NODE_OLD = 21,           ///< 模型树节点
    OBJTYPE_LIGHT_OLD = 22,                     ///< 灯光对象
    OBJTYPE_TEXTURE_OLD = 23,                   ///< 纹理对象
    OBJTYPE_PRIMCOLLECTION_OLD = 41,            ///< 图元集合
    OBJTYPE_POINT_OLD = 42,                     ///< 点
    OBJTYPE_CURVE_OLD = 43,                     ///< 线
    OBJTYPE_SURFACE_OLD = 44,                   ///< 面
    OBJTYPE_TOPO_OLD = 45,                      ///< 拓扑
    OBJTYPE_BREP_OLD = 46,                      ///< 几何拓扑
    OBJTYPE_PRIMITY_OLD = 49,                   ///< 基本体
    OBJTYPE_ATTRIBUTE_GROUP_OLD = 51,           ///< 属性集
    OBJTYPE_ANNOTATION_ITEM_OLD = 61,           ///< 标注项
    OBJTYPE_ANNOTATION_VIEW_OLD = 62,           ///< 标注视图
    OBJTYPE_ANNOTATION_GEOMETRY_OLD = 63,       ///< 标注辅助几何
};

/** @brief 对象类型 */
enum OBJTYPE
{
    OBJTYPE_UNKNOWN = 0,               ///< 未知类型
    OBJTYPE_SCENE = 1,                 ///< 场景对象
    OBJTYPE_MODEL_TREE = 2,            ///< 模型树对象
    OBJTYPE_MODEL = 3,                 ///< 模型对象
    OBJTYPE_MESH = 4,                  ///< 网格对象
    OBJTYPE_PRIMITY = 5,               ///< 基本体
    OBJTYPE_BREP = 6,                  ///< 几何拓扑
    OBJTYPE_ATTRIBUTE = 7,             ///< 属性对象
    OBJTYPE_MATERIAL = 8,              ///< 材质对象
    OBJTYPE_TEXTURE = 9,               ///< 纹理对象
    OBJTYPE_CAMERA = 10,               ///< 摄像机对象
    OBJTYPE_LIGHT = 11,                ///< 灯光对象
    OBJTYPE_ANNOTATION = 12,           ///< 标注对象
    OBJTYPE_REVIEW = 13,               ///< 审阅对象
    OBJTYPE_VIEW = 14,                 ///< 视图对象
    OBJTYPE_ANIMATION = 15,            ///< 动画对象
    OBJTYPE_RESOURCE = 16,             ///< 资源文件对象
    OBJTYPE_SECURITY = 17,             ///< 安全控制对象
    OBJTYPE_EXTERNAL_LINK = 18,        ///< 外部链接对象
    OBJTYPE_USER_DATA = 19,            ///< 用户自定义对象
    OBJTYPE_MODEL_TREE_NODE = 20,      ///< 模型树节点
    OBJTYPE_PRIMCOLLECTION = 21,       ///< 图元集合
    OBJTYPE_POINT = 22,                ///< 点
    OBJTYPE_CURVE = 23,                ///< 线
    OBJTYPE_SURFACE = 24,              ///< 面
    OBJTYPE_TOPO = 25,                 ///< 拓扑
    OBJTYPE_ATTRIBUTE_GROUP = 26,      ///< 属性集
    OBJTYPE_ANNOTATION_ITEM = 27,      ///< 标注项
    OBJTYPE_ANNOTATION_VIEW = 28,      ///< 标注视图
    OBJTYPE_ANNOTATION_GEOMETRY = 29,  ///< 标注辅助几何
    OBJTYPE_ANIMATION_CLIP = 30,       ///< 动画片段
    OBJTYPE_TILE = 50,                 ///< 渲染瓦片
    OBJTYPE_RESULT_CONFIG = 51,        ///< 分析结果配置
    OBJTYPE_NODE_SUBSET_MATERIAL = 52, ///< 节点面材质
    OBJTYPE_RENDER_BODY = 53,          ///< 渲染主体
    OBJTYPE_RENDER_MESH = 54,          ///< 渲染网格
    OBJTYPE_BATCHED_MESH = 55,         ///< 批处理网格
    OBJTYPE_INSTANCED_MESH = 56,       ///< 实例化网格
    OBJTYPE_RENDER_GEOMETRY = 57,      ///< 渲染几何体
    OBJTYPE_RENDER_VERTEX = 58,        ///< 渲染几何体顶点结构
    OBJTYPE_RENDER_BODY_SUBSET = 59,   ///< 渲染主体子集
    OBJTYPE_ANALYSIS_RESULT = 60,      ///< 分析结果
    OBJTYPE_PHYSICAL_QUANTITY = 61,    ///< 物理量
    OBJTYPE_REFERENCE_GEOMETRY = 62,   ///< 辅助几何
};

/**
 * @brief 获取PDVCore的版本
 * @return CUnicodeString PDVCore的版本描述
 */
PDVCORE_API CUnicodeString GetPDVCoreVersion();

/**
 * @brief 获取类型的描述
 * @param[in] iType 类型标识
 * @return CUnicodeString 类型的描述
 */
inline CUnicodeString GetObjectTypeString(DftUInt iType)
{
    if (iType == OBJTYPE_SCENE)
        return "Scene";
    if (iType == OBJTYPE_MODEL_TREE)
        return "ModelTree";
    if (iType == OBJTYPE_MODEL)
        return "Model";
    if (iType == OBJTYPE_MESH)
        return "Mesh";
    if (iType == OBJTYPE_BREP)
        return "BRep";
    if (iType == OBJTYPE_ATTRIBUTE)
        return "Attribute";
    if (iType == OBJTYPE_ANNOTATION)
        return "PMI";
    if (iType == OBJTYPE_REVIEW)
        return "Review";
    if (iType == OBJTYPE_CAMERA)
        return "Camera";
    if (iType == OBJTYPE_VIEW)
        return "View";
    if (iType == OBJTYPE_PRIMITY)
        return "Primity";
    if (iType == OBJTYPE_MATERIAL)
        return "Material";
    if (iType == OBJTYPE_ANIMATION)
        return "Animation";
    if (iType == OBJTYPE_RESOURCE)
        return "Resource";
    if (iType == OBJTYPE_SECURITY)
        return "Security";
    if (iType == OBJTYPE_USER_DATA)
        return "UserData";
    if (iType == OBJTYPE_EXTERNAL_LINK)
        return "ExternalLink";
    if (iType == OBJTYPE_MODEL_TREE_NODE)
        return "ModelTreeNode";
    if (iType == OBJTYPE_PRIMCOLLECTION)
        return "PrimCollection";
    if (iType == OBJTYPE_POINT)
        return "Point";
    if (iType == OBJTYPE_CURVE)
        return "Curve";
    if (iType == OBJTYPE_SURFACE)
        return "Surface";
    if (iType == OBJTYPE_TOPO)
        return "Topo";
    if (iType == OBJTYPE_ATTRIBUTE_GROUP)
        return "AttributeGroup";
    if (iType == OBJTYPE_ANNOTATION_ITEM)
        return "AnnotationItem";
    if (iType == OBJTYPE_ANNOTATION_VIEW)
        return "AnnotationView";
    if (iType == OBJTYPE_ANNOTATION_GEOMETRY)
        return "AnnotationGeometry";
    if (iType == OBJTYPE_TEXTURE)
        return "Texture";
    if (iType == OBJTYPE_LIGHT)
        return "Light";
    if (iType == OBJTYPE_TILE)
        return "Tile";
    if (iType == OBJTYPE_RESULT_CONFIG)
        return "ResultConfig";
    if (iType == OBJTYPE_NODE_SUBSET_MATERIAL)
        return "NodeSubsetMaterial";
    if (iType == OBJTYPE_RENDER_BODY)
        return "RenderBody";
    if (iType == OBJTYPE_BATCHED_MESH)
        return "BatchedMesh";
    if (iType == OBJTYPE_INSTANCED_MESH)
        return "InstancedMesh";
    if (iType == OBJTYPE_RENDER_GEOMETRY)
        return "RenderGeometry";
    if (iType == OBJTYPE_RENDER_BODY_SUBSET)
        return "RenderBodySubset";
    if (iType == OBJTYPE_ANALYSIS_RESULT)
        return "AnalysisResult";
    if (iType == OBJTYPE_PHYSICAL_QUANTITY)
        return "PhysicalQuantity";
    if (iType == OBJTYPE_REFERENCE_GEOMETRY)
        return "ReferenceGeometry";
    return "";
}

/**
 * @brief 赋值数据，仅用于以指针为元素的vector
 * @param[in,out] ioTarget 目标数据
 * @param[in] iSource 源数据
 */
template <typename T> void ASSIGN(std::vector<T*>& oTarget, const std::vector<T*>& iSource)
{
    DftUInt i, count = (DftUInt)oTarget.size();
    for (i = 0; i < count; i++)
        SAFE_DELETE(oTarget[i]);

    count = (DftUInt)iSource.size();
    oTarget.resize(count);
    for (i = 0; i < count; i++)
        oTarget[i] = new T(*(iSource[i]));
}

/**
 * @brief 清空数据，仅用于以指针为元素的vector
 * @param[in,out] ioTarget 目标数据
 */
template <typename T> void CLEAR(std::vector<T*>& ioTarget)
{
    DftUInt i, count = (DftUInt)ioTarget.size();
    for (i = 0; i < count; i++)
        SAFE_DELETE(ioTarget[i]);
    ioTarget.clear();
}

/**
 * @brief 清空数据，仅用于以指针为元素的map
 * @param[in,out] ioTarget 目标数据
 */
template <typename K, typename T> void CLEAR(std::map<K, T*>& ioTarget)
{
    typename std::map<K, T *>::iterator iter;
    for (iter = ioTarget.begin(); iter != ioTarget.end();)
    {
        T *value = iter->second;
        iter = ioTarget.erase(iter);
        SAFE_DELETE(value);
    }
}

/** @brief 颜色数据 */
struct PDVCORE_API RGBColor
{
    DftUInt8 _red;   ///< 红色颜色分量, 取值范围[0, 255]
    DftUInt8 _green; ///< 绿色颜色分量, 取值范围[0, 255]
    DftUInt8 _blue;  ///< 蓝色颜色分量, 取值范围[0, 255]

    /** 默认构造函数 */
    RGBColor()
    {
        _red = 0;
        _green = 0;
        _blue = 0;
    }
    /** 参数化构造函数 */
    RGBColor(DftUInt8 iRed, DftUInt8 iGreen, DftUInt8 iBlue)
    {
        _red = iRed;
        _green = iGreen;
        _blue = iBlue;
    }
    /** 拷贝构造函数 */
    RGBColor(const RGBColor& iData)
    {
        _red = iData._red;
        _green = iData._green;
        _blue = iData._blue;
    }
    /** 赋值运算符 */
    RGBColor& operator=(const RGBColor& iData)
    {
        if (this == &iData)
            return *this;
        _red = iData._red;
        _green = iData._green;
        _blue = iData._blue;
        return *this;
    }
    /** 相等比较运算符 */
    DftBool operator==(const RGBColor& iData) const
    {
        if (_red != iData._red)
            return FALSE;
        if (_green != iData._green)
            return FALSE;
        if (_blue != iData._blue)
            return FALSE;
        return TRUE;
    }
    /** 不相等比较运算符 */
    DftBool operator!=(const RGBColor& iData) const
    {
        return (!((*this) == iData));
    }
};

/** @brief 立方体包围盒 */
struct PDVCORE_API BoundingBox
{
    PDVVector3F _min; ///< 最小点坐标
    PDVVector3F _max; ///< 最大点坐标

    /** 默认构造函数 */
    BoundingBox()
    {
        _min.SetZero();
        _max.SetZero();
    }
    /** 参数化构造函数 */
    BoundingBox(const PDVVector3F &iMin, const PDVVector3F &iMax)
    {
        _min = iMin;
        _max = iMax;
    }
    /** 拷贝构造函数 */
    BoundingBox(const BoundingBox& iData)
    {
        _min = iData._min;
        _max = iData._max;
    }
    /** 赋值运算符 */
    BoundingBox& operator=(const BoundingBox& iData)
    {
        if (this == &iData)
            return *this;
        _min = iData._min;
        _max = iData._max;
        return *this;
    }
    /** 相等比较运算符 */
    DftBool operator==(const BoundingBox& iData) const
    {
        if (!IsDftVector3FEqual(_min._data, iData._min._data))
            return FALSE;
        if (!IsDftVector3FEqual(_max._data, iData._max._data))
            return FALSE;
        return TRUE;
    }
    /** 不相等比较运算符 */
    DftBool operator!=(const BoundingBox& iData) const
    {
        return (!((*this) == iData));
    }
    /** 合并 */
    void Merge(const BoundingBox& iBox);
    /** 输出数据 */
    void Output(DftJson iJson) const;
};

/** @brief 平面 */
struct PDVCORE_API PlaneData
{
    PDVVector3F _vAxisX;  ///< X轴向量
    PDVVector3F _vAxisY;  ///< Y轴向量
    PDVVector3F _vAxisZ;  ///< Z轴向量
    PDVVector3F _vOrigin; ///< 原点

    /** 相等比较运算符 */
    DftBool operator==(const PlaneData &iData) const
    {
        if (!_vAxisX.IsEqual(iData._vAxisX))
            return FALSE;
        if (!_vAxisY.IsEqual(iData._vAxisY))
            return FALSE;
        if (!_vAxisZ.IsEqual(iData._vAxisZ))
            return FALSE;
        if (!_vOrigin.IsEqual(iData._vOrigin))
            return FALSE;
        return TRUE;
    }
    /** 不相等比较运算符 */
    DftBool operator!=(const PlaneData& iData) const
    {
        return !((*this) == iData);
    }
    /** 输出数据 */
    void Output(DftJson iJson) const;
};

/** @brief 点类型 */
enum PointStyle
{
    POINTSTYLE_NULL = 0,         ///< 未知
    POINTSTYLE_SOLID_POINT = 1,  ///< 实心点
    POINTSTYLE_HOLLOW_POINT = 2, ///< 空心点
    POINTSTYLE_CROSS_POINT = 3,  ///< 交叉点
    POINTSTYLE_TRIANGLE = 4,     ///< 三角形
};

/** @brief 线类型 */
enum LineStyle
{
    LINESTYLE_NULL = 0,                 ///< 未知
    LINESTYLE_THIN_SOLID_LINE = 1,      ///< 细实线
    LINESTYLE_THICK_SOLID_LINE = 2,     ///< 粗实线
    LINESTYLE_THIN_DASH_LINE = 3,       ///< 细虚线
    LINESTYLE_THICK_DASH_LINE = 4,      ///< 粗虚线
    LINESTYLE_THIN_DOT_DASH_LINE = 5,   ///< 细点画线
    LINESTYLE_THICK_DOT_DASH_LINE = 6,  ///< 粗点画线
    LINESTYLE_THIN_DOUBLE_DOT_LINE = 7, ///< 细双点画线
};

/** @brief 模型统计信息 */
struct PDVCORE_API Statistics
{
    DftUInt _faceMeshCount;         ///< 模型面网格数
    DftUInt _faceSubSetCount;       ///< 模型面子集数
    DftUInt _faceCount;             ///< 模型三角面数
    DftUInt _lineMeshCount;         ///< 模型线网格数
    DftUInt _lineSubSetCount;       ///< 模型线子集数
    DftUInt _lineCount;             ///< 模型线段数
    DftUInt _pointMeshCount;        ///< 模型点网格数
    DftUInt _pointSubSetCount;      ///< 模型点子集数
    DftUInt _pointCount;            ///< 模型点数

    /** 默认构造函数 */
    Statistics()
    {
        _faceMeshCount = 0;
        _faceSubSetCount = 0;
        _faceCount = 0;
        _lineMeshCount = 0;
        _lineSubSetCount = 0;
        _lineCount = 0;
        _pointMeshCount = 0;
        _pointSubSetCount = 0;
        _pointCount = 0;
    }
    /** 相等比较运算符 */
    DftBool operator==(const Statistics& iData) const
    {
        if (_faceMeshCount != iData._faceMeshCount)
            return FALSE;
        if (_faceSubSetCount != iData._faceSubSetCount)
            return FALSE;
        if (_faceCount != iData._faceCount)
            return FALSE;
        if (_lineMeshCount != iData._lineMeshCount)
            return FALSE;
        if (_lineSubSetCount != iData._lineSubSetCount)
            return FALSE;
        if (_lineCount != iData._lineCount)
            return FALSE;
        if (_pointMeshCount != iData._pointMeshCount)
            return FALSE;
        if (_pointSubSetCount != iData._pointSubSetCount)
            return FALSE;
        if (_pointCount != iData._pointCount)
            return FALSE;
        return TRUE;
    }
    /** 不相等比较运算符 */
    DftBool operator!=(const Statistics& iData) const
    {
        return (!((*this) == iData));
    }
    /** 增加统计数据 */
    void Add(const Statistics& iData);
    /** 输出数据 */
    void Output(DftJson iJson) const;
};

/** @brief 有向外包盒 */
struct PDVCORE_API OrientedBoundingBox
{
    PDVVector3F _center; ///< 中心点坐标
    PDVVector3F _axisX;  ///< X轴向量, 长度为X范围一半
    PDVVector3F _axisY;  ///< Y轴向量, 长度为Y范围一半
    PDVVector3F _axisZ;  ///< Z轴向量, 长度为Z范围一半

    /** 默认构造函数 */
    OrientedBoundingBox()
    {
        Clear();
    }
    /** 参数化构造函数 */
    OrientedBoundingBox(const OrientedBoundingBox& iData)
    {
        _center = iData._center;
        _axisX = iData._axisX;
        _axisY = iData._axisY;
        _axisZ = iData._axisZ;
    }
    /** 赋值运算符 */
    OrientedBoundingBox& operator=(const OrientedBoundingBox& iData)
    {
        if (&iData != this)
        {
            _center = iData._center;
            _axisX = iData._axisX;
            _axisY = iData._axisY;
            _axisZ = iData._axisZ;
        }
        return *this;
    }
    /** 从AABB包围盒构建 */
    void BuildFromBoundingBox(const BoundingBox& iBoundingBox);
    /** 转换至AABB包围盒 */
    void ConvertToBoundingBox(BoundingBox& oBoundingBox);
    /** 清除数据 */
    void Clear()
    {
        _center.SetZero();
        _axisX.SetZero();
        _axisY.SetZero();
        _axisZ.SetZero();
    }
    /** 是否有效 */
    DftBool IsValid() const;
    /** 输出数据 */
    void Output(DftJson iJson) const;
};

/** @brief 外包球 */
struct PDVCORE_API BoundingSphere
{
    PDVVector3F _center; ///< 球体中心
    DftFloat _radius;    ///< 半径

    /** 默认构造函数 */
    BoundingSphere()
    {
        _radius = 0.f;
    }
    /** 拷贝构造函数 */
    BoundingSphere(const BoundingSphere& iData)
    {
        _center = iData._center;
        _radius = iData._radius;
    }
    /** 赋值运算符 */
    BoundingSphere& operator=(const BoundingSphere& iData)
    {
        if (&iData != this)
        {
            _center = iData._center;
            _radius = iData._radius;
        }
        return *this;
    }
    /** 从AABB包围盒构建 */
    void BuildFromBoundingBox(const BoundingBox& iBoundingBox);
    /** 转换至AABB包围盒 */
    void ConvertToBoundingBox(BoundingBox& oBoundingBox);
    /** 是否有效 */
    DftBool IsValid() const;
    /** 清除数据 */
    void Clear();
    /** 输出数据 */
    void Output(DftJson iJson) const;
};

/** @brief 外包区域 */
struct PDVCORE_API BoundingVolume
{
    OrientedBoundingBox _box; ///< 外包盒
    BoundingSphere _sphere;   ///< 外包球

    /** 默认构造函数 */
    BoundingVolume()
    {
        Clear();
    }
    /** 拷贝构造函数 */
    BoundingVolume(const BoundingVolume& iData)
    {
        _box = iData._box;
        _sphere = iData._sphere;
    }
    /** 赋值运算符 */
    BoundingVolume& operator=(const BoundingVolume& iData)
    {
        if (&iData != this)
        {
            _box = iData._box;
            _sphere = iData._sphere;
        }
        return *this;
    }
    /** 从AABB包围盒构建 */
    void BuildFromBoundingBox(const BoundingBox& iBoundingBox);
    /** 转换至AABB包围盒 */
    void ConvertToBoundingBox(BoundingBox& oBoundingBox);
    /** 是否有效 */
    DftBool IsValid() const;
    /** 清除数据 */
    void Clear();
    /** 输出数据 */
    void Output(DftJson iJson) const;
};

} ///< namespace pdv

} ///< namespace kernel

#endif

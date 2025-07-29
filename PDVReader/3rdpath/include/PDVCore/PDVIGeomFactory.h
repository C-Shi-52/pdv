/**
 * @file PDVIGeomFactory.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2022-11-15
 * @brief 概述：PDV几何工厂接口，包含构建PDV几何数据接口的声明
 * @details 详细说明
 */

#ifndef PDVIGEOMFACTORY_H
#define PDVIGEOMFACTORY_H

#include "PDVBase.h"

namespace kernel
{

namespace pdv
{

class ICurveOnSurface;
class IGeomCurve2dData;
class IGeomCurveData;
class IGeomSurfaceData;
class IGeomPointData;
class ITopo;

/** @brief NURBS曲线标识位 */
enum NurbsCurveBitMask
{
    NURBSCURVE_MASK_WEIGHT = 0x0001,     ///< 是否包含权重数据
    NURBSCURVE_MASK_KNOT = 0x0002        ///< 是否包含节点矢量数据，如果不包含，那么认为曲线的节点是均匀分布的
};

/** @brief 二维NURBS曲线数据 */
struct PDVCORE_API NurbsCurve2dData
{
    DftUInt8 _bitMask;                    ///< 标识位
    DftUInt8 _periodic;                   ///< 是否为周期函数
    DftUInt8 _degree;                     ///< 曲线的度数
    std::vector<PDVVector2D> _ctrlPoints; ///< 曲线的控制点数据
    std::vector<DftDouble> _weights;      ///< 曲线的权重数据
    std::vector<DftDouble> _knots;        ///< 曲线的节点矢量数据
    /** 默认构造函数 */
    NurbsCurve2dData() { Clear(); }
    /** 拷贝构造函数 */
    NurbsCurve2dData(const NurbsCurve2dData& iData)
    {
        _bitMask = iData._bitMask;
        _periodic = iData._periodic;
        _degree = iData._degree;
        _ctrlPoints = iData._ctrlPoints;
        _weights = iData._weights;
        _knots = iData._knots;
    }
    /** 赋值运算符 */
    NurbsCurve2dData& operator=(const NurbsCurve2dData& iData)
    {
        if (&iData != this)
        {
            _knots = iData._knots;
            _bitMask = iData._bitMask;
            _degree = iData._degree;
            _ctrlPoints = iData._ctrlPoints;
            _weights = iData._weights;
            _periodic = iData._periodic;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _bitMask = 0;
        _periodic = FALSE;
        _degree = 0;
        _ctrlPoints.clear();
        _weights.clear();
        _knots.clear();
    }
    /** 输出数据 */
    void Output(DftJson iJsonNode) const;
};

/** @brief 二维NURBS曲线数据数组 */
typedef std::vector<NurbsCurve2dData> NurbsCurve2dDataArray;

/** @brief NURBS曲线数据 */
struct PDVCORE_API NurbsCurveData
{
    DftUInt8 _bitMask;                    ///< 标识位
    DftUInt8 _periodic;                   ///< 是否为周期函数
    DftUInt8 _degree;                     ///< 曲线的度数
    std::vector<PDVVector3D> _ctrlPoints; ///< 曲线的控制点数据
    std::vector<DftDouble> _weights;      ///< 曲线的权重数据
    std::vector<DftDouble> _knots;        ///< 曲线的节点矢量数据
    /** 默认构造函数 */
    NurbsCurveData() { Clear(); }
    /** 拷贝构造函数 */
    NurbsCurveData(const NurbsCurveData& iData)
    {
        _bitMask = iData._bitMask;
        _periodic = iData._periodic;
        _degree = iData._degree;
        _ctrlPoints = iData._ctrlPoints;
        _weights = iData._weights;
        _knots = iData._knots;
    }
    /** 赋值运算符 */
    NurbsCurveData& operator=(const NurbsCurveData& iData)
    {
        if (&iData != this)
        {
            _bitMask = iData._bitMask;
            _periodic = iData._periodic;
            _degree = iData._degree;
            _ctrlPoints = iData._ctrlPoints;
            _weights = iData._weights;
            _knots = iData._knots;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _bitMask = 0;
        _periodic = FALSE;
        _degree = 0;
        _ctrlPoints.clear();
        _weights.clear();
        _knots.clear();
    }
    /** 输出数据 */
    void Output(DftJson iJsonNode) const;
};

/** @brief NURBS曲线数据数组 */
typedef std::vector<NurbsCurveData> NurbsCurveDataArray;

/** @brief NURBS曲面数据 */
struct PDVCORE_API NurbsSurfaceData
{
    DftUInt8 _bitMask;                    ///< 标识位
    DftUInt8 _uPeriodic;                  ///< U方向是否为周期函数
    DftUInt8 _vPeriodic;                  ///< V方向是否为周期函数
    DftUInt8 _uDegree;                    ///< U方向曲面的度数
    DftUInt8 _vDegree;                    ///< V方向曲面的度数
    DftUInt64 _ctrlRowCount;              ///< 曲面的控制点行数
    DftUInt64 _ctrlColumnCount;           ///< 曲面的控制点列数
    std::vector<PDVVector3D> _ctrlPoints; ///< 曲面的控制点数据
    std::vector<DftDouble> _weights;      ///< 曲面的权重数据
    std::vector<DftDouble> _uKnots;       ///< U方向曲面的节点矢量数据
    std::vector<DftDouble> _vKnots;       ///< V方向曲面的节点矢量数据
    /** 默认构造函数 */
    NurbsSurfaceData() { Clear(); }
    /** 拷贝构造函数 */
    NurbsSurfaceData(const NurbsSurfaceData& iData)
    {
        _bitMask = iData._bitMask;
        _uPeriodic = iData._uPeriodic;
        _vPeriodic = iData._vPeriodic;
        _uDegree = iData._uDegree;
        _vDegree = iData._vDegree;
        _ctrlRowCount = iData._ctrlRowCount;
        _ctrlColumnCount = iData._ctrlColumnCount;
        _ctrlPoints = iData._ctrlPoints;
        _weights = iData._weights;
        _uKnots = iData._uKnots;
        _vKnots = iData._vKnots;
    }
    /** 赋值运算符 */
    NurbsSurfaceData& operator=(const NurbsSurfaceData& iData)
    {
        if (&iData != this)
        {
            _bitMask = iData._bitMask;
            _uPeriodic = iData._uPeriodic;
            _vPeriodic = iData._vPeriodic;
            _uDegree = iData._uDegree;
            _vDegree = iData._vDegree;
            _ctrlRowCount = iData._ctrlRowCount;
            _ctrlColumnCount = iData._ctrlColumnCount;
            _ctrlPoints = iData._ctrlPoints;
            _weights = iData._weights;
            _uKnots = iData._uKnots;
            _vKnots = iData._vKnots;
        }
        return *this;
    }
    /** 清除数据 */
    void Clear()
    {
        _bitMask = 0;
        _uPeriodic = FALSE;
        _vPeriodic = FALSE;
        _uDegree = 0;
        _vDegree = 0;
        _ctrlRowCount = 0;
        _ctrlColumnCount = 0;
        _ctrlPoints.clear();
        _weights.clear();
        _uKnots.clear();
        _vKnots.clear();
    }
    /** 输出数据 */
    void Output(DftJson iJsonNode) const;
};

/** @brief NURBS曲面数据数组 */
typedef std::vector<NurbsSurfaceData> NurbsSurfaceDataArray;

/** @brief PDV几何工厂接口 */
class PDVCORE_API IGeomFactory
{
public:
    /**
     * @brief 获取PDV几何工厂接口
     * @return IGeomFactory * PDV几何工厂接口
     * @note
     */
    static IGeomFactory* GetGeomFactory();

    /**
     * @brief 创建直线几何接口类
     * @return IGeomCurve2dData *
     * @param[in] iID 唯一标识
     * @param[in] iStartPoint 起点
     * @param[in] iEndPoint 终点
     * @note 尽量用另一个重载接口，这个不带参数变量，容易出问题
     */
    virtual IGeomCurve2dData* CreateLine2dData(DftUInt64 iID, const PDVVector2D& iStartPoint, const PDVVector2D& iEndPoint) = 0;

    /**
     * @brief 创建直线几何接口类
     * @return IGeomCurve2dData *
     * @param[in] iID 唯一标识
     * @param[in] iOrigin 起点
     * @param[in] iDirection 终点
     * @param[in] iStartPara 起始参数
     * @param[in] iEndPara 终止参数
     * @note
     */
    virtual IGeomCurve2dData* CreateLine2dData(DftUInt64 iID, const PDVVector2D& iOrigin, const PDVVector2D& iDirection, DftDouble iStartPara,
                                               DftDouble iEndPara) = 0;

    /**
     * @brief 创建圆几何接口类
     * @return IGeomCurve2dData *
     * @param[in] iID 唯一标识
     * @param[in] iOrigin 圆心坐标
     * @param[in] iXDir X轴方向
     * @param[in] iRadius 半径
     * @param[in] iStartAngle 起始角（单位为弧度）
     * @param[in] iEndAngle 终止角（单位为弧度）
     * @note
     */
    virtual IGeomCurve2dData* CreateCircle2dData(DftUInt64 iID, const PDVVector2D& iOrigin, const PDVVector2D& iXDir, DftDouble iRadius,
                                                 DftDouble iStartAngle, DftDouble iEndAngle) = 0;

    /**
     * @brief 创建椭圆几何接口类
     * @return IGeomCurve2dData *
     * @param[in] iID 唯一标识
     * @param[in] iOrigin 圆心坐标
     * @param[in] iXDir X轴方向
     * @param[in] iMajorRadius 大径
     * @param[in] iMinorRadius 小径
     * @param[in] iStartAngle 起始角（单位为弧度）
     * @param[in] iEndAngle 终止角（单位为弧度）
     * @note
     */
    virtual IGeomCurve2dData* CreateEllipse2dData(DftUInt64 iID, const PDVVector2D& iOrigin, const PDVVector2D& iXDir, DftDouble iMajorRadius,
                                                  DftDouble iMinorRadius, DftDouble iStartAngle, DftDouble iEndAngle) = 0;

    /**
     * @brief 创建NURBS曲线几何接口类
     * @return IGeomCurve2dData *
     * @param[in] iID 唯一标识
     * @param[in] iNurbsCurve NURBS曲线数据
     * @param[in] iStartParam 起始参数
     * @param[in] iEndParam 终止参数
     * @note
     */
    virtual IGeomCurve2dData* CreateNurbsCurve2dData(DftUInt64 iID, const NurbsCurve2dData& iNurbsCurve, DftDouble iStartParam,
                                                     DftDouble iEndParam) = 0;

    /**
     * @brief 创建空的几何接口类
     * @return IGeomCurveData *
     * @param[in] iID 唯一标识
     * @note
     */
    virtual IGeomCurveData* CreateNoCurveData(DftUInt64 iID) = 0;

    /**
     * @brief 创建直线几何接口类
     * @return IGeomCurveData *
     * @param[in] iID 唯一标识
     * @param[in] iStartPoint 起点
     * @param[in] iEndPoint 终点
     * @note 尽量用另一个重载接口，这个不带参数变量，容易出问题
     */
    virtual IGeomCurveData* CreateLineData(DftUInt64 iID, const PDVVector3D& iStartPoint, const PDVVector3D& iEndPoint) = 0;

    /**
     * @brief 创建直线几何接口类
     * @return IGeomCurveData *
     * @param[in] iID 唯一标识
     * @param[in] iOrigin 起点
     * @param[in] iDirection 终点
     * @param[in] iStartPara 起始参数
     * @param[in] iEndPara 终止参数
     * @note
     */
    virtual IGeomCurveData* CreateLineData(DftUInt64 iID, const PDVVector3D& iOrigin, const PDVVector3D& iDirection, DftDouble iStartPara,
                                           DftDouble iEndPara) = 0;

    /**
     * @brief 创建圆几何接口类
     * @return IGeomCurveData *
     * @param[in] iID 唯一标识
     * @param[in] iOrigin 圆心坐标
     * @param[in] iXDir X轴方向
     * @param[in] iYDir Y轴方向
     * @param[in] iRadius 半径
     * @param[in] iStartAngle 起始角（单位为弧度）
     * @param[in] iEndAngle 终止角（单位为弧度）
     * @note
     */
    virtual IGeomCurveData* CreateCircleData(DftUInt64 iID, const PDVVector3D& iOrigin, const PDVVector3D& iXDir, const PDVVector3D& iYDir,
                                             DftDouble iRadius, DftDouble iStartAngle, DftDouble iEndAngle) = 0;

    /**
     * @brief 创建椭圆几何接口类
     * @return IGeomCurveData *
     * @param[in] iID 唯一标识
     * @param[in] iOrigin 圆心坐标
     * @param[in] iXDir X轴方向
     * @param[in] iYDir Y轴方向
     * @param[in] iMajorRadius 大径
     * @param[in] iMinorRadius 小径
     * @param[in] iStartAngle 起始角（单位为弧度）
     * @param[in] iEndAngle 终止角（单位为弧度）
     * @note
     */
    virtual IGeomCurveData* CreateEllipseData(DftUInt64 iID, const PDVVector3D& iOrigin, const PDVVector3D& iXDir, const PDVVector3D& iYDir,
                                              DftDouble iMajorRadius, DftDouble iMinorRadius, DftDouble iStartAngle, DftDouble iEndAngle) = 0;

    /**
     * @brief 创建NURBS曲线接口类
     * @return IGeomCurveData *
     * @param[in] iID 唯一标识
     * @param[in] iNurbsCurve NURBS曲线数据
     * @note
     */
    virtual IGeomCurveData* CreateNurbsCurveData(DftUInt64 iID, const NurbsCurveData& iNurbsCurve, DftDouble iStartParam, DftDouble iEndParam) = 0;

    /**
     * @brief 创建平面几何接口类
     * @return IGeomSurfaceData *
     * @param[in] iID 唯一标识
     * @param[in] iOrigin 原点坐标
     * @param[in] iXDir X轴方向
     * @param[in] iYDir Y轴方向
     * @param[in] iDomainMin 参数域的最小值
     * @param[in] iDomainMax 参数域的最大值
     * @note
     */
    virtual IGeomSurfaceData* CreatePlaneData(DftUInt64 iID, const PDVVector3D& iOrigin, const PDVVector3D& iXDir, const PDVVector3D& iYDir,
                                              const PDVVector2D& iDomainMin, const PDVVector2D& iDomainMax) = 0;

    /**
     * @brief 创建圆柱面几何接口类
     * @return IGeomSurfaceData *
     * @param[in] iID 唯一标识
     * @param[in] iOrigin 原点坐标
     * @param[in] iXDir X轴方向
     * @param[in] iYDir Y轴方向
     * @param[in] iRadius 半径
     * @param[in] iDomainMin 参数域的最小值
     * @param[in] iDomainMax 参数域的最大值
     * @note
     */
    virtual IGeomSurfaceData* CreateCylinderData(DftUInt64 iID, const PDVVector3D& iOrigin, const PDVVector3D& iXDir, const PDVVector3D& iYDir,
                                                 DftDouble iRadius, const PDVVector2D& iDomainMin, const PDVVector2D& iDomainMax) = 0;

    /**
     * @brief 创建圆锥面几何接口类
     * @return IGeomSurfaceData *
     * @param[in] iID 唯一标识
     * @param[in] iOrigin 原点坐标
     * @param[in] iXDir X轴方向
     * @param[in] iYDir Y轴方向
     * @param[in] iHalfAngle 锥角（圆锥z轴和母线之间的夹角）
     * @param[in] iRadius 圆锥半径
     * @param[in] iDomainMin 参数域的最小值
     * @param[in] iDomainMax 参数域的最大值
     * @note
     */
    virtual IGeomSurfaceData* CreateConeData(DftUInt64 iID, const PDVVector3D& iOrigin, const PDVVector3D& iXDir, const PDVVector3D& iYDir,
                                             DftDouble iHalfAngle, DftDouble iRadius, const PDVVector2D& iDomainMin,
                                             const PDVVector2D& iDomainMax) = 0;

    /**
     * @brief 创建圆环面几何接口类
     * @return IGeomSurfaceData *
     * @param[in] iID 唯一标识
     * @param[in] iOrigin 原点坐标
     * @param[in] iXDir X轴方向
     * @param[in] iYDir Y轴方向
     * @param[in] iMajorRadius 主半径
     * @param[in] iMinorRadius 副半径
     * @param[in] iDomainMin 参数域的最小值
     * @param[in] iDomainMax 参数域的最大值
     * @note
     */
    virtual IGeomSurfaceData* CreateTorusData(DftUInt64 iID, const PDVVector3D& iOrigin, const PDVVector3D& iXDir, const PDVVector3D& iYDir,
                                              DftDouble iMajorRadius, DftDouble iMinorRadius, const PDVVector2D& iDomainMin,
                                              const PDVVector2D& iDomainMax) = 0;

    /**
     * @brief 创建球面几何接口类
     * @return IGeomSurfaceData *
     * @param[in] iID 唯一标识
     * @param[in] iOrigin 原点坐标
     * @param[in] iXDir X轴方向
     * @param[in] iYDir Y轴方向
     * @param[in] iRadius 球半径
     * @param[in] iDomainMin 参数域的最小值
     * @param[in] iDomainMax 参数域的最大值
     * @note
     */
    virtual IGeomSurfaceData* CreateSphereData(DftUInt64 iID, const PDVVector3D& iOrigin, const PDVVector3D& iXDir, const PDVVector3D& iYDir,
                                               DftDouble iRadius, const PDVVector2D& iDomainMin, const PDVVector2D& iDomainMax) = 0;

    /**
     * @brief 创建NURBS曲面几何接口类
     * @return IGeomSurfaceData *
     * @param[in] iID 唯一标识
     * @param[in] iNurbsSurface NURBS曲面几何数据
     * @param[in] iDomainMin 参数域的最小值
     * @param[in] iDomainMax 参数域的最大值
     * @note
     */
    virtual IGeomSurfaceData* CreateNurbsSurfaceData(DftUInt64 iID, const NurbsSurfaceData& iNurbsSurface, const PDVVector2D& iDomainMin,
                                                     const PDVVector2D& iDomainMax) = 0;

    /**
     * @brief 创建点数据
     * @return IGeomPointData *
     * @param[in] iID 唯一标识
     * @param[in] iPosition 点的位置信息
     * @note
     */
    virtual IGeomPointData* CreatePointData(DftUInt64 iID, const PDVVector3D& iPosition) = 0;

    /**
     * @brief 创建曲面上的曲线数据
     * @return ICurveOnSurface *
     * @param[in] iSrfId 曲面的唯一标识
     * @param[in] iPCrv 参数曲线
     * @note
     */
    virtual ICurveOnSurface* CreateCurveOnSurface(DftUInt64 iSrfId, const IGeomCurve2dData* iPCrv) = 0;

    /**
     * @brief 添加曲面上的曲线数据
     * @return DftBool
     * @param[in] iCrvData 几何曲线对象
     * @param[in] iCOS 曲面上的曲线数据
     * @note
     */
    virtual DftBool AddCurveOnSurfaceData(IGeomCurveData* iCrvData, const ICurveOnSurface* iCOS) = 0;

    /**
     * @brief 创建拓扑数据
     * @return ITopo *
     * @param[in] iID 唯一标识
     * @param[in] iType 拓扑数据的类型
     * @note
     */
    virtual ITopo* CreateTopoData(DftUInt64 iID, DftUInt8 iType) = 0;
};

} // namespace pdv

} // namespace kernel

#endif

#ifndef DFTMATH_H
#define DFTMATH_H

/**
 * @file DftMath.h
 * @author Steven.Liu
 * @version 1.0
 * @date 2025-01-18
 * @brief 概述：数学函数库
 * @details 详细说明
 */

#include "DftBase.h"

#ifdef _MSC_VER
#if (_MSC_VER >= 1900)
/**
 * @brief 判断单精度浮点数是否无效
 * @return DftBool TRUE表示该数无效，FALSE表示该数有效
 * @param[in] iValue 单精度浮点数
 * @note
 */
DFT_PUBLIC(DftBool) IsDftFloatNan(const DftFloat iValue);

/**
 * @brief 判断双精度浮点数是否无效
 * @return DftBool TRUE表示该数无效，FALSE表示该数有效
 * @param[in] iValue 双精度浮点数
 * @note
 */
DFT_PUBLIC(DftBool) IsDftDoubleNan(const DftDouble iValue);
#endif
#else
/**
 * @brief 判断单精度浮点数是否无效
 * @return DftBool TRUE表示该数无效，FALSE表示该数有效
 * @param[in] iValue 单精度浮点数
 * @note
 */
DFT_PUBLIC(DftBool) IsDftFloatNan(const DftFloat iValue);

/**
 * @brief 判断双精度浮点数是否无效
 * @return DftBool TRUE表示该数无效，FALSE表示该数有效
 * @param[in] iValue 双精度浮点数
 * @note
 */
DFT_PUBLIC(DftBool) IsDftDoubleNan(const DftDouble iValue);
#endif

/**
 * @brief 判断单精度浮点数是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 单精度浮点数
 * @note
 */
DFT_PUBLIC(DftBool) IsDftFloatZero(const DftFloat iValue);

/**
 * @brief 判断双精度浮点数是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 双精度浮点数
 * @note
 */
DFT_PUBLIC(DftBool) IsDftDoubleZero(const DftDouble iValue);

/**
 * @brief 判断单精度浮点型二维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 单精度浮点型二维向量
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2FZero(const DftVector2F iValue);

/**
 * @brief 判断单精度浮点型三维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 单精度浮点型三维向量
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3FZero(const DftVector3F iValue);

/**
 * @brief 判断单精度浮点型四维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 单精度浮点型四维向量
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4FZero(const DftVector4F iValue);

/**
 * @brief 判断双精度浮点型二维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 双精度浮点型二维向量
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2DZero(const DftVector2D iValue);

/**
 * @brief 判断双精度浮点型三维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 双精度浮点型三维向量
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3DZero(const DftVector3D iValue);

/**
 * @brief 判断双精度浮点型四维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 双精度浮点型四维向量
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4DZero(const DftVector4D iValue);

/**
 * @brief 判断单精度浮点数是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 单精度浮点数
 * @param[in] iZero 单精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftFloatZeroEx(const DftFloat iValue, DftFloat iZero);

/**
 * @brief 判断双精度浮点数是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 双精度浮点数
 * @param[in] iZero 双精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftDoubleZeroEx(const DftDouble iValue, DftDouble iZero);

/**
 * @brief 判断单精度浮点型二维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 单精度浮点型二维向量
 * @param[in] iZero 单精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2FZeroEx(const DftVector2F iValue, DftFloat iZero);

/**
 * @brief 判断单精度浮点型三维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 单精度浮点型三维向量
 * @param[in] iZero 单精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3FZeroEx(const DftVector3F iValue, DftFloat iZero);

/**
 * @brief 判断单精度浮点型四维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 单精度浮点型四维向量
 * @param[in] iZero 单精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4FZeroEx(const DftVector4F iValue, DftFloat iZero);

/**
 * @brief 判断双精度浮点型二维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 双精度浮点型二维向量
 * @param[in] iZero 双精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2DZeroEx(const DftVector2D iValue, DftDouble iZero);

/**
 * @brief 判断双精度浮点型三维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 双精度浮点型三维向量
 * @param[in] iZero 双精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3DZeroEx(const DftVector3D iValue, DftDouble iZero);

/**
 * @brief 判断双精度浮点型四维向量是否为0
 * @return DftBool TRUE或FALSE
 * @param[in] iValue 双精度浮点型四维向量
 * @param[in] iZero 双精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4DZeroEx(const DftVector4D iValue, DftDouble iZero);

/**
 * @brief 判断单精度浮点数是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点数1
 * @param[in] iValue2 单精度浮点数2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftFloatEqual(const DftFloat iValue1, const DftFloat iValue2);

/**
 * @brief 判断双精度浮点数是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点数1
 * @param[in] iValue2 双精度浮点数2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftDoubleEqual(const DftDouble iValue1, const DftDouble iValue2);

/**
 * @brief 判断单精度浮点型二维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型二维向量1
 * @param[in] iValue2 单精度浮点型二维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2FEqual(const DftVector2F iValue1, const DftVector2F iValue2);

/**
 * @brief 判断单精度浮点型三维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型三维向量1
 * @param[in] iValue2 单精度浮点型三维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3FEqual(const DftVector3F iValue1, const DftVector3F iValue2);

/**
 * @brief 判断单精度浮点型四维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型四维向量1
 * @param[in] iValue2 单精度浮点型四维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4FEqual(const DftVector4F iValue1, const DftVector4F iValue2);

/**
 * @brief 判断双精度浮点型二维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型二维向量1
 * @param[in] iValue2 双精度浮点型二维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2DEqual(const DftVector2D iValue1, const DftVector2D iValue2);

/**
 * @brief 判断双精度浮点型三维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型三维向量1
 * @param[in] iValue2 双精度浮点型三维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3DEqual(const DftVector3D iValue1, const DftVector3D iValue2);

/**
 * @brief 判断单精度浮点型四维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型四维向量1
 * @param[in] iValue2 双精度浮点型四维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4DEqual(const DftVector4D iValue1, const DftVector4D iValue2);

/**
 * @brief 判断单精度浮点数是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点数1
 * @param[in] iValue2 单精度浮点数2
 * @param[in] iZero 单精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftFloatEqualEx(const DftFloat iValue1, const DftFloat iValue2, DftFloat iZero);

/**
 * @brief 判断双精度浮点数是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点数1
 * @param[in] iValue2 双精度浮点数2
 * @param[in] iZero 双精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftDoubleEqualEx(const DftDouble iValue1, const DftDouble iValue2, DftDouble iZero);

/**
 * @brief 判断单精度浮点型二维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型二维向量1
 * @param[in] iValue2 单精度浮点型二维向量2
 * @param[in] iZero 单精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2FEqualEx(const DftVector2F iValue1, const DftVector2F iValue2, DftFloat iZero);

/**
 * @brief 判断单精度浮点型三维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型三维向量1
 * @param[in] iValue2 单精度浮点型三维向量2
 * @param[in] iZero 单精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3FEqualEx(const DftVector3F iValue1, const DftVector3F iValue2, DftFloat iZero);

/**
 * @brief 判断单精度浮点型四维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型四维向量1
 * @param[in] iValue2 单精度浮点型四维向量2
 * @param[in] iZero 单精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4FEqualEx(const DftVector4F iValue1, const DftVector4F iValue2, DftFloat iZero);

/**
 * @brief 判断双精度浮点型二维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型二维向量1
 * @param[in] iValue2 双精度浮点型二维向量2
 * @param[in] iZero 双精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2DEqualEx(const DftVector2D iValue1, const DftVector2D iValue2, DftDouble iZero);

/**
 * @brief 判断双精度浮点型三维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型三维向量1
 * @param[in] iValue2 双精度浮点型三维向量2
 * @param[in] iZero 双精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3DEqualEx(const DftVector3D iValue1, const DftVector3D iValue2, DftDouble iZero);

/**
 * @brief 判断单精度浮点型四维向量是否相等
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型四维向量1
 * @param[in] iValue2 双精度浮点型四维向量2
 * @param[in] iZero 双精度浮点数零值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4DEqualEx(const DftVector4D iValue1, const DftVector4D iValue2, DftDouble iZero);

/**
 * @brief 判断单精度浮点数是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点数1
 * @param[in] iValue2 单精度浮点数2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftFloatNear(const DftFloat iValue1, const DftFloat iValue2);

/**
 * @brief 判断双精度浮点数是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点数1
 * @param[in] iValue2 双精度浮点数2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftDoubleNear(const DftDouble iValue1, const DftDouble iValue2);

/**
 * @brief 判断单精度浮点型二维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型二维向量1
 * @param[in] iValue2 单精度浮点型二维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2FNear(const DftVector2F iValue1, const DftVector2F iValue2);

/**
 * @brief 判断单精度浮点型三维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型三维向量1
 * @param[in] iValue2 单精度浮点型三维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3FNear(const DftVector3F iValue1, const DftVector3F iValue2);

/**
 * @brief 判断单精度浮点型四维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型四维向量1
 * @param[in] iValue2 单精度浮点型四维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4FNear(const DftVector4F iValue1, const DftVector4F iValue2);

/**
 * @brief 判断双精度浮点型二维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型二维向量1
 * @param[in] iValue2 双精度浮点型二维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2DNear(const DftVector2D iValue1, const DftVector2D iValue2);

/**
 * @brief 判断双精度浮点型三维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型三维向量1
 * @param[in] iValue2 双精度浮点型三维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3DNear(const DftVector3D iValue1, const DftVector3D iValue2);

/**
 * @brief 判断单精度浮点型四维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型四维向量1
 * @param[in] iValue2 双精度浮点型四维向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4DNear(const DftVector4D iValue1, const DftVector4D iValue2);

/**
 * @brief 判断单精度浮点数是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点数1
 * @param[in] iValue2 单精度浮点数2
 * @param[in] iEpsilon 单精度浮点数极小值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftFloatNearEx(const DftFloat iValue1, const DftFloat iValue2, DftFloat iEpsilon);

/**
 * @brief 判断双精度浮点数是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点数1
 * @param[in] iValue2 双精度浮点数2
 * @param[in] iEpsilon 双精度浮点数极小值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftDoubleNearEx(const DftDouble iValue1, const DftDouble iValue2, DftDouble iEpsilon);

/**
 * @brief 判断单精度浮点型二维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型二维向量1
 * @param[in] iValue2 单精度浮点型二维向量2
 * @param[in] iEpsilon 单精度浮点数极小值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2FNearEx(const DftVector2F iValue1, const DftVector2F iValue2, DftFloat iEpsilon);

/**
 * @brief 判断单精度浮点型三维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型三维向量1
 * @param[in] iValue2 单精度浮点型三维向量2
 * @param[in] iEpsilon 单精度浮点数极小值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3FNearEx(const DftVector3F iValue1, const DftVector3F iValue2, DftFloat iEpsilon);

/**
 * @brief 判断单精度浮点型四维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 单精度浮点型四维向量1
 * @param[in] iValue2 单精度浮点型四维向量2
 * @param[in] iEpsilon 单精度浮点数极小值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4FNearEx(const DftVector4F iValue1, const DftVector4F iValue2, DftFloat iEpsilon);

/**
 * @brief 判断双精度浮点型二维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型二维向量1
 * @param[in] iValue2 双精度浮点型二维向量2
 * @param[in] iEpsilon 双精度浮点数极小值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector2DNearEx(const DftVector2D iValue1, const DftVector2D iValue2, DftDouble iEpsilon);

/**
 * @brief 判断双精度浮点型三维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型三维向量1
 * @param[in] iValue2 双精度浮点型三维向量2
 * @param[in] iEpsilon 双精度浮点数极小值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3DNearEx(const DftVector3D iValue1, const DftVector3D iValue2, DftDouble iEpsilon);

/**
 * @brief 判断单精度浮点型四维向量是否相近
 * @return DftBool TRUE或FALSE
 * @param[in] iValue1 双精度浮点型四维向量1
 * @param[in] iValue2 双精度浮点型四维向量2
 * @param[in] iEpsilon 双精度浮点数极小值
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector4DNearEx(const DftVector4D iValue1, const DftVector4D iValue2, DftDouble iEpsilon);

/**
 * @brief 二维向量相加
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector2FAdd(const DftVector2F iVec1, const DftVector2F iVec2, DftVector2F oResult);

/**
 * @brief 二维向量相减
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector2FSub(const DftVector2F iVec1, const DftVector2F iVec2, DftVector2F oResult);

/**
 * @brief 二维向量缩放
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec 向量
 * @param[in] iScale 缩放系数
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector2FScale(const DftVector2F iVec, const DftFloat iScale, DftVector2F oResult);

/**
 * @brief 二维向量点积
 * @return DftFloat 结果
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @note
 */
DFT_PUBLIC(DftFloat) DftVector2FDot(const DftVector2F iVec1, const DftVector2F iVec2);

/**
 * @brief 二维向量模长
 * @return DftFloat 结果
 * @param[in] iVec 向量
 * @note
 */
DFT_PUBLIC(DftFloat) DftVector2FLength(const DftVector2F iVec);

/**
 * @brief 二维向量单位化
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in,out] ioVec 向量
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector2FNormalize(DftVector2F ioVec);

/**
 * @brief 二维点的距离
 * @return DftFloat 二维点的距离
 * @param[in] iPoint1 点1
 * @param[in] iPoint2 点2
 * @note
 */
DFT_PUBLIC(DftFloat) DftPoint2FDistance(const DftPoint2F iPoint1, const DftPoint2F iPoint2);

/**
 * @brief 二维点的距离的平方
 * @return DftFloat 二维点的距离的平方
 * @param[in] iPoint1 点1
 * @param[in] iPoint2 点2
 * @note
 */
DFT_PUBLIC(DftFloat) DftPoint2FSquareDistance(const DftPoint2F iPoint1, const DftPoint2F iPoint2);

/**
 * @brief 将二维点投影到直线上
 * @return DftFloat 二维点的距离的平方
 * @param[in] iLinePt 直线上一点
 * @param[in] iLineDir 直线方向
 * @param[in] iSrcPt 输入点
 * @param[out] oPrjPt 投影点
 * @note
 */
DFT_PUBLIC(DftStatus) DftProjectPoint2FToLine(const DftPoint2F iLinePt, const DftVector2F iLineDir, const DftPoint2F iSrcPt, DftPoint2F oPrjPt);

/**
 * @brief 获取二维点集的包围盒
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iPointArr 二维点集的首地址
 * @param[in] iPointCount 二维点个数
 * @param[out] oBoxMin 包围盒最小点
 * @param[out] oBoxMax 包围盒最大点
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetPoint2FBoundingBox(const DftFloat* iPointArr, DftInt iPointCount, DftPoint2F oBoxMin, DftPoint2F oBoxMax);

/**
 * @brief 三维向量相加
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector3FAdd(const DftVector3F iVec1, const DftVector3F iVec2, DftVector3F oResult);

/**
 * @brief 三维向量相减
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector3FSub(const DftVector3F iVec1, const DftVector3F iVec2, DftVector3F oResult);

/**
 * @brief 三维向量缩放
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec 向量
 * @param[in] iScale 缩放系数
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector3FScale(const DftVector3F iVec, const DftFloat iScale, DftVector3F oResult);

/**
 * @brief 三维向量点积
 * @return DftFloat 结果
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @note
 */
DFT_PUBLIC(DftFloat) DftVector3FDot(const DftVector3F iVec1, const DftVector3F iVec2);

/**
 * @brief 三维向量叉积
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector3FCross(const DftVector3F iVec1, const DftVector3F iVec2, DftVector3F oResult);

/**
 * @brief 三维向量模长
 * @return DftFloat 结果
 * @param[in] iVec 向量
 * @note
 */
DFT_PUBLIC(DftFloat) DftVector3FLength(const DftVector3F iVec);

/**
 * @brief 三维向量单位化
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in,out] ioVec 向量
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector3FNormalize(DftVector3F ioVec);

/**
 * @brief 三维点的距离
 * @return DftFloat 三维点的距离
 * @param[in] iPoint1 点1
 * @param[in] iPoint2 点2
 * @note
 */
DFT_PUBLIC(DftFloat) DftPoint3FDistance(const DftPoint3F iPoint1, const DftPoint3F iPoint2);

/**
 * @brief 三维点的距离的平方
 * @return DftFloat 三维点的距离的平方
 * @param[in] iPoint1 点1
 * @param[in] iPoint2 点2
 * @note
 */
DFT_PUBLIC(DftFloat) DftPoint3FSquareDistance(const DftPoint3F iPoint1, const DftPoint3F iPoint2);

/**
 * @brief 计算两直线的交点
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 直线无交点
 * @param[in] iPt1 直线1上点
 * @param[in] iDir1 直线1方向
 * @param[in] iPt2 直线2上点
 * @param[in] iDir2 直线2方向
 * @param[out] oIntersectPt 交点
 * @param[out] oIsCollinear 是否重合
 * @note
 */
DFT_PUBLIC(DftStatus)
DftVector3FCalcIntersectOfTwoLine(const DftPoint3F iPt1, const DftVector3F iDir1, const DftPoint3F iPt2, const DftVector3F iDir2,
                                  DftPoint3F oIntersectPt, DftBool* oIsCollinear);

/**
 * @brief 两向量是否同向
 * @return DftBool TRUE或FALSE
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3FSameDir(const DftVector3F iVec1, const DftVector3F iVec2);

/**
 * @brief 两向量是否反向
 * @return DftBool TRUE或FALSE
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3FReverseDir(const DftVector3F iVec1, const DftVector3F iVec2);

/**
 * @brief 点是否在直线上
 * @return DftBool TRUE或FALSE
 * @param[in] iLinePt 直线上一点
 * @param[in] iLineDir 直线方向
 * @param[in] iPoint 点
 * @note
 */
DFT_PUBLIC(DftBool) IsDftPoint3FOnLine(const DftPoint3F iLinePt, const DftVector3F iLineDir, const DftPoint3F iPoint);

/**
 * @brief 点是否在平面上
 * @return DftBool TRUE或FALSE
 * @param[in] iPlanePt 平面上一点
 * @param[in] iPlaneDir 平面法向
 * @param[in] iPoint 点
 * @note
 */
DFT_PUBLIC(DftBool) IsDftPoint3FOnPlane(const DftPoint3F iPlanePt, const DftVector3F iPlaneDir, const DftPoint3F iPoint);

/**
 * @brief 将一个点投影到一条直线上
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 直线无交点
 * @param[in] iLinePt 直线上一点
 * @param[in] iLineDir 直线方向
 * @param[in] iSrcPt 输入点
 * @param[out] oPrjPt 投影点
 * @note
 */
DFT_PUBLIC(DftStatus) DftProjectPoint3FToLine(const DftPoint3F iLinePt, const DftVector3F iLineDir, const DftPoint3F iSrcPt, DftPoint3F oPrjPt);

/**
 * @brief 将一个点投影到一条直线上
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 直线无交点
 * @param[in] iPlanePt 平面上一点
 * @param[in] iPlaneDir 平面法向
 * @param[in] iSrcPt 输入点
 * @param[out] oPrjPt 投影点
 * @note
 */
DFT_PUBLIC(DftStatus) DftProjectPoint3FToPlane(const DftPoint3F iPlanePt, const DftVector3F iPlaneDir, const DftPoint3F iSrcPt, DftPoint3F oPrjPtx);

/**
 * @brief 获取三维点集的包围盒
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iPointArr 三维点集的首地址
 * @param[in] iPointCount 三维点个数
 * @param[out] oBoxMin 包围盒最小点
 * @param[out] oBoxMax 包围盒最大点
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetPoint3FBoundingBox(const DftFloat* iPointArr, DftInt iPointCount, DftPoint3F oBoxMin, DftPoint3F oBoxMax);

/**
 * @brief 获取包围盒的八个角点
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iBoxMin 包围盒最小点
 * @param[in] iBoxMax 包围盒最大点
 * @param[out] oCornerPoints 包围盒八个角点
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetBoundingBoxCornerFPoints(const DftPoint3F iBoxMin, const DftPoint3F iBoxMax, DftPoint3F oCornerPoints[8]);

/**
 * @brief 三维点的矩阵变换
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iPointIn 输入点
 * @param[in] iTrans 矩阵
 * @param[out] oPointOut 输出点
 * @note
 */
DFT_PUBLIC(DftStatus) DftTransformPoint3F(const DftPoint3F iPointIn, const DftMatrix4F iTrans, DftPoint3F oPointOut);

/**
 * @brief 三维向量的矩阵变换
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVectorIn 输入向量
 * @param[in] iTrans 矩阵
 * @param[out] oVectorOut 输出向量
 * @note
 */
DFT_PUBLIC(DftStatus) DftTransformVector3F(const DftVector3F iVectorIn, const DftMatrix4F iTrans, DftVector3F oVectorOut);

/**
 * @brief 获取坐标系的变换矩阵
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iOrigin 原点
 * @param[in] iAxisX X轴
 * @param[in] iAxisY Y轴
 * @param[in] iAxisZ Z轴
 * @param[out] oTrans 变换矩阵
 * @note
 */
DFT_PUBLIC(DftStatus)
DftCoordsTransformMatrix4F(const DftPoint3F iOrigin, const DftVector3F iAxisX, const DftVector3F iAxisY, const DftVector3F iAxisZ,
                           DftMatrix4F oTrans);

/**
 * @brief 输出四维单位矩阵
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[out] oMatrix 四维单位矩阵
 * @note
 */
DFT_PUBLIC(DftStatus) DftMatrix4FIdentity(DftMatrix4F oMatrix);

/**
 * @brief 求四维矩阵的逆矩阵
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iMatrix 四维矩阵
 * @param[out] oMatrixInverse 逆矩阵
 * @note
 */
DFT_PUBLIC(DftStatus) DftMatrix4FInverse(const DftMatrix4F iMatrix, DftMatrix4F oMatrixInverse);

/**
 * @brief 四维矩阵相乘
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iMatrix1 四维矩阵1
 * @param[in] iMatrix2 四维矩阵2
 * @param[out] oMatrixResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftMatrix4FMultiply(const DftMatrix4F iMatrix1, const DftMatrix4F iMatrix2, DftMatrix4F oMatrixResult);

/**
 * @brief 四维矩阵转置
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iMatrix 四维矩阵
 * @param[out] oMatrixTranspose 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftMatrix4FTranspose(const DftMatrix4F iMatrix, DftMatrix4F oMatrixTranspose);

/**
 * @brief 二维向量相加
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector2DAdd(const DftVector2D iVec1, const DftVector2D iVec2, DftVector2D oResult);

/**
 * @brief 二维向量相减
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector2DSub(const DftVector2D iVec1, const DftVector2D iVec2, DftVector2D oResult);

/**
 * @brief 二维向量缩放
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec 向量
 * @param[in] iScale 缩放系数
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector2DScale(const DftVector2D iVec, DftDouble iScale, DftVector2D oResult);

/**
 * @brief 二维向量点积
 * @return DftBool 结果
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @note
 */
DFT_PUBLIC(DftDouble) DftVector2DDot(const DftVector2D iVec1, const DftVector2D iVec2);

/**
 * @brief 二维向量模长
 * @return DftDouble 结果
 * @param[in] iVec 向量
 * @note
 */
DFT_PUBLIC(DftDouble) DftVector2DLength(const DftVector2D iVec);

/**
 * @brief 二维向量单位化
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in,out] ioVec 向量
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector2DNormalize(DftVector2D ioVec);

/**
 * @brief 二维点的距离
 * @return DftDouble 二维点的距离
 * @param[in] iPoint1 点1
 * @param[in] iPoint2 点2
 * @note
 */
DFT_PUBLIC(DftDouble) DftPoint2DDistance(const DftPoint2D iPoint1, const DftPoint2D iPoint2);

/**
 * @brief 二维点的距离的平方
 * @return DftDouble 二维点的距离的平方
 * @param[in] iPoint1 点1
 * @param[in] iPoint2 点2
 * @note
 */
DFT_PUBLIC(DftDouble) DftPoint2DSquareDistance(const DftPoint2D iPoint1, const DftPoint2D iPoint2);

/**
 * @brief 将二维点投影到直线上
 * @return DftDouble 二维点的距离的平方
 * @param[in] iLinePt 直线上一点
 * @param[in] iLineDir 直线方向
 * @param[in] iSrcPt 输入点
 * @param[out] oPrjPt 投影点
 * @note
 */
DFT_PUBLIC(DftStatus) DftProjectPoint2DToLine(const DftPoint2D iLinePt, const DftVector2D iLineDir, const DftPoint2D iSrcPt, DftPoint2D oPrjPt);

/**
 * @brief 获取二维点集的包围盒
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iPointArr 二维点集的首地址
 * @param[in] iPointCount 二维点个数
 * @param[out] oBoxMin 包围盒最小点
 * @param[out] oBoxMax 包围盒最大点
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetPoint2DBoundingBox(const DftDouble* iPointArr, DftInt iPointCount, DftPoint2D oBoxMin, DftPoint2D oBoxMax);

/**
 * @brief 三维向量相加
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector3DAdd(const DftVector3D iVec1, const DftVector3D iVec2, DftVector3D oResult);

/**
 * @brief 三维向量相减
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector3DSub(const DftVector3D iVec1, const DftVector3D iVec2, DftVector3D oResult);

/**
 * @brief 三维向量缩放
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec 向量
 * @param[in] iScale 缩放系数
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector3DScale(const DftVector3D iVec, DftDouble iScale, DftVector3D oResult);

/**
 * @brief 三维向量点积
 * @return DftDouble 结果
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @note
 */
DFT_PUBLIC(DftDouble) DftVector3DDot(const DftVector3D iVec1, const DftVector3D iVec2);

/**
 * @brief 三维向量叉积
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @param[out] oResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector3DCross(const DftVector3D iVec1, const DftVector3D iVec2, DftVector3D oResult);

/**
 * @brief 三维向量模长
 * @return DftDouble 结果
 * @param[in] iVec 向量
 * @note
 */
DFT_PUBLIC(DftDouble) DftVector3DLength(const DftVector3D iVec);

/**
 * @brief 三维向量单位化
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in,out] ioVec 向量
 * @note
 */
DFT_PUBLIC(DftStatus) DftVector3DNormalize(DftVector3D ioVec);

/**
 * @brief 三维点的距离
 * @return DftDouble 三维点的距离
 * @param[in] iPoint1 点1
 * @param[in] iPoint2 点2
 * @note
 */
DFT_PUBLIC(DftDouble) DftPoint3DDistance(const DftPoint3D iPoint1, const DftPoint3D iPoint2);

/**
 * @brief 三维点的距离的平方
 * @return DftDouble 三维点的距离的平方
 * @param[in] iPoint1 点1
 * @param[in] iPoint2 点2
 * @note
 */
DFT_PUBLIC(DftDouble) DftPoint3DSquareDistance(const DftPoint3D iPoint1, const DftPoint3D iPoint2);

/**
 * @brief 计算两直线的交点
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 直线无交点
 * @param[in] iPt1 直线1上点
 * @param[in] iDir1 直线1方向
 * @param[in] iPt2 直线2上点
 * @param[in] iDir2 直线2方向
 * @param[out] oIntersectPt 交点
 * @param[out] oIsCollinear 是否重合
 * @note
 */
DFT_PUBLIC(DftStatus)
DftVector3DCalcIntersectOfTwoLine(const DftPoint3D iPt1, const DftVector3D iDir1, const DftPoint3D iPt2, const DftVector3D iDir2,
                                  DftPoint3D oIntersectPt, DftBool* oIsCollinear);

/**
 * @brief 两向量是否同向
 * @return DftBool TRUE或FALSE
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3DSameDir(const DftVector3D iVec1, const DftVector3D iVec2);

/**
 * @brief 两向量是否反向
 * @return DftBool TRUE或FALSE
 * @param[in] iVec1 向量1
 * @param[in] iVec2 向量2
 * @note
 */
DFT_PUBLIC(DftBool) IsDftVector3DReverseDir(const DftVector3D iVec1, const DftVector3D iVec2);

/**
 * @brief 点是否在直线上
 * @return DftBool TRUE或FALSE
 * @param[in] iLinePt 直线上一点
 * @param[in] iLineDir 直线方向
 * @param[in] iPoint 点
 * @note
 */
DFT_PUBLIC(DftBool) IsDftPoint3DOnLine(const DftPoint3D iLinePt, const DftVector3D iLineDir, const DftPoint3D iPoint);

/**
 * @brief 点是否在平面上
 * @return DftBool TRUE或FALSE
 * @param[in] iPlanePt 平面上一点
 * @param[in] iPlaneDir 平面法向
 * @param[in] iPoint 点
 * @note
 */
DFT_PUBLIC(DftBool) IsDftPoint3DOnPlane(const DftPoint3D iPlanePt, const DftVector3D iPlaneDir, const DftPoint3D iPoint);

/**
 * @brief 将一个点投影到一条直线上
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iLinePt 直线上一点
 * @param[in] iLineDir 直线方向
 * @param[in] iSrcPt 输入点
 * @param[out] oPrjPt 投影点
 * @note
 */
DFT_PUBLIC(DftStatus) DftProjectPoint3DToLine(const DftPoint3D iLinePt, const DftVector3D iLineDir, const DftPoint3D iSrcPt, DftPoint3D oPrjPt);

/**
 * @brief 将一个点投影到一条直线上
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 直线无交点
 * @param[in] iPlanePt 平面上一点
 * @param[in] iPlaneDir 平面法向
 * @param[in] iSrcPt 输入点
 * @param[out] oPrjPt 投影点
 * @note
 */
DFT_PUBLIC(DftStatus) DftProjectPoint3DToPlane(const DftPoint3D iPlanePt, const DftVector3D iPlaneDir, const DftPoint3D iSrcPt, DftPoint3D oPrjPtx);

/**
 * @brief 获取三维点集的包围盒
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iPointArr 三维点集的首地址
 * @param[in] iPointCount 三维点个数
 * @param[out] oBoxMin 包围盒最小点
 * @param[out] oBoxMax 包围盒最大点
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetPoint3DBoundingBox(const DftDouble* iPointArr, DftInt iPointCount, DftPoint3D oBoxMin, DftPoint3D oBoxMax);

/**
 * @brief 获取包围盒的八个角点
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iBoxMin 包围盒最小点
 * @param[in] iBoxMax 包围盒最大点
 * @param[out] oCornerPoints 包围盒八个角点
 * @note
 */
DFT_PUBLIC(DftStatus) DftGetBoundingBoxCornerDPoints(const DftPoint3D iBoxMin, const DftPoint3D iBoxMax, DftPoint3D oCornerPoints[8]);

/**
 * @brief 三维点的矩阵变换
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iPointIn 输入点
 * @param[in] iTrans 矩阵
 * @param[out] oPointOut 输出点
 * @note
 */
DFT_PUBLIC(DftStatus) DftTransformPoint3D(const DftPoint3D iPointIn, const DftMatrix4D iTrans, DftPoint3D oPointOut);

/**
 * @brief 三维向量的矩阵变换
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iVectorIn 输入向量
 * @param[in] iTrans 矩阵
 * @param[out] oVectorOut 输出向量
 * @note
 */
DFT_PUBLIC(DftStatus) DftTransformVector3D(const DftVector3D iVectorIn, const DftMatrix4D iTrans, DftVector3D oVectorOut);

/**
 * @brief 获取坐标系的变换矩阵
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iOrigin 原点
 * @param[in] iAxisX X轴
 * @param[in] iAxisY Y轴
 * @param[in] iAxisZ Z轴
 * @param[out] oTrans 变换矩阵
 * @note
 */
DFT_PUBLIC(DftStatus)
DftCoordsTransformMatrix4D(const DftPoint3D iOrigin, const DftVector3D iAxisX, const DftVector3D iAxisY, const DftVector3D iAxisZ,
                           DftMatrix4D oTrans);

/**
 * @brief 输出四维单位矩阵
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[out] oMatrix 四维单位矩阵
 * @note
 */
DFT_PUBLIC(DftStatus) DftMatrix4DIdentity(DftMatrix4D oMatrix);

/**
 * @brief 求四维矩阵的逆矩阵
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iMatrix 四维矩阵
 * @param[out] oMatrixInverse 逆矩阵
 * @note
 */
DFT_PUBLIC(DftStatus) DftMatrix4DInverse(const DftMatrix4D iMatrix, DftMatrix4D oMatrixInverse);

/**
 * @brief 四维矩阵相乘
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iMatrix1 四维矩阵1
 * @param[in] iMatrix2 四维矩阵2
 * @param[out] oMatrixResult 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftMatrix4DMultiply(const DftMatrix4D iMatrix1, const DftMatrix4D iMatrix2, DftMatrix4D oMatrixResult);

/**
 * @brief 四维矩阵转置
 * @return DftStatus \ref DFT_SUCCESS 执行成功；\ref DFT_ERROR 执行失败
 * @param[in] iMatrix 四维矩阵
 * @param[out] oMatrixTranspose 结果
 * @note
 */
DFT_PUBLIC(DftStatus) DftMatrix4DTranspose(const DftMatrix4D iMatrix, DftMatrix4D oMatrixTranspose);

#endif

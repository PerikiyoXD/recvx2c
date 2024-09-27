#pragma once

#ifndef _PS2_NAMATH_H_
#define _PS2_NAMATH_H_

#define _NINJA_API_H_ // Just skip the NINJA definitions

#include "types.h"

#define SIN_TABLE_SIZE 0x4000

extern Float SinTable[SIN_TABLE_SIZE];

void _Make_SinTable();
// Float njSin(Angle lAngle);
// Float njCos(Angle lAngle);
// void njSinCos(Angle lAngle, Float* sin, Float* cos);
// Float njFraction(Float fN);
// Float njSqrt(Float x);
// Float njInvertSqrt(Float x);
// void njLinear(Float* fpIdata, Float* fpOdata, Float fFrame);
// void njOverhauserSpline(Float* fpIdata, Float* fpOdata, NJS_SPLINE* pAttr, Float fT);
// void njBezierSpline(Float* fpIdata, Float* fpOdata, NJS_SPLINE* pAttr, Float fFrame);
// Uint32 njFactorial(Uint32 ulN);

#endif // _PS2_NAMATH_H_
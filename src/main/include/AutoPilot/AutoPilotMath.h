#ifndef AUTOPILOT_MATH_H
#define AUTOPILOT_MATH_H

#include "AutoPilot/PathBuilding.h"
#include <math.h>

double Angle2Deriv(double AngleInDegrees);

double ArcLengthDistance(SplineFunction TheSplineFunction);

double TimeGivenSFVAJ(SplineFunction TheSplineFunction, double Velocity, double Acceleration, double Jerk);

Spline SortSpline(Spline Spline);

#endif
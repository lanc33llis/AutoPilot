#ifndef AUTOPILOT_MATH_H
#define AUTOPILOT_MATH_H

#include "AutoPilot/PathBuilding.h"
#include <algorithm> 
#include <math.h>

//finds deriv or slope of an angle. Used to find exit angle slope or deriv
double Angle2Deriv(double AngleInDegrees);

//Finds the distance of a spline function using arc length
double ArcLengthDistance(SplineFunction TheSplineFunction);

//Finds the time needed to traverse the distance given velocity, acceleration, and jerk
double TimeGivenSFVAJ(SplineFunction TheSplineFunction, double Velocity, double Acceleration, double Jerk);

#endif
#ifndef AUTOPILOT_PATHBUILDING_H
#define AUTOPILOT_PATHBUILDING_H

#include <vector>

typedef struct
{
    double X, Y, Angle;
} Waypoint;

typedef struct
{
    Waypoint PointOne, PointTwo;
    double Ax, Bx, Cx, Dx, S;
} SplineFunction;

SplineFunction HermiteFinder(Waypoint PointOne, Waypoint PointTwo);

typedef std::vector<SplineFunction> Spline; 

#endif
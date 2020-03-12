#ifndef AUTOPILOT_PATHBUILDING_H
#define AUTOPILOT_PATHBUILDING_H

#include <vector>

typedef struct Waypoint
{
    double X, Y, Angle;
};

typedef struct SplineFunction
{
    Waypoint PointOne, PointTwo;
    double Ax, Bx, Cx, Dx, S;
};

SplineFunction HermiteFinder(Waypoint PointOne, Waypoint PointTwo);

typedef std::vector<SplineFunction> Spline; 

#endif
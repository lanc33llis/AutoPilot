#ifndef AUTOPILOT_PATHBUILDING_H
#define AUTOPILOT_PATHBUILDING_H

#include <vector>

struct Waypoint
{
    double X, Y, Angle;
};

typedef std::vector<Waypoint> Path;

struct SplineFunction
{
    Waypoint PointOne, PointTwo;
    double Ax, Bx, Cx, Dx, S;
};

SplineFunction HermiteFinder(Waypoint PointOne, Waypoint PointTwo);

typedef std::vector<SplineFunction> Spline; 

Spline SplineGeneration(Path ThePath);

#endif
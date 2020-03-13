#include "AutoPilot/PathBuilding.h"
#include "AutoPilot/AutoPilotMath.h"
#include "AutoPilot/Hermite/hermite_cubic.hpp"


SplineFunction HermiteFinder(Waypoint PointOne, Waypoint PointTwo)
{
    double* A0, *A1, *A2, *A3; 
    hermite_cubic_to_power_cubic(PointOne.X, PointOne.Y, Angle2Deriv(PointOne.Angle), PointTwo.X, PointTwo.Y, Angle2Deriv(PointTwo.Angle), A0, A1, A2, A3);
    return SplineFunction{PointOne, PointTwo, *A0, *A1, *A2, *A3};
}

Spline SplineGeneration(Path ThePath)
{
    bool IsEven;
    if ((ThePath.size() % 2) != 0)
    {
        IsEven = false;
    }
    else
    {
        IsEven = true;
    }
    
}
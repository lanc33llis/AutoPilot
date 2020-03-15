#include "AutoPilot/PathBuilding.h"
#include "AutoPilot/AutoPilotMath.h"
#include "AutoPilot/Hermite/hermite_cubic.h"

namespace AP{

SplineFunction HermiteFinder(Waypoint PointOne, Waypoint PointTwo)
{
    double* A0, *A1, *A2, *A3; 
    hermite_cubic_to_power_cubic(PointOne.X, PointOne.Y, Angle2Deriv(PointOne.Angle), PointTwo.X, PointTwo.Y, Angle2Deriv(PointTwo.Angle), A0, A1, A2, A3);
    return SplineFunction{PointOne, PointTwo, *A0, *A1, *A2, *A3};
}

Spline GenerateSpline(Path ThePath)
{
    Spline ReturnSpline;
    int NumberOfFunctions = ThePath.size() - 2;
    for (int i = 0; i <= NumberOfFunctions; i++)
    {
        SplineFunction Temp = HermiteFinder(ThePath[i], ThePath[i + 1]);
        ReturnSpline.push_back(Temp);
    }
    return ReturnSpline;
}

}
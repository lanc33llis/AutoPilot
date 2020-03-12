#include "AutoPilot/Trajectory.h"

Segment GenerateSegment(SplineFunction Function, double Velocity, double Acceleration, double Jerk)
{
    double B0, B1, B2, Time;

    Time = TimeGivenSFVAJ(Function, Velocity, Acceleration, Jerk);

    B0 = Function.Ax; B1 = Function.Bx; B2 = Function.Cx;
    return Segment{Function, B0, B1, B2, Time};
}

Trajectory GenerateTrajectory(Spline Spline)
{
    
    for (int i = 0; i <= Spline.size(); i++)
    {

    }
}
#include "AutoPilot/Trajectory.h"

double Segment::Velocity(double Seconds)
{
    //deriv = 3ax^2 + 2bx + c
    double BaseVelocity = ArcLengthDistance(Function) / Time;
    if (Seconds > Time)
    {
        return NAN;
    }
    else
    {
        return (pow(3*Ax * Seconds, 2) + (2*Bx * Seconds) + C);
    }
}

double Segment::Acceleration(double Seconds)
{
    //deriv 6ax + 2b
    if (Seconds > Time)
    {
        return NAN;
    }
    else
    {
        return (6*Ax*Seconds + 2*Bx);
    }
}

double Segment::Jerk(double Seconds)
{
    //deriv 6ax
    if (Seconds > Time)
    {
        return NAN;
    }
    else
    {
        return 6*Ax;
    }
}

//Generates segment 
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
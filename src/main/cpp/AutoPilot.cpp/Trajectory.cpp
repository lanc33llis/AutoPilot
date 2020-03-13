#include "AutoPilot/Trajectory.h"

double Segment::Velocity(double Seconds)
{
    //deriv y = 3ax^2 + 2bx + c
    //deriv x = y-(d/ax^2+bx+c)
    double YVelocity, XVelocity;
    double Displacement; 
    if (Seconds > Time)
    {
        return NAN;
    }
    else
    {
        
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
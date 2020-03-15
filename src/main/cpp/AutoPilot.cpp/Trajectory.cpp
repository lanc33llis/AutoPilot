#include "AutoPilot/Trajectory.h"
#include "AutoPilot/Hermite/hermite_cubic.h"

namespace AP
{

double Segment::Velocity(double Seconds)
{
    //deriv 3ax^2 + 2bx + c
    if (Seconds > Time)
    {
        return NAN;
    }
    else
    {
        double Xa = XFunction.Ax, Xb = XFunction.Bx, Xc = XFunction.Cx;
        double Ya = YFunction.Ax, Yb = YFunction.Cx, Yc = YFunction.Cx;
        return (sqrt(((3 * Xa * pow(Seconds, 2)) + (2 * Xb) + Xc) + ((3 * Ya * pow(Seconds, 2)) + (2 * Yb) + Yc)));
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
        double Xa = XFunction.Ax, Xb = XFunction.Bx;
        double Ya = YFunction.Ax, Yb = YFunction.Cx;
        return sqrt(pow((6 * Xa * Seconds + 2 * Xb), 2) + pow((6 * Ya * Seconds + 2 * Yb), 2));
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
        double Xa = XFunction.Ax;
        double Ya = YFunction.Ax;
        return sqrt(pow(6*Xa*Seconds, 2) + pow(6*Ya*Seconds, 2));
    }
}

//Generates a segment.
Segment GenerateSegment(SplineFunction Function, double Jerk)
{
    double B0, B1, B2, Time;

    Time = TimeGivenSFJ(Function, Jerk);
    SplineFunction XFunction = HermiteFinder(Waypoint{0, 0, Function.PointOne.Angle}, Waypoint{Time, Function.PointTwo.X - Function.PointOne.X, Function.PointTwo.Angle});
    SplineFunction YFunction = HermiteFinder(Waypoint{0, 0, Function.PointOne.Angle}, Waypoint{Time, Function.PointTwo.Y - Function.PointOne.Y, Function.PointTwo.Angle});
    B0 = Function.Ax; B1 = Function.Bx; B2 = Function.Cx;
    return Segment{Function, XFunction, YFunction, B0, B1, B2, Time};
}

Trajectory GenerateTrajectory(Spline Spline, double Jerk)
{
    Trajectory ReturnTrajectory;
    for (int i = 0; i <= Spline.size(); i++)
    {
        Segment Temp = GenerateSegment(Spline[i], Jerk);
        ReturnTrajectory.push_back(Temp);
    }
    return ReturnTrajectory;
}

}
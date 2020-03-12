#include "AutoPilot/Trajectory.h"

MotionProfile GenerateMotionProfile(SplineFunction function, double Velocity, double Acceleration, double Jerk)
{
    double B0, B1, B2, time;

    

    B0 = function.Ax; B1 = function.Bx; B2 = function.Cx;
    return MotionProfile{function, B0, B1, B2, time};
}

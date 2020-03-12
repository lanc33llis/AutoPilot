#include "AutoPilot/Trajectory.h"

MotionProfile GenerateMotionProfile(SplineFunction function, double Velocity, double Acceleration, double Jerk)
{
    double B0, B1, B2, time;

    /*

    v(t) = interval [0, t] a(t)dt=1/2Jmax*t^2

    x(t) = interval [0, t] v(t)dt=1/2Jmax*t^3

    thus

    time for end position is:

    t = (6*end position/Jmax)^1/3

    and time for maximum speed

    t = (2*velocitymax/Jmax)^1/2

    */
   
   time = ();

    B0 = function.Ax; B1 = function.Bx; B2 = function.Cx;
    return MotionProfile{function, B0, B1, B2, time};
}

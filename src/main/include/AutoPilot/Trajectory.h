#ifndef AUTOPILOT_TRAJECTORY_H
#define AUTOPILOT_TRAJECTORY_H

#include "AutoPilot/PathBuilding.h"

typedef struct MotionProfile
{
    SplineFunction Function;
    double Ax, Bx, C, time;
};

MotionProfile GenerateMotionProfile(SplineFunction function, double Velocity, double Acceleration, double Jerk);

typedef std::vector<MotionProfile> Trajectory;

#endif
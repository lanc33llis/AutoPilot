#ifndef AUTOPILOT_TRAJECTORY_H
#define AUTOPILOT_TRAJECTORY_H

#include "AutoPilot/PathBuilding.h"
#include "AutoPilot/AutoPilotMath.h"

typedef struct
{
    SplineFunction Function;
    double Velocity(double Seconds); double Acceleration(double Seconds); double Jerk(double Seconds); 
    double Ax, Bx, C, Time;
} Segment;

Segment GenerateSegment(SplineFunction function, double Velocity, double Acceleration, double Jerk);

typedef std::vector<Segment> Trajectory;

Trajectory GenerateTrajectory(Spline Spline);


#endif
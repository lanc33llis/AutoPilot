#ifndef AUTOPILOT_TRAJECTORY_H
#define AUTOPILOT_TRAJECTORY_H

#include "AutoPilot/PathBuilding.h"
#include "AutoPilot/AutoPilotMath.h"

namespace AP {

	struct Segment
	{
		SplineFunction Function, XFunction, YFunction;
		double Velocity(double Seconds); double Acceleration(double Seconds); double Jerk(double Seconds);
		double Ax, Bx, C, Time;
	};

    Segment GenerateSegment(SplineFunction function, double Jerk);

    typedef std::vector<Segment> Trajectory;

    Trajectory GenerateTrajectory(Spline Spline, double Jerk);

}
#endif
#ifndef AUTOPILOT_PATHBUILDING_H
#define AUTOPILOT_PATHBUILDING_H

#include <vector>

namespace AP
{
    struct Waypoint
	{
		double X, Y, Angle;
	};

	typedef std::vector<Waypoint> Path;

	struct SplineFunction
	{
		Waypoint PointOne, PointTwo;
		double Ax, Bx, Cx, Dx;
	};

	typedef std::vector<SplineFunction> Spline;

    SplineFunction HermiteFinder(Waypoint PointOne, Waypoint PointTwo);

    Spline GenerateSpline(Path ThePath);
}
#endif
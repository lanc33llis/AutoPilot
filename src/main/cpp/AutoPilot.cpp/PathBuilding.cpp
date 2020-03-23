#include "AutoPilot/PathBuilding.h"
#include "AutoPilot/AutoPilotMath.h"
#include "AutoPilot/Hermite/hermite_cubic.h"

namespace AP{

	//Finds the cubic equation given two poitns
	SplineFunction HermiteFinder(Waypoint PointOne, Waypoint PointTwo)
	{
		// p(x) = c0 + c1 * x + c2 * x^2 + c3 * x^3
		// p(x) = c3 * x^3 + c2 * x^2 + c1 * x + c0
		double *A0 = new double(0), *A1 = new double(0), *A2 = new double(0), *A3 = new double(0);
		hermite_cubic_to_power_cubic(PointOne.X, PointOne.Y, Angle2Deriv(PointOne.Angle), PointTwo.X, PointTwo.Y, Angle2Deriv(PointTwo.Angle), A0, A1, A2, A3);
		return SplineFunction{ PointOne, PointTwo, *A3, *A2, *A1, *A0 };
	}

	//Generates a spline using a path structure
	Spline GenerateSpline(Path ThePath)
	{
		Spline ReturnSpline;
		int NumberOfFunctions = ThePath.size() - 1;
		for (int i = 0; i < NumberOfFunctions; i++)
		{
			SplineFunction Temp = HermiteFinder(ThePath[i], ThePath[i + 1]);
			ReturnSpline.push_back(Temp);
		}
		return ReturnSpline;
	}

}
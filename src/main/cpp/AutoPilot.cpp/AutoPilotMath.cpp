#include "AutoPilot/AutoPilotMath.h"
#include "AutoPilot/Hermite/hermite_cubic.hpp"

double Angle2Deriv(double AngleInDegrees)
{
    double a = AngleInDegrees;
    if (a == 90 || a == 270)
    {
        return -1;
    }
    else
    {
        return tan(a);
    }
}

double ArcLengthDistance(SplineFunction TheSplineFunction)
{   //deriv = 3ax^2 + 2bx + c
    double Ax = 3*TheSplineFunction.Ax, Bx = 2*TheSplineFunction.Bx, C = TheSplineFunction.Cx;
    return (TheSplineFunction.PointTwo.X - TheSplineFunction.PointOne.X) * (sqrt(1+pow(2, pow(2, Ax) + Bx+ C)));
}

double TimeGivenSFVAJ(SplineFunction TheSplineFunction, double Velocity, double Acceleration, double Jerk)
{
    /*

    v(t) = interval [0, t] a(t)dt=1/2Jmax*t^2

    x(t) = interval [0, t] v(t)dt=1/2Jmax*t^3

    thus

    time for end position is:

    t = (6*end position/Jmax)^1/3

    and time for maximum speed

    t = (2*velocitymax/Jmax)^1/2

    */

   return pow(1/3, (6*ArcLengthDistance(TheSplineFunction)));
}

template <class type> bool Comp(type a, type b)
    {
        return (a.i>b.i);
    }


Spline SplineSort(Spline Spline)
{
    struct SplineFunctionCarrier
    {
        SplineFunction SplineFunction; int i;
    };
    
    std::vector<SplineFunctionCarrier> Carrier;
    for (int i = 0; i <= Spline.size(); i++)
    {
        Carrier[i].SplineFunction = Spline[i];
        Carrier[i].i = i;
    }

    for (int i = 0; i <= Spline.size(); i++)
    {
        for (int j = 0; j <= Spline.size(); j++)
        {
            if (Carrier[i].SplineFunction.PointOne.X < Carrier[j].SplineFunction.PointOne.X)
            {
                Carrier[i].i = (j-1);
            }
            else 
            {
                Carrier[i].i = (j+1);
            }
        }
    }

    std::sort(Carrier.begin(), Carrier.end(), Comp);
}



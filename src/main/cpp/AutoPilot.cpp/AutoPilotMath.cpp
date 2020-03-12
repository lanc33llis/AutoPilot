#include "AutoPilot/AutoPilotMath.h"

double Angle2Deriv(double AngleInDegrees)
{
    double a = AngleInDegrees;
    if (a == 90)
    {
        return -2;
    }
    else
    {
        return tan(a);
    }

}
#ifndef AUTOPILOT_H
#define AUTOPILOT_H

#include "AutoPilotMath.h"
#include "PathBuilding.h"
#include "Trajectory.h"
#include "Follower.h"
namespace AP
{

class AutoPilot
{
    public:
    double MaxJerk;
    AutoPilot(double Jerk);
    ~AutoPilot();
};

}
#endif
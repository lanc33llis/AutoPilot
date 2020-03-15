#ifndef AUTOPILOT_FOLLOWER_H
#define AUTOPILOT_FOLLOWER_H

namespace AP

{

struct TankDrive
{
    std::vector<std::vector<double>> LeftMotors, RightMotors;
};

TankDrive GenerateTankDrive(Trajectory ATrajectory, double TimeStep);

}

#endif
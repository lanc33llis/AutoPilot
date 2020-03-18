#ifndef AUTOPILOT_FOLLOWER_H
#define AUTOPILOT_FOLLOWER_H
#include "AutoPilot/Trajectory.h"
#include <vector>

namespace AP

{

struct TankDrive
{
    std::vector<std::vector<double>> LeftMotors, RightMotors;
};

template <class MotorGroup, class EncoderType>
void AP::FollowTankDrive(AP::Trajectory ATrajecotry, double TimeStep, MotorGroup &LeftMotors, MotorGroup &RightMotors, std::vector<EncoderType> LeftEncoders, std::vector<EncoderType> RightEncoders, double kP);



}

#endif
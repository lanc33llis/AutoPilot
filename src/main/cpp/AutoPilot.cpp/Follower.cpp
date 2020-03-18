#include "AutoPilot/Follower.h"
#include "AutoPilot/Trajectory.h"
#include <frc/Timer.h>


template <class MotorGroup, class EncoderType>
void AP::FollowTankDrive(AP::Trajectory ATrajecotry, double TimeStep, MotorGroup &LeftMotors, MotorGroup &RightMotors, std::vector<EncoderType> LeftEncoders, std::vector<EncoderType> RightEncoders, double kP)
{
    frc::MyTimer();
    double TotalTime;
    for (int i = 0; i <= ATrajecotry.size(); i++)
    {
        TotalTime = TotalTime + ATrajecotry[i].Time;
    }

    double Steps = TotalTime/TimeStep;

    double LeftEncodersVelocity = 0, RightEncodersVelocity = 0;

    while (MyTimer.Get() >= TotalTime)
    {
        for (int i = 0; i <= LeftEncoders.size(); i++)
        {
            LeftEncodersVelocity = (LeftEncodersVelocity + LeftEncoders[i].GetVelocity());
            if (i == LeftEncoders.size())
            {
                LeftEncodersVelocity = (LeftEncodersVelocity/LeftEncoders.size());
            }
        }
        for (int i = 0; i <= RightEncoders.size(); i++)
        {
            RightEncodersVelocity = (RightEncodersVelocity + RightEncoders[i].GetVelocity());
            if (i == RightEncoders.size())
            {
                RightEncodersVelocity = (RightEncodersVelocity/RightEncoders.size());
            }
        }
    }


}
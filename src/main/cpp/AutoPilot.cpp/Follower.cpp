#include "AutoPilot/Follower.h"
#include "AutoPilot/Trajectory.h"

AP::TankDrive AP::GenerateTankDrive(AP::Trajectory ATrajecotry, double TimeStep)
{
    double TotalTime;
    for (int i = 0; i <= ATrajecotry.size(); i++)
    {
        TotalTime = TotalTime + ATrajecotry[i].Time;
    }
    double Steps = TotalTime/TimeStep;
    
    for (int j = TimeStep; ; j + TimeStep)
    {
        
    }
}
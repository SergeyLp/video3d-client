#include    "trajectory.h"
#include    "filesystem.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
TrainTrajectory::TrainTrajectory(std::string routeDir,
                                 int direction,
                                 float height)
    : direction(direction)
    , height(height)
    , init_yaw(0.0f)

{
    FileSystem &fs = FileSystem::getInstance();    
    std::string track_name = routeDir + fs.separator() +  "route";

    if (direction > 0)
    {
        track_name += "1.trk";
        init_yaw = 0.0f;
    }
    else
    {
        track_name += "2.trk";
        init_yaw = osg::PIf;
    }

    routePath = new RoutePath(track_name);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TrainTrajectory::update(const traj_element_t &traj_elem, const float &delta_time)
{
    float t = delta_time / traj_elem.delta_time;
    float coord = (1 - t) * traj_elem.coord_begin + traj_elem.coord_end * t;

    position = routePath->getPosition(coord, attitude);

    position.z() += height;

    attitude.x() = -osg::PIf / 2.0f + attitude.x();
    attitude.z() = init_yaw + attitude.z();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
osg::Vec3 TrainTrajectory::getPosition() const
{
    return position;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
osg::Vec3 TrainTrajectory::getAttitude() const
{
    return attitude;
}

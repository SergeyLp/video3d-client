//------------------------------------------------------------------------------
//
//      Trajectory processor for camera motion
//      (c) maisvendoo
//
//------------------------------------------------------------------------------
/*!
 * \file
 * \brief Trajectory processor for camera motion
 * \copyright maisvendoo
 * \author maisvendoo
 */

#ifndef     TRAJECTORY_H
#define     TRAJECTORY_H

#include    <osg/Referenced>

#include    <string>

#include    "trajectory-element.h"
#include    "route-path.h"

/*!
 * \class
 * \brief Train trajectory
 */
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class TrainTrajectory : public osg::Referenced
{
public:

    /// Constructor
    TrainTrajectory(std::string routeDir,
                    int direction,
                    float height);

    /// Update train position
    void update(const traj_element_t &traj_elem, const float &delta_time);

    /// Get trajectory positiob
    osg::Vec3   getPosition() const;
    /// Get trajectory attitude
    osg::Vec3   getAttitude() const;

private:

    /// Motion direction
    int                         direction;
    /// Camera's height over rails
    float                       height;
    /// Initial yaw of camera
    float                       init_yaw;
    /// Route path (tracks data processing)
    osg::ref_ptr<RoutePath>     routePath;
    /// Route directory
    std::string                 routeDir;

    /// Current position
    osg::Vec3                   position;
    /// Current attitude
    osg::Vec3                   attitude;
};

#endif // TRAJECTORY_H

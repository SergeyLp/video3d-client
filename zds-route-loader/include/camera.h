//------------------------------------------------------------------------------
//
//      Camera's events hadnler (to process camera motion)
//      (c) maisvendoo, 01/12/2018
//
//------------------------------------------------------------------------------
/*!
 * \file
 * \brief Camera's events hadnler (to process camera motion)
 * \copyright maisvendoo
 * \author maisvendoo
 * \date 01/12/2018
 */

#ifndef     CAMERA_H
#define     CAMERA_H

#include    <osgGA/GUIEventAdapter>
#include    <osgGA/GUIActionAdapter>
#include    <osgViewer/Viewer>

#include    "trajectory.h"

/*!
 * \class
 * \brief Camera pseudo-manipulator
 */
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class RailwayManipulator : public osgGA::GUIEventHandler
{
public:

    /// Conastructor
    RailwayManipulator(TrainTrajectory *train_traj);

    /// Events handler
    virtual bool handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &aa);

protected:

    /// Train trajectory object
    osg::ref_ptr<TrainTrajectory>   train_traj;
    /// Reference time count between position data update
    double                          ref_time;
    /// Initial time of frame draw
    double                          _startTime;
    /// Current trajectory element
    traj_element_t                  traj_element;
    /// Camera's view matrix
    osg::Matrix                     matrix;

    /// Camera motion
    void moveCamera(double ref_time,
                    const traj_element_t &traj_element,
                    osgViewer::Viewer *viewer);
};

#endif // CAMERA_H

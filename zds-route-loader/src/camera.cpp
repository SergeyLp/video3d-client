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

#include    "camera.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
RailwayManipulator::RailwayManipulator(TrainTrajectory *train_traj)
    : train_traj(train_traj)
    , ref_time(0.0)
    , _startTime(0.0)

{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool RailwayManipulator::handle(const osgGA::GUIEventAdapter &ea,
                                osgGA::GUIActionAdapter &aa)
{
    switch (ea.getEventType())
    {
    case osgGA::GUIEventAdapter::FRAME:
    {
        osgViewer::Viewer *viewer = dynamic_cast<osgViewer::Viewer *>(&aa);

        if (!viewer)
            break;

        // Current time label
        double time = viewer->getFrameStamp()->getReferenceTime();
        // Calculationg of frame drawing time
        double delta_time = time - _startTime;
        ref_time += delta_time;
        _startTime = time;

        // Move camera to new position
        moveCamera(ref_time, traj_element, viewer);

        break;
    }

    case osgGA::GUIEventAdapter::USER:
    {
        const traj_element_t *te = dynamic_cast<const traj_element_t *>(ea.getUserData());

        if (traj_element.count == 0)
            traj_element.coord_begin = traj_element.coord_end = te->coord_end;
        else
        {
            traj_element.coord_begin = traj_element.coord_end;
            traj_element.coord_end = te->coord_end;
        }

        traj_element.delta_time = te->delta_time;
        traj_element.count++;
        ref_time = 0.0;

        break;
    }

    default:

        break;
    }

    return false;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void RailwayManipulator::moveCamera(double ref_time,
                                    const traj_element_t &traj_element,
                                    osgViewer::Viewer *viewer)
{
    // Update train position on trajectory
    train_traj->update(traj_element, static_cast<float>(ref_time));

    // Get current camera position and attitude
    osg::Vec3 position = train_traj->getPosition();
    osg::Vec3 attitude = train_traj->getAttitude();

    // View matrix calculation
    matrix = osg::Matrix::translate(position *= -1.0f);
    matrix *= osg::Matrix::rotate(static_cast<double>(attitude.x()), osg::Vec3(1.0f, 0.0f, 0.0f));
    matrix *= osg::Matrix::rotate(static_cast<double>(attitude.z()), osg::Vec3(0.0f, 1.0f, 0.0f));

    viewer->getCamera()->setViewMatrix(matrix);
}

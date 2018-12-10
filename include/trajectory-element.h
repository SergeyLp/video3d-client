//------------------------------------------------------------------------------
//
//      Current trajectory element for lineaer approximate of camera motion
//      (c) maisvendoo
//
//------------------------------------------------------------------------------
/*!
 * \file
 * \brief Current trajectory element for lineaer approximate of camera motion
 * \copyright maisvendoo
 * \author maisvendoo
 */

#ifndef     TRAJECTORY_ELEMENT_H
#define     TRAJECTORY_ELEMENT_H

#include    <osg/Referenced>

/*!
 * \struct
 * \brief Trajectory element
 */
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
struct traj_element_t : public osg::Referenced
{
    float           coord_begin;
    float           coord_end;
    float           delta_time;
    unsigned long   count;

    traj_element_t()
        : coord_begin(1000.0f)
        , coord_end(1000.0f)
        , delta_time(3600.0f)
        , count(0)
    {

    }
};

#endif // TRAJECTORY_ELEMENT_H

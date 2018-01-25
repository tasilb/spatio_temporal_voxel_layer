/*********************************************************************
 *
 * Software License Agreement
 *
 *  Copyright (c) 2018, Simbe Robotics, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: Steve Macenski (steven.macenski@simberobotics.com)
 * Purpose: Measurement reading structure containing info needed for marking
 *          and frustum clearing.
 *********************************************************************/

#ifndef MEASUREMENT_READING_H_
#define MEASUREMENT_READING_H_
// PCL
#include <pcl/point_cloud.h>
#include <pcl_ros/point_cloud.h>
// msgs
#include <geometry_msgs/Point.h>

namespace observation
{

struct MeasurementReading
{
  /*****************************************************************************/
  MeasurementReading() :
  /*****************************************************************************/
    _cloud(new pcl::PointCloud<pcl::PointXYZ>)
  {
  }

  /*****************************************************************************/
  MeasurementReading(geometry_msgs::Point& origin, pcl::PointCloud<pcl::PointXYZ> cloud, \
            double obstacle_range, double min_z, double max_z, double vFOV, double hFOV,
            bool marking, bool clearing) :
  /*****************************************************************************/
                                      _origin(origin),                                   \
                                      _cloud(new pcl::PointCloud<pcl::PointXYZ>(cloud)), \
                                      _obstacle_range_in_m(obstacle_range),              \
                                      _min_z_in_m(min_z),                                \
                                      _max_z_in_m(max_z),                                \
                                      _vertical_fov_in_rad(vFOV),                        \
                                      _horizontal_fov_in_rad(hFOV),                      \
                                      _marking(marking),                                 \
                                      _clearing(clearing)
  {
  }

  /*****************************************************************************/
  MeasurementReading(pcl::PointCloud<pcl::PointXYZ> cloud, double obstacle_range) :
  /*****************************************************************************/
                                    _cloud(new pcl::PointCloud<pcl::PointXYZ>(cloud)), \
                                    _obstacle_range_in_m(obstacle_range)
  {
  }

  /*****************************************************************************/
  MeasurementReading(const MeasurementReading& obs) :
  /*****************************************************************************/
                             _origin(obs._origin),                                      \
                             _cloud(new pcl::PointCloud<pcl::PointXYZ>(*(obs._cloud))), \
                             _obstacle_range_in_m(obs._obstacle_range_in_m),            \
                             _min_z_in_m(obs._min_z_in_m),                              \
                             _max_z_in_m(obs._max_z_in_m),                              \
                             _vertical_fov_in_rad(obs._vertical_fov_in_rad),            \
                             _horizontal_fov_in_rad(obs._horizontal_fov_in_rad),        \
                             _marking(obs._marking),                                    \
                             _clearing(obs._clearing)
  {
  }

  geometry_msgs::Point _origin;
  pcl::PointCloud<pcl::PointXYZ>::Ptr _cloud;
  double _obstacle_range_in_m, _min_z_in_m, _max_z_in_m;
  double _vertical_fov_in_rad, _horizontal_fov_in_rad;
  double _marking, _clearing;

};

} // end namespace

#endif  // MEASUREMENT_READING_H_

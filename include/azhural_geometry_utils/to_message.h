#ifndef AZGEO_TO_MESSAGE_H
#define AZGEO_TO_MESSAGE_H

#include <tf2/utils.h>

namespace azgeo { namespace msgs {

geometry_msgs::Point toPoint(const tf2::Vector3 &v);
geometry_msgs::PointStamped toPointStamped(const std::string &frame_id, const tf2::Vector3 &v);

geometry_msgs::Pose toPose(const tf2::Vector3 &position, const tf2::Quaternion &orientation);
geometry_msgs::PoseStamped toPoseStamped(const std::string &frame_id, const tf2::Vector3 &position, const tf2::Quaternion &orientation);

geometry_msgs::Transform toTransform(const tf2::Vector3 &translation, const tf2::Quaternion &rotation);
geometry_msgs::TransformStamped toTransformStamped(const std::string &parent_frame_id, const std::string &child_frame_id, const tf2::Vector3 &translation, const tf2::Quaternion &rotation);

}}

#endif

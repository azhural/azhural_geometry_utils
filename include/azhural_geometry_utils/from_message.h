#ifndef AZGEO_FROM_MESSAGE_H
#define AZGEO_FROM_MESSAGE_H

#include <tf2/utils.h>

namespace azgeo { namespace msgs {

tf2::Quaternion extractQuaternion(const geometry_msgs::Quaternion& quat);
tf2::Quaternion extractQuaternion(const geometry_msgs::Pose& pose);
tf2::Quaternion extractQuaternion(const geometry_msgs::PoseStamped &pose);
tf2::Quaternion extractQuaternion(const geometry_msgs::Transform &transform);
tf2::Quaternion extractQuaternion(const geometry_msgs::TransformStamped &transform);

tf2::Vector3 extractVector(const geometry_msgs::Vector3& vector);
tf2::Vector3 extractVector(const geometry_msgs::Point& point);
tf2::Vector3 extractVector(const geometry_msgs::Pose& pose);
tf2::Vector3 extractVector(const geometry_msgs::PoseStamped& pose);
tf2::Vector3 extractVector(const geometry_msgs::Transform& transform);
tf2::Vector3 extractVector(const geometry_msgs::TransformStamped& transform);

}}

#endif

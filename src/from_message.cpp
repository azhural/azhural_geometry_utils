#include <azhural_geometry_utils/from_message.h>

namespace azgeo { namespace msgs {

tf2::Quaternion extractQuaternion(const geometry_msgs::Quaternion& quat){
  return tf2::Quaternion{quat.x, quat.y, quat.z, quat.w};
}
tf2::Quaternion extractQuaternion(const geometry_msgs::Pose& pose){
  return extractQuaternion(pose.orientation);
}
tf2::Quaternion extractQuaternion(const geometry_msgs::PoseStamped &pose){
  return extractQuaternion(pose.pose);
}
tf2::Quaternion extractQuaternion(const geometry_msgs::Transform &transform){
  return extractQuaternion(transform.rotation);
}
tf2::Quaternion extractQuaternion(const geometry_msgs::TransformStamped &transform){
  return extractQuaternion(transform.transform);
}

tf2::Vector3 extractVector(const geometry_msgs::Vector3& vector){
  return tf2::Vector3{vector.x, vector.y, vector.z};
}
tf2::Vector3 extractVector(const geometry_msgs::Point& point){
  return tf2::Vector3{point.x, point.y, point.z};
}
tf2::Vector3 extractVector(const geometry_msgs::Pose& pose){
  return extractVector(pose.position);
}
tf2::Vector3 extractVector(const geometry_msgs::PoseStamped& pose){
  return extractVector(pose.pose);
}
tf2::Vector3 extractVector(const geometry_msgs::Transform& transform){
  return extractVector(transform.translation);
}
tf2::Vector3 extractVector(const geometry_msgs::TransformStamped& transform){
  return extractVector(transform.transform);
}

}}

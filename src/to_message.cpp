#include <azhural_geometry_utils/to_message.h>

namespace azgeo { namespace msgs {

geometry_msgs::Point toPoint(const tf2::Vector3 &v){
  geometry_msgs::Point point;
  point.x = v.x();
  point.y = v.y();
  point.z = v.z();
  return point;
}

geometry_msgs::PointStamped toPointStamped(const std::string &frame_id, const tf2::Vector3 &v){
  geometry_msgs::PointStamped point_stamped;
  point_stamped.point = toPoint(v);
  point_stamped.header.frame_id = frame_id;
  return point_stamped;
}

geometry_msgs::Pose toPose(const tf2::Vector3 &position, const tf2::Quaternion &orientation){
  geometry_msgs::Pose pose;
  pose.position = toPoint(position);
  pose.orientation = tf2::toMsg(orientation);
  return pose;
}

geometry_msgs::PoseStamped toPoseStamped(const std::string &frame_id, const tf2::Vector3 &position, const tf2::Quaternion &orientation){
  geometry_msgs::PoseStamped pose_stamped;
  pose_stamped.pose = toPose(position, orientation);
  pose_stamped.header.frame_id = frame_id;
  return pose_stamped;
}

geometry_msgs::Transform toTransform(const tf2::Vector3 &translation, const tf2::Quaternion &rotation){
  geometry_msgs::Transform transform;
  transform.translation = tf2::toMsg(translation);
  transform.rotation = tf2::toMsg(rotation);
  return transform;
}

geometry_msgs::TransformStamped toTransformStamped(const std::string &parent_frame_id, const std::string &child_frame_id, const tf2::Vector3 &translation, const tf2::Quaternion &rotation){
  geometry_msgs::TransformStamped transform_stamped;
  transform_stamped.transform = toTransform(translation, rotation);
  transform_stamped.header.frame_id = parent_frame_id;
  transform_stamped.child_frame_id = child_frame_id;
  return transform_stamped;
}

}}

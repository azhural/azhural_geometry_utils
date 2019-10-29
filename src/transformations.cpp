#include <azhural_geometry_utils/transformations.h>
#include <azhural_geometry_utils/from_message.h>
#include <azhural_geometry_utils/to_message.h>
#include <azhural_geometry_utils/utils.h>

namespace azgeo { namespace transformations {

geometry_msgs::Pose calculatePoseRelativeToPose(const geometry_msgs::Pose &origin_to_intermediate, const geometry_msgs::Pose &intermediate_to_target){
  tf2::Vector3 translation;
  tf2::Quaternion rotation;
  transformRelative(msgs::extractVector(origin_to_intermediate), msgs::extractQuaternion(origin_to_intermediate), msgs::extractVector(intermediate_to_target), msgs::extractQuaternion(intermediate_to_target), translation, rotation);
  return msgs::toPose(translation, rotation);
}
geometry_msgs::PoseStamped calculatePoseRelativeToPoseStamped(const geometry_msgs::PoseStamped &origin_to_intermediate, const geometry_msgs::Pose &intermediate_to_target){
  geometry_msgs::PoseStamped result;
  result.header.frame_id = origin_to_intermediate.header.frame_id;
  result.pose = calculatePoseRelativeToPose(origin_to_intermediate.pose, intermediate_to_target);
  return result;
}

geometry_msgs::Pose calculatePoseRelativeToTransform(const geometry_msgs::Transform &origin_to_intermediate, const geometry_msgs::Pose &intermediate_to_target){
  tf2::Vector3 translation;
  tf2::Quaternion rotation;
  transformRelative(msgs::extractVector(origin_to_intermediate), msgs::extractQuaternion(origin_to_intermediate), msgs::extractVector(intermediate_to_target), msgs::extractQuaternion(intermediate_to_target), translation, rotation);
  return msgs::toPose(translation, rotation);
}

geometry_msgs::Transform calculateTransformRelativeToTransform(const geometry_msgs::Transform &origin_to_intermediate, const geometry_msgs::Transform &intermediate_to_target){
  tf2::Vector3 translation;
  tf2::Quaternion rotation;
  transformRelative(msgs::extractVector(origin_to_intermediate), msgs::extractQuaternion(origin_to_intermediate), msgs::extractVector(intermediate_to_target), msgs::extractQuaternion(intermediate_to_target), translation, rotation);
  return msgs::toTransform(translation, rotation);
}

void transformRelative(const tf2::Vector3 &origin_to_intermediate_t, const tf2::Quaternion &origin_to_intermediate_r, const tf2::Vector3 &intermediate_to_target_t, const tf2::Quaternion &intermediate_to_target_r,
                       tf2::Vector3 &translation_out, tf2::Quaternion &rotation_out){
  translation_out = origin_to_intermediate_t + utils::rotateVector(origin_to_intermediate_r, intermediate_to_target_t);
  rotation_out = origin_to_intermediate_r * intermediate_to_target_r;
}

}}

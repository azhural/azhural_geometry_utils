#ifndef AZGEO_TRANSFORMATIONS_H
#define AZGEO_TRANSFORMATIONS_H

#include <tf2/utils.h>

namespace azgeo { namespace transformations {

geometry_msgs::Pose calculatePoseRelativeToPose(const geometry_msgs::Pose &origin_to_intermediate, const geometry_msgs::Pose &intermediate_to_target);
geometry_msgs::PoseStamped calculatePoseRelativeToPoseStamped(const geometry_msgs::PoseStamped &origin_to_intermediate, const geometry_msgs::Pose &intermediate_to_target);

geometry_msgs::Pose calculatePoseRelativeToTransform(const geometry_msgs::Transform &origin_to_intermediate, const geometry_msgs::Pose &intermediate_to_target);

geometry_msgs::Transform calculateTransformRelativeToTransform(const geometry_msgs::Transform &origin_to_intermediate, const geometry_msgs::Transform &intermediate_to_target);

void transformRelative(const tf2::Vector3 &origin_to_intermediate_t, const tf2::Quaternion &origin_to_intermediate_r, const tf2::Vector3 &intermediate_to_target_t, const tf2::Quaternion &intermediate_to_target_r,
                       tf2::Vector3 &translation_out, tf2::Quaternion &rotation_out);

}}


#endif

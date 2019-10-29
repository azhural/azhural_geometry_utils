#ifndef AZGEO_UTILS_H
#define AZGEO_UTILS_H

#include <tf2/utils.h>

namespace azgeo { namespace utils {

tf2::Vector3 rotateVector(const tf2::Quaternion& quat, const tf2::Vector3 vector);

tf2::Quaternion homogenizeVector(const tf2::Vector3& vector);
tf2::Vector3 undoHomogenizeVector(const tf2::Quaternion& quat);

void getRPYfromQuaternion(const tf2::Quaternion& quat, tf2Scalar& roll, tf2Scalar& pitch, tf2Scalar& yaw);

}}

#endif

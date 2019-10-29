#include <azhural_geometry_utils/utils.h>

namespace azgeo { namespace utils {

tf2::Vector3 rotateVector(const tf2::Quaternion& quat, const tf2::Vector3 vector){
  return undoHomogenizeVector(quat * homogenizeVector(vector) * quat.inverse());
}

tf2::Quaternion homogenizeVector(const tf2::Vector3& vector){
  return tf2::Quaternion{vector.getX(), vector.getY(), vector.getZ(), 0};
}
tf2::Vector3 undoHomogenizeVector(const tf2::Quaternion& quat){
  return tf2::Vector3{quat.getX(), quat.getY(), quat.getZ()};
}

void getRPYfromQuaternion(const tf2::Quaternion& quat, tf2Scalar& roll, tf2Scalar& pitch, tf2Scalar& yaw){
  tf2::Matrix3x3 temp{quat};
  temp.getRPY(roll, pitch, yaw);
}

}}

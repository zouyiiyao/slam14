#include <iostream>
#include <cmath>

using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

int main(int argc, char** argv) {
  
  Matrix3d rotation_matrix = Matrix3d::Identity();
  
  // 旋转向量
  AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1));  // 沿Z轴旋转45度
  cout.precision(3);
  cout << "rotation matrix =\n" << rotation_vector.matrix() << endl;
  rotation_matrix = rotation_vector.toRotationMatrix();
  
  // 用旋转向量可以进行坐标变换
  Vector3d v(1, 0, 0);
  Vector3d v_rotated = rotation_vector * v;
  cout << "(1, 0, 0) after rotation (by angle axis) = " << v_rotated.transpose() << endl;
  v_rotated = rotation_matrix * v;
  cout << "(1, 0, 0) after rotation (by matrix) = " << v_rotated.transpose() << endl;
  
  // 欧拉角
  Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);  // ZYX顺序
  cout << "yaw-pitch-roll = " << euler_angles.transpose() << endl;
  
  // 欧式变换
  Isometry3d T = Isometry3d::Identity();  // 虽然称为3d，但实质上是4 * 4 矩阵（旋转+平移）
  T.rotate(rotation_vector);              // 按照rotation_vector进行旋转
  T.pretranslate(Vector3d(1, 3, 4));      // 将平移向量设为(1, 3, 4)
  cout << "Transform matrix = \n" << T.matrix() << endl;
  Vector3d v_transformed = T * v;         // 坐标变换，相当于R * v + t
  cout << "v transformed = " << v_transformed.transpose() << endl;
  
  // 对于仿射变换和射影变换，使用Eigen::Affine3d和Eigen::Projective3d
  
  // 四元数
  Quaterniond q = Quaterniond(rotation_vector);
  cout << "quaternion from rotation vector = " << q.coeffs().transpose() << endl;
  q = Quaterniond(rotation_matrix);
  cout << "quaternion from rotation matrix = " << q.coeffs().transpose() << endl;
  // 使用四元数旋转一个向量，使用重载的乘法即可
  v_rotated = q * v;  // 注意数学上是qvq^-1
  cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << endl;
  cout << "should be equal to " << (q * Quaterniond(0, 1, 0 ,0) * q.inverse()).coeffs().transpose() << endl;

  return 0;
}
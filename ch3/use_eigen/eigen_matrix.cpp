/*
 * eigen库的使用，类似matlab
 */

#include <iostream>
#include <ctime>
/* Eigen核心部分 */
#include <Eigen/Core>
/* 稠密矩阵的代数运算（求逆、特征值等） */
#include <Eigen/Dense>

using namespace Eigen;

#define MATRIX_SIZE 100

int main(int argc, char** argv) {
  Matrix<float, 2, 3> matrix_23;
  
  
  Vector3d v_3d;    // Matrix<Double, 3, 1>
  Matrix<float, 3, 1> vd_3d;
  
  Matrix3d matrix_33 = Matrix3d::Zero();
  /* 动态大小的矩阵 */
  Matrix<double, Dynamic, Dynamic> matrix_dynamic;
  MatrixXd matrix_x;
  

  /* 初始化 */
  matrix_23 << 1, 2, 3, 4, 5, 6;
  std::cout << "matrix 2x3 from 1 to 6: \n" << matrix_23 << std::endl;
  
  /* 用()访问矩阵中的元素 */
  std::cout << "print matrix 2x3: " << std::endl;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << matrix_23(i, j) << "\t";
    }
    std::cout << std::endl;
  }
  
  v_3d << 3, 2, 1;
  vd_3d << 4, 5, 6;
  
  Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
  std::cout << "[1, 2, 3; 4, 5, 6;] * [3, 2, 1]: " << result.transpose() << std::endl;
  
  Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
  std::cout << "[1, 2, 3; 4, 5, 6;] * [4, 5, 6]: " <<result2.transpose() << std::endl;
  
  /* 矩阵运算 */
  matrix_33 = Matrix3d::Random();
  std::cout << "random_matrix: \n" << matrix_33 << std::endl;
  std::cout << "transpose: \n" << matrix_33.transpose() << std::endl;
  std::cout << "sum: \n" << matrix_33.sum() << std::endl;
  std::cout << "trace: \n" << matrix_33.trace() << std::endl;
  std::cout << "x10: \n" << 10 * matrix_33 << std::endl;
  std::cout << "inverse: \n" << matrix_33.inverse() << std::endl;
  std::cout << "det: \n" << matrix_33.determinant() << std::endl;
  
  /* 求特征值 */
  SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose() * matrix_33);
  std::cout << "Eigen values: \n" << eigen_solver.eigenvalues() << std::endl;
  std::cout << "Eigen vectors: \n" << eigen_solver.eigenvectors() << std::endl;
  
  /* 解方程 matrix_NN * x = v_Nd */
  Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
  matrix_NN = matrix_NN * matrix_NN.transpose();    // 保证半正定
  Matrix<double, MATRIX_SIZE, 1> v_Nd = MatrixXd::Random(MATRIX_SIZE, 1);
  
  std::clock_t time_stt = std::clock();
  /* 直接求逆 */
  Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse() * v_Nd;
  std::cout << "time of normal inverse is " << 1000 * (std::clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << std::endl;
  std::cout << "x = " << x.transpose() << std::endl;
  
  /* QR分解 */
  time_stt = std::clock();
  x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
  std::cout << "time of QR decomposition is " << 1000 * (std::clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << std::endl;
  std::cout << "x = " << x.transpose() << std::endl;
  
  /* 对于正定矩阵，还可以用cholesky分解 */
  time_stt = std::clock();
  x = matrix_NN.ldlt().solve(v_Nd);
  std::cout << "time of ldlt decomposition is " << 1000 * (std::clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << std::endl;
  std::cout << "x = " << x.transpose() << std::endl;
  return 0;
}

#include "matrix_ops.h"
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

// 调用 Eigen 库：将原始二维数组转换为 Eigen 矩阵，
// 用 Eigen 内置运算独立验证“转置”和“主对角线之和”的结果。
void EigenVerify(int myArray[][M], int size) {
    // 把 C++ 二维数组的数据载入到 Eigen 的整型矩阵中
    MatrixXi mat(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mat(i, j) = myArray[i][j];
        }
    }

    cout << "\n===== 使用 Eigen 库进行验证 =====" << endl;
    cout << "Eigen 读取到的矩阵：\n" << mat << endl;

    // 用 Eigen 的 transpose() 计算转置矩阵
    cout << "Eigen 计算的转置矩阵：\n" << mat.transpose() << endl;

    // 用 Eigen 的 trace() 计算主对角线元素之和
    cout << "Eigen 计算的主对角线之和（trace）：" << mat.trace() << endl;
}

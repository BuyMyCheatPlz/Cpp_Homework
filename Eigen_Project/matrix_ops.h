#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

#include <iostream>
#include <iomanip>

const int M = 3;  // 预定义矩阵维度（整型常量，可根据需要修改）

// 函数1：按行、列形式输出矩阵（使用setw控制格式）
void PrintArray(int myArray[][M], int rownum, int colnum);

// 函数2：计算主对角线元素之和 & 次对角线元素之积
void DiagonalOps(int myArray[][M], int size);

// 函数3：对矩阵第一行元素按升序冒泡排序
void SortFirstRow(int myArray[][M], int size);

// 函数4：获取并输出转置矩阵
void Transpose(int myArray[][M], int size);

// 调用 Eigen 库：将二维数组转为 Eigen 矩阵，验证转置与主对角线之和
// （在独立源文件 eigen_verify.cpp 中实现）
void EigenVerify(int myArray[][M], int size);

#endif
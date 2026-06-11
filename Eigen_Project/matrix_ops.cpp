#include "matrix_ops.h"
using namespace std;

// 函数1：按行、列形式输出矩阵（使用setw控制格式）
void PrintArray(int myArray[][M], int rownum, int colnum) {
    cout << "矩阵元素为：" << endl;
    for (int i = 0; i < rownum; i++) {
        for (int j = 0; j < colnum; j++) {
            cout << setw(6) << myArray[i][j];
        }
        cout << endl;
    }
}

// 函数2：计算主对角线元素之和 & 次对角线元素之积
void DiagonalOps(int myArray[][M], int size) {
    int mainDiagSum = 0;
    long long subDiagProd = 1;  // 用long long防止乘积溢出

    for (int i = 0; i < size; i++) {
        // 主对角线：行号==列号
        mainDiagSum += myArray[i][i];
        // 次对角线：行号 + 列号 == size - 1
        subDiagProd *= myArray[i][size - 1 - i];
    }

    cout << "主对角线元素之和为：" << mainDiagSum << endl;
    cout << "次对角线元素之积为：" << subDiagProd << endl;
}

// 函数3：对矩阵第一行元素按升序冒泡排序
void SortFirstRow(int myArray[][M], int size) {
    // 冒泡排序：升序排列第一行
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (myArray[0][j] > myArray[0][j + 1]) {
                int temp = myArray[0][j];
                myArray[0][j] = myArray[0][j + 1];
                myArray[0][j + 1] = temp;
            }
        }
    }
    cout << "第一行冒泡排序后：" << endl;
    for (int j = 0; j < size; j++) {
        cout << setw(6) << myArray[0][j];
    }
    cout << endl;
}

// 函数4：获取并输出转置矩阵
void Transpose(int myArray[][M], int size) {
    cout << "转置矩阵为：" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(6) << myArray[j][i];  // 行列互换输出
        }
        cout << endl;
    }
}
#include "matrix_ops.h"
#include <limits>  // std::numeric_limits，用于清空输入缓冲区
#ifdef _WIN32
#include <windows.h>  // Windows 下设置控制台代码页，解决中文乱码
#endif
using namespace std;

int main() {
#ifdef _WIN32
    // 源码以 UTF-8 保存，将控制台输出/输入代码页也设为 UTF-8(65001)，避免中文乱码
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    int myArray[M][M];  // 二维数组存放输入数据

    // 键盘输入：按先行后列顺序输入各元素
    cout << "请输入" << M << "×" << M << "矩阵的各个元素（按先行后列顺序）：" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> myArray[i][j];
        }
    }

    // 功能1：按行、列形式输出显示矩阵元素
    PrintArray(myArray, M, M);

    // 功能2：计算并输出主对角线元素之和、次对角线元素之积
    DiagonalOps(myArray, M);

    // 调用 Eigen 库：在排序改动数组之前，独立验证主对角线之和与转置
    EigenVerify(myArray, M);

    // 功能3：对矩阵第一行元素按升序冒泡排序
    SortFirstRow(myArray, M);

    // 功能4：获取该矩阵的转置矩阵，并输出显示
    Transpose(myArray, M);

    // 程序结束前暂停，避免外部控制台窗口立即关闭、看不到输出
    cout << "\n按回车键退出……";
    cin.clear();  // 清除可能的错误状态
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃上次输入残留的换行符
    cin.get();    // 等待用户按下回车
    return 0; 
}

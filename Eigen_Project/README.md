# 矩阵运算程序（调用 Eigen 库）

一个 C++ 多文件程序：从键盘读入一个 `M×M` 整数矩阵，用四个独立函数完成
**打印、对角线计算、第一行排序、转置**四项功能，并额外调用 **Eigen 数学库**
独立验算转置与主对角线之和。

---

## 目录

- [项目结构](#项目结构)
- [整体数据流](#整体数据流)
- [逐行解释](#逐行解释)
  - [matrix_ops.h —— 头文件（接口契约）](#matrix_opsh--头文件接口契约)
  - [main.cpp —— 主控流程](#maincpp--主控流程)
  - [matrix_ops.cpp —— 四个功能函数](#matrix_opscpp--四个功能函数)
  - [eigen_verify.cpp —— Eigen 验算](#eigen_verifycpp--eigen-验算)
- [关键设计点](#关键设计点)
- [编译与运行](#编译与运行)

---

## 项目结构

```
Eigen_Project/
├── matrix_ops.h       接口契约：常量 M、五个函数的声明。三个 .cpp 都包含它
├── main.cpp           主控：读输入 → 依次调用各函数 → 暂停退出
├── matrix_ops.cpp     四个功能函数的实现（纯 C++，不依赖 Eigen）
└── eigen_verify.cpp   用 Eigen 库独立验算（transpose / trace）
```

> 满足题目“多文件结构”要求：**3 个源文件（.cpp）+ 1 个头文件（.h）**。

---

## 整体数据流

```
键盘输入 M×M 个整数
        │
        ▼
  int myArray[M][M]      ← 唯一一份二维数组，靠"参数传递"在函数间共享
        │
        ├─► PrintArray    打印矩阵
        ├─► DiagonalOps   主对角线求和 / 次对角线求积
        ├─► EigenVerify   ★ 排序前：用 Eigen 复算（看到的是原始矩阵）
        ├─► SortFirstRow  把第一行就地冒泡排序（会改动数组！）
        └─► Transpose     打印转置矩阵
```

---

## 逐行解释

### `matrix_ops.h` —— 头文件（接口契约）

```cpp
#ifndef MATRIX_OPS_H        // 头文件保护：若未定义过该宏……
#define MATRIX_OPS_H        // ……就定义它，防止本头文件被重复包含（多个 .cpp 都 include 时只展开一次）

#include <iostream>         // 提供 cout / cin（声明里、各 .cpp 都要用到）
#include <iomanip>          // 提供 setw（输出对齐）

const int M = 3;            // 矩阵维度。用 const int 而非 #define，避免宏 M 与 Eigen 内部 template<int M> 冲突

// 五个函数的"声明"（只说明长相，不含实现）。形参 int myArray[][M] 必须写明列数 M
void PrintArray(int myArray[][M], int rownum, int colnum);  // 函数1：打印矩阵
void DiagonalOps(int myArray[][M], int size);               // 函数2：对角线求和/求积
void SortFirstRow(int myArray[][M], int size);              // 函数3：第一行升序冒泡排序
void Transpose(int myArray[][M], int size);                 // 函数4：打印转置
void EigenVerify(int myArray[][M], int size);               // 附加：Eigen 验算（实现在 eigen_verify.cpp）

#endif                      // 结束头文件保护
```

**要点**
- `#ifndef / #define / #endif` 是**头文件保护符**，保证内容只被编译一次。
- `const int M = 3`：之所以**不用 `#define M 3`**，是因为宏会做文本替换，会把 Eigen 源码里
  `template<int M>` 的 `M` 也替换成 `3`，导致编译报错。`const int` 不做文本替换，安全。
- 形参写成 `int myArray[][M]`：C++ 传二维数组时**必须指明列数**，编译器才知道每行有多宽、
  如何用 `[i][j]` 定位元素。这正是题目强调的知识点。

---

### `main.cpp` —— 主控流程

```cpp
#include "matrix_ops.h"     // 引入五个函数声明和常量 M
#include <limits>           // 提供 numeric_limits，用于清空输入缓冲区
#ifdef _WIN32               // 仅在 Windows 平台编译以下内容（换平台不报错）
#include <windows.h>        // 提供 SetConsoleOutputCP / SetConsoleCP
#endif
using namespace std;        // 省去 std:: 前缀，可直接写 cout / cin

int main() {
#ifdef _WIN32
    // 源码以 UTF-8 保存；Windows 控制台默认按 GBK 解读会乱码，故把控制台代码页也设为 UTF-8(65001)
    SetConsoleOutputCP(65001);  // 输出端切 UTF-8（解决中文乱码"璇疯緭鍏"）
    SetConsoleCP(65001);        // 输入端切 UTF-8
#endif

    int myArray[M][M];      // 声明 M×M 二维数组，存放即将输入的矩阵

    // 提示并按"先行后列"顺序读入 M×M 个整数
    cout << "请输入" << M << "×" << M << "矩阵的各个元素（按先行后列顺序）：" << endl;
    for (int i = 0; i < M; i++) {        // 外层循环：逐行
        for (int j = 0; j < M; j++) {    // 内层循环：逐列
            cin >> myArray[i][j];        // 读一个整数存入第 i 行第 j 列（空格/回车/Tab 均可分隔）
        }
    }

    PrintArray(myArray, M, M);   // 功能1：打印矩阵（行数、列数都是 M）
    DiagonalOps(myArray, M);     // 功能2：算主对角线和、次对角线积
    EigenVerify(myArray, M);     // 附加：在排序"之前"用 Eigen 复算，保证它看到的是原始矩阵
    SortFirstRow(myArray, M);    // 功能3：把第一行就地排序（此后数组第一行已被改动）
    Transpose(myArray, M);       // 功能4：打印转置矩阵

    // 收尾：让外部控制台窗口停住，否则跑完一闪就关、看不到结果
    cout << "\n按回车键退出……";
    cin.clear();                                        // 清掉流的错误状态（保险）
    cin.ignore(numeric_limits<streamsize>::max(), '\n');// 丢弃上次 cin>> 残留在缓冲区的换行符
    cin.get();                                          // 阻塞等待用户按下回车

    return 0;               // 返回 0 表示程序正常结束
}
```

**为什么需要那段 `cin.clear() / ignore / get`？**
前面用 `cin >> ` 读数字时，回车键留下的换行符 `\n` 还留在缓冲区。
若直接 `cin.get()`，会立刻读到这个残留换行、根本停不住。
所以先 `ignore` 把残留清空，`cin.get()` 才能真正等用户按键。

---

### `matrix_ops.cpp` —— 四个功能函数

```cpp
#include "matrix_ops.h"     // 引入声明，保证定义与声明一致
using namespace std;
```

#### 函数 1：`PrintArray` —— 按行列打印

```cpp
void PrintArray(int myArray[][M], int rownum, int colnum) {
    cout << "矩阵元素为：" << endl;
    for (int i = 0; i < rownum; i++) {       // 逐行
        for (int j = 0; j < colnum; j++) {   // 逐列
            cout << setw(6) << myArray[i][j];// setw(6)：每个元素占 6 字符宽、右对齐，列对齐美观
        }
        cout << endl;                        // 每打印完一行换行
    }
}
```

#### 函数 2：`DiagonalOps` —— 对角线求和 / 求积

```cpp
void DiagonalOps(int myArray[][M], int size) {
    int mainDiagSum = 0;          // 主对角线累加器，初值 0（加法单位元）
    long long subDiagProd = 1;    // 次对角线累乘器，初值 1（乘法单位元）；用 long long 防乘积溢出

    for (int i = 0; i < size; i++) {
        mainDiagSum += myArray[i][i];               // 主对角线：行号==列号，即 (0,0)(1,1)(2,2)
        subDiagProd *= myArray[i][size - 1 - i];    // 次对角线：行号+列号==size-1，即 (0,2)(1,1)(2,0)
    }

    cout << "主对角线元素之和为：" << mainDiagSum << endl;
    cout << "次对角线元素之积为：" << subDiagProd << endl;
}
```
- **主对角线**（左上→右下）：下标特点是 `行 == 列`，用 `myArray[i][i]`。
- **次对角线**（右上→左下）：下标特点是 `行 + 列 == size-1`，用 `myArray[i][size-1-i]`。
- 求和初值取 `0`、求积初值取 `1`，这样第一次运算结果正确。

#### 函数 3：`SortFirstRow` —— 第一行升序冒泡排序

```cpp
void SortFirstRow(int myArray[][M], int size) {
    for (int i = 0; i < size - 1; i++) {              // 冒泡趟数：n 个元素最多 n-1 趟
        for (int j = 0; j < size - 1 - i; j++) {      // 每趟两两比较；-i 因为末尾 i 个已就位
            if (myArray[0][j] > myArray[0][j + 1]) {  // 前者大于后者 → 逆序，需交换
                int temp = myArray[0][j];             // 经典三步交换：暂存
                myArray[0][j] = myArray[0][j + 1];    //   后者前移
                myArray[0][j + 1] = temp;             //   暂存值后移
            }
        }
    }
    cout << "第一行冒泡排序后：" << endl;             // 打印排序后的第一行
    for (int j = 0; j < size; j++) {
        cout << setw(6) << myArray[0][j];
    }
    cout << endl;
}
```
- 只操作第一行 `myArray[0][...]`，**就地修改**原数组。
- 冒泡：相邻两两比较，大的逐步"冒"到右端；每趟末尾 `i` 个元素已排好，故内层界限 `size-1-i`。

#### 函数 4：`Transpose` —— 打印转置矩阵

```cpp
void Transpose(int myArray[][M], int size) {
    cout << "转置矩阵为：" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(6) << myArray[j][i];  // 关键：输出时把行列下标对调 [j][i] 即得转置
        }
        cout << endl;
    }
}
```
- 转置 = 行列互换。这里**不另开数组**，而是在打印时把下标从 `[i][j]` 写成 `[j][i]`，
  直接按转置后的顺序输出。

---

### `eigen_verify.cpp` —— Eigen 验算

```cpp
#include "matrix_ops.h"     // 引入 M 和 EigenVerify 的声明
#include <Eigen/Dense>      // Eigen 库主头文件（矩阵类与运算）
using namespace std;
using namespace Eigen;      // 省去 Eigen:: 前缀，可直接写 MatrixXi

void EigenVerify(int myArray[][M], int size) {
    MatrixXi mat(size, size);            // 创建一个 size×size 的整型 Eigen 矩阵（XI = X 动态尺寸 + Integer）
    for (int i = 0; i < size; i++) {     // 把原始二维数组的数据……
        for (int j = 0; j < size; j++) {
            mat(i, j) = myArray[i][j];   // ……逐个拷贝进 Eigen 矩阵（注意 Eigen 用圆括号 (i,j) 访问元素）
        }
    }

    cout << "\n===== 使用 Eigen 库进行验证 =====" << endl;
    cout << "Eigen 读取到的矩阵：\n" << mat << endl;          // Eigen 矩阵可直接 << 输出

    cout << "Eigen 计算的转置矩阵：\n" << mat.transpose() << endl;  // .transpose() 一步求转置，验证函数4
    cout << "Eigen 计算的主对角线之和（trace）：" << mat.trace() << endl; // .trace() 求迹=主对角线和，验证函数2
}
```

**Eigen 在本程序中的角色 = 独立裁判**
四个功能函数按题目要求必须用**原始二维数组**手写实现，Eigen 不参与它们；
它把数组复制进 `MatrixXi`，用库自带的 `.transpose()`（转置）和 `.trace()`（主对角线和）
**再算一遍**，与手写结果对照——两边一致即证明手写逻辑正确。

| 手写函数 | Eigen 对应 | 验证内容 |
|----------|------------|----------|
| `Transpose` | `mat.transpose()` | 转置矩阵 |
| `DiagonalOps`（主对角线和） | `mat.trace()` | 主对角线元素之和 |

---

## 关键设计点

1. **二维数组靠参数传递、形参写明列数 `int myArray[][M]`** —— 题目核心知识点。
   全程只有一份 `myArray`，所有函数共享同一份数据。

2. **`EigenVerify` 放在 `SortFirstRow` 之前调用**
   因为 `SortFirstRow` 会**就地改动**数组第一行。若 Eigen 在排序后才读数据，
   它算出的主对角线和会与 `DiagonalOps` 的结果不一致，看起来像 bug。
   放在排序前，两者都基于原始矩阵，数字才能对得上。

3. **`const int M` 而非 `#define M`** —— 避免宏的文本替换破坏 Eigen 内部的 `template<int M>`。

4. **跨平台中文 & 暂停** —— `SetConsoleOutputCP(65001)` 解决 UTF-8 乱码；
   末尾 `cin.get()` 防止窗口一闪而过。

---

## 编译与运行

需要 MSYS2 UCRT64 的 g++，以及 Eigen 头文件（位于 `C:\Eigen`）。

```bash
# 关键：先把 ucrt64\bin 顶到 PATH 最前，否则 g++ 的 cc1plus 找不到依赖 DLL
set PATH=C:\msys64\ucrt64\bin;%PATH%

# 静态链接（-static）把 C++ 运行时打进 exe，避免与系统其它旧版 libstdc++ 冲突
g++ -g -std=c++11 -static -I C:\Eigen main.cpp matrix_ops.cpp eigen_verify.cpp -o matrix.exe
```

或直接运行项目里的 `build.bat`。在 VS Code 中按 **F5** 可自动编译并进入断点调试。

### 输入格式

总共输入 `M×M`（默认 9）个整数，**空格、Tab、回车均可作分隔**（不要用逗号）。例如：

```
3 1 2
9 8 7
4 6 5
```

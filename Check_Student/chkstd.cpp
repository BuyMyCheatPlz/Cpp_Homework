#include "chkstd.h"
#include <iostream>
#include <iomanip>
#include <cstring>      // strcmp：比较字符串是否相同
#ifdef _WIN32
#include <windows.h>    // 设置控制台代码页，避免中文乱码
#endif
using namespace std;

// 功能1：按行列形式输出显示所有学生信息（每行一个学生）
void PrintStudents(const Student *stu, int count) {
    cout << "\n===== 全部学生信息 =====" << endl;
    // 表头
    cout << left << setw(8) << "序号"
         << setw(20) << "姓名(Name)"
         << setw(8) << "年龄"
         << setw(12) << "性别(Gender)" << endl;
    // 逐行输出每个学生（stu[i] 等价于 *(stu + i)，基于指针访问结构数组元素）
    for (int i = 0; i < count; i++) {
        cout << left << setw(8) << (i + 1)
             << setw(20) << stu[i].name
             << setw(8) << stu[i].age
             << setw(12) << stu[i].gender << endl;
    }
}

// 功能2：按姓名查找学生
void SearchStudent(const Student *stu, int count, const char *target) {
    for (int i = 0; i < count; i++) {
        // strcmp 返回 0 表示两个字符串完全相同
        if (strcmp(stu[i].name, target) == 0) {
            cout << "\n找到该学生：" << endl;
            cout << "姓名：" << stu[i].name
                 << "  年龄：" << stu[i].age
                 << "  性别：" << stu[i].gender << endl;
            return;  // 找到即返回，不再继续查找
        }
    }
    // 循环结束仍未找到
    cout << "\n该学生（" << target << "）不存在。" << endl;
}

int main() {
#ifdef _WIN32
    // 源码以 UTF-8 保存，将控制台代码页设为 UTF-8(65001)，避免中文乱码
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    int n = 0;
    cout << "请输入学生的个数：";
    cin >> n;
    if (n <= 0) {
        cout << "学生个数必须为正整数，程序结束。" << endl;
        return 0;
    }

    // 根据学生个数动态申请内存（new 申请，结束前用 delete[] 释放）
    Student *stu = new Student[n];

    // 逐个输入学生信息
    for (int i = 0; i < n; i++) {
        cout << "\n请输入第 " << (i + 1) << " 个学生的信息：" << endl;
        cout << "  姓名(name)：";
        cin >> stu[i].name;       // 读入字符串到 char 数组（遇空白停止）
        cout << "  年龄(age)：";
        cin >> stu[i].age;
        cout << "  性别(gender)：";
        cin >> stu[i].gender;
    }

    // 功能1：输出显示所有学生信息
    PrintStudents(stu, n);

    // 功能2：查找
    char target[32];
    cout << "\n请输入要查找的学生姓名：";
    cin >> target;
    SearchStudent(stu, n, target);

    // 释放动态申请的内存
    delete[] stu;
    stu = nullptr;

    // 收尾暂停，避免外部控制台窗口立即关闭
    cout << "\n按回车键退出……";
    cin.ignore();   // 丢弃上次输入残留的换行符
    cin.get();      // 等待用户按回车
    return 0;
}

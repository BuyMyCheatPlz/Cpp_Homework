#ifndef CHKSTD_H
#define CHKSTD_H

// 学生信息结构体
// 姓名、性别为 char[] 类型，年龄为 int 类型（按题目要求）
struct Student {
    char name[32];    // 姓名（建议英文，最长 31 个字符 + 结束符）
    int  age;         // 年龄
    char gender[16];  // 性别（建议英文，如 male / female）
};

// 功能1：按行列形式输出显示所有学生信息（每行一个学生）
// 参数：stu 指向学生数组首元素的指针；count 学生个数
void PrintStudents(const Student *stu, int count);

// 功能2：按姓名查找学生；找到则显示其信息，否则提示不存在
// 参数：stu 学生数组指针；count 学生个数；target 待查找的姓名
void SearchStudent(const Student *stu, int count, const char *target);

#endif

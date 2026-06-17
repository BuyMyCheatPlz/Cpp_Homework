#ifndef MYSTRING_H
#define MYSTRING_H

class MyString {
private:
    char* data;     // 指向动态申请的字符数组空间
    int maxSize;    // 字符数组空间的大小

public:
    // 构造函数1：无形参，申请大小为1的空字符串空间
    MyString();

    // 构造函数2：带const char*形参，申请恰能存放str的空间并复制
    MyString(const char* str);

    // 析构函数：释放动态申请的空间
    ~MyString();

    // 返回当前的字符串长度（不含'\0'）
    int getLength() const;

    // 返回当前的字符数组空间大小
    int getMaxSize() const;

    // 判断字符串是否为空串
    bool isEmpty() const;

    // 获取并返回指向当前字符串的指针
    char* getString() const;

    // 将原来的字符串修改为str所指向的字符串
    void setString(const char* str);

    // 输出显示当前字符串内容
    void printString() const;
};

#endif
#include "MyString.h"
#include <cstring>
#include <iostream>

// 构造函数1：无形参，申请大小为1且存放空字符串的字符数组空间
MyString::MyString() {
    maxSize = 1;
    data = new char[maxSize];
    data[0] = '\0';
}

// 构造函数2：带const char*形参，申请恰能存放str的空间并复制
MyString::MyString(const char* str) {
    int len = std::strlen(str);
    maxSize = len + 1;          // +1 for '\0'
    data = new char[maxSize];
    std::strcpy(data, str);
}

// 析构函数：释放动态申请的空间
MyString::~MyString() {
    delete[] data;
}

// 返回当前的字符串长度（不含'\0'）
int MyString::getLength() const {
    return std::strlen(data);
}

// 返回当前的字符数组空间大小
int MyString::getMaxSize() const {
    return maxSize;
}

// 判断字符串是否为空串
bool MyString::isEmpty() const {
    return (data[0] == '\0');
}

// 获取并返回指向当前字符串的指针
char* MyString::getString() const {
    return data;
}

// 将原来的字符串修改为str所指向的字符串
void MyString::setString(const char* str) {
    int newLen = std::strlen(str);
    int newMaxSize = newLen + 1;

    // 若原有空间能存放得下新字符串，则直接存入
    if (newMaxSize <= maxSize) {
        std::strcpy(data, str);
    } else {
        // 否则重新申请恰能存入新字符串的空间
        delete[] data;
        maxSize = newMaxSize;
        data = new char[maxSize];
        std::strcpy(data, str);
    }
}

// 输出显示当前字符串内容
void MyString::printString() const {
    std::cout << data << std::endl;
}
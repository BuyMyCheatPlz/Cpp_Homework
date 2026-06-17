#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    cout << "===== 测试构造函数1（无参数）：创建空字符串对象 s1 =====" << endl;
    MyString s1;
    cout << "s1 内容: ";
    s1.printString();
    cout << "s1 长度: " << s1.getLength() << endl;
    cout << "s1 空间大小: " << s1.getMaxSize() << endl;
    cout << "s1 是否为空: " << (s1.isEmpty() ? "是" : "否") << endl;
    cout << "s1 字符串指针内容: " << s1.getString() << endl;
    cout << endl;

    cout << "===== 测试构造函数2（带参数）：用 \"Hello\" 创建 s2 =====" << endl;
    MyString s2("Hello");
    cout << "s2 内容: ";
    s2.printString();
    cout << "s2 长度: " << s2.getLength() << endl;
    cout << "s2 空间大小: " << s2.getMaxSize() << endl;
    cout << "s2 是否为空: " << (s2.isEmpty() ? "是" : "否") << endl;
    cout << endl;

    cout << "===== 测试构造函数2（带参数）：用空字符串 \"\" 创建 s3 =====" << endl;
    MyString s3("");
    cout << "s3 内容: ";
    s3.printString();
    cout << "s3 长度: " << s3.getLength() << endl;
    cout << "s3 空间大小: " << s3.getMaxSize() << endl;
    cout << "s3 是否为空: " << (s3.isEmpty() ? "是" : "否") << endl;
    cout << endl;

    cout << "===== 测试 setString：将 s1 从空串改为 \"World\" =====" << endl;
    cout << "修改前 s1 空间大小: " << s1.getMaxSize() << endl;
    s1.setString("World");
    cout << "修改后 s1 内容: ";
    s1.printString();
    cout << "修改后 s1 长度: " << s1.getLength() << endl;
    cout << "修改后 s1 空间大小: " << s1.getMaxSize() << endl;
    cout << "修改后 s1 是否为空: " << (s1.isEmpty() ? "是" : "否") << endl;
    cout << endl;

    cout << "===== 测试 setString：空间够用时直接存入（\"Hi\" 放入原空间）=====" << endl;
    cout << "s1 当前空间大小: " << s1.getMaxSize() << "，当前内容: ";
    s1.printString();
    s1.setString("Hi");
    cout << "setString(\"Hi\") 后 s1 内容: ";
    s1.printString();
    cout << "s1 长度: " << s1.getLength() << endl;
    cout << "s1 空间大小: " << s1.getMaxSize() << "（应仍为6）" << endl;
    cout << endl;

    cout << "===== 测试 setString：空间不够时重新申请（\"C++ Programming\"）=====" << endl;
    cout << "s1 当前空间大小: " << s1.getMaxSize() << endl;
    s1.setString("C++ Programming");
    cout << "setString 后 s1 内容: ";
    s1.printString();
    cout << "s1 长度: " << s1.getLength() << endl;
    cout << "s1 空间大小: " << s1.getMaxSize() << endl;
    cout << endl;

    cout << "===== 测试 getString 返回的指针可直接操作 =====" << endl;
    char* p = s2.getString();
    cout << "通过 getString 获取的 s2 内容: " << p << endl;
    p[0] = 'M';  // 修改第一个字符
    cout << "修改首字符后 s2 内容: ";
    s2.printString();
    cout << endl;

    cout << "===== 全部测试完成 =====" << endl;
    return 0;
}
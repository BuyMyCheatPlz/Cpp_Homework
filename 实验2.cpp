#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    char char_val;
    cout<<"请输入一个字符：";
    cin>>char_val;
    if (char_val>='0' && char_val<='9')
    {
        cout<<"输入的是数字\n"<<"ascii码值为："<<(int)char_val<<endl;
    }
    else if ((char_val>='a' && char_val<='z'))
    {
        cout<<"输入的是小写字母\n"<<"ascii码值为："<<(int)char_val<<endl;
    }
        else if ((char_val>='A' && char_val<='Z'))
        {
            cout<<"输入的是大写字母\n"<<"ascii码值为："<<(int)char_val<<endl;
        }
    else
    {
        cout<<"输入的是其他字符\n"<<"ascii码值为："<<(int)char_val<<endl;
    }
    return 0;
}
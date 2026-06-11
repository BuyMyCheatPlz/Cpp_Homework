#include <iostream> 
#include<cmath>
#define PI 3.14159
using namespace std;
int main()
{
    double x;
    cout<<"请输入一个数：";
    cin>>x;
    double y=(3.0/7.0)*pow(((exp(sin(x))*log(x+1)))/(pow(x,2)+1),0.5)*PI*cos(32*(PI/180));
    cout<<"计算结果为："<<y<<endl;
    return 0;
}
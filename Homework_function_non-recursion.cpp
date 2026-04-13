#include <iostream>
#include <cmath>
using namespace std;
double function(double x, int n)
{
    if (n==0)
{
    return 1;
}
if (n==1)
{
    return x;
}
double p0=1;
double p1=x;
double pn=0;
for(int k=2;k<=n;k++)
{
    pn=((2*k-1)*x*p1-(k-1)*p0)/k;
    p0=p1;
    p1=pn;
}
return pn;
}
int main()
{
    double x;
    int n;
    cout<<"请输入x的值：";
    cin>>x;
    cout<<"请输入n的值：";
    cin>>n;
    cout<<"函数值为："<<function(x,n)<<endl;
    return 0;
}
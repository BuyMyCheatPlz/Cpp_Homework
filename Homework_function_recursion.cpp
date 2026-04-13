#include <iostream>
using namespace std;

double function(double x, double n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    return ((2 * n - 1) * x * function(x, n - 1) - (n - 1) * function(x, n - 2)) / n;
}

int main()
{
    double x;
    int n;
    cout << "请输入x的值：";
    cin >> x;
    cout << "请输入n的值：";
    cin >> n;
    cout << "函数值为："
         << function(x, n) << endl;
    return 0;
}

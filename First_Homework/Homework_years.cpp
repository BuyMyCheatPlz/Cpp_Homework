#include <iostream>
#include <cmath>
using namespace std;

bool is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int datetodays(int year, int month, int day) {
    int days = 0;
    for (int i = 1; i < year; i++) {
        days += is_leap_year(i) ? 366 : 365;
    }
    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year)) {
        month_days[1] = 29; // February has 29 days in a leap year
    }
    for (int i = 0; i < month - 1; i++) {
        days += month_days[i];
    }
    days += day;
    return days;
}

int main(){
    int year, month, day,known_year, known_month, known_day,known_weekday;
    cout << "请输入年份：";
    cin >> year;
    cout << "请输入月份：";
    cin >> month;
    cout << "请输入日期：";
    cin >> day;
    cout << "请输入已知日期的年份：";
    cin >> known_year;
    cout << "请输入已知日期的月份：";
    cin >> known_month;
    cout << "请输入已知日期的日期：";
    cin >> known_day;
    cout << "请输入已知日期的星期几（0-6，0代表星期天，1代表星期一，以此类推）：";
    cin >> known_weekday;

    int target_days = datetodays(year, month, day);
    int known_days = datetodays(known_year, known_month, known_day);
    int days_difference = target_days - known_days;
    int result_weekday = (known_weekday + days_difference) % 7;
    if (result_weekday < 0) {
        result_weekday += 7;
    }

    cout << "目标日期的星期几是：" << result_weekday << endl;

    return 0;
}
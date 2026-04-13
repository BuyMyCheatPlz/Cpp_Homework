#include <iostream>
#include <cmath>
using namespace std;

double sin_taylor(double x, double accuracy, int& k) {
    double term = x; // First term of the series
    double sum = term; // Initialize sum with the first term
    k = 1;

    while (abs(term) > accuracy) {
        term *= -x * x / ((2 * k) * (2 * k + 1)); // Calculate the next term
        sum += term; // Add the new term to the sum
        ++k;
    }

    return sum;
}

int main() {
    double x, accuracy;
    int k;
    cout << "Enter the value of x (in radians): ";
    cin >> x;
    cout << "Enter the desired accuracy: ";
    cin >> accuracy;
    cout << "sin(" << x << ") = " << sin_taylor(x, accuracy, k) << endl;
    cout << "k = " << k << endl;
    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

const double eps = 1e-6;
double f(double a, double b, double c, double d, double x){
    return a * x * x * x + b * x * x + c * x + d;
}

int main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double l = -100000;
    double r = 100000;

    while (r - l > eps){
        double m = (l + r) / 2;
        if (f(a, b, c, d, l) * f(a, b, c, d, m) > 0){
            l = m;
        } else{
            r = m;
        }
    }
    cout << fixed << setprecision(12) << (l + r) / 2;
}
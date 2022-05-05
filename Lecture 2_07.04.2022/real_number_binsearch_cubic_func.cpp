#include <iostream>

double func(double a, double b, double c, double d, double x) { // функция, заданная на отрезке, можно заменить
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    double a;
    double b;
    double c;
    double d;
    std::cin >> a >> b >> c >> d; // коэффициенты, задаются тестами
    double epsilon = 1.0e-10; // подобранное эпсилон для нужной точности
    double left = -1001; // значение конца отрезка a
    double right = 1001; // значение конца отрезка b

    /* Здесь вместо цикла while и использования эпсилон можно "прикинуть", какова будет сложность наших операций и написать её в цикл for */

    while ((right - left) / 2 > epsilon) {
        double mid = (right + left) / 2;
        if (func(a, b, c, d, left) * func(a, b, c, d, mid) == 0) { // проверка на несовпадение корня с выбранным mid
            break;
        } else if (func(a, b, c, d, left) * func(a, b, c, d, mid) < 0) {
            right = mid;
        } else {
            left = mid;
        }
    }
    std::cout.precision(7); // ~ настройки нужной нам точности
    std::cout << (right + left) / 2; // делим ещё раз пополам — раз (right - left) / 2 > epsilon, корень лежит между ними
    return 0;
}


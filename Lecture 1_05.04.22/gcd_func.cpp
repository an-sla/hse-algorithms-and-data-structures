#include <iostream>

long long gcd_func(long long a, long long b) { // функция для нахождения НОДа
    if (a < b) { // находим большее из чисел (хотим, чтобы это была переменная "а")
        std::swap(a, b);
    }
    while (b != 0) { // применяем алгоритм Евклида — НОД(а, b) = НОД(b, r) : a = b * k + r
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a; // возвращаем оставшееся делимое
}

int main() {
    long long a;
    long long b;
    std::cin >> a >> b;
    std::cout << gcd_func(a, b) << std::endl;
    return 0;
}

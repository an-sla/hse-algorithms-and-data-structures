#include <iostream>

double pow(double number, long long power) {
    if (power == 0) {
        return 1;
    } else if (power % 2 == 0) {
        return pow(number * number, power / 2); // разделение степени на чётные
    } else {
        return number * (pow(number, (power - 1)));
        // один раз домножаем, избавляемся тем самым от нечётности, далее работаем с чётной степенью
    }
}


int main() {
    double number;
    long long power;
    std::cin >> number;
    std::cin >> power;
    std::cout << pow(number, power);
    return 0;
}

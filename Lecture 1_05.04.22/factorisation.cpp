#include <iostream>
#include <vector>

void factorise(int& number) {
    std::vector<int> factors;
    while (number % 2 == 0) { // пока имеем чётное делимое — делим на 2
        number /= 2; // делим число "inplace"
        factors.push_back(2);
    }
    for (long long i = 3; i * i <= number; i += 2) { // двигаемся с шагом +2, проходим до корня
        // за счёт предварительного деления на все предыдущие простые числа, у нас не будет отрабатывать цикл while на составных делителях
        while (number % i == 0) { // пока число делится на данное число — делим, получаем результат с учётом кратности
            number /= i;
            factors.push_back(i);
        }
    }
    for (int i : factors) {
        std::cout << i << ' ';
    }
    if (number != 1) {
        std::cout << number;
    }
}


int main() {
    int number;
    std::cin >> number;
    factorise(number);
    return 0;
}

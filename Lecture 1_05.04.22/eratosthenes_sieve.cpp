#include <iostream>
#include <vector>

std::vector<int> primes(std::vector<int>& p) {
    std::vector<int> list_of_all_primes; // список всех простых чисел
    for (size_t i = 2; i < p.size(); ++i) {
        if (p[i] == 1) { // случай — i = простое число
            list_of_all_primes.push_back(i);
            // здесь можно проходить по i + i:
            for (auto j = i * i; j < p.size(); j += i) {
                p[j] = 0; // вычёркиваем все множители до конца вектора p
            }
        }
    }
    return list_of_all_primes;
}

int main() {
    long long length;
    std::cin >> length;
    std::vector<int> p(1300000, 1); // список всех чисел, ограничения задаются тем, что 10^5-ое простое число — 1299709
    std::vector<int> list_of_all_primes = primes(p);
    for (size_t i = 0; i < length; ++i) {
        int a;
        std::cin >> a;
        // хотим — a–тое простое число, начиная с двойки (двойка — первое простое число):
        std::cout << list_of_all_primes[a-1] << ' ';
    }
    return 0;
}


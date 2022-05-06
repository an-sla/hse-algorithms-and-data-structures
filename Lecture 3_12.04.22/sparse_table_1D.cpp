#include <iostream>
#include <vector>


size_t lg2(size_t n) { // двоичный логарифм от числа, округлённый вниз
    int k = 0;
    while ((1 << k) <= n) {
        k++;
    }
    return k - 1;
}


int main() {
    size_t vect_size;
    std::cin >> vect_size;
    std::vector<size_t> a; // исходный вектор
    for (size_t i = 0; i < vect_size; ++i) {
        size_t temp;
        std::cin >> temp;
        a.push_back(temp);
    }
    std::vector<std::vector<size_t>> p (lg2(a.size()) + 1, std::vector<size_t>(a.size())); // sparse table, длину каждой строки делаем с прикидкой вверх a.size()
    p[0] = a;
    for (size_t l = 0; l < lg2(a.size()); ++l) {
        for (size_t i = 0; i + (2 << l) <= a.size(); ++i) { // побитовый сдвиг на l (2 * 2^l)
            p[l + 1][i] = std::min(p[l][i], p[l][i + (1 << l)]); // i + log2 (l) (логарифм — старший бит числа)
        }
    }
    int query_num;
    std::cin >> query_num;
    for (size_t i = 0; i < query_num; ++i) {
        size_t l;
        size_t r;
        std::cin >> l >> r;
        if (l - r == 0) {
            std::cout << a[l-1] << ' ';
        } else {
            size_t t = lg2(r - l);
            std::cout << std::min(p[t][l-1], p[t][r - (1 << t)]) << ' ';
        }
    }
    return 0;
}

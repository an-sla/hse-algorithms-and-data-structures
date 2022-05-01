#include <iostream>
#include <algorithm>
#include <cmath>


// Нерекурсивный GCD, необязательно привязывать к классу
int64_t gcd_func(int64_t a, int64_t b) {
    if (a < b) {
        std::swap(a, b);
    }
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


struct Tree {

    // текущий GCD:
    int64_t gcd = 0; // используем значение 0, так как для наших тестовых кейсов оно не будет приниматься
    // ссылки на предыдущие ноды:
    Tree* left = nullptr;
    Tree* right = nullptr;
    // обслуживаемые границы:
    int left_bound = 0;
    int right_bound = 0;

    // конструктор:
    Tree(int left_bound, int right_bound) {
        this->left_bound = left_bound;
        this->right_bound = right_bound;
        if (left_bound + 1 < right_bound) {
            int mid = (left_bound + right_bound) / 2;
            this->left = new Tree(left_bound, mid);
            this->right = new Tree(mid, right_bound);
        }
    }

    void add(int id, int64_t value) { // добавляем значения в дерево
        gcd = gcd_func(gcd, value);
        if (left != 0) {
            if (id < left->right_bound) {
                left->add(id, value);
            } else {
                right->add(id, value);
            }
        }
    }

    int64_t get_gcd(int left_query, int right_query) { // находим GCD по запросу
        if (left_bound >= left_query && right_bound <= right_query) {
            return gcd;
        } else if (std::max(left_query, left_bound) >= std::min(right_query, right_bound)) {
            return 0;
        } else {
            return gcd_func(left->get_gcd(left_query, right_query), right->get_gcd(left_query, right_query));
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(0); // отключаем синхронизацию между потоками (C, C++) — std::cout, printf
    // не надо использовать C–шный и C++–овский ввод/вывод в одной программе -> но это ускоряет ввод-вывод
    std::cin.tie(nullptr);
    int n = 0; // размер дерева
    int m = 0; // количество запросов
    int x = 0; // значение ноды
    int right_query = 0; // границы запросов — полуинтервалы начиная с 1
    int left_query = 0;
    std::cin >> n;
    Tree* t = new Tree(1, n+1);
    for (size_t i = 1; i <= n; ++i) {
        std::cin >> x;
        t->add(i, x);
    }
    std::cin >> m;
    std::string cmd;
    for (size_t i = 1; i <= m; ++i) {
        std::cin >> left_query >> right_query;
        std::cout << t->get_gcd(left_query, right_query + 1) << ' ';
    }
    return 0;
}

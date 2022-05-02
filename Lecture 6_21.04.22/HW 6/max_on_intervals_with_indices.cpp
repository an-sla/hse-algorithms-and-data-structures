#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>


struct Tree {
    // текущий макс:
    int64_t curr_max = -2e9; // сделает неявное приведение типов от double к int
    // индекс текущего максимума:
    int curr_max_index = 0;
    // ссылки на предыдущие ноды:
    Tree* left = 0;
    Tree* right = 0;
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
    // данный метод добавляет значение:
    void add(int id, int64_t value) {
        if (curr_max < value) {
            // заполняем и значение, и индекс:
            curr_max_index = id;
            curr_max = value;
        }
        if (left != 0) { // мы не в "листе" (есть потомки)
            if (id < left->right_bound) { // обращаемся к потомку, смотрим его правую границу
                // передаём id, value — рекурсивно спускаемся:
                left->add(id, value);
            } else {
                right->add(id, value);
            }
        }
    }

    std::pair<int, int> get_max(int left_query, int right_query) {
        if (left_query <= left_bound  && right_bound <= right_query) { // отрезок вошёл в запрос
            return std::pair<int, int> {curr_max, curr_max_index}; // значение вершины + индекс
        } else if (std::max(left_bound, left_query) >= std::min(right_bound, right_query)) {
            return std::pair<int, int> {-2e9, -1}; // возвращаем -inf, если отрезки не пересекаются (допустим, пользователь задал границы, которые полностью превышают количество листьев в дереве
            // также возвращаем -1 в качестве значения индекса максимума на несуществующем отрезке
        } else { // передаём запрос ниже
            // сейчас работаем с pairs — сначала находим их, затем ищем максимум из их первых элементов в развилке с if
            std::pair<int, int> left_res = left->get_max(left_query, right_query);
            std::pair<int, int> right_res = right->get_max(left_query, right_query);
            if (left_res.first > right_res.first) {
                return left_res;
            } else {
                return right_res;
            }
        }
    }

};

int main() {
    // оптимизация:
    std::ios_base::sync_with_stdio(0); // отключаем синхронизацию между потоками (C, C++) — std::cout, printf
    // не надо использовать C–шный и C++–овский ввод/вывод в одной программе -> но это ускоряет ввод-вывод
    std::cin.tie(NULL);

    // запуск для проверки
    int n = 0; // размер дерева
    int m = 0; // количество запросов
    int x = 0; // значение ноды
    int right_query = 0; // границы запросов — полуинтервалы начиная с 1
    int left_query = 0;
    std::cin >> n;
    Tree* t = new Tree(1, n+1);
    for (size_t i = 1; i <= n; ++i) { // составляем дерево из постепенно считываемых запросов
        std::cin >> x;
        t->add(i, x);
    }
    std::cin >> m;
    for (size_t i = 1; i <= m; ++i) {  // выполняем запросы на вывод максимума на под-отрезке
        std::cin >> left_query >> right_query;
        // "распаковываем" значения из pair:
        std::pair<int, int> res = t->get_max(left_query, right_query+1);
        std::cout << res.first << ' ' << res.second << std::endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cmath>


struct Tree {
    // текущая сумма:
    int64_t curr_sum = 0;
    int sign = 0;
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

    // данный метод добавляет значение в дерево:
    void add(int id, int64_t value) {
        if (id % 2 == 0) {
            sign = -1;
            curr_sum += (value * sign);
        } else {
            sign = 1;
            curr_sum += (value * sign);
        }
        // — пробавляем значение ячейки исходного массива, которая добавилась к интервалу потомков, обслуживаемому данной нодой
        if (left != 0) { // мы не в "листе" (есть потомки)
            if (id < left->right_bound) { // обращаемся к потомку, смотрим его правую границу
                // передаём id, value — рекурсивно спускаемся:
                left->add(id, value);
            } else {
                right->add(id, value);
            }
        }
    }

    // МЕТОД ДЛЯ ИЗМЕНЕНИЯ ОДНОГО ЭЛЕМЕНТА:
    void update(int element_number, int64_t value) {
        if (left_bound + 1 == right_bound) { // случай — лист
            // заменяем значение в листе
            curr_sum = (value * sign);
            return;
        } else {
            // идём по рёбрам графа, пока не настанет случай "лист":
            if (element_number < left->right_bound) {
                left->update(element_number, value);
            } else {
                right->update(element_number, value);
            }
            // заменяем значение в данной ноде, суммируя потомков "под ней":
            curr_sum = left->curr_sum + right->curr_sum;
        }
    }

    int64_t get_sum(int left_query, int right_query) {
        if (left_query <= left_bound && right_bound <= right_query) { // отрезок вошёл в запрос
            return curr_sum; // значение вершины
        } else if (std::max(left_query, left_bound) >= std::min(right_query, right_bound)) {
            return 0; // возвращаем 0, если не пересекаются (сумма — 0)
        } else {
            return (left->get_sum(left_query, right_query) + right->get_sum(left_query, right_query)); // передаём запрос ниже
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(0); // отключаем синхронизацию между потоками (C, C++) — std::cout, printf
    // не надо использовать C–шный и C++–овский ввод/вывод в одной программе -> но это ускоряет ввод-вывод
    std::cin.tie(NULL);
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
    int cmd;
    int value;
    for (size_t i = 1; i <= m; ++i) {
        std::cin >> cmd;
        // в качестве параметра update передаём номер изменяемого элемента и его новое значение
        if (cmd == 0) {
            std::cin >> left_query >> value;
            t->update(left_query, value);
        } else if (cmd == 1) {
            std::cin >> left_query >> right_query;
            int res = t->get_sum(left_query, right_query+1);
            if (left_query % 2 == 0) {
                res *= -1;
            }
            std::cout << res << std::endl;
        }
    }
    return 0;
}


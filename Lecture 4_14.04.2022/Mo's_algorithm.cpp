#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v = {1, 7, 2, 3, 7, 3, 8, 1, 2, 6, 7, 3, 4, 9, 3, 2 }; // пример вектора, для которого будут приходить запросы
int s = 0, a = 0, b = -1; // исходная сумма и указатели — на начало и конец вектора
int sz = 4; // sqrt(v_size) — надо для мысленного разбиения на "блоки"/"ячейки"

struct query { // запрос
    int id, l, r, res = 0;
    query(int _id, int _l, int _r) {
        this->id = _id; // для выдачи результатов в правильном порядке в конце
        this->l = _l;
        this->r = _r;
    };
};


void Mo(int l, int r) {
    // рассматриваем 4 случая — либо элементы надо добавлять, либо удалять в зависимости от отрезка
    while (l < a) {
        --a;
        s += v[a];
    }
    while (l > a) {
        s -= v[a];
        ++a;
    }
    while (r < b) {
        s -= v[b];
        --b;
    }
    while (r > b) {
        ++b;
        s += v[b];
    }
}

bool cmp(query a, query b) { // компаратор для структур query:
    if (a.l / sz == b.l / sz)
        return a.r < b.r; // сюда можно добавить условие, что чётные блоки мы будем сортировать по убыванию (например), а нечётные — по возрастанию
    else
        return a.l < b.l;
}

int main() {
    std::vector<query> q;
    // примеры запросов:
    q.push_back(query(0, 1, 7 ));
    q.push_back(query(1, 8, 9));
    q.push_back(query(2, 0, 10));
    q.push_back(query(3, 6, 7));
    // сортируем их с помощью кастомного компаратора:
    std::sort(q.begin(), q.end(), cmp);
    // выдаём ответ на запрос (не упорядочивая/приводя к исходному виду!):
    for (size_t i = 0; i < q.size(); ++i) {
        Mo(q[i].l, q[i].r);
        q[i].res = s;
        std::cout << q[i].id << ' ' << q[i].l << ' ' << q[i].r << ' ' << q[i].res << '\n';
    }
    return 0;
}

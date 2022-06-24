#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

// решаем задачу поиска МАКСИМУМА на подотрезках:

std::vector<int> a = { 1, 7, 2, 4, 7, 3, 6, 9 }; // исходный массив — надо дополнить до чётного размера, если он нечётный
std::vector<int> tree(15); // размерность массива дерева задаётся как 2n - 1

const int inf = 1e9; // удобная константа

void build(int v, int l, int r) { // заполняем дерево
    if (r - l == 1) { // случай — лист, заполняем им же (в начале нашего вспомогательного массива стоит исходный)
        tree[v] = a[l];
        return; // так как мы начинаем заполнять "с конца", то этот return отработает лишь в конце рекурсии, если у нас априори не L + 1 = R
    }
    int m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
    tree[v] = std::max(tree[2 * v + 1], tree[2 * v + 2]);
}

int query(int v, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) { // случай — нода или "лист"
        return tree[v];
    } else if (r <= ql || qr <= l) { // если запросы не пересекаются (между ними нет отрезка вида [L, R])
        return -inf;
    } else {
        int m = (l + r) / 2;
        int ans_left = query(2 * v + 1, l, m, ql, qr);
        int ans_right = query(2 * v + 2, m, r, ql, qr);
        return std::max(ans_left, ans_right);
    }
}

int main() {
    build(0, 0, 8); //
    for (size_t i = 0; i < tree.size(); ++i) {
        std::cout << tree[i] << ' ';
    }
    std::cout << '\n' << query(0, 0, 8, 3, 7);
    return 0;
}

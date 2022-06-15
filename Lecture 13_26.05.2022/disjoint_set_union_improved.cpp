#include <iostream>
#include <vector>
#include <numeric>

// Задача — ОСТРОВА:

/* объединяем все множества в одну компоненту связности,
 * с помощью DSU некоторые "мосты" мы можем игнорировать,
 * так как острова уже будут лежать в 1 компоненте связности. */

struct dsu {
private:
    std::vector<int> p;
public:
    dsu(size_t size) {
        p.resize(size);
        std::iota(p.begin(), p.end(), 0);
    }
    // делаем нерекурентно:
    int find(int v) {
        int r = v;
        while (p[r] != r) { // пока мы не поднялись до корня, идём к корню
            r = p[r];
        }
        // ДОБАВЛЯЕМ СЖАТИЕ ПУТЕЙ: — будет работать за O(log(log(log... n))):
        while (v != p[v]) {
            int next = p[v];
            p[v] = r;
            v = next;
        }
        return r;
    }

    int united(int x, int y) {
        p[find(x)] = find(y);
    }
};

int main() {
    int n;
    int m;
    std::cin >> n >> m;
    dsu d(n+1); // в задаче нумерация с 1
    for (size_t i = 0; i < m; ++i) {
        int a;
        int b;
        std::cin >> a >> b;
        if (d.find(a) != d.find(b)) { // если (пока) множества не в 1 компоненте — объединяем
            d.united(a, b);
            n--; // уменьшаем количество компонент связности
        }

        if (n == 1) { // осталось 1 множество
            std::cout << i + 1; // выводим количество шагов
            break;
        }
    }
    return 0;
}

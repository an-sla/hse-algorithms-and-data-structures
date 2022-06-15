#include <iostream>
#include <vector>

// Задача — ОСТРОВА:

/* объединяем все множества в одну компоненту связности,
 * с помощью DSU некоторые "мосты" мы можем игнорировать,
 * так как острова уже будут лежать в 1 компоненте связности. */

// Сначала делаем наивную реализацию без улучшения с помощью O(G(n)):
struct dsu {
private:
    std::vector<int> p;
public:
    dsu(size_t size) {
        p.resize(size, -1);
    }
    // делаем нерекурентно:
    int find(int a) {
        int r = a;
        while (p[r] != 1) { // пока мы не поднялись до корня, идём к корню
            r = p[r];
        }
        return r;
    }

    int united(int a, int b) { // делаем объединение множеств
        p[find(a)] = p[find(b)];
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
        if (d.find(a) != d.find(b)) {
            d.united(a, b);
            n--; // уменьшаем количество компонент связности
        }
        if (n == 1) { // осталось 1 множество
            std::cout << i + 1;
            break;
        }
    }
    return 0;
}

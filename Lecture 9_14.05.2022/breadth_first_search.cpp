#include <iostream>
#include <vector>
#include <queue>
#include <climits>


// Задача — все расстояния = 1 — по сути алгоритм Беллмана-Форда:
int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n); // список смежности
    // ... заполняем неориентированный граф:
    for (size_t i = 0; i < m; ++i) {
        int f = 0, t = 0;
        std::cin >> f >> t;
        g[f].push_back(t);
        g[t].push_back(f);
    }

    std::vector<int> p(n - 1), r(n - 1, std::numeric_limits<int>::infinity()); // список "предков" и массив расстояний (изначально — бесконечность)
    std::queue<int> q; // стэк/очередь
    q.push(0); // текущую вершину кинули в очередь
    r[0] = 0; // зафиксировали до неё расстояние
    while (!q.empty()) { // пока не раскрасим все вершины и стэк не опустеет...
        int cur = q.front(); // берём вершину — выкидываем, делаем из неё current
        q.pop();
        for (auto to :  g[cur]) { // смотрим все инцидентные...
            if (r[cur] + 1 < r[to]) { // если расстояние 1
                // кладём значения в вектора по индексу текущей вершины!
                r[to] = r[cur] + 1; // значение расстояния до данной вершины
                p[to] = cur; // значение предка
                q.push(to);
            }
        }
    }
    return 0;
}


/* тест:
8 10
0 1
0 5
1 2
2 4
2 3
3 4
3 5
5 6
6 4
6 7
*/
#include<iostream>
#include<vector>

// Вывод пути при обходе:

std::vector<int> used, path; // вектор раскрашенных, путь
std::vector<std::vector<int>> g; // граф

void dfs(int v) {
    used[v] = 1; // помечаем вершину
    path.push_back(v); // добавляем в путь
    for (auto to : g[v]) { // для всех исходящих...
        if (!used[to]) { // если там ещё не были...
            dfs(to); // запускаем dfs
            path.push_back(v); // снова добавляем вершину в путь на выходе (возвращении)!
        }
    }
}

int main() {
    int n = 0, m = 0, v = 0;
    std::cin >> n >> m >> v;
    n++;
    g = std::vector<std::vector<int>> (n);
    for (size_t i = 0; i < m; ++i) { // заполняем список смежности для неориентированного графа
        int f = 0, t = 0;
        std::cin >> f >> t;
        g[f].push_back(t);
        g[t].push_back(f);
    }

    used = std::vector<int> (n); // присваиваем вектор раскрашенных конкретного размера
    dfs(v); // запускаем dfs из данной по условию вершины
    // dfs заполнил наш путь (глобальная переменная)
    std::cout << path.size() << '\n'; // размер пути
    for (int i = 0; i < path.size(); ++i) { // вершины в пути — через пробел
        std::cout << path[i] << ' ';
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

const int inf = 1e9;

int main() {
    // n – количество вершин
    // m – количество рёбер
    // vertex – вершина, с которой мы инициализируем дерево кратчайших расстояний (его корень)
    int n, m, vertex;
    std::cin >> n >> m >> vertex;
    std::vector<std::vector<std::pair<int, int>>> g(n); // список смежности

    // инициализируем граф:
    for (int i = 0; i < m; ++i) {
        int from, to, w;
        std::cin >> from >> to >> w;
        g[from].push_back({to, w}); // номер вершины, вес ребра
        g[to].push_back({from, w}); // граф неориентирован, поэтому заполняем рёбра в обе стороны
    }

    std::vector<int> p(n, -1); // список предков (= пути в дереве)
    std::queue<int> q; // очередь
    std::vector<int> dist(n, inf); // массив расстояний в дереве, изначально — максимальное возможное (inf)

    q.push(vertex); // добавляем корень дерева
    dist[vertex] = 0; // расстояние до корня — 0

    while (!q.empty()) {
        int cur = q.front(); // выбираем вершину для просмотра
        q.pop();
        for (auto v: g[cur]) { // рассматриваем все смежные с просматриваемой вершины, итерируемся по парам значений вершина-вес
            int to = v.first; // вершина, куда хотим пойти дальше ("трогаем")
            int weight_to = v.second; // вес до неё
            // проверяем, что у нас улучшится расстояние + что мы не прийдём назад в предок, где мы уже были
            if (dist[cur] + weight_to < dist[to] and p[cur] != to) { // именно тут происходит превенция отрицательного цикла!
                dist[to] = dist[cur] + weight_to; // фиксируем новое расстояние
                p[to] = cur; // записываем нового предка для вершины to
                q.push(to); // добавляем новую "потроганную" вершину в очередь на просмотр
            }
        }
    }

    // вывод дерева кратчайших расстояний:
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == -1) { // (если предка нет, не выводим ничего)
            continue;
        }
        std::cout << p[i] << "->" << i << ";" << std::endl;
    }
    return 0;
}

/*
Test input:
8 10 2
0 1 3
0 5 -1
1 2 6
2 4 2
2 3 6
3 4 6
3 5 3
5 6 -2
6 4 -2
6 7 7

Test Output:
5->0;
0->1;
5->3;
2->4;
6->5;
4->6;
6->7;
*/
#include<iostream>
#include<vector>
#include <set>
using namespace std;
const int inf = 1e9;

/* test data
8 10 2
0 1 3
0 5 1
1 2 6
2 4 2
2 3 6
3 4 6
3 5 3
5 6 2
6 4 2
6 7 7
*/

int main() {
    // n вершин и m - рёбер, v0 - вершина от которой строим Дейкстру
    int n = 0, m = 0, vs;
    cin >> n >> m >> vs;
    // считываем как список смежности с весами
    vector<vector<pair<int, int>>> g(n);
    for (size_t i = 0; i < m; ++i) {
        int f = 0, t = 0, w = 0;
        std::cin >> f >> t >> w;
        // считвание рёбер неориентированного графа
        g[f].push_back({t, w}); // first - vertex, second - weight
        g[t].push_back({f, w});
    }

    // список предков для того, чтобы хранить ответы и массив расстояний //
    vector<int> parents(n, -1), dist(n, inf); //
    set<pair<int, int>> q;
    q.insert({0, vs}); // first - dist, second - number of vertex
    dist[vs] = 0; // расстояние до неё 0
    while (!q.empty()) { // пока текущий вектор, который мы просматриваем, не пустой или rnext не пустой
        // забираем из очереди следующую вершину
        auto u = q.begin(); // хранится минимальный элемент
        int rcur = u->first; // dist
        int cur = u->second;

        q.erase(q.begin());
        // начинаем просматривать все достижиимые до неё вершины (инцидентные рёбра)
        for (auto v : g[cur]){

            int to = v.first;
            int w_to = v.second;


            if (dist[cur] + w_to < dist[to]){

                if (dist[to] != inf){ // если не бесконечность, то мы уже считали эту вершину
                    q.erase({dist[to], to});  // удаляем и потом пересчитываем по новой
                }

                dist[to] = dist[cur] + w_to;
                parents[to] = cur;
                q.insert({dist[to], to});
            }
        }
    }


    // построение результата:
    for (size_t i = 0; i < parents.size(); ++i) {
        if (parents[i] == -1) continue;
        cout << parents[i] << "->" << i << ";\n";
    }
    return 0;
}

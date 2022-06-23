#include <iostream>
#include <vector>
using namespace std;

const auto INF = 1e10l;
int64_t MAXN = 2000;

struct edge{ 
    int64_t start, finish, weight; 
};

vector<vector<pair<int64_t, int64_t>>> graph(MAXN);
vector<edge> edges;
vector<int64_t> distances(MAXN, -INF), parents(MAXN, -1), used(MAXN, 0), failed(MAXN, 0);

void dfs(int64_t i, int64_t c) {
    used[i] = c;
    for (auto& e : graph[i]) {
        if (!used[e.first]) dfs(e.first, c);
    }
}

int main() {
    int64_t n, m;
    cin >> n >> m;
    distances[0] = 0;
    for (auto i = 0; i < m; i++) {
        edge temp;
        cin >> temp.start >> temp.finish >> temp.weight;
        temp.start--; 
        temp.finish--;

        graph[temp.finish].push_back({ temp.start, temp.weight });
        edges.push_back(temp);
    }

    for (auto k = 0; k < n; k++) {
        for (auto &e : edges) {
            if (distances[e.start] > -INF && distances[e.finish] < distances[e.start] + e.weight) {
                distances[e.finish] = distances[e.start] + e.weight;
                parents[e.finish] = e.start;
            }
        }
    }

    if (distances[n - 1] == -INF) {
        cout << ":(";
        return 0;
    }
    
    dfs(n - 1, 1);

    int64_t current_vertex = MAXN;
    while (current_vertex != -1) {
        current_vertex = -1;
        for (auto &e : edges) {
            if (!failed[e.start] && !failed[e.finish]) {
                if (distances[e.start] > -INF && distances[e.finish] < distances[e.start] + e.weight) {
                    distances[e.finish] = distances[e.start] + e.weight;
                    parents[e.finish] = e.start;
                    current_vertex = e.start;
                }
            }
        }
        if (current_vertex == -1) { 
            continue; 
        }
        vector<int64_t> cycle;
        auto temp_vertex = current_vertex;
        for (auto i = 0; i < n; i++) {
            temp_vertex = parents[temp_vertex];
        }
        for (auto cur = temp_vertex; ; cur = parents[cur]) {
            cycle.push_back(cur);
            if (cur == temp_vertex && cycle.size() > 1) {
                break;
            }
        }
        for (auto b : cycle) { 
            failed[b] = 1;
        }
    }

    for (auto i = 0; i < n; i++) {
        if (used[i] && failed[i]) {
            cout << ":)"; return 0;
        }
    }
    cout << distances[n - 1];
    return 0;
}
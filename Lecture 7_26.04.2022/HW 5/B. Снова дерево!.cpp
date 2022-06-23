#include <iostream>
#include <vector>

// Задача 2 из контеста — является ли граф деревом:

int n;
std::vector<std::vector<int>> adj; // граф
std::vector<bool> visited;
std::vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) {
    visited[v] = true;
    for (int u : adj[v]) {
        if(u == par) continue; // если ребро идёт к самому первому предку — пропускаем
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

int main() {
    int m;
    std::cin >> n >> m;
    n++;
    adj = std::vector<std::vector<int>> (n);
    for (size_t i = 0; i < m; ++i) {
        int f = 0, t = 0;
        std::cin >> f >> t;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    visited = std::vector<bool> (n, false);
    parent = std::vector<int> (n, -1);
    cycle_start = -1;
    dfs(1, parent[1]);
    bool one_comp = true;
    for (auto i = 1; i < visited.size(); ++i) {
        if (visited[i] == false) {
            one_comp = false;
            break;
        }
    }
    if (cycle_start == -1 && one_comp) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<int> used;
vector<int> path;
vector<vector<int>> g;

bool flag = false;
void dfs(int v){
    if (flag)
        return;
    used[v] = 1;

    path.push_back(v);
    for (int to : g[v]){
        if (used[to] == 1){
            path.push_back(to);
            flag = true;
            return;
        } else {
            dfs(to);
        }
        if (flag)
            return;
    }
    used[v] = 2;
    path.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    used.resize(n + 1, 0);
    for (size_t i = 0; i < m; ++i) {
        int f = 0, t = 0;
        std::cin >> f >> t;
        g[f].push_back(t);
    }

    for (auto i = 1; i < n + 1; ++i){
        if (used[i] == 0) {
            dfs(i);
            if (flag){
                break;
            }
        }
    }

    if (flag){
        int p = path.size() - 2;
        int to = path.back();
        while (path[p] != to)
            p--;
        cout << "YES\n";
        for (; p < path.size() - 1; p++){
            cout << path[p] << " ";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}
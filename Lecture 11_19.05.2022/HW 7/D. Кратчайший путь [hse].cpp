#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int64_t inf = INT64_MAX;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vii;
typedef vector<bool> vb;

vii g;

void dfs(bool* used, int s) {
    if (!used[s]) {
        used[s] = 1;
        for (int v : g[s]) {
            dfs(used, v);
        }
    }
}

void ford(int n, int m, int s, pair<pair<int, int>, int64_t>* edges) {
    int64_t dists[n];
    int step = 0;
    bool flag = 1;
    bool used[n];
    
    for (auto i = 0; i < n; i++) {
        if (i == s){
            dists[i] = 0;
        } else {
            dists[i] = inf;
        }
        used[i] = false;
    }

    while (step < n && flag) {
        flag = false;

        for (auto i = 0; i < m; i++) {
            if (dists[edges[i].first.first] < inf){
                if (dists[edges[i].first.second] > dists[edges[i].first.first] + edges[i].second) {
                    if (step == n - 1) {
                        dfs(used, edges[i].first.first);
                    } else {
                        dists[edges[i].first.second] = max(-inf, dists[edges[i].first.first] + edges[i].second);
                        flag = true;
                    }
                }
            }
        }

        step += 1;
    }

    for (auto i = 0; i < n; i++) {
        if (dists[i] == inf) {
            cout << '*' << "\n";
        } else if (used[i]) {
            cout << '-' << "\n";
        } else {
            cout << dists[i] << "\n";
        }
    }
}

int main() {
    int n, m, s, from, to;
    int64_t weight;
    cin >> n >> m >> s;
    g.resize(n);
    pair<pii, int64_t> edges[m];

    for (auto i = 0; i < m; ++i) {
        cin >> from >> to >> weight;
        g[from - 1].push_back(to - 1);
        edges[i] = {{ from - 1, to - 1 }, weight};
    }

    ford(n, m, s - 1, edges);
}
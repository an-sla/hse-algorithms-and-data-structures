#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int inf = 1e9;

int main() {
    int n = 0, m = 0, s = 0;
    cin >> n >> m >> s;
    n++;
    vector<vector<int> > g(n);
    for (size_t i = 0; i < m; ++i) {
        int f = 0, t = 0;
        cin >> f >> t;
        g[f].push_back(t);
        g[t].push_back(f);
    }
    vector<int> dist(n, inf);
    queue<int> q;
    vector<int> path;
    path.push_back(s);
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto to : g[cur]) {
            if (dist[cur] + 1 < dist[to]) {
                dist[to] = dist[cur] + 1;
                q.push(to);
                path.push_back(q.back());
            }
        }
    }
    cout << path.size() << endl;
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    return 0;
}
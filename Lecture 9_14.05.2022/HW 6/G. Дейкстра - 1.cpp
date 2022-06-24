#include <iostream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

const int inf = 1e9;


int main(){
    int N, S, F;
    cin >> N >> S >> F;
    N++;
    vector<vector<pair<int, int>>> g(N);

    for (auto i = 1; i < N; ++i){
        for (auto j = 1; j < N; ++j){
            int w;
            cin >> w;
            if (w >= 0){
                g[i].push_back({j, w});
            }
        }
    }

    vector<int> dist(N, inf);
    set<pair<int, int>> q;

    q.insert({0, S});
    dist[S] = 0;

    while(!q.empty()){
        auto u = q.begin();
        q.erase(q.begin());

        int current_vertex = u->second;
        for (auto v : g[current_vertex]){
            int to = v.first;
            int weight_to = v.second;
            if (dist[current_vertex] + weight_to < dist[to]){
                q.erase({dist[to], to});
                dist[to] = dist[current_vertex] + weight_to;
                q.insert({dist[to], to});
            }
        }
    }
    if (dist[F] != inf){
        cout << dist[F];
    } else {
        cout << -1;
    }


    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


struct edge {
    int from = 0, to = 0, cost = 0;
};

bool cmp(edge a, edge b){
    return a.cost < b.cost;
}

struct dsu {
    vector<int> parent;

    dsu(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int vertex){
        int root = vertex;
        while(parent[root] != root){
            root = parent[root];
        }
        while(parent[vertex] != vertex){
            int next = parent[vertex];
            parent[vertex] = root;
            vertex = next;
        }
        return root;
    }

    int merge(int a, int b){
        parent[find(a)] = find(b);
    }

};

int main() {
    int64_t summary_cost = 0;
    int n = 0, m = 0;
    cin >> n >> m;

    vector<edge> edges(m);
    vector<edge> answer;

    for (size_t i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }

    sort(edges.begin(), edges.end(), cmp);
    dsu d = dsu(n);
    
    for (size_t i = 0; i < m; ++i) {
        int a = edges[i].from, b = edges[i].to;
        if (d.find(a) != d.find(b)) {
            d.merge(a, b);
            answer.push_back(edges[i]);
        }
    }
    vector<int> included(n, 0);
		
    if (answer.size() != (n - 1)) {
        cout << "NON-CONNECTED" << endl;
    } else {
        for (size_t i = 0; i < answer.size(); ++i) {
            summary_cost += answer[i].cost;
        }
        cout << summary_cost;
    }
    return 0;
}
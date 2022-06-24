#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct edge{
    int from, to, cost;
};

bool cmp(edge a, edge b){
    return a.cost < b.cost;
}

struct dsu{
    std::vector<int> p;
    dsu(int n){
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int v){
        int r = v;
        while(p[r] != r){
            r = p[r];
        }
        while(p[v] != v){
            int next = p[v];
            p[v] = r;
            v = next;
        }
        return r;
    }

    int merge(int a, int b){
        p[find(a)] = find(b);
    }
};

int main() {
    std::ios_base::sync_with_stdio(NULL);
    std::cin.tie(0);
    std::cout.tie(0);
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<edge> e(m);
    std::vector<edge> ans;
    for(size_t i = 0; i < m; ++i){
        std::cin >> e[i].from >> e[i].to >> e[i].cost;
    }
    sort(e.begin(), e.end(), cmp);
    dsu d = dsu(n + 1);
    for (size_t i = 0; i < m; ++i){
        int a = e[i].from, b = e[i].to;
        if (d.find(a) != d.find(b)){
            d.merge(a, b);
            ans.push_back(e[i]);
        }
    }
    long long sm = 0;
    for (size_t i = 0; i < ans.size(); ++i){
        sm += ans[i].cost;
    }
    std::cout << sm;
    return 0;
}

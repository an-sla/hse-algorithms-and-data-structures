#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct dsu {
    int n = 0;
    std::vector<int> parents;
    std::vector<int> weights;
    dsu(int n) {
        parents.resize(n);
        weights.resize(n, 0);
        std::iota(parents.begin(), parents.end(), 0);
    }
    int find(int vertex) {
        int root = vertex;
        while(root != parents[root]) {
            root = parents[root];
        }
        while (vertex != parents[vertex]) {
            int next = parents[vertex];
            parents[vertex] = root;
            vertex = next;
        }
        return vertex;
    }

    int get_weight(int vertex) {
        int w = weights[vertex];
        return w;
    }

    void merge(int a, int b, int weight) {
        weights[find(b)] += weights[find(a)];
        parents[find(a)] = find(b);
        weights[find(b)] += weight;
    }
    void add(int a, int b, int weight) {
        if (parents[find(a)] != parents[find(b)]) {
            merge(a, b, weight);
        } else {
            weights[find(a)] += weight;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 0, m = 0, a = 0, b = 0, weight = 0, cmd = 0;
    std::cin >> n >> m;
    dsu d = dsu(n);
    for(int i = 0; i < m; i++) {
        std::cin >> cmd;
        if (cmd == 1) {
            std::cin >> a >> b >> weight;
            a--, b--;
            d.add(a, b, weight);
        } else {
            std::cin >> a;
            a--;
            int root = d.find(a);
            cout << d.get_weight(root) << "\n";
        }
    }
    return 0;
}
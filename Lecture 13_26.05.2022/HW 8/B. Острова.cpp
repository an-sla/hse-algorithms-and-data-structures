#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct dsu{
    vector<int> parents;
    int n = 0;

    dsu(int n){
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int vertex){
        int root = vertex;
        while (root != parents[root]) {
            root = parents[root];
        }
        while (vertex != parents[vertex]) {
            int next = parents[vertex];
            parents[vertex] = root;
            vertex = next;
        }
        return vertex;
    }

    void merge(int a, int b) {
        parents[find(a)] = find(b);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    int n, m, j, k;
    cin >> n >> m;
    dsu d = dsu(n);
    for (int i = 0; i < m; ++i) {
        cin >> j >> k;

        --j;
        --k;

        if (d.find(j) != d.find(k)) {
            d.merge(j, k);
            --n;
        }

        if (n == 1) {
            cout << i + 1 << "\n";
            break;
        }
    }

    return 0;
}

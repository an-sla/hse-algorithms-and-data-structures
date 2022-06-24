#include <iostream>
#include <vector>
using namespace std;

void build(vector<vector<int>> &graph, vector<vector<int>> &table, vector<int> &x, vector<int> &y){
    int MIN = 1e9;
    for (auto x1 = 0; x1 < graph.size(); ++x1){
        for (auto y1 = 0; y1 < graph[x1].size(); ++y1){
            MIN = 1e9;
            for (auto k = 0; k < x.size(); ++k){
                int x2 = x[k];
                int y2 = y[k];
                int sum = abs(x1 - x2) + abs(y1 - y2);
                MIN = min(MIN, sum);
            }
            table[x1][y1] = MIN;
        }
    }
}

void answer(vector<vector<int>> &result){
    for (auto i = 0; i < result.size(); ++i){
        for (auto j = 0; j < result[i].size(); ++j){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {

    int n, m, MIN = 1e9;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    vector<int> xcord;
    vector<int> ycord;
    vector<vector<int>> table(n, vector<int>(m, 0));
    for (auto i = 0; i < n; ++i){
        for (auto j = 0; j < m; ++j){
            cin >> g[i][j];
            if (g[i][j]){
                xcord.push_back(i);
                ycord.push_back(j);
            }
        }
    }

    build(g, table, xcord, ycord);
    answer(table);

    return 0;
}
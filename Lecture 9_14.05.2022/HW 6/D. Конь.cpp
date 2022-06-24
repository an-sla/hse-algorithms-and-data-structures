#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

int main() {    
    bool flag = false;
    int K, N, j, i, m, s;
    // (j, i) - start; (m, s) - finish
    cin >> K >> N >> j >> i >> m >> s;
    queue<pii> q;
    vii table(K + 1, vi(N + 1, INF)); 

    table[j][i] = 0;
    q.push({j, i});


    while (!q.empty() && !flag) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;

        if (x < K - 1 && y > 1 && table[x + 2][y - 1] == INF) {
            table[x + 2][y - 1] = table[x][y] + 1;
            q.push({x + 2, y - 1});
        }

        if (x > 1 && y < N - 1 && table[x - 1][y + 2] == INF) {
            table[x - 1][y + 2] = table[x][y] + 1;
            q.push({x - 1, y + 2});
        }
        if (x < K - 1 && y < N && table[x + 2][y + 1] == INF) {
            table[x + 2][y + 1] = table[x][y] + 1;
            q.push({x + 2, y + 1});
        }
        if (x < K && y < N - 1 && table[x + 1][y + 2] == INF) {
            table[x + 1][y + 2] = table[x][y] + 1;
            q.push({x + 1, y + 2});
        }
        if (x > 1 && y > 2 && table[x - 1][y - 2] == INF) {
            table[x - 1][y - 2] = table[x][y] + 1;
            q.push({x - 1, y - 2});
        }
        if (x > 2 && y > 1 && table[x - 2][y - 1] == INF) {
            table[x - 2][y - 1] = table[x][y] + 1;
            q.push({x - 2, y - 1});
        }
        if (x > 2 && y < N && table[x - 2][y + 1] == INF) {
            table[x - 2][y + 1] = table[x][y] + 1;
            q.push({x - 2, y + 1});
        }
        if (x < K && y > 2 && table[x + 1][y - 2] == INF) {
            table[x + 1][y - 2] = table[x][y] + 1;
            q.push({x + 1, y - 2});
        }
        
        if (x == m && y == s) {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
    return 0;
}
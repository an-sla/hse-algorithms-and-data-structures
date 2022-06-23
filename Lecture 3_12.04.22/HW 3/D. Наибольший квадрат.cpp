#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void read(vector<vector<T>> &v, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
}


int main() {
    int n, m;
    int x = 0, y = 0;
    int size = 0;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    read(v, n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 1) {
                if (i > 0 && j > 0)
                    v[i][j] = min(min(v[i - 1][j], v[i - 1][j - 1]), v[i][j - 1]) + 1;
                if (i == 0 || j == 0) {
                    if (size == 0)
                        size = 1;
                }
            }
            if (v[i][j] > size) {
                x = i;
                y = j;
                size = v[x][y];
            }
        }
    }
    cout << size << "\n";
    cout << x - size + 2 << " " << y - size + 2;
    return 0;
}
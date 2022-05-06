#include <iostream>
#include <vector>


int main() {
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> initial(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> auxilary(n+1, std::vector<int>(m+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int t;
            std::cin >> t;
            initial[i][j] = t;
            auxilary[i][j] = auxilary[i-1][j] + auxilary[i][j-1] - auxilary[i-1][j-1] + initial[i-1][j-1];
        }
    }
    int x1;
    int x2;
    int y1;
    int y2;
    int queries;
    std::cin >> queries;
    for (auto i = 0; i < queries; ++i) {
        std::cin >> x1 >> x2 >> y1 >> y2;
        std::cout << auxilary[x2][y2] - auxilary[x1][y2] - auxilary[x2][y1] + auxilary[x1][x1] << std::endl;
    }
}

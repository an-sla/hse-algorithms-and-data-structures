#include <unordered_set>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    int64_t answer = 0;
    std::cin >> n >> m;
    std::unordered_set<int> L[301];

    for (auto i = 0; i < m; ++i){
        int a, b;
        std::cin >> a >> b;
        L[a].insert(b);
        L[b].insert(a);
    }

    for (auto i = 1; i <= n; ++i) {
        for (auto j = i + 1; j <= n; ++j) {
            int64_t count = 0;
            for (auto &l : L[i]) {
                if (L[j].count(l)) {
                    count++;
                }
            }
            answer += count * (count - 1) / 2;
        }
    }

    std::cout << answer / 2;
}

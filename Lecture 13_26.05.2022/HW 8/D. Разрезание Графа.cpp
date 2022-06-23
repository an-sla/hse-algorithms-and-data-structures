#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <tuple>

using namespace std;
struct dsu {
    
    std::vector<int> parent;
    dsu(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int vertex){
        int root = vertex;
        while (parent[root] != root){
            root = parent[root];
        }

        while (parent[vertex] != vertex){
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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::tuple<std::string, int, int>> requests;
    std::vector<std::string> answer;


    for (auto i = 0; i < m; ++i) {
        int trash_1, trash_2;
        std::cin >> trash_1 >> trash_2;
    }

    std::string cmd;
    int vertex_first, vertex_second;
    for (auto i = 0; i < k; ++i) {
        std::cin >> cmd >> vertex_first >> vertex_second;
        requests.emplace_back(cmd, vertex_first, vertex_second);
    }

    dsu d = dsu(n + 1);
    for (int i = k - 1; i >= 0; --i) {
        if (std::get<0>(requests[i]) == "cut") {
            d.merge(std::get<1>(requests[i]) , std::get<2>(requests[i]));
        } else {
            if (d.find(std::get<1>(requests[i])) == d.find(std::get<2>(requests[i]))) {
                answer.emplace_back("YES");
            } else {
                answer.emplace_back("NO");
            }
        }
    }

    std::reverse(answer.begin(), answer.end());

    for (const auto& elem : answer) {
        std::cout << elem << "\n";
    }
    return 0;
}
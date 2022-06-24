#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int answer = -1;
    cin >> N;
    N++;    
    vector<int> vec;
    vector<vector<int>> graph(N);
    for (int i = 2; i < N; ++i) {
        int v;
        cin >> v;
        graph[v].push_back(i);
    }


    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        vec.clear();
        auto q_size = q.size();
        for (int i = 0; i < q_size; ++i) {
            int current_vertex = q.front();
            vec.push_back(current_vertex);
            q.pop();
            for (auto vertex : graph[current_vertex]) {
                q.push(vertex);
            }
        }
        answer += 1;
    }
    
    sort(vec.begin(), vec.end()); 

    cout << answer << "\n";
    cout << vec.size() << "\n";
    
    for (auto v: vec) {
        cout << v << " ";
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int inf = 1e9;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    for (auto i = 0; i < N; ++i){
        for (auto j = 0; j < N; ++j){
            int x = 0;
            cin >> x;
            if(i == j) {
                continue;
            } else if (x == 0) {
                A[i][j] = inf;
            } else {
                A[i][j] = x;
            }
        }
    }

    for(auto k = 0; k < N; ++k){
        for (auto i = 0; i < N; ++i){
            for (auto j = 0; j < N; ++j){
                A[i][j] = min(A[i][k] + A[k][j], A[i][j]);
            }
        }
    }
    for (auto i = 0; i < N; ++i){
        for (auto j = 0; j < N; ++j){
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
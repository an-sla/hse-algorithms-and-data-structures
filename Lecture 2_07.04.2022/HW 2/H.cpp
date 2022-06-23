#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    size_t n, k, sum = 0;
    cin >> n >> k;
    vector<size_t> v(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i];
        sum += v[i];
    }
    size_t l = 0;
    size_t r = sum / k + 2;
    while (r - l > 1){
        size_t m = (l + r) / 2;
        size_t K = 0;
        for (auto i = 0; i < n; ++i){
            K = K + v[i] / m;
        }
        if (K < k){
            r = m;
        } else{
            l = m;
        }
    }
    cout << l;
    return 0;
}
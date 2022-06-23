#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool f(vector<int> &v, int &x, int &k) {
    int cnt = 1;
    int last = v[0];
    for (auto cur : v) {
        if (cur - last >= x) {
            ++cnt;
            last = cur;
        }
    }
    return cnt >= k;
}

void solve(vector<int> &v, int &k){
    int l = 0;
    int r = v.back() - v[0] + 1;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (f(v, m, k)){
            l = m;
        } else{
            r = m;
        }
    }
    cout << l;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto i = 0; i < v.size(); ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    solve(v, k);
    return 0;
}
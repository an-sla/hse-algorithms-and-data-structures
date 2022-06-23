#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

template<typename T>
int count_int(vector<T> &v, int l, int r, int x){
    auto ans = count(v.begin() + l, v.begin() + r, x);
    return ans;
}

int main(){
    int n, sz;
    cin >> n;
    sz = ceil(sqrt(n));
    vector<int> arr(n + 1, 0);
    vector<int> blocks(sz, 0);
    for (auto i = 1; i < n + 1; ++i){
        cin >> arr[i];
        blocks[i / sz] = max(blocks[i / sz], arr[i]);
    }
    int k;
    cin >> k;
    for (auto i = 0; i < k; ++i){
        int l, r;
        cin >> l >> r;
        int res = arr[l];
        int tl = l, tr = r;
        while (l <= r){
            if (l % sz == 0 && l + sz - 1 <= r){
                res = max(res, blocks[l / sz]);
                l += sz;
            } else {
                res = max(res, arr[l]);
                ++l;
            }
        }
        cout << res << " " << count_int(arr, tl, tr + 1, res) << "\n";
    }
}
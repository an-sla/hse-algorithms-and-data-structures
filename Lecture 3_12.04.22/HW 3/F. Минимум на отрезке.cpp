#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int inf = 1e9;
int main(){
    int n, k, sz;
    cin >> n >> k;
    sz = ceil(sqrt(n));
    vector<int> arr(n + 1, 0);
    vector<int> blocks(sz, inf);
    for (auto i = 1; i < n + 1; ++i){
        cin >> arr[i];
        blocks[i / sz] = min(blocks[i / sz], arr[i]);
    }

    for (auto i = 1; i <= n - k + 1; ++i){
        int l = i, r = i + k - 1;
        int res = arr[l];
        while (l <= r){
            if (l % sz == 0 && l + sz - 1 <= r){
                res = min(res, blocks[l / sz]);
                l += sz;
            } else {
                res = min(res, arr[l]);
                ++l;
            }
        }
        cout << res << "\n";
    }
}

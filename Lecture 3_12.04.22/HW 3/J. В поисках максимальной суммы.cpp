#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef unordered_map<int, pair<int64_t, int>> umap;

int main() {
    int n;
    cin >> n;
    int64_t sum = 0;
    int64_t ans = INT64_MIN;
    vector<int64_t> vec(n);
    umap sums;
    int l = 0, r = 0;
    for (auto i = 0; i < n; ++i){
        cin >> vec[i];
        if (sums.find(vec[i]) != sums.end()){
            if (sums[vec[i]].first > sum){
                sums[vec[i]].first = sum;
                sums[vec[i]].second = i;
            }
        } else {
            sums[vec[i]].first = sum;
            sums[vec[i]].second = i;
        }

        sum += vec[i];
        if (ans < sum - sums[vec[i]].first){
            l = sums[vec[i]].second;
            r = i;
        }
        ans = max(ans, sum - sums[vec[i]].first);
    }
    cout << ans << "\n";
    cout << ++l << " " << ++r << endl;
    return 0;
}
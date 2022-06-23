#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

template<typename T>
void out(vector<T> &v){
    for (const auto &i : v){
        cout << i << " ";
    }
    cout << endl;
}
template<typename T>
void out(vector<T> &v, int l, int r){
    for (auto i = l; i < r; ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (auto i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int l = 0, r = 0, idx = -1;
    int sum = 0, msum = 0, MAX = arr[0];

    for (auto i = 0; i < n; ++i) {
        sum += arr[i];

        if (MAX < sum - msum) {
            MAX = sum - msum;
            l = idx + 1;
            r = i;
        }

        if (sum < msum) {
            msum = sum;
            idx = i;
        }
    }
    cout << l + 1 << " " << r + 1 << " " << MAX;
}
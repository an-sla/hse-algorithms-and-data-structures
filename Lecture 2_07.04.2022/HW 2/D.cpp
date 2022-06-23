#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lowerbound(vector<int> &v, int x){
    int l = 0;
    int r = v.size();
    while (l < r){
        int m = l + (r - l) / 2;
        if (x <= v[m]){
            r = m;
        } else{
            l = m + 1;
        }
    }
    if (l < v.size() && v[l] < x){
        ++l;
    }
    return l;
}

int upperbound(vector<int> &v, int x){
    int l = 0;
    int r = v.size();
    while (l < r){
        int m = l + (r - l) / 2;
        if (x >= v[m]){
            l = m + 1;
        } else{
            r = m;
        }
    }
    if (l < v.size() && v[l] <= x){
        ++l;
    }
    return l;
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto i = 0; i < n; ++i){
        cin >> v[i];
    }
    int k;
    cin >> k;
    sort(v.begin(), v.end());
    for (auto i = 0; i < k; ++i){
        int l, r;
        cin >> l >> r;
        cout << upperbound(v, r) - lowerbound(v, l) << " ";
    }
    return 0;
}
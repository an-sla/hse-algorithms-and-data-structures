#include <iostream>
#include <vector>
using namespace std;

bool bs(vector<int> &a, int x){
    int l = -1;
    int r = a.size();
    while (l < r - 1){
        int m = (l + r) / 2;
        if (a[m] < x){
            l = m;
        } else {
            r = m;
        }
    }
    if (r != a.size() && a[r] == x){
        return true;
    }
    return false;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(k);
    for (auto i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (auto i = 0; i < k; ++i){
        cin >> b[i];
        cout << (bs(a, b[i]) ? "YES\n" : "NO\n");
    }

}
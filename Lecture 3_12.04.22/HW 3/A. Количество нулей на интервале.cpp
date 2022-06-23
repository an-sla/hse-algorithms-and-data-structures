#include <iostream>
#include <climits>
#include <vector>
using namespace std;

template <typename T>
void output(vector<T> &v){
    for (const auto &i : v){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    vector<int> p(n + 1, 0);
    vector<int> m(n + 1, 0);
    int cnt = 0;
    for (int i = 1; i < n + 1; ++i){
        cin >> v[i];
        p[i] = v[i] + p[i - 1];
        if (v[i] == 0){
            m[i] = ++cnt;
        } else if (v[i] != 0){
            m[i] = cnt;
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i){
        int l, r;
        cin >> l >> r;
        cout << m[r] - m[l - 1] << " ";
    }
    return 0;
}

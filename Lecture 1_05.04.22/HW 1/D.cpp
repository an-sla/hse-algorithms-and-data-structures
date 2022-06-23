#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &d, string s, int p, int &n, int i){
    if (p == n){
        s.erase(s.begin());
        cout << s << "\n";
        return;
    }
    for (auto j = i; j < d.size(); ++j){
        if (d[j] * p <= n){
            solve(d, s + "*" + to_string(d[j]), p * d[j], n, j);
        }
    }
}

void divs(vector<int> &d, int &n, int &m){
    for (int i = m; i < n; ++i){
        if (n % i == 0){
            d.push_back(i);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> d;
    divs(d, n, m);
    solve(d, "", 1, n, 0);
    cout << n;
}
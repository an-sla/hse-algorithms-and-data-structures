#include <iostream>
using namespace std;

const unsigned int MOD = 1e9 + 9;

int64_t gcd(int64_t a, int64_t b, int64_t &x, int64_t &y){
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int64_t g = gcd(b, a % b, x, y);
    x = x - (a / b) * y;
    swap(x, y);
    return g;
}
void solve(int64_t &a){
    int64_t x, y;
    int64_t m = MOD;
    int64_t g = gcd(a, m, x, y);
    if (g == 1){
        x = (x % m + m) % m;
        cout << x << "\n";
    }
}


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int64_t t;
        cin >> t;
        solve(t);
    }
}
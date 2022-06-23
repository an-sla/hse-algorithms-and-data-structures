#include <iostream>
using namespace std;

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
void solve(int64_t &a, int64_t &b, int64_t &c, int64_t &x, int64_t &y){
    int64_t g = gcd(a, b, x, y);
    if (c % g != 0){
        cout << 0 << " " << 0 << "\n";
        return;
    }
    int64_t k0 = x * c / g;
    int64_t k1 = b / g;
    int64_t xi, yi;
    if (k0 > 0){
        xi = k0 - k1 * (k0 / k1);
        yi = y * c / g + a / g * (k0 / k1);
    } else if (k0 == 0){
        xi = 0;
        yi = y * c / g;
    } else {
        xi = k0 - k1 * ((k0 - k1 + 1) / k1);
        yi = y * c / g + a / g * ((k0 - k1 + 1)/ k1);
    }
    cout << xi << " " << yi << "\n";
}


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int64_t a, b, c, x, y, g;
        cin >> a >> b >> c;
        solve(a, b, c, x, y);
    }
}
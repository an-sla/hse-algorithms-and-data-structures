#include <iostream>
using namespace std;

size_t f(size_t n, size_t a, size_t b, size_t w, size_t h){
    size_t l = 0;
    size_t r = min(w, h) + 1;
    while (r - l > 1){
        size_t d = (l + r) / 2;
        size_t d1 = (a + 2 * d);
        size_t d2 = (b + 2 * d);
        if ((w / d1) * (h / d2) >= n){
            l = d;
        } else{
            r = d;
        }
    }
    return l;
}

int main(){
    size_t n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    cout << max(f(n, a, b, w, h), f(n, b, a, w, h));
    return 0;
}
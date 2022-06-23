#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int a, b;
    size_t k, m, x;
    cin >> a >> k >> b >> m >> x;
    size_t l = 0;
    size_t r = 2 * x / (a + b) + 1;
    while (r - l > 1){
        size_t M = (l + r) / 2;
        if ((M - M / k) * a + (M - M / m) * b < x){
            l = M;
        } else{
            r = M;
        }
    }
    cout << r << endl;
    return 0;
}
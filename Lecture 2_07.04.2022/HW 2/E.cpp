#include <iostream>
using namespace std;

uint64_t bs(uint64_t x){

    if (x < 2){
        return x;
    }

    uint64_t l = 1;
    uint64_t r = x;

    while (l <= r){
        uint64_t m = l + ((r - l) >> 1);
        if (m == x / m){
            return m;
        } else {
            if (m < x / m){
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
    }
    return r;
}

int main(){
    uint64_t n;
    while (cin >> n){
        cout << bs(n) << endl;
    }
}
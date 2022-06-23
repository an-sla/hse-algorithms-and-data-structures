#include <iostream>
#include <vector>
using namespace std;

size_t foo(int n){
    vector<char> p(n + 1, true);
    p[0] = p[1] = true;
    size_t sum = 0;
    for (size_t i = 2; i <= n; ++i){
        if (p[i] == 1){
            sum += i;
            for (size_t j = i * i; j <= n; j += i){
                if (p[j] != 0){
                    sum += i;
                }
                p[j] = 0;
            }
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    size_t sum = foo(n);
    cout << sum;
    return 0;
}
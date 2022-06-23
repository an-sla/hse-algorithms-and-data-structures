#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<unsigned int> erat(int n){
    vector<unsigned int> p(n + 1, 1);
    vector<unsigned int> primes;
    primes.push_back(1);
    for (size_t i = 2; i <= n; i++){
        if (p[i] == 1){
            primes.push_back(i);
            for (size_t j = i * i; j <= n; j += i){
                p[j] = 0;
            }
        }
    }
    return primes;
}
const int N = 10e6 + 1;
const vector<unsigned int> PRIMES = erat(N);

int main() {
    int n;
    cin >> n;
    for (auto i = 0; i < n; i++){
        int k;
        cin >> k;
        cout << PRIMES[k] << " ";
    }
    return 0;
}
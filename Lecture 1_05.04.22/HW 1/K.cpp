#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<char> similiar_block_erat(size_t &a, size_t &b) {
    vector<size_t> primes;
    size_t sq = static_cast<size_t>(sqrt(b));
    vector<char> prime(sq + 1, false);
    for (size_t i = 2; i <= sq; ++i) {
        if (!prime[i]) {
            primes.emplace_back(i);
            for (size_t j = i * i; j <= sq; j += i){
                prime[j] = true;
            }
        }
    }

    vector<char> isPrime(b - a + 1, true);
    for (const auto &i : primes){
        for (auto j = max(i * i, (a + i - 1) / i * i); j <= b; j += i){
            isPrime[j - a] = false;
        }
    }
    if (a == 1){
        isPrime[0] = false;
    }
    return isPrime;
}

int main()
{
    size_t a, b;
    cin >> a >> b;
    auto result = similiar_block_erat(a, b);
    for (auto i = 0; i < result.size(); ++i){
        if (result[i]){
            cout << a + i << " ";
        }
    }
}

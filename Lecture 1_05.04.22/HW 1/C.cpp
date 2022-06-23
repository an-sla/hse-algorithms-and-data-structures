#include <iostream>
#include <vector>

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> result;

    if (n == 1){
        std::cout << 1;
        return 0;
    }

    for (size_t i = 2; i * i <= n; i++){
        while (n % i == 0) {
            result.push_back(i);
            n /= i;
        }
    }

    if (n > 1){
        result.push_back(n);
    }

    for (const auto& elem : result){
        std::cout << elem << " ";
    }

    return 0;
}
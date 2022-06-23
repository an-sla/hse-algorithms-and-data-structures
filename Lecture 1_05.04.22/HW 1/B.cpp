#include <iostream>

size_t gcd(size_t a, size_t b){
    if (b == 0){
        return a;
    } else {
        return gcd(b, a % b);
    }
}

size_t lcm(size_t a, size_t b){ // function for finding the least common multiple
    return a / gcd(a, b) * b;
}

int main() {
    size_t a, b;
    std::cin >> a;
    std::cin >> b;
    std::cout << lcm(a, b);
    return 0;
}
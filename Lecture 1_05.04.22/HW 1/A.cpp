#include <iostream>


int gcd(int a, int b){
    if (b == 0){
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int a, b;
    std::cin >> a;
    std::cin >> b;
    std::cout << gcd(a, b);
    return 0;
}
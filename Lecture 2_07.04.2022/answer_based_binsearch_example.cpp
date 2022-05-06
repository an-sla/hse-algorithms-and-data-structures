#include <iostream>

/* нашей переменной будет x — длина стороны квадрата
 * формула площади дипломов: h * w * n */


bool checker(long long middle, long long w, long long h, long long n) {
    // условия: дипломы помещаются как с точки зрения площади, так и с точки зрения сторон:
    if ((middle / w) * (middle / h) >= n) {
        return true;
    } return false;
}


int main() {
    long long w;
    long long h;
    long long n;
    std::cin >> w >> h >> n;
    long long L = 0;
    long long R = std::max(w, h) * n;
    while (R > L + 1) {
        long long middle = (L + R) / 2;
        if (checker(middle, w, h, n)) {
            R = middle;
        } else {
            L = middle;
        }
    }
    // числа сошлись, осталось проверить, подойдёт ли меньшее:
    if ((((L + R) / 2) / w) * (((L + R) / 2) / h) >= n) {
        std::cout << L << std::endl;
    } else {
        std::cout << R << std::endl;
    }
    return 0;
}

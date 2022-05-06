#include <iostream>

double poly(double x) {
    double a = 1, b = 5, c = -4;
    return a * x * x + b * x + c;
}

int main() {
    // заданы границы:
    double L = -99;
    double R = 99;
    // взвешанные "средние" (принцип рычага / центра масс), т.е. трети:
    double s1 = (L * 2 + R) / 3;
    double s2 = (L + 2 * R) / 3;
    double epsilon = 0.001;
    while (s2 - s1 > epsilon) {
        // проводим сравнение и берём нужный нам отрезок:
        if (poly(L) >= poly(s1) && poly(s1) >= poly(s2)) {
            L = s1;
        } else {
            R = s2;
        }
        // пересчитываем новые трети
        s1 = (2 * L + R) / 3;
        s2 = (L + 2 * R) / 3;
    }
    // печатаем наше значение корня и считаем его реальное значение при подставлении в функцию:
    std::cout << (s1 + s2) / 2 << ' ' << poly((s1 + s2) / 2);
}

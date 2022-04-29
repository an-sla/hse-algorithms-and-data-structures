#include <iostream>
#include <vector>

// Подсчёт базовых префиксных сумм:
int main() {
  std::vector<int> a = {7, -2, 3, 1, 4, 0, -3, 5, 4, 8};
  std::vector<int> p(a.size() + 1, 0); // Вспомогательный массив размера на 1 больше, чем `a`
  for (size_t i = 0; i < a.size(); ++i) {
    p[i + 1] = p[i] + a[i]; // Заполняем, надо иметь ввиду различие в размерностях `a`, `p` при заполнении
  }
  size_t L;
  size_t R;
  std::cin >> L >> R;
  std::cout << (p[R] - p[L - 1]);
  return 0;
}

/* Тест:
   5 10
 * Верный ответ:
   18
*/

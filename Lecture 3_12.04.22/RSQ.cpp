#include <iostream>
#include <vector>

// Подсчёт базовых префиксных сумм:
int main() {
  size_t vect_size;
  std::cin >> vect_size;
  std::vector<int> a;
  for (size_t i = 0; i < vect_size;
       ++i) { // Заполняем исходный вектор из потока ввода
    int temp;
    std::cin >> temp;
    a.push_back(temp);
  }
  std::vector<int> p(a.size() + 1,
                     0); // Вспомогательный массив размера на 1 больше, чем `a`
  for (size_t i = 0; i < a.size(); ++i) {
    p[i + 1] = p[i] + a[i]; // Заполняем, надо иметь ввиду различие в
                            // размерностях `a`, `p` при заполнении
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

#include <iostream>
#include <vector>

const int inf = 1e9;

int main() {
    // n – количество вершин
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 0)); // матрица смежности с результирующими значениями

    // заполнение матрицы смежности:
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            std::cin >> x;
            if (i == j) { // если мы на диагонали — расстояние от вершины до самой себя всегда 0
                continue;
            } else if (x == -1) { // иначе заполняем inf...
                A[i][j] = inf;
            } else {
                A[i][j] = x; // ...если только нам по условию не дано ребро (исходное расстояние, которое мы пытаемся уменьшить)
            }
        }
    }
    int diameter = -1;
    int radius = -1;
    // решаем без явного использования вспомогательных матриц:
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // здесь можно добавить проверку на диагональ:
                if (i == j) continue;
                // (от самой себя до самой себя мы никак не улучшим)
                // по новому условию также надо проверить наличие ребра:
                else if (A[i][k] != -1 && A[k][j] != -1) { // если вершина, через которую мы пытаемся улучшить путь имеет путь/ребро, которое соединяет i, j
                    if (A[i][j] != -1) {
                        A[i][j] = std::min(A[i][k] + A[k][j], A[i][j]); // проверяем, сможем ли мы обходом через k–ю вершину улучшить путь из i до j
                    } else {
                        A[i][j] = A[i][k] + A[k][j];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int rad = inf;
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << ' ';
            if (i != j && A[i][j] != -1 && rad > A[i][j]) {
                rad = A[i][j];
            }
            if (A[i][j] > diameter && i != j) {
                diameter = A[i][j];
            }
        }
        if (rad > radius) {
            radius = rad;
        }
        std::cout << std::endl;
    }
    // выводим радиус, диаметр
    std::cout << diameter << std::endl;
    std::cout << radius;
    return 0;
}



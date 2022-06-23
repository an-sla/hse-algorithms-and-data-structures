#include <iostream>
#include <vector>
#include <queue>
#include <set>

// Задача 1 из контеста — количество вершин в одной компоненте связности с данной вершиной:

int main() {
    int n;
    int s;
    std::cin >> n >> s; // количество вершин, заданная вершина
    std::vector<std::vector<int>> matrix;
    for (size_t i = 0; i < n; ++i) { // заполняем матрицу смежности
        std::vector<int> t;
        for (size_t j = 0; j < n; ++j) {
            int temp;
            std::cin >> temp;
            t.push_back(temp);
        }
        matrix.push_back(t);
    }
    std::queue<int> q; // стэк
    q.push(s - 1); // s - 1 для более простой индексации
    int sum = 1; // количество нод в компоненте
    std::set<int> se; // посчитанные вершины?
    se.insert(s-1);

    while (!q.empty()) { // пока стэк не пустой...
        for (size_t i = 0; i < n; ++i) { // обходим все вершины
            if (matrix[q.front()][i] && (se.find(i) == se.end())) { // если имеем исходящие ребро И вершина ещё не раскрашена...
                // (щупаем все ноды, достижимые из первого, самого старого элемента на стэке)
                q.push(i); // добавляем в стэк
                se.insert(i); // добавляем в помеченные
                sum += 1; // +1 к количеству нод в компоненте связности
            }
        }
        q.pop(); // удаление самого первого элемента
    }
    std::cout << sum;
    return 0;
}
// OK
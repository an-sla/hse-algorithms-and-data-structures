#include <iostream>
#include <vector>

int first_entry_binsearch(std::vector<int> &data, int key) { // передаём вектор по ссылке! -> иначе происходит копирование и линейный поиск
    int left = -1, right = data.size(); // инициируем фиктивные элементы
    while (right > left + 1) { // пока индексы не сошлись...
        int middle = (left + right) / 2;
        if (data[middle] < key) { // строго меньше, двигаем правый элемент при равности (отрабатывает вилка else)
            left = middle;
        } else {
            right = middle;
        }
    }
    return right; // возвращаем правый элемент
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> sequence(n);
    for (size_t i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        sequence[i] = temp;
    }
    int queries;
    int key;
    std::cin >> queries;
    for (auto i = 0; i < queries; ++i) {
        std::cin >> key;
        int index = first_entry_binsearch(sequence, key);
        if (index != sequence.size() and sequence[index] == key) {
            std::cout << "Element in array at index " << index << " as first entry" << std::endl;
        } else {
            std::cout << "Element not in array" << std::endl;
        }
    }
    return 0;
}

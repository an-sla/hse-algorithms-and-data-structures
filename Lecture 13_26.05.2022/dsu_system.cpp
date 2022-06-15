#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
#include <string>

using namespace std;

// Система непересекающихся множеств — Семинарская задача 4:

struct dsu{
    int n = 0;
    vector<int> p;
    dsu(int n){
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int v){
        int r = v; // улучшение для создания "звёзд" / "ежей"
        while(r != p[r])
            r = p[r];
        while (v != p[v]){
            int next = p[v];
            p[v] = r;
            v = next;
        }
        return v;
    }
    void merge(int a, int b) {
        p[find(a)] = find(b);
    }
};

int main() {
    int tasks = 14; // количество запросов (хардкод)
    dsu d = dsu(0); // инициализируем пустой dsu
    for (auto i = 0; i < tasks; ++i) {
        std::string cmd; // ввод команд
        std::cin >> cmd;
        if (cmd == "RESET") {
            int nodes = 0;
            std::cin >> nodes;
            d = dsu(nodes);
            std::cout << "RESET DONE" << std::endl;
        } else if (cmd == "JOIN") {
            int j, k;
            std::cin >> j >> k;
            if (d.find(j) == d.find(k)) {
                std::cout << "ALREADY" << ' ' << j << ' ' << k << std::endl; // ноды j, k уже в одной компоненте связности
            } else {
                d.merge(j, k); // если не в одной, добавляем, ничего не выводим
            }
        } else {
            int j, k;
            std::cin >> j >> k;
            if (d.find(j) == d.find(k)) { // проверка, в одной ли компоненте связности ноды j, k
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}

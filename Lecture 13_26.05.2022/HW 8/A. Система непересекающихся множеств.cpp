#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;

// Система непересекающихся множеств:

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
    dsu d = dsu(0); // инициализируем пустой dsu
    int x;
    std::vector<std::string> file;
    std::string line;
    while(getline(std::cin,line))
    {
        if (line.empty()) {
            break;
        }
        file.push_back(line);
    }
    for (auto line : file) {
        std::stringstream ss(line);
        string word;
        int i = 0;
        int nodes = 0;
        int j = 0;
        int k = 0;
        int marker = 0;
        while (ss >> word) {
            // std::cout << word << std::endl;
            if (i == 0) {
                if (word == "RESET") {
                    marker = 1;
                } else if (word == "JOIN") {
                    marker = 2;
                } else {
                    marker = 3;
                }
                ++i;
            } else if (i == 1 && marker == 1) {
                nodes = std::stoi(word);
                d = dsu(nodes);
                std::cout << "RESET DONE" << std::endl;
                break;
            } else if (i == 1 && marker != 1) {
                j = std::stoi(word);
                ++i;
            } else if (i == 2 && marker != 1) {
                k = std::stoi(word);
            }
        }
        if (marker == 2) {
            if (d.find(j) == d.find(k)) {
               std::cout << "ALREADY" << ' ' << j << ' ' << k << std::endl; // ноды j, k уже в одной компоненте связности
            } else {
                d.merge(j, k); // если не в одной, добавляем, ничего не выводим
            }
        } else if (marker == 3) {
            if (d.find(j) == d.find(k)) { // проверка, в одной ли компоненте связности ноды j, k
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}
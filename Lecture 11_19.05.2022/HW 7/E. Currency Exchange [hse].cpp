#include <iostream>
#include <vector>
using namespace std;

struct foo
{
    int a, b;
    double rate, comission;
};

int main()
{
    int a, b, n, m, s; 
    double v, rab, cab, rba, cba;
    cin >> n >> m >> s >> v;

    vector<foo> change;
    vector<double> money(n + 1, 0.f);
    money[s] = v;

    
    for (auto i = 0; i < m; ++i) {
        cin >> a >> b >> rab >> cab >> rba >> cba; 
        change.push_back({a, b, rab, cab }); 
        change.push_back({b, a, rba, cba }); 
    }

    for (auto i = 0; i < n - 1; ++i) {
        for (const auto &c : change) {
            money[c.b] = max((money[c.a] - c.comission) * c.rate, money[c.b]);
        } 
    }

    for (const auto &i : change) {
        if ((money[i.a] - i.comission) * i.rate > money[i.b]) {
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    return 0;
}
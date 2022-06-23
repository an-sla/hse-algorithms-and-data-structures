#include <iostream>
#include <vector>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(NULL);
typedef long long ll;

ll gcd(ll a, ll b){
    if (b == 0){
        return a;
    } return gcd(b, a % b);
}

struct Tree {
    int lb = 0, rb = 0;
    ll GCD = 0;
    Tree *left = nullptr, *right = nullptr;

    Tree(int lb, int rb){
        this->lb = lb;
        this->rb = rb;
        if (lb + 1 < rb){
            int m = (lb + rb) / 2;
            this->left = new Tree(lb, m);
            this->right = new Tree(m, rb);
        }
    }

    void add(int id, ll val){
        GCD = gcd(GCD, val);
        if (left != nullptr){
            if (id < left->rb){
                left->add(id, val);
            } else {
                right->add(id, val);
            }
        }
    }

    void upd(int lq, int rq, ll val){
        if (lb + 1 == rb){
            GCD = val;
        } else {
            if (lq < left->rb){
                left->upd(lq, lq + 1, val);
            } else {
                right->upd(lq, lq + 1, val);
            }
            GCD = gcd(left->GCD, right->GCD);
        }
    }

    ll get_gcd(int lq, int rq){
        if (lb >= lq && rb <= rq){
            return GCD;
        } else if (max(lb, lq) >= min(rb, rq)){
            return 0;
        } else {
            return gcd(left->get_gcd(lq, rq), right->get_gcd(lq, rq));
        }
    }


};

int main() {
    int n = 0, m = 0, x, lq = 0, rq = 0, val = 0;
    char c;
    cin >> n;
    Tree * tree = new Tree(1, n + 1);
    for (auto i = 1; i <= n; ++i){
        cin >> x;
        tree->add(i, x);
    }
    cin >> m;
    for (auto i = 1; i <= m; ++i){
        cin >> c;
        if (c == 's'){
            cin >> lq >> rq;
            cout << tree->get_gcd(lq, rq + 1) << " ";
        } else {
            cin >> lq >> val;
            tree->upd(lq, lq + 1, val);
        }
    }
    return 0;
}
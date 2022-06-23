#include <iostream>
using namespace std;

typedef long long ll;

struct Tree{
    int lb = 0, rb = 0;
    Tree *left = nullptr, *right = nullptr;
    ll MAX = INT64_MIN;

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
        MAX = max(MAX, val);
        if (left != nullptr){
            if (id < left->rb){
                left->add(id, val);
            } else {
                right->add(id, val);
            }
        }
    }

    // update для одного элемента
    void update(int id, ll val){
        if (lb + 1 == rb){
            MAX = val;
            return;
        } else {
            if (id < left->rb){
                left->update(id, val);
            } else {
                right->update(id, val);
            }
            MAX = max(left->MAX, right->MAX);
        }
    }

    ll get_max(int lq, int rq){
        if (lb >= lq && rb <= rq){
            return MAX;
        } else if (max(lb, lq) >= min(rb, rq)){
            return -2e9;
        } else {
            return max(left->get_max(lq, rq), right->get_max(lq, rq));
        }
    }


};

int main(){
    int n = 0, m = 0, lq = 0, rq = 0;
    char c;
    ll x = 0;
    cin >> n;
    Tree * tree = new Tree(1, n + 1);
    for (auto i = 1; i < n + 1; ++i){
        cin >> x;
        tree->add(i, x);
    }

    cin >> m;
    for (auto i = 0; i < m; ++i){
        cin >> c;
        if (c == 's'){
            cin >> lq >> rq;
            cout << tree->get_max(lq, rq + 1) << " ";
        } else {
            cin >> lq >> x;
            tree->update(lq, x);
        }
    }
}
#include <iostream>
#include <cmath>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

struct tree {

    int lb = 0, rb = 0;
    int64_t assign = 0;
    int64_t MAX = -2e9;
    tree *left = nullptr, *right = nullptr;

    tree(int lb, int rb){
        this->lb = lb;
        this->rb = rb;

        if (lb + 1 < rb){
            int m = (lb + rb) / 2;
            this->left = new tree(lb, m);
            this->right = new tree(m, rb);
        }
    }

    void add(int id, int64_t val) {
        MAX = max(MAX, val);
        if (left != 0){
            if (id < left->rb){
                left->add(id, val);
            } else {
                right->add(id, val);
            }
        }
    }
    void push() {

        if (assign != 0){
            MAX += assign;
            if (left != nullptr){
                left->assign += assign;
                right->assign += assign;
            }
            assign = 0;
        }
    }
    void upd(int lq, int rq, int64_t val) {
        push();
        if (lb >= lq && rb <= rq){
            assign += val;
            push();
        } else if (left != 0 && max(lb, lq) < min(rb, rq)){
            left->upd(lq, rq, val);
            right->upd(lq, rq, val);
            MAX = max(left->MAX, right->MAX);
        }
    }

    int64_t get_max(int lq, int rq){
        push();
        if (lb >= lq && rb <= rq){
            return MAX;
        } else if (max(lb, lq) >= min(rb, rq)) {
            return -2e9;
        } else {
            return max(left->get_max(lq, rq), right->get_max(lq, rq));
        }
    }

};

int main(){
    fast
            int n = 0, m = 0, x = 0, lq = 0, rq = 0, val = 0;
    char op;
    cin >> n;
    tree* t = new tree(1, n + 1);
    for (auto i = 1; i <= n; ++i){
        cin >> x;
        t->add(i, x);
    }
    cin >> m;
    for (auto i = 0; i < m; ++i){
        cin >> op;
        if (op == 'm'){
            cin >> lq >> rq;
            cout << t->get_max(lq, rq + 1) << " ";
        } else {
            cin >> lq >> rq >> val;
            t->upd(lq, rq + 1, val);
        }
    }

    return 0;
}
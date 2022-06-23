#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

vector<ll> cnt;
vector<ll> meet;
vector<ll> ans;
int sz = 0;
int res = 0;
int L = 0;
int R = -1;

struct query{
    int l, r, idx;
    ll res = 0;
    query(int l, int r, int idx) : l(l), r(r), idx(idx) {}

};

bool cmp(query &first, query &second){
    if (first.l / sz == second.l / sz){
        return first.r < second.r;
    }
    return first.l < second.l;
}

void add(int i){
    if (cnt[meet[i]]++ == 0)
        res++;
}
void del(int i){
    if (--cnt[meet[i]] == 0)
        res--;
}

void mo(query &q){
    while (L < q.l){
        del(L++);
    }
    while (L > q.l){
        add(--L);
    }

    while (R < q.r){
        add(++R);
    }

    while (q.r < R){
        del(R--);
    }
    q.res = res;
    ans[q.idx--] = q.res;
}

void bs(vector<int> &vec, int i){
    int l = -1, r = vec.size();
    while (r - l > 1){
        int m = (l + r) / 2;
        if (vec[m] <= meet[i]){
            l = m;
        } else {
            r = m;
        }
    }
    meet[i] = l;
}

int main() {
    int n, k, idx = 0, L = 0, R = -1;
    cin >> n;

    sz = static_cast<int>(sqrt(n));
    cnt.resize(n); 
    meet.resize(n);
    fill(cnt.begin(), cnt.end(), 0);

    vector<int> vec(n);
    for (auto i = 0; i < n; ++i){
        cin >> vec[i];
        meet[i] = vec[i];
    }

    sort(vec.begin(), vec.end());
    for (auto i = 0; i < n; ++i) {
        bs(vec, i);
    }

    cin >> k;
    ans.resize(k);
    vector<query> Q;
    while (k--){
        int l, r;
        cin >> l >> r;
        Q.emplace_back(--l, --r, idx++);
    }


    sort(Q.begin(), Q.end(), cmp);

    for (auto &i : Q){
        mo(i);
    }

    for (auto i : ans){
        cout << i << "\n";
    }

    return 0;
}
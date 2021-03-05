#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

class RUQ {
    int n;
    ll e;
    vector<pair<int,ll> > dat;

public: 
    RUQ(int m, ll e_) {
        n = 1;  e = e_;
        while (n < m)   n *= 2;
        dat.resize(2*n-1, pair<int,ll>(-1, e));
    }

    //tはこの更新が何回目か
    void update(int a, int b, int t, ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)  r = n;
        if (r <= a || b <= l)
            return;
        else if (a <= l && r <= b)
            dat[k] = make_pair(t, x);
        else {
            update(a, b, t, x, 2*k+1, l, (l+r)/2);
            update(a, b, t, x, 2*k+2, (l+r)/2, r);
        }
    }

    ll get(int k) {
        k += n-1;
        pair<int,ll> p = dat[k];
        while (k > 0) {
            k = (k-1) / 2;
            if (dat[k].first > p.first)
                p = dat[k];
        }
        return p.second;
    }
};

int main() {
    int n, q;   cin >> n >> q;
    RUQ sg(n, (1LL<<31)-1);
    for (int i = 0; i < q; i++) {
        int c;  cin >> c;
        if (c == 0) {
            int s, t;   ll x;   cin >> s >> t >> x;
            sg.update(s, t+1, i, x);
        }
        else {
            int k;  cin >> k;
            cout << sg.get(k) << endl;
        }
    }
    return 0;
}
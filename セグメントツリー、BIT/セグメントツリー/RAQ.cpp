#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class RAQ {
    int n;
    ll e;
    vector<ll> dat;

public:
    RAQ(int m, ll e_){
        n = 1;  e = e_;
        while (n < m)   n *= 2;
        dat.resize(2*n-1, e);
    }

    void add(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)  r = n;
        if (r <= a || b <= l)
            return;
        else if (a <= l && r <= b)
            dat[k] += x;
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
        }
    }

    ll get(int k) {
        k += n-1;
        ll res = dat[k];
        while (k > 0) {
            k = (k-1) / 2;
            res += dat[k];
        }
        return res;
    }
};

int main() {
    int n, q;   cin >> n >> q;
    RAQ sg(n, 0);
    while (q--) {
        int c;  cin >> c;
        if (c == 0) {
            int s, t;   ll x;   cin >> s >> t >> x;
            s--;    t--;
            sg.add(s, t+1, x);
        }
        else {
            int k;  cin >> k;   k--;
            cout << sg.get(k) << endl;
        }
    }
    return 0;
}
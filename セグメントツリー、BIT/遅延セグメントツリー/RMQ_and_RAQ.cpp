#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class RMQ_and_RAQ {
    int n;
    ll e1, e2;
    vector<ll> dat, lazy;

public:
    RMQ_and_RAQ(vector<ll> &v, ll e1_, ll e2_) {
        int m = v.size();
        n = 1;
        e1 = e1_;
        e2 = e2_;
        while (n < m)   n *= 2;
        dat.resize(2*n-1, e1);
        for (int i = 0; i < m; i++)
            dat[i+n-1] = v[i];
        for (int i = n-2; i >= 0; i--)
            dat[i] = min(dat[2*i+1], dat[2*i+2]);
        lazy.resize(2*n-1, e2);
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != e2) {
            dat[k] += lazy[k];
            if (r-l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }
            lazy[k] = e2;
        }
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)  r = n;
        eval(k, l, r);
        
        if (r <= a || b <= l)
            return ;
        else if (a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            dat[k] = min(dat[2*k+1], dat[2*k+2]);
        }
    }

    ll get_min(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)  r = n;
        eval(k, l, r);

        if (r <= a || b <= l)
            return e1;
        else if (a <= l && r <= b)
            return dat[k];
        else 
            return min(get_min(a, b, 2*k+1, l, (l+r)/2), get_min(a, b, 2*k+2, (l+r)/2, r));
    }
};

int main() {
    int n, q;   cin >> n >> q;
    vector<ll> v(n, 0);
    RMQ_and_RAQ sg(v, 1e15, 0);
    while (q--) {
        int c;  cin >> c;
        if (c == 0) {
            int s, t;   ll x;   cin >> s >> t >> x;
            sg.add(s, t+1, x);
        }
        else {
            int s, t;   cin >> s >> t;
            cout << sg.get_min(s, t+1) << endl;
        }
    }
    return 0;
}
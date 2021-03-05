#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class RSQ_and_RUQ {
    int n;
    ll e1, e2;
    vector<ll> dat, lazy;
    vector<bool> flag;

public:
    RSQ_and_RUQ(vector<ll> &v, ll e1_, ll e2_) {
        int m = v.size();
        e1 = e1_;
        e2 = e2_;
        n = 1;
        while (n < m)   n *= 2;
        dat.resize(2*n-1, e1);
        lazy.resize(2*n-1, e2);
        flag.resize(2*n-1, false);
        for (int i = 0; i < m; i++)
            dat[i+n-1] = v[i];
        for (int i = n-2; i >= 0; i--)
            dat[i] = dat[2*i+1] + dat[2*i+2]; 
    }

    void eval(int k, int l, int r) {
        if (flag[k]) {
            dat[k] = lazy[k] * (ll)(r-l);
            if (r-l > 1) {
                lazy[2*k+1] = lazy[k];
                flag[2*k+1] = true;
                lazy[2*k+2] = lazy[k];
                flag[2*k+2] = true;
            }
            flag[k] = false;
        }
    }

    void update(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)  r = n;
        eval(k, l, r);

        if (r <= a || b <= l)
            return ;
        else if (a <= l && r <= b) {
            lazy[k] = x;
            flag[k] = true;
            eval(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            dat[k] = dat[2*k+1] + dat[2*k+2];
        }
    }

    ll get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)  r = n;
        eval(k, l, r);

        if (r <= a || b <= l)
            return e1;
        else if (a <= l && r <= b)
            return dat[k];
        else 
            return get_sum(a, b, 2*k+1, l, (l+r)/2) + get_sum(a, b, 2*k+2, (l+r)/2, r);
    }
};

int main() {
    int n, q;   cin >> n >> q;
    vector<ll> v(n, 0);
    RSQ_and_RUQ sg(v, 0, 0);
    while (q--) {
        int c;  cin >> c;
        if (c == 0) {
            int s, t;   ll x;  
            cin >> s >> t >> x; 
            sg.update(s, t+1, x);
        }
        else {
            int s, t;   cin >> s >> t;
            cout << sg.get_sum(s, t+1) << endl;
        }
    }
    return 0;
}
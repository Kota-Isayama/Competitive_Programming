#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class RMQ {
    int n;
    ll e;
    vector<ll> dat;

public:
    RMQ(int m, ll e_) {
        n = 1;  e = e_;
        while (n < m)
            n *= 2;
        dat.resize(2*n-1, e);
    }

    void update(int k, ll x) {
        k += n-1;
        dat[k] = x;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = min(dat[2*k+1], dat[2*k+2]);
        }
    }

    ll get_min(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)  r = n;
        if (r <= a || b <= l)
            return e;
        else if (a <= l && r <= b)
            return dat[k];
        else 
            return min(get_min(a, b, 2*k+1, l, (l+r)/2), get_min(a, b, 2*k+2, (l+r)/2, r));
    }
};

int main() {
    int n, q;   cin >> n >> q;
    ll e = (1LL<<31)-1;
    RMQ sg(n, e);
    while (q--) {
        int c;  cin >> c;
        if (c == 0) {
            int x;  ll y;   cin >> x >> y;
            sg.update(x, y);
        }
        else {
            int x, y;   cin >> x >> y;
            cout << sg.get_min(x, y+1) << endl;
        }
    }
    return 0;
}
class BIT {
    int n;
    vector<ll> dat;
public:
    BIT(int m) {
        n = m;
        dat.resize(n, 0);
    }

    ll sum(int i) {
        ll res = 0;
        while (i > 0) {
            res += dat[i];
            i -= i & -i;
        }
        return res;
    }

    void add(int i, int x) {
        while (i <= n) {
            dat[i] += x;
            i += i & -i;
        }
    }
};

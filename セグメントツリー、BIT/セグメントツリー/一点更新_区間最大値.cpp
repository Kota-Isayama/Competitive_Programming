const ll e = 0;

class segment_tree {
    int n;
    vector<ll> dat;

public:
    segment_tree(int m) {
        n = 1;
        while (n < m)   n *= 2;
        dat.resize(2*n-1, e);
    }

    void update(int k, ll x) {
        k += n-1;
        dat[k] = x;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = max(dat[2*k+1], dat[2*k+2]);
        }
    }

    ll get_max(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)  r = n;
        if (r <= a || b <= l)
            return e;
        else if (a <= l && r <= b)
            return dat[k];
        else 
            return max(get_max(a, b, 2*k+1, l, (l+r)/2), get_max(a, b, 2*k+2, (l+r)/2, r));
    }
};

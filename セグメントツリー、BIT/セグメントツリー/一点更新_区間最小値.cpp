class segment_tree {
    int n;
    vector<ll> dat;
    ll inf = 1e18;

    //半開区間[a,b)の最小値を求める。
    //kは今見ている節点の番号、[l,r)はそれに対応する区間を表す。
    ll query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)
            return inf;
        
        if (a <= l && r <= b) 
            return dat[k];
        
        else 
            return min(query_sub(a, b, k*2+1, l, (l+r)/2), query_sub(a, b, k*2+2, (l+r)/2, r));
    }
public:
        segment_tree(int m) {
            n = 1;
            while (n < m)
                n *= 2;
            
            dat.resize(2*n-1, inf);
        }

    //k番目の要素をaに書き換える
    void update(int k, ll a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1)/2;
            dat[k] = min(dat[2*k+1], dat[2*k+2]);
        }
    }

    ll query(int a, int b) {
        return query_sub(a, b, 0, 0, n);
    }
};
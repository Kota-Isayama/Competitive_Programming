class union_find {
    vector<long long> par, sz, h;
    long long g;    //連結成分数

public:
     union_find(long long n) {
        par.resize(n);
        h.resize(n, 0);
        sz.resize(n,1);
        g = n;
        for (long long i = 0; i < n; i++)
            par[i] = i;
    }

    long long find(long long x) {
        if (par[x] == x)
            return x;
        else 
            return par[x] = find(par[x]);
    }

    void unite(long long x, long long y) {
        x = find(x), y = find(y);
        if (x == y)
            return ;
        
        g--;
        if (h[x] < h[y])
            swap(x, y);
        
        sz[x] += sz[y];
        sz[y] = sz[x];
        par[y] = x;
        if (h[x] == h[y])
            h[x]++;
    }

    bool same(long long x, long long y) {
        return find(x) == find(y);
    }
    
    int size(long long x) {
        return sz[x] = sz[find(x)];
    }

    long long groups() {
        return g;
    }
};
class quick_find {
    vector<int> par, sz;
    int g;

public:
    quick_find(int n) {
        par.resize(n);
        sz.resize(n, 1);
        g = n;
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        else 
            return par[x] = find(par[x]);
    }

    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b)
            return;
        
        if (sz[a] < sz[b])
            swap(a, b);

        sz[a] += sz[b];
        par[b] = a;
        g--;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int groups() {
        return g;
    }

    int size(int x) {
        return sz[find(x)];
    }
};
class union_find {
    int n, g;
    vector<int> par, sz, h;

public:
    union_find (int n_) : n(n_), g(n_) {
        par.resize(n);
        sz.resize(n, 1);
        h.resize(n, 0);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int find(int x) {
        if (x == par[x])    return x;
        else    return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return ;
        if (h[x] < h[y])    swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        if (h[x] == h[y])
            h[x] += 1;
        g--;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int number_of_groups() {
        return g;
    }
};
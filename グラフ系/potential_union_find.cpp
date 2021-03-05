#include <iostream>
#include <vector>

using namespace std;

struct potential_union_find {
    vector<int> par, sz, diff_weight;

    potential_union_find(int n) {
        par.resize(n);
        sz.resize(n);
        diff_weight.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 0;
            diff_weight[i] = 0;
        }
    }

    int find(int x) {
        if (x == par[x])
            return x;
        else {
            int r = find(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    int weight(int x) {
        find(x);
        return diff_weight[x];
    }

    int diff(int x, int y) {
        return diff_weight[y] - diff_weight[x];
    }

    bool unite(int x, int y, int w) {
        w += weight(x);
        w -= weight(y);
        
        x = find(x), y = find(y);

        if (x == y)
            return false;
        
        if (sz[x] < sz[y]) {
            swap(x, y);
            w = -w;
        }

        if (sz[x] == sz[y])
            sz[x]++;
        par[y] = x;

        diff_weight[y] = w;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class union_find {
    vector<long long> par, sz, h;

public:
     union_find(long long n) {
        par.resize(n);
        h.resize(n, 0);
        sz.resize(n,1);
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
};
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, P> PP;

ll minimum_spanning_tree(int n, vector<PP> &G) {
    ll ans = 0;
    union_find uf(n);
    sort(G.begin(), G.end());

    for (int i = 0; i < G.size(); i++) {
        int u = G[i].second.first;
        int v = G[i].second.second;
        ll cost = G[i].first;

        if (uf.same(u, v))
            continue;

        uf.unite(u, v);
        ans += cost;
        
    }
    
    return ans;
}

/*int main() {
    int V, E;   cin >> V >> E;
    vector<PP> G;
    for (int i = 0; i < E; i++) {
        int s, t;   ll w;
        cin >> s >> t >> w;
        G.push_back(PP(w, P(s, t)));
    }

    ll ans = minimum_spanning_tree(V, G);

    cout << ans << endl;

    return 0;
}*/
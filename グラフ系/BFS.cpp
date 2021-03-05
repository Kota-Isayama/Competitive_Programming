#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef struct {
    int to;
    ll cost;
} edge;
ll INF = 99999999999;
typedef pair<ll,int> P;

vector<vector<edge> > G;
vector<ll> dist;


//nは頂点数　sは出発点
void bfs(int n, int s) {
    dist.resize(n);
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[s] = 0;

    queue<P> que;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.front();  que.pop();
        ll d = p.first;
        int u = p.second;

        if (dist[u] < d)
            continue;

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].to;
            ll c = G[u][i].cost;

            if (dist[v] <= d + c)
                continue;

            dist[v] = d + c;
            que.push(P(dist[v], v));
        }
    }
}
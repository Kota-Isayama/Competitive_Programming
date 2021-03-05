struct edge {
    int to;
    ll cost;
    edge(int to, ll cost): to(to), cost(cost) {};
};
 
void dijkstra(vector<vector<edge> >&G, int s, vector<ll> &dist) {
    dist.resize(G.size());
    dist.assign(dist.size(), LINF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, s));
    while (que.size()) {
        P p = que.top();    que.pop();
        int u = p.second;   ll d = p.first;
        if (dist[u] < d)    continue;
        for (auto e: G[u]) {
            int v = e.to;   ll c = e.cost;
            if (chmin(dist[v], d+c))
                que.push(P(dist[v], v));
        }
    }
}
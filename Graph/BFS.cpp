void bfs(vector<vector<int> > &G, int s, vector<int> &dist) {
    int n = G.size();
    dist.resize(n);
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[s] = 0;
    queue<int> que; que.push(s);
    
    while (!que.empty()) {
        int u = que.front();    que.pop();
        for (int v: G[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }
}
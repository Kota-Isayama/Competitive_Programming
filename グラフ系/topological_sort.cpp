//入次数が０のものを次々に入れていく
//orderがソート済みのもの
//orderの数が頂点数に等しいとDAG、そうでなければループがある。
vector<int> topological_sort(vector<vector<int> > &adj) {
    int n = adj.size();
    vector<int> order, in_degree(n, 0);
    rep(i, n) {
        for (int v: adj[i])
            in_degree[v]++;
    }
    rep(i, n) {
        if (in_degree[i] == 0)
            order.push_back(i);
    }

    rep(i, order.size()) {
        int node = order[i];
        for (int v: adj[node]) {
            in_degree[v]--;
            if (in_degree[v] == 0)
                order.push_back(v);
        }
    }

    return order;
}
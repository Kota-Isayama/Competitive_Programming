#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef struct {
    int to;
    ll cap;
    int rev;
} edge;

vector<vector<edge> > G;
vector<bool> used;
ll INF = 10000000000000;


//辺の追加
void add_edge(int from, int to, ll cap) {
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}


//頂点vからの増加パスのフローを返す
//頂点sの時はf=INFとする
//fは現在の頂点に来るまでの増加パス中の最小の容量
ll dfs(int v, int t, ll f) {
    if (v == t)
        return f;
    
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        
        if (!used[e.to] && e.cap > 0) {
            //dはvからtへの増加パスのフロー
            ll d = dfs(e.to, t, min(f, e.cap));
            
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}


//sからtへの最大流を返す
//nは頂点数
//O(F|E|) Fは最大流量
ll max_flow(int n, int s, int t) {
    ll flow = 0;
    used.resize(n);
    while (1) {
        for (int i = 0; i < n; i++)
            used[i] = false;
        
        ll f = dfs(s, t, INF);

        if (f == 0)
            return flow;
        else 
            flow += f;
    }
}

int main() {
    int n, m;   cin >> n >> m;
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;   ll c;
        cin >> u >> v >> c;
        add_edge(u, v, c);
    }

    cout << max_flow(n, 0, n-1) << endl;

    return 0;
}
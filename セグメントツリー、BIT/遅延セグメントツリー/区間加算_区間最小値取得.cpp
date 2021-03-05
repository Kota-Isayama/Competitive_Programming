#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

const int INF = (1<<30)-1;
const ll LINF = 1e15;

#define rep(i, n) for (int i = 0; i < n; i++)

template<class T> 
bool chmax(T &a, T b) {if (a < b) {a = b;return true;}else return false;}

template<class T> 
bool chmin(T &a, T b) {if (a > b) {a = b;return true;}else return false;}

class lazy_segtree {
    int n;
    vector<ll> node, lazy;

public:

    lazy_segtree(vector<ll> &v) {
        n = 1;
        while (n < v.size())   n *= 2;

        node.resize(2*n-1, LINF);
        rep(i, v.size())
            node[i+n-1] = v[i];
        for (int i = n-2; i >= 0; i--)
            node[i] = min(node[2*i+1], node[2*i+2]);
        lazy.resize(2*n-1, 0);
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] += lazy[k];

            if (r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }

            lazy[k] = 0;
        }
    }

    void add(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        
        eval(k, l, r);
        if (r <= a || b <= l)
            return ;
        if (a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }

    ll get_minimum(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        
        eval(k, l, r);
        if (r <= a || b <= l)
            return LINF;
        if (a <= l && r <= b)
            return node[k];
        
        return min(get_minimum(a, b, 2*k+1, l, (l+r)/2), get_minimum(a, b, 2*k+2, (l+r)/2, r));
    }
};

int main() {
    int n, q;   cin >> n >> q;
    vector<ll> v(n, 0);
    lazy_segtree sg(v);
    vector<ll> ans;
    rep(k, q) {
        int c;  cin >> c;
        if (c == 0) {
            int s, t;   ll x;   cin >> s >> t >> x;
            sg.add(s, t+1, x);
        }
        else {
            int s, t;   cin >> s >> t;
            ans.push_back(sg.get_minimum(s, t+1));
        }
    }
    rep(i, ans.size())
        cout << ans[i] << endl;
    return 0;
}

//小数点精度
//cout << fixed << std::setprecision(15) << y << endl;
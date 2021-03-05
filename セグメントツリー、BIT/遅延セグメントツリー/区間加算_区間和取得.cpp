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
const ll LINF = 1e18;

#define rep(i, n) for (int i = 0; i < n; i++)

template<class T> 
bool chmax(T &a, T b) {if (a < b) {a = b;return true;}else return false;}

template<class T> 
bool chmin(T &a, T b) {if (a > b) {a = b;return true;}else return false;}

class lazy_segtree {
    int n;
    vector<ll> node, lazy;

public:
    lazy_segtree(int m) {
        n = 1;
        while (n < m)
            n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] += lazy[k];

            if (r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }

            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)  r = n;

        eval(k, l, r);

        if (b <= l || r <= a)
            return ;
        
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }

        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)
            return 0;
        
        eval(k, l, r);
        if (a <= l && r <= b)
            return node[k];
        
        return getsum_sub(a, b, 2*k+1, l, (l+r)/2) + getsum_sub(a, b, 2*k+2, (l+r)/2, r);
    }

    ll getsum(int a, int b) {
        return getsum_sub(a, b, 0, 0, n);
    }
};

int main() {
    int n, q;   cin >> n >> q;
    lazy_segtree sg(n);
    rep(k, q) {
        int query;  cin >> query;
        if (query == 0) {
            int s, t;   ll x;
            cin >> s >> t >> x;
            s--;    t--;
            sg.add(s, t+1, x);
        }
        else {
            int s, t;   cin >> s >> t;
            s--;    t--;
            cout << sg.getsum(s, t+1) << endl;
        }
    }
    return 0;
}

//小数点精度
//cout << fixed << std::setprecision(15) << y << endl;
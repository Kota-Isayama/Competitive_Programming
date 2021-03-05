#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll extended_gcd(ll x, ll y, ll &u, ll &v) {
    if (y == 0) {
        u = 1;  v = 1;
        return x;
    }
    else {
        ll g = extended_gcd(y, x%y, v, u);
        v -= u * (x/y);
        return g;
    }
}

//中国剰余アルゴリズム
//x = a mod m 
//x = b mod n の連立方程式の唯一解を返す
//gcd(m, n) = 1 が必要
ll CRA(ll m, ll n, ll a, ll b) {
    ll u, v, g, res;
    g = extended_gcd(m, n, u, v);
    
    res = a * n * v + b * m * u;
    return (m*n + res % (m*n)) % (m*n);
}

//x = a[i] mod m[i] を満たす唯一解xを求める
//ただし、gcd(m) = 1;
ll CRAs(vector<ll> &m, vector<ll> &a) {
    ll A = a[0], M = m[0];
    for (int i = 1; i < m.size(); i++) {
        A = CRA(M, m[i], A, a[i]);
        M *= m[i];
    }
    return A;
}


int main() {
    ll n;
    cout << "連立方程式は何個？："; cin >> n;
    vector<ll> m(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> m[i];
    
    cout << CRAs(m, a) << endl;
    
    return 0;
}
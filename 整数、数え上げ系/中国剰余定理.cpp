ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;

    if (b != 0) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }
    else {
        x = 1, y = 0;
    }
    return d;
}

inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
//解が存在する必要十分条件はb1 = b2 mod gcd(m1,m2)
pair<long long, long long> ChineseRem(long long b1, long long m1, long long b2, long long m2) {
    long long p, q; 
    b1 %= m1;
    b2 %= m2;
    long long d = extgcd(m1, m2, p, q);
    if ((b2-b1) % d != 0) return make_pair(0, -1);
    long long m = m1 / d * m2;
    long long tmp = (b2 - b1) / d * p % (m2/d);
    long long r = mod(b1 + m1 * tmp, m);
    return make_pair(r, m);
}

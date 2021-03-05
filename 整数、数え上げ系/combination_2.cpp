#define MAX (ll)1e6+1    //nCrのnの最大値+1

ll fac[MAX], inv[MAX], finv[MAX];

void COMinit(ll mod) {
    fac[0] = 1, finv[0] = 1;
    fac[1] = 1, inv[1] = 1, finv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mod - (inv[mod % i] * (mod/i) % mod) % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}

ll COM(ll n, ll k, ll mod) {
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * finv[k] % mod * finv[n-k] % mod;
}

ll P(ll n, ll r, ll mod) {
    if (n < r)
        return 0;
    if (n < 0 || r < 0)
        return 0;
    return fac[n] * finv[n-r] % mod;
}

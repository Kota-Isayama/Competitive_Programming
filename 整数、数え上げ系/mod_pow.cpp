ll mod_pow(ll a, ll n, ll p) {
    ll  ans = 1, tmp = a % p;
    while (n > 0) {
        if (n & 1)
            ans = ans * tmp % p;
        tmp = tmp * tmp % p;
        n = (n>>1);
    }
    return ans;
}
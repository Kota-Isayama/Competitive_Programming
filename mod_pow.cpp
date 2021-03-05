long long mod_pow(long long a, long long n, long long mod) {
    long long res = 1, pw = 1;
    while (n) {
        pw = pw * a % mod;
        if (n % 2)  
            res = res * pw % mod;
        n /= 2;
    }
    return res;
}
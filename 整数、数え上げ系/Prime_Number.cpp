#include <iostream>

using namespace std;

typedef long long ll;


//素数ならtrue
bool prime_number_judgement(ll n) {
    for (ll i = 2; i*i <= n; i++) {
        if (n%i == 0)
            return false;
    }
    return true;
}


//Nの素因数の個数をfacに格納
ll *Prime_Factorization(ll N) {
    ll *fac = new ll[N];
    ll N_ = N;
    for (ll i = 2; i*i <= N_; i++) {
        while (N % i == 0) {
            fac[i]++;
            N /= i;
        }
    }
    if (N > 1)
        fac[N]++;
    return fac;
}

//facにNの素因数の個数を格納
//約数の個数を返す。
ll Prime_Factorization_2(ll N, ll *fac, ll mod) {
    ll N_ = N;
    ll ans = 1;
    for (ll i = 2; i*i <= N_; i++) {
        while (N % i == 0) {
            fac[i]++;
            N /= i;
        }
        ans *= fac[i]+1;
        ans %= mod;
    }
    if (N > 1) {
        fac[N]++;
        ans *= 2;
        ans %= mod;
    }
    return ans;
}
#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

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

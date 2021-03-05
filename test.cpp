#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define rep(i, n)   for (int i = 0; i < n; i++)

using namespace std;
typedef long long ll;

int main() {
    int n;  cin >> n;
    if (n == 2 || n % 2) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << n/2 << endl;
    rep(i, n/2) {
        cout << 2 << " " << 2*i+1 << " " << 2*n-1-2*i << endl;
    }
    return 0;
}
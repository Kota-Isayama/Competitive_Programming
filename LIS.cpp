#include <iostream>
#include <vector>

using namespace std;


//単調増加部分列の最大の長さを返す  O(nlogn)
long long LIS(long long n, long long *a, long long INF) {
    vector<long long> dp(n, INF);

    for (long long i = 0; i < n; i++) {
        auto ite = lower_bound(dp.begin(), dp.end(), a[i]);
        *ite = a[i];
    }

    auto ite = lower_bound(dp.begin(), dp.end(), INF);

    return ite - dp.begin();
}
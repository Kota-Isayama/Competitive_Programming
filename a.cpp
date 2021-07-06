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
#include <ctype.h>

using namespace std;

typedef long long ll;

const int INF = (1<<30)-1;
const ll LINF = (1LL<<60)-1;

#define rep(i, n) for (int i = 0; i < n; i++)

template<class T> 
bool chmax(T &a, T b) {if (a < b) {a = b;return true;}else return false;}

template<class T> 
bool chmin(T &a, T b) {if (a > b) {a = b;return true;}else return false;}



//コーナーケースに気をつけろ！
int main() {
    int n, k;   cin >> n >> k;
    vector<int> p(k), b;
    rep(i, k)   cin >> p[i];
    int nx = 1, i = 0;
    stack<int> s;
    set<int> st;
    while (1) {
        while (i < k && (s.size() && s.top() != nx)) {
            st.insert(i);
            s.push(p[i++]);
        }
        if (s.empty() || s.top() != nx) {
            cout << -1 << endl;
            return 0;
        }
        
    }
    return 0;
}

//小数点精度
//cout << fixed << std::setprecision(15) << y << endl;
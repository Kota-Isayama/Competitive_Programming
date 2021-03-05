//二乗してx以下になる最大の正の整数を返す
ll sqr(ll x){
	ll r=sqrt(x)-1;
	while((r+1)*(r+1)<=x)r++;
	return r;
}


//stringで受け取った少数を10^n倍してlonglongで返す
ll x10(string s, int n) {
    int l = s.size(), m = l;
    bool is_negative = false;
    ll res = 0;
    rep(i, l) {
        if (s[i] == '-')
            is_negative = true;
        else if (s[i] == '.')
            m = i;
        else 
            res = res * 10 + (s[i] - '0');
    }
    if (is_negative)
        res *= -1;
    for (int i = 0; i < n-max(0, (l-1-m)); i++)
        res *= 10;
    return res;
}
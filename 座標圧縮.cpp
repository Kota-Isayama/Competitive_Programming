vector<ll> compress(vector<ll> &v) {
    vector<ll> vals;
    for (int i = 0; i < v.size(); i++)
        vals.push_back(v[i]);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < v.size(); i++)
        v[i] = lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin();
    return vals;
}

vector<ll> compress(vector<ll> &v, vector<ll> &u) {
    vector<ll> vals;
    for (int i = 0; i < v.size(); i++)
        vals.push_back(v[i]);
    for (int i = 0; i < u.size(); i++)
        vals.push_back(u[i]);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < v.size(); i++)
        v[i] = lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin();
    for (int i = 0; i < u.size(); i++)
        u[i] = lower_bound(vals.begin(), vals.end(), u[i]) - vals.begin();
    return vals;
}

vector<ll> compress(vector<vector<ll> >& v) {
    vector<ll> vals;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            vals.push_back(v[i][j]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            v[i][j] = lower_bound(vals.begin(), vals.end(), v[i][j]) - vals.begin();
    }
    return vals;
}
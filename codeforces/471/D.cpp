// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

int rabin_karp(string const& s, string const& t) {
    debug(s, t);
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - ' ' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - ' ' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences.size();
}

void solve()
{
    int n, m; cin >> n >> m;
    if (m == 1) {
        cout << n << endl;
        return;
    }
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> w(m);
    for (int i = 0; i < m; ++i) {
        cin >> w[i];
    }
    vector<int> vd(n-1);
    for (int i = 0; i < n-1; ++i) {
        vd[i] = v[i+1] - v[i];
    }
    vector<int> wd(m-1);
    for (int i = 0; i < m-1; ++i) {
        wd[i] = w[i+1] - w[i];
    }
    ostringstream s1;
    for (auto& x : vd) {
        s1 << x << ' ';
    }
    ostringstream s2;
    for (auto& x : wd) {
        s2 << x << ' ';
    }
    cout << rabin_karp(s2.str(), s1.str()) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
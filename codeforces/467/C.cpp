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

void test()
{
    int n, m, k; cin >> n >> m >> k;
    // n : arr size, m: range size, k: num ranges
    // n < 5000
    // choose k non overlapping ranges of size m so that sum is maximised
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> p = {accumulate(v.begin(), v.begin()+m, 0ll)};
    for (int i = m; i < n; ++i) {
        p.push_back(p.back() - v[i-m] + v[i]);
    }
    int s = p.size();
    int dp    [s];
    int maxdp [s];
    memset(dp, 0, sizeof(dp));
    memset(maxdp, 0, sizeof(maxdp));
    print("Mem: ", (sizeof(dp) + sizeof(maxdp)) >> 10, "KB");
    for (int j = 0; j < k; ++j) {
        int new_dp   [s];
        int new_maxdp[s];
        for (int i = 0; i < s; ++i) {
            new_dp[i] = p[i] + (i>=m&&j?maxdp[i-m]:0);
            new_maxdp[i] = max(i?new_maxdp[i-1]:0, new_dp[i]);
        }
        for (int i = 0; i < s; ++i) {
            dp[i] = new_dp[i];
            maxdp[i] = new_maxdp[i];
        }
    }
    cout << maxdp[s-1] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
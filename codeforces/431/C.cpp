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

int N, K, D;
const int mod = 1e9+7;

int dp[101][101];

int solve (int n, int d)
{
    if (n < d) {
        return 0;
    }
    if (n <= 0) {
        return n == 0 and d == 0;
    }
    if (dp[n][d]) {
        return dp[n][d];
    }
    debug(n,d);
    int ans = 0;
    for (int i = 1; i <= K; ++i) {
        if (i >= d)
            ans += solve(n-i, 0);
        else
            ans += solve(n-i, d);
        ans %= mod;
    }
    return dp[n][d] = ans;
}

void test()
{
    cin >> N >> K >> D;
    debug(N, K, D);
    cout << solve(N, D) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
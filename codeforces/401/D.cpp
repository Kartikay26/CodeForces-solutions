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

int n, m, d;
string s;

int dp[1<<18][101];

void solve()
{
    cin >> n >> m;
    s = to_string(n);
    d = s.size();
    // PUSH DP
    dp[0][0] = 1;
    for (int mask = 0; mask < (1<<d); ++mask) {
        for (int mod = 0; mod < m; ++mod) {
            // we have used digits set in _mask_
            // choice: which number to set next?
            for (int i = 0; i < d; ++i) {
                if (!(mask & (1<<i))) {
                    // we will use this as next digit
                    int digit = s[i] - '0';
                    if (!digit && !mask) continue;
                    int next_mod = (mod*10 + digit) % m;
                    dp[mask|(1<<i)][next_mod] += dp[mask][mod];
                }
            }
        }
    }
    int fact = 1;
    for (int k = 0; k < 10; ++k) {
        int cnt = count(s.begin(), s.end(), k+'0');
        for (int i = 1; i <= cnt; ++i) {
            fact *= i;
        }
    }
    cout << dp[(1<<d)-1][0] / fact << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
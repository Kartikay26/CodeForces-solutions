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

vector<int> a;

int solve(int i, int j, int l = 0)
{
    if (i == j)
        return 0;
    debug(i, j);
    int m = i;
    for (int x = i; x < j; ++x) {
        if (a[x] < a[m]) {
            m = x;
        }
    }
    int h = a[m] - l;
    int ans = min(
        h + solve(i, m, a[m]) + solve(m+1, j, a[m]),
        j - i
    );
    debug(i,j, ans);
    return ans;
}

void solve()
{
    int n; cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(0, n) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
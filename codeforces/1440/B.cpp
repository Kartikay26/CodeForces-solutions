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

void test(int)
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n*k);
    for (int i = 0; i < n*k; ++i) {
        cin >> v[i];
    }
    int ans = 0;
    int leave = n/2 + 1;
    debug(n,k,leave);
    for (int i = 0; i < k; ++i) {
        int pos = n*k - leave * (i+1);
        debug(pos, v[pos]);
        ans += v[pos];
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
    {
        test(i);
    }
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
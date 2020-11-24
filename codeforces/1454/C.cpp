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
    int n; cin >> n;
    vector<int> v(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    cnt[v.front()]--;
    cnt[v.back()]--;
    for (int i = 0; i < n-1; ++i) {
        int a = v[i], b = v[i+1];
        if (a == b) {
        	cnt[a]--;
        }
    }
    int ans = 1e18;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, cnt[v[i]] + 1);
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
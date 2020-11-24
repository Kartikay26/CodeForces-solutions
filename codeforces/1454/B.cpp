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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i+1;
    }
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cnt[v[i].first]++;
    }
    pair<int, int> ans = {1e18, -1};
    for (int i = 0; i < n; ++i) {
        if (cnt[v[i].first] == 1) {
        	ans = min(ans, v[i]);
        }
    }
    cout << ans.second << endl;
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
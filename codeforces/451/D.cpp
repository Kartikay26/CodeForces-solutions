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

void solve()
{
    string s; cin >> s;
    int cnt[2][2] = {0}; // a/b, e/o
    int ans[2] = {0};
    for (char c : s) {
        cnt[c-'a'][0]++;
        swap(cnt[0][0], cnt[0][1]);
        swap(cnt[1][0], cnt[1][1]);
        ans[0] += cnt[c-'a'][0];
        ans[1] += cnt[c-'a'][1];
    }
    cout << ans[0] << ' ' << ans[1] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
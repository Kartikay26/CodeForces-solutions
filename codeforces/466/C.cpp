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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int p = 0;
    for(int& i : v){
        p += i; i = p;
    }
    debug(v);
    int c = v.back();
    if (c % 3 != 0) {
        cout << 0 << endl; return;
    }
    int a = c / 3;
    int b = a * 2;
    debug(a,b,c);
    array<int, 2> dp = {0, 0};
    for (int i = 0; i < n-1; ++i) {
        int x = v[i];
        if (x == b) {
            dp[1] += dp[0];
        }
        if (x == a) {
            dp[0] += 1;
        }
    }
    cout << dp[1] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
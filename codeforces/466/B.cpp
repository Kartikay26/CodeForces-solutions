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
    int n, a, b; cin >> n >> a >> b;
    n *= 6;
    int ans = 1e18;
    int ans_a = 0;
    int ans_b = 0;
    if (a*b >= n) {
        cout << a*b << endl << a << " " << b << endl;
        return;
    }
    for (int x = 1; x*x <= n; ++x) {
        int y = (n+x-1)/x;
        debug(x, y, x*y);
        if ((x >= a and y >= b) or (x >= b and y >= a)) {
            if (x*y < ans) {
                ans = x*y;
                ans_a = x;
                ans_b = y;
            }
        }
    }
    if (!(ans_a >= a and ans_b >= b)) {
        swap(ans_a, ans_b);
    }
    cout << ans << endl;
    cout << ans_a << " " << ans_b << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
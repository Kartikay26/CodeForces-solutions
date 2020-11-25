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

int solve(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    return n % 2 ? 3 : 2;
}

void test(int)
{
    int n; cin >> n;
    cout << solve(n) << endl;
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
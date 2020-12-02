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

void testcase(int)
{
    string s; cin >> s;
    cout << s.size() << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
    {
        testcase(i);
    }
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
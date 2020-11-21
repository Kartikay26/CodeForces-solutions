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
    int k; cin >> k;
    string s; cin >> s;
    int p = 0;
    map<int, int> cnt = {{0,1}};
    int a = 0;
    for (char c: s) {
        p += c == '1';
        a += cnt[p-k];
        cnt[p]++;
    }
    cout << a << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
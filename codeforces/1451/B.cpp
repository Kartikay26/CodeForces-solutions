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

int n;
int q;
string s;

void preprocess()
{
    cin >> n;
    cin >> q;
    cin >> s;
}

bool query(int)
{
    int a, b; cin >> a >> b;
    for (int i = 0; i < a-1; ++i) {
        if (s[i] == s[a-1])
            return true;
    }
    for (int i = b; i < n; ++i) {
        if (s[i] == s[b-1])
            return true;
    }
    return false;
}

int32_t main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        preprocess();
        for (int i = 0; i < q; ++i)
        {
            cout << (query(i) ? "YES" : "NO") << endl;
        }
    }
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
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
    int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    int z = 0, o = 0;
    for (char c : s) {
        if (c == '0') z++;
        if (c == '1') o++;
    }
    if (c0 > c1) {
        swap(c0, c1);
        swap( z,  o);
    }
    // c0 is now always lower
    int delta_c = c1 - c0;
    int init_cost = z * c0 + o * c1;
    int final_cost = init_cost;
    if (delta_c > h) {
        z = n;
        final_cost += (h - delta_c) * o;
    }
    cout << final_cost << endl;
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
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

// Usage: TTTT..TTFFF  low <= i < high
int findLastTrue(int low, int high, function<bool(int)> check, bool debug = false)
{
    if (debug) {
        bool prev = true;
        for (int i = low; i < high; ++i) {
            bool chk = check(i);
            debug(i, chk);
            assert(prev or not chk);
            prev = chk;
        }
    }
    if (!check(low))
        return low-1;
    int i = low;
    for (int b = (high - low); b > 0; b /= 2) {
        while (i+b < high and check(i+b)) i += b;
    }
    return i;
}

void test()
{
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (auto& x : s) {
        if (x == 'B') a++;
        if (x == 'S') b++;
        if (x == 'C') c++;
    }
    int na, nb, nc;
    cin >> na >> nb >> nc;
    int pa, pb, pc;
    cin >> pa >> pb >> pc;
    int r;
    cin >> r;
    cout << findLastTrue(0, 2e12, [&](int x) {
        // I want to find if I can make x sandwiches?
        // We need to buy a*x-na, b*x-nb, c*x-nc ingredients
        // just see if we have that much money
        return max(a*x-na, 0ll)*pa
             + max(b*x-nb, 0ll)*pb
             + max(c*x-nc, 0ll)*pc <= r;
    }, false) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
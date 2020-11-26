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
    int n; cin >> n;
    int ans[n] = {0};
    // ====================== N - 1 Queries ======================
    for (int i = 0; i < n-1; ++i) {
        cout << "XOR " << i+1 << " " << i+2 << endl;
        int x; cin >> x;
        ans[i+1] = ans[i] ^ x;
    }
    
    // ====================== 2 Queries left ======================
    // search for any two equal elements in the array
    map<int, int> m; // number -> position
    int i = -1, j = -1;
    for (int a = 0; a < n; ++a) {
        if (m.count(ans[a])) {
            i = m[ans[a]];
            j = a;
            break;
        } else {
            m[ans[a]] = a;
        }
    }

    if (i == -1 and j == -1) {
        // gotta look for 00001 and 11110 and AND/OR them with 0
        for (int a = 0; a < n; ++a) {
            if (ans[a] == 1)   i = a;
            if (ans[a] == n-2) j = a;
        }
        cout << "AND 1 " << i+1 << endl;
        cout << "AND 1 " << j+1 << endl;
        int x, y; cin >> x >> y;
        ans[0] = (x&(n-1)) | (y&1);
    } else {
        // we have found indices that are equal, just ask for their OR
        cout << "OR " << i+1 << " " << j+1 << endl;
        int x; cin >> x;
        ans[0] = ans[i] ^ x;
    }

    // ===========================================================
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << (ans[i] ^ (i?ans[0]:0)) << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
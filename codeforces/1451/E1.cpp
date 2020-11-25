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
    vector<int> ans(n); // ans[i] will store the answer
    vector<int> x0r(n); // x0r[i] will store ans[i] ^ ans[i+1]
    // int runnning_xor = 0;
    for (int i = 0; i < n-1; ++i) {
        cout << "XOR " << i+1 << " " << i+2 << endl;
        cin >> x0r[i];
        // runnning_xor ^= x0r[i];
    }
    // runnning_xor ^= (n-1);
    // x0r[n-2] = runnning_xor;
    cout << "AND 1 2" << endl;
    cout << "AND 2 3" << endl;
    cout << "AND 1 3" << endl;
    int x, y, z; cin >> x >> y >> z;
    debug(x,y,z);
    for (int i = 0; i < n; ++i) {
        int a = i;
        int b = a ^ x0r[0];
        int c = b ^ x0r[1];
        if ((a & b) == x and (b & c) == y and (c & a) == z) {
            ans[0] = i;
            break;
        }
    }
    for (int i = 1; i < n; ++i) {
        ans[i] = ans[i-1] ^ x0r[i-1];
    }
    cout << "! ";
    for (auto& x : ans) {
        cout << x << " ";
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
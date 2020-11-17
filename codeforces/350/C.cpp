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

#define x first
#define y second

void test()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
    	return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
    });
    debug(v);
    int m = 0;
    for (auto& [a, b] : v) {
        if (a == 0) m+=2;
        if (b == 0) m+=2;
    }
    cout << (6*n - m) << '\n';
    for (auto& [a, b] : v) {
    	if (a) cout << 1 << " " << abs(a) << " " << "LR"[a>0] << '\n';
    	if (b) cout << 1 << " " << abs(b) << " " << "DU"[b>0] << '\n';
        cout << 2 << '\n';
    	if (a) cout << 1 << " " << abs(a) << " " << "RL"[a>0] << '\n';
    	if (b) cout << 1 << " " << abs(b) << " " << "UD"[b>0] << '\n';
        cout << 3 << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
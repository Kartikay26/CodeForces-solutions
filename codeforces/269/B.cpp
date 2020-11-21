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
    int n, m; // m = num species
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        float x; // dummy
        cin >> v[i] >> x;
    }
    debug(v);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[v[i]].push_back(i);
    }
    int cnt = 0;
    for (auto& [k, positions] : mp) {
        for (auto& i : positions) {
            v[i] = cnt++;
        }
    }
    debug(v);

    set<int> s;
    for (auto& x : v) {
        auto it = s.lower_bound(x);
        if (it != s.end()) {
            s.erase(it);
        }
        s.insert(x);
    }

    cout << n - s.size() << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
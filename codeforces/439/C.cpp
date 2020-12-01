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

void check(bool cond) {
    if (!cond) {
        cout << "NO" << endl;
        exit(0);
    }
}

void solve()
{
    int n, k, p; cin >> n >> k >> p;
    // p parts even
    int o = k - p;
    // o parts odd
    vector<int> even;
    vector<int> odd;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x % 2 == 0) {
            even.push_back(x);
        } else {
            odd.push_back(x);
        }
    }

    vector<vector<int>> ans;
    vector<int> remaining;
    
    check(o <= odd.size());
    
    for (int i = 0; i < o; ++i) {
        ans.push_back({odd[i]});
    }
    for (int i = o; i < odd.size(); ++i) {
        remaining.push_back(odd[i]);
    }
    
    check(remaining.size() % 2 == 0);
    check(remaining.size() / 2 + even.size() >= p);

    for (int i = 0; i < p; ++i) {
        if (i != p-1) {
            if (i < even.size()) {
                ans.push_back({even[i]});
            } else {
                int j = (i - even.size()) * 2;
                ans.push_back({remaining[j], remaining[j+1]});
            }
        } else {
            // put everything that's left in one big group
            // even [i] to even[end] and remaining[j] to remaining[end]
            vector<int> big_grp;
            for (int k = i; k < even.size(); ++k) {
                big_grp.push_back(even[k]);
            }
            int j = max((i - int(even.size())) * 2, 0ll);
            for (int k = j; k < remaining.size(); ++k) {
                big_grp.push_back(remaining[k]);
            }
            ans.push_back(big_grp);
        }
    }

    if (p == 0) {
        ans.back().insert(ans.back().end(), even.begin(), even.end());
        ans.back().insert(ans.back().end(), remaining.begin(), remaining.end());
    }

    cout << "YES" << endl;
    for (auto& v : ans) {
        cout << v.size() << " ";
        for (auto& x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
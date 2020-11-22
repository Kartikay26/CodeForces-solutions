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
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    set<int> ans;
    if (n == 1) {
        cout << -1 << endl;
        return;
    } else if (n == 2) {
        ans.insert(2*v[0]-v[1]);
        ans.insert(2*v[1]-v[0]);
        if ((v[0] + v[1]) % 2 == 0) {
            ans.insert((v[0]+v[1])/2);
        }
    } else {
        // n == 3 or more
        map<int, int> diff;
        for (int i = 1; i < n; ++i) {
            diff[v[i] - v[i-1]]++;
        }
        int f = v.front();
        int b = v.back();
        if (diff.size() == 1) {
            int r = diff.begin()->first;
            ans.insert(f-r);
            ans.insert(b+r);
        } else if (diff.size() == 2) {
            vector<pair<int, int>> r(diff.begin(), diff.end());
            sort(r.begin(), r.end(), [&](pair<int, int> a, pair<int, int> b) {
                return a.second > b.second;
            });
            if (r[1].second == 1 and r[1].first == 2*r[0].first) {
                int a = -1e18;
                for (int i = 1; i < n; ++i) {
                    if(v[i] - v[i-1] == r[1].first) {
                        a = (v[i] + v[i-1]) / 2;
                    }
                }
                ans.insert(a);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto& x : ans) {
        cout << x << ' ';
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
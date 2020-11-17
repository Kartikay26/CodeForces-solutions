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
    int n, m;
    cin >> n >> m;
    vector<array<int, 6>> ans;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1'){
                if (i == n-1 and j == m-1) {
                    ans.push_back({i,j, i-1,j,   i,j-1});
                    ans.push_back({i,j, i-1,j-1, i,j-1});
                    ans.push_back({i,j, i-1,j-1, i-1,j});
                } else if (i == n-1) {
                    ans.push_back({i,j, i-1,j,   i,j+1});
                    ans.push_back({i,j, i-1,j+1, i,j+1});
                    ans.push_back({i,j, i-1,j+1, i-1,j});
                } else if (j == m-1) {
                    ans.push_back({i,j, i+1,j,   i,j-1});
                    ans.push_back({i,j, i+1,j-1, i,j-1});
                    ans.push_back({i,j, i+1,j-1, i+1,j});
                } else {
                    ans.push_back({i,j, i+1,j,   i,j+1});
                    ans.push_back({i,j, i+1,j+1, i,j+1});
                    ans.push_back({i,j, i+1,j+1, i+1,j});
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto& r : ans) {
        for (auto& x : r) {
            cout << x+1 << " ";
        }
        cout << "\n";
    }
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
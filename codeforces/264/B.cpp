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

vector<int> factorize (int num)
{
    vector<int> ans;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            num /= i;
            ans.push_back(i);
            i--;
        }
    }
    if(num > 1) ans.push_back(num);
    return ans;
}

void test()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    map<int, int> dp;
    for (auto& x : v) {
        int ans = 0;
        auto f = factorize(x);
        for (auto& p : f) {
            ans = max(ans, dp[p]+1);
        }
        for (auto& p : f) {
            dp[p] = ans;
        }
    }
    int ans = 0;
    for (auto& [x,y] : dp) {
        ans = max(ans, y);
    }
    cout << max(ans, 1ll) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
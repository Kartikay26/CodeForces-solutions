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

void test(int)
{
    int n; cin >> n;
    vector<int> f = factorize(n);
    int ans = 0;
    int ansp = 0;
    map<int, int> cnt;
    for (auto& p : f) {
        cnt[p]++;
        if (cnt[p] > ans) {
        	ans = cnt[p];
        	ansp = p;
        }
    }
    debug(f);
    debug(cnt);
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        if (i == ans - 1) {
        	cout << n << endl;
        }
        else {
        	cout << ansp << " ";
        	n /= ansp;
        }
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
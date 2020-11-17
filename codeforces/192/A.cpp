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

int solve(int k)
{
	int d = sqrt(8*k+1);
	if (d * d == 8*k+1) {
		return (d - 1)/2;
	}
	return -1;
}

void test()
{
	int n;
	cin >> n;
    for (int k1 = 1, i = 1; k1 < n; ++i, k1 += i) {
    	int k2 = n-k1;
    	if (solve(k2) != -1) {
    		cout << "YES\n"; return;
    	}
    }
    cout << "NO\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
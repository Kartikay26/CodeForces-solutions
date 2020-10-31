// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

void solve()
{
	int n, a, b, c; cin >> n >> a >> b >> c;
	int ans = 0;
	for (int i = 0; i <= 4000; ++i) {
		for (int j = 0; j <= 4000; ++j) {
			// n == i*a + j*b + k*c
			int kc = n - i*a - j*b;
			if (kc >= 0 and kc % c == 0) {
				int k = kc / c;
				ans = max(ans, i+j+k);
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
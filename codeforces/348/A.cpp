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

void test()
{
	int n; cin >> n;
	ll s = 0;
	ll m = 0;
	for (int i = 0; i < n; ++i)
	{
		ll x; cin >> x;
		s += x;
		m = max(m, x);
	}
	cout << max(m, (s + n - 2) / (n - 1)) << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
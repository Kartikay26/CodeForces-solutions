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

void test (int)
{
	int n, m; cin >> n >> m;
	vector<int> v;
	int total = 0;
	int neg = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x; cin >> x;
			if (x<0) neg++;
			v.push_back(abs(x));
			total += abs(x);
		}
	}
	sort(v.begin(), v.end());
	if (neg%2 == 1) {
		total -= 2 * v[0];
	}
	cout << total << endl;
}

int32_t main ()
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
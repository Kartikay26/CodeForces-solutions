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
	int N; cin >> N; // num elements
	int n = sqrt(N); // side length
	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	int k = __builtin_ctz(n);
	ll ans = 0;
	for (int i = 0; i <= k; ++i) {
		int s = 1<<(2*i);
		ans += accumulate(v.begin(), v.begin() + s, 0ll);
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
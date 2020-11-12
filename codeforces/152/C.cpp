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

const int mod = 1e9+7;

void test()
{
	int n, m; cin >> n >> m;
	vector<set<char>> chars(m); // characters in each col
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			chars[j].insert(s[j]);
		}
	}
	vector<int> distinct(m); // number of distinct chars in each col
	for (int j = 0; j < m; ++j) {
		distinct[j] = chars[j].size();
	}
	debug(distinct);
	ll ans = 1;
	for (auto& x : distinct) {
		ans *= ll(x);
		ans %= mod;
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
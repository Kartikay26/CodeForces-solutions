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

bool check (string s, int k) // check if S = k * s1
{
	if (s.size() % k != 0) {
		assert(false);
		return false;
	}
	for (int i = 0; i < k; ++i) {
		for (int j = k; j < s.size(); j += k) {
			if (s[j+i] != s[i]) {
				return false;
			}
		}
	}
	return true;
}

void test ()
{
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	int g = __gcd(n, m);
	int ans = 0;
	for (int i = 1; i <= g; ++i) {
		if (g % i == 0) {
			debug("check", i);
			if (check(a, i) && check(b, i) && a.substr(0, i) == b.substr(0, i)) {
				debug(i);
				ans++;
			}
		}
	}
	cout << ans << endl;
}

int32_t main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
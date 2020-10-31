// kartikay26
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

bool solve()
{
	string s; cin >> s;
	char last = '.';
	int ans = 0;
	for (char c : s)
	{
		if (c == last) {
			ans++;
		} else {
			ans = 1;
		}
		debug(ans, c);
		if (ans >= 7)
		{
			return true;
		}
		last = c;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << (solve() ? "YES" : "NO") << endl;
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
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
	string match = "hello";
	vector<bool> dp(match.size());
	for (char c : s)
	{
		for (int i = match.size()-1; i >= 0; --i)
		{
			if (c == match[i] && (i == 0 || dp[i-1]))
			{
				dp[i] = true;
			}
		}
		debug(c, dp);
	}
	return dp.back();
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << (solve() ? "YES" : "NO") << endl;
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
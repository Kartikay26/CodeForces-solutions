// kartikay26
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

bool lucky (int n)
{
	for (char c : to_string(n))
	{
		if (c != '4' and c != '7')
		{
			return false;
		}
	}
	return true;
}

bool almost_lucky(int n)
{
	for (int i = 1; i <= 1000; ++i)
	{
		if (n % i == 0 and lucky(i))
		{
			return true;
		}
	}
	return false;
}

void solve()
{
	int x; cin >> x;
	cout << (almost_lucky(x) ? "YES" : "NO") << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
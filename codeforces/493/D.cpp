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
	int n; cin >> n;
	if (n % 2 == 0) {
		cout << "white\n1 2\n";
	} else {
		cout << "black\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
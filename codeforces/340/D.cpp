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
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	set<int> s;
	for (auto& i : v) {
		auto it = s.lower_bound(i);
		if (it != s.end()) {
			s.erase(it);
		}
		s.insert(i);
		debug(s);
	}
	cout << s.size() << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
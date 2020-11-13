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

void test(int)
{
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	set<int> s(v.begin(), v.end());

	if (s.size() == v.size()) {
		cout << "NO";
	} else {
		cout << "YES";
	}
	cout << endl;
}

int main()
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
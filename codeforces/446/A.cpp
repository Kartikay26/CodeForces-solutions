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
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<vector<int>> s;
	for (auto& x : v) {
		if (s.empty()) {
			s.push_back({x});
		} else {
			if (x > s.back().back()) {
				s.back().push_back(x);
			} else {
				s.push_back({x});
			}
		}
	}
	debug(s);
	int ans = s[0].size();
	for (int i = 0; i < s.size()-1; ++i) {
		vector<int>& v1 = s[i];
		vector<int>& v2 = s[i+1];
		bool ok = false;
		// check mergability, if cannot merge -> continue
		if (v1.size() > 1 and v2.size() > 1) {
			int a = v1[v1.size()-2];
			int b = v1[v1.size()-1];
			int c = v2[0];
			int d = v2[1];
			// given : ... < a < b and c < d < ... (but b >= c)
			if (a < c-1) // make b = c-1
				ok = true;
			if (b+1 < d) // make c = b+1
				ok = true;
		}
		if (ok)
			ans = max(ans, int (v1.size() + v2.size()));
		else
			ans = max(ans, int (max(v1.size(), v2.size()) + 1));
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
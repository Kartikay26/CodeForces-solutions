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

void test (int)
{
	int n, w; cin >> n >> w;
	int lo = ((w+1)/2), hi = w;
	vector<int> v1(n);
	for (int i = 0; i < n; ++i) {
		cin >> v1[i];
	}
	vector<pair<int, int>> v;
	int ps = 0;
	for (int i = 0; i < n; ++i) {
		int x = v1[i];
		if (x > hi) {
			// discard
		} else if (x >= lo and x <= hi) {
			// got answer
			cout << 1 << endl;
			cout << i+1 << endl;
			return;
		} else {
			// check later
			v.push_back({x, i});
			ps += x;
		}
	}
	
	if (ps < lo) {
		cout << -1 << endl;
		return;
	}

	// consider now only elements below w/2
	n = v.size();
	sort(v.begin(), v.end());
	// main idea: w/3 + w/3 + w/3 is the worst that can happen
	int ans = 0;
	int s = 0;
	for (int i = 0; i < n; ++i) {
		s += v[i].first;
		if (s >= lo and s <= hi) {
			ans = i;
			break;
		}
	}
	cout << ans+1 << endl;
	for (int i = 0; i <= ans; ++i) {
		cout << v[i].second+1 << " ";
	}
	cout << endl;
}

int32_t main ()
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
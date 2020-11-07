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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int l = 0, r = 1;
	ll sum = a[0];
	int ans = a[0];
	int ans_size = 1;
	while (r <= n) {
		int len = r - l;
		int last_el = a[r-1];
		if (len * 1ll * last_el - sum <= k) {
			if (len > ans_size) {
				ans = last_el;
				ans_size = len;
			}
			// we can add more, but check if we reached the end
			if (r == n) break;
			sum += a[r]; r++;
		} else {
			// remove first el
			sum -= a[l]; l++;
		}
	}
	cout << ans_size << ' ' << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
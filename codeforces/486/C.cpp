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
	int n, p; cin >> n >> p;
	string s; cin >> s;
	int ans = 0;
	vector<int> v;
	for (int i = 0; i < n-1-i; ++i) {
		int j = n-1-i;
		int a = s[i] - 'a';
		int b = s[j] - 'a';
		int d = min((a-b+26)%26, (b-a+26)%26);
		v.push_back(d);
		ans += d;
	}
	p--;
	p = min(p, n-1-p);
	bool ok = false;
	for (auto& i : v) {
		if (i) ok = true;
	}
	if (!ok) {
		cout << 0 << endl; // already palindrome
		return;
	}
	int firstone = -1;
	int lastone = -1;
	int m = v.size();
	for (int i = 0; i < m; ++i) {
		if (v[i]) {
			firstone = i; break;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (v[i]) {
			lastone = i;
		}
	}
	ans += lastone - firstone;
	ans += min(abs(p - firstone), abs(p - lastone));
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
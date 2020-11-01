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
	string s = to_string(n);
	reverse(s.begin(), s.end());
	string prev = "";
	for (char c : s) {
		debug(c, c+prev);
		prev += c;
		if (c == '1'){
			if (not (prev == "1" or prev == "41" or prev == "441")) {
				cout << "NO\n"; return;
			}
			prev = "";
		}
	}
	if (prev != "") {
		cout << "NO\n"; return;
	}
	cout << "YES\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
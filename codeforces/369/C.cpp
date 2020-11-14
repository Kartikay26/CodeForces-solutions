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

const int N = 1e5+1;
bool                   mark [N];
vector<pair<int, int>> edges[N]; // to, type

bool dfs(int x, int p = -1, bool to_mark = false) // returns 'marked'
{
	if (to_mark) {
		mark[x] = 1;
	}
	bool marked = false;
	for (auto [y, t] : edges[x]) {
		if (y == p)
			continue;
		marked |= dfs(y, x, t == 2); // mark if t = 2
	}
	if (marked) {
		mark[x] = 0;
	}
	return to_mark || marked;
}

void test()
{
	int n; cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b, x; cin >> a >> b >> x;
		edges[a].push_back({b, x});
		edges[b].push_back({a, x});
	}
	dfs(1);
	int ans = accumulate(mark+1, mark+1+n, 0);
	cout << ans << endl;
	for (int i = 1; i <= n; ++i) {
		if (mark[i])
			cout << i << " ";
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
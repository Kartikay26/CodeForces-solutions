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
	int n, m; cin >> n >> m;
	int a[n][m];
	
	map<int, vector<pair<int, int>>> positions;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			positions[a[i][j]].push_back({i,j});
		}
	}

	debug(positions);

	for (auto& [k, v] : positions) {
		// k is the integer, in increasing order
		// v contains all the positions
		debug(k,v);
		for (auto& [x, y] : v) {
			if ((x+y+k)%2) {
				a[x][y] += 1;
				positions[k+1].push_back({x,y});
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	debug("done");
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
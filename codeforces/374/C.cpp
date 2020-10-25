// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(...)
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef vector<int> vi; typedef long long int ll;

const int mod = 1e9+7;
const int N = 1e3+1;

int n, m;

char grid[N][N]; // input grid
int  dans[N][N]; // dfs answers
int  vis[N][N];  // visited status

int vis_token = 1;
// 1 = processing 1
// 2 = done processing 1

// down, up, right, left
int dx[] = {1, -1,  0,  0};
int dy[] = {0,  0,  1, -1};

map<char, char> next_ = {
	{'D', 'I'},
	{'I', 'M'},
	{'M', 'A'},
	{'A', 'D'},
};

bool check(int i, int j) {return 0<=i && i<n and 0<=j && j<m;}

int dfs(int i, int j) { // dfs(i,j): return longest path from i, j
	if (vis[i][j]) {
		if (vis[i][j] % 2 == 1) return dans[i][j]=1e9; // cycle found! [back edge]
		if (vis[i][j] % 2 == 0) return dans[i][j]; // no cycle, but return size of this component
	}
	vis[i][j] = vis_token; // odd number : processing
	int ans = 1;
	for (int d = 0; d < 4; ++d) {
		int ii = i + dx[d];
		int jj = j + dy[d];
		if (check(ii, jj) && grid[ii][jj] == next_[grid[i][j]]) {
			ans = max(ans, dfs(ii, jj) + 1);
		}
	}
	vis[i][j] = vis_token + 1; // even number : finished
	return dans[i][j]=ans;
}

void solve(){
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (vis[i][j] == 0 and grid[i][j] == 'D') {
				dfs(i, j);
				ans = max(dans[i][j], ans);
				vis_token += 2;
				// print("--- vis:");
				// for (int i = 0; i < n; ++i) {
				// 	for (int j = 0; j < m; ++j) {
				// 		prints(vis[i][j], "\t");
				// 	} print();
				// }
				// print("--- dans:");
				// for (int i = 0; i < n; ++i) {
				// 	for (int j = 0; j < m; ++j) {
				// 		prints(dans[i][j], "\t");
				// 	} print();
				// }
			}
		}
	}
	
	ans /= 4;

	if (ans == 0) {
		cout << "Poor Dima!" << endl;
	} else if (ans >= 1e8) {
		cout << "Poor Inna!" << endl;
	} else {
		cout << ans << endl;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
#include <bits/stdc++.h>
// #include "prettyprint.hpp"
using namespace std;

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

#define debug(x) cout << "debug: " << #x " = " << x << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int32_t main(){
	fast_io();

	int n, m; cin >> n >> m;
	vector<string> Matrix(n);
	for (int i = 0; i < n; ++i) {
		cin >> Matrix[i];
	}

	bool flags[n][m];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			flags[i][j] = false;
		}
	}

	for (int i = 1; i < n-1; ++i) {
		for (int j = 1; j < m-1; ++j) {
			if (Matrix[i-1][j-1] == '#' &&
				Matrix[i-1][j-0] == '#' &&
				Matrix[i-1][j+1] == '#' &&
				Matrix[i-0][j-1] == '#' &&

				Matrix[i-0][j+1] == '#' &&
				Matrix[i+1][j-1] == '#' &&
				Matrix[i+1][j-0] == '#' &&
				Matrix[i+1][j+1] == '#'){
				flags[i][j] = true;
			}
		}
	}

	bool ans = true;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Matrix[i][j] == '#') {
				if (not ((i-1>=0 and i-1 < n and j-1 >= 0 and j-1 < m and flags[i-1][j-1] == true)or
						 (i-1>=0 and i-1 < n and j-0 >= 0 and j-0 < m and flags[i-1][j-0] == true)or
						 (i-1>=0 and i-1 < n and j+1 >= 0 and j+1 < m and flags[i-1][j+1] == true)or
						 (i-0>=0 and i-0 < n and j-1 >= 0 and j-1 < m and flags[i-0][j-1] == true)or
						 (i-0>=0 and i-0 < n and j+1 >= 0 and j+1 < m and flags[i-0][j+1] == true)or
						 (i+1>=0 and i+1 < n and j-1 >= 0 and j-1 < m and flags[i+1][j-1] == true)or
						 (i+1>=0 and i+1 < n and j-0 >= 0 and j-0 < m and flags[i+1][j-0] == true)or
						 (i+1>=0 and i+1 < n and j+1 >= 0 and j+1 < m and flags[i+1][j+1] == true))){
					ans = false;
					break;
				}
			}
		}
	}

	cout << (ans?"YES":"NO") << endl;

}
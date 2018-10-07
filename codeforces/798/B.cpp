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
	int n; cin >> n;
	vector<string> ss(n);
	for (int i = 0; i < n; ++i) {
		cin >> ss[i];
	}
	
	int l = ss[0].size();
	int min_steps_taken = 1e9;

	for (int i = 0; i < n; ++i) {
		// preprocessing: get all rotations of ss[i] and store them in a map
		map<string, int> m;
		string q = ss[i];
		for (int k = 0; k < l; ++k) {
			// we get to string q after k rotations
			// we can convert string q to ss[i] in (l-k)%l steps
			// m[q] = (l-k)%l; // MISTAKE!! q may already be in the map, in that case, take minimum
			if (m.find(q) == m.end()) {
				m[q] = (l-k)%l;
			} else {
				m[q] = min((l-k)%l, m[q]);
			}
			q = q.substr(1,l-1) + q[0];
		}
		int steps_taken = 0;
		// debug(ss[i]);
		for (int j = 0; j < n; ++j) {
			// try converting ss[j] into ss[i]
			// debug(ss[j]);
			if (m.find(ss[j]) != m.end()) {
				steps_taken += m[ss[j]];
			} else {
				cout << -1 << endl; return 0;
			}
			// debug(steps_taken);
		}
		min_steps_taken = min(steps_taken, min_steps_taken);
	}

	cout << min_steps_taken << endl;
}
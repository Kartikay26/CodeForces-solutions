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

void solve(int n, int k){
	if (n == 1) {
		cout << k;
		return;
	} else if (n == 2) {
		cout << k << " " << k*2;
		return;
	} else if (n == 3) {
		cout << k << " " << k << " " << k*3;
	} else {
		for (int i = 0; i < ceil(n/2.); ++i) {
			cout << k << " ";
		}
		solve(n/2, k*2);
	}
}

int32_t main(){
	fast_io();

	int n;
	cin >> n;

	solve(n, 1);

	cout << endl;
}
#include <bits/stdc++.h>
// #include "prettyprint.hpp"
using namespace std;

typedef long long int lli;
#define int lli

#define debug(x) cout << "debug: " << #x " = " << x << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int32_t main(){
	fast_io();

	int n, d; cin >> n >> d;

	int m; cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		if (not (d <= x + y and x + y <= 2*n-d and abs(x-y) <= d))
		{
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}

}
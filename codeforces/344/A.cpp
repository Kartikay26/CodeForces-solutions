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

	int pr = -1, gr = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		if (x != pr)
		{
			gr++;
		}
		pr = x;
	}

	cout << gr << endl;

}
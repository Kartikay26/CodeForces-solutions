#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli

#define debug(x) cout << "debug: " << #x " = " << x << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int32_t main(){
	// freopen("input.txt","r",stdin);
	fast_io();

	int n;
	cin >> n;
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		m = max(m,x+y);
	}
	cout << m << endl;

}
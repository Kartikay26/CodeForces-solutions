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

	int x = 0;

	int n; cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;
		x += (a[1]=='+')?1:-1;
	}

	cout << x << endl;

}
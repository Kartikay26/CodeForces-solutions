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

	string s1, s2;
	cin >> s1 >> s2;

	transform(all(s1), s1.begin(), ::tolower);
	transform(all(s2), s2.begin(), ::tolower);

	if (s1 == s2)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << ((s1 < s2) ? -1 : 1) << endl;
	}
	
}
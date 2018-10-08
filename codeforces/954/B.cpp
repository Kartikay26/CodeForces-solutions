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
	string s; cin >> s;

	int maxl = 0;

	if (n==1) {
		cout << 1 << endl; return 0;
	}

	for (int l = 0; l <= s.size()/2; ++l) {
		// debug(l);
		// debug(s.substr(0,l));
		// debug(s.substr(l,l));
		if (s.substr(0,l) == s.substr(l,l))
			maxl = l;
	}

	if(maxl == 0)
		cout << s.size() << endl;
	else
		cout << maxl+1+s.size()-2*maxl << endl;

}
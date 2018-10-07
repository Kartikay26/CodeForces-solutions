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

	string s;
	cin >> s;

	int cnt = 0, l = s.size();

	for (int i = 0; i < l/2; ++i) {
		if (s[i] != s[l-i-1]) {
			cnt++;
		}
	}

	cout << ((cnt==1 or (cnt==0 and l%2==1))?"YES":"NO") << endl;
	
}
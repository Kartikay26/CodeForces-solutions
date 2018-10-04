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
	vector<char> vc(n);
	int n8s = 0;
	for (int i = 0; i < n; ++i) {
		cin >> vc[i];
		if(vc[i]=='8') n8s++;
	}
	int m = n/11;
	// debug(n8s); debug(n);
	cout << min(n8s,m) << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
	#include "prettyprint.hpp"
	#define debug(x) cout << "debug: " << #x " = " << x << endl
#else
	#define debug(x) 0
#endif

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

int32_t main(){
	fast_io();
	int n; cin >> n;
	string s;
	cin >> s;
	map<string, int> freqs;
	for (int i = 0; i < s.size()-1; ++i) {
		if ('A'<=s[i] and s[i]<='Z' and 'A'<=s[i+1] and s[i+1]<='Z') {
			string n = "  ";
			n[0] = s[i];
			n[1] = s[i+1];
			freqs[n]++;
		}
	}
	string maxs=""; int maxf = -1;
	for(auto st_fr : freqs){
		if (st_fr.second > maxf) {
			maxf = st_fr.second;
			maxs = st_fr.first;
		}
	}
	cout << maxs << endl;
}
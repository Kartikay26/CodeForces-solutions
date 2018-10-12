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

vector<char> a(16);

vector<vi> wins = { {0,1,2},
					{1,2,3},
					{4,5,6},
					{5,6,7},
					{8,9,10},
					{9,10,11},
					{12,13,14},
					{13,14,15},
					{0,4,8},
					{4,8,12},
					{1,5,9},
					{5,9,13},
					{2,6,10},
					{6,10,14},
					{3,7,11},
					{7,11,15},
					{4,9,14},
					{0,5,10},
					{5,10,15},
					{1,6,11},
					{2,5,8},
					{3,6,9},
					{6,9,12},
					{7,10,13}
				  };

int32_t main(){
	fast_io();

	for (int i = 0; i < 4; ++i) {
		string s; cin >> s;
		for (int j = 0; j < 4; ++j) {
			a[i*4+j] = s[j];
		}
	}

	for(auto &v : wins){
		int cntx = 0, cntd = 0;
		for(auto i : v){
			if (a[i] == '.') cntd++;
			if (a[i] == 'x') cntx++;
		}
		if (cntx == 2 and cntd == 1) {
			cout << "YES\n";
			return 0;
		}
	}
	
	cout << "NO\n";
}
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

vector<char> seq;

int32_t main(){
	fast_io();
	int n; cin >> n;
	seq.resize(n,'O');
	int lO = n-1; int ans = 1;
	cout << 1 << " ";
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; x--;
		if (x<lO) {
			seq[x] = 'X';
			ans++;
		} else if (x == lO){
			seq[x] = 'X'; ans++;
			while(seq[x] == 'X'){
				x--; lO--; ans--;
				if(x==-1){break;}
			}
		}
		cout << ans << " ";
	}
	cout << endl;
}
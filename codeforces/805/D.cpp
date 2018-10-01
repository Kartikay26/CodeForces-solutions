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

const int mod = 1e9+7;

int32_t main(){
	fast_io();

	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	int nb = 0;
	for (int i = n-1; i >= 0; --i){
		if (s[i] == 'b'){
			nb++;
			nb %= mod;
		}
		if (s[i] == 'a'){
			ans += nb;
			ans %= mod;
			nb*=2;
			nb %= mod;
		}
	}
	cout << ans << endl;
}
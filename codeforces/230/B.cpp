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

vector<int> getPrimes(int n){
	vector<int> result;
	vector<bool> isComposite(n+1);
	for (int i = 2; i*i <= n; ++i) {
		if(isComposite[i]) continue;
		for (int x = i*2; x <= n; x += i) {
			isComposite[x] = true;
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (!isComposite[i]) result.push_back(i);
	}
	return result;
}

int32_t main(){
	fast_io();
	vi primes_v = getPrimes(1e6);
	set<int> primes(all(primes_v));
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		int y = sqrt(x);
		if (y*y == x and primes.count(y)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
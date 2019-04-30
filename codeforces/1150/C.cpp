// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = "; _dbg(__VA_ARGS__);
#define debuga(arr, n) _dbga(arr, n, #arr)
#else
#define debug(...)
#define debuga(arr, n)
#endif
typedef long long int ll;
#define int ll
#define F first
#define S second
#define float double
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;

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
	int n; cin >> n;
	int ones = 0, twos = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		x == 1 ? ones++ : twos ++;
	}
	debug(ones, twos);
	vi primes_v = getPrimes(ones + 2*twos);
	set<int> primes (all(primes_v));
	debug(primes);
	int cur_sum = 0;
	for (int i = 0; i < n; ++i) {
		if (!twos || (ones && primes.count(cur_sum + 1))){
			cout << 1 << " ";
			ones--; cur_sum += 1;
		} else {
			cout << 2 << " ";
			twos--; cur_sum += 2;
		}
		// cout << cur_sum << " " << " *"[primes.count(cur_sum)] << endl;
	}
	return 0;
}
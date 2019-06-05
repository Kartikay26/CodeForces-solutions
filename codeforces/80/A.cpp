// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(...)
#define debuga(arr, n)
#define debugg(grid, n) 
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
	vi ps = getPrimes(100);
	int n, m; cin >> n >> m;
	auto i = find(all(ps), n);
	i++;
	if (*i == m){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
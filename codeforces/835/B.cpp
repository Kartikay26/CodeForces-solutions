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

int32_t main(){
	fast_io();
	int k;
	cin >> k;
	string n;
	cin >> n;
	map<int, int> m;
	int s = 0;
	for(auto i : n){
		m[i - '0']++;
		s += (i-'0');
	}
	int req = k - s;
	int changed = 0;
	if (req <= 0){
		cout << 0 << endl;
		return 0;
	}
	for(auto [d,x] : m){
		if (req > (9-d)*x){
			req -= (9-d)*x;
			changed += x;
		} else {
			changed += ceil(float(req) / (9-d));
			break;
		}
	}
	cout << changed << endl;
	return 0;
}
// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#else
#define debug(...) 0
#endif
typedef long long int ll;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e6+1;


int32_t main(){
	fast_io();
	int n, m=0;
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		s += x;
		m = max(m,x);
	}
	int k = ((2*s)/n) + 1;
	cout << max(m,k) << endl;
}
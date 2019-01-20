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

int n, a[N], score[N];

void getscore(int t){
	int s = 0;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		if (x == t) continue;
		if (x < t){
			s += (t - 1 - x);
		} else {
			s += (x - (t + 1));
		}
	}
	score[t] = s;
}

int32_t main(){
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= 100; ++i) {
		getscore(i);
	}
	int index = min_element(score+1, score+101) - (score);
	cout << index << " " << score[index];
	return 0;
}
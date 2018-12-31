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
const int N = 1e5+1;

int n, c[N];
string s[N][2];

int mincost[N][2];

int32_t main(){
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> s[i][0];
		s[i][1] = s[i][0];
		reverse(all(s[i][1]));
	}
	mincost[0][0] = 0;
	mincost[0][1] = c[0];
	auto xmin = [](int a, int b){
		if(a == -1)
			return b;
		if(b == -1)
			return a;
		return min(a,b);
	};
	for (int i = 1; i < N; ++i) {
		// mincost[i][0] = ?
		int &rq0 = mincost[i][0];
		rq0 = -1;
		if(s[i][0] >= s[i-1][0] and mincost[i-1][0]!=-1)
			rq0 = xmin(mincost[i-1][0], rq0);
		if(s[i][0] >= s[i-1][1] and mincost[i-1][1]!=-1)
			rq0 = xmin(mincost[i-1][1], rq0);
		// mincost[i][1] = ?
		int &rq1 = mincost[i][1];
		rq1 = -1;
		if(s[i][1] >= s[i-1][0] and mincost[i-1][0]!=-1)
			rq1 = xmin(mincost[i-1][0] + c[i], rq1);
		if(s[i][1] >= s[i-1][1] and mincost[i-1][1]!=-1)
			rq1 = xmin(mincost[i-1][1] + c[i], rq1);
	}
	debuga(mincost, n);
	int final_mincost = xmin(mincost[n-1][0],mincost[n-1][1]);
	cout << final_mincost << endl;
	return 0;
}
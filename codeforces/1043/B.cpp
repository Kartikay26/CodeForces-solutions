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

const int N = 1e3+1;
int n, a[N], b[N];

bool check(int l){
	int x[l+1];
	for (int i = 1; i <= l; ++i) {
		x[i%l] = b[i];
	}
	for (int i = l+1; i <= n; ++i) {
		if(x[i%l] != b[i]) return false;
	}
	return true;
}

int32_t main(){
	fast_io();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		b[i] = a[i] - a[i-1];
	}
	vi ans;
	for (int l = 1; l <= n; ++l) {
		// check whether period of length l exists in O(N) time
		if(check(l)) ans.push_back(l);
	}
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i << " ";
	}
	cout << endl;
}
// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#define debuga(arr, n) dbga(arr, n, #arr)
#else
#define debug(...)
#define debuga(arr, n)
#endif
typedef long long int ll;
#define int ll
template<typename T> void dbga(T* a, int n, string s){
	cout << "debug: " << s << "= [";
	while(n--){cout << *a++ << (n?", ":"");} cout << "]\n";
}
#define F first
#define S second
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e3+1;

int a[N];

int n;

int electricity(int x){
	int r = 0;
	for (int i = 1; i <= n; ++i) {
		int ppl = a[i];
		int cost = abs(x - i) + abs(i - 1) + abs(1 - x);
		r += ppl * cost;
	}
	return 2*r;
}

int32_t main(){
	fast_io();
	
	cin >> n;
	for (int i = 1; i <= n; ++i) { cin >> a[i]; }

	int min_elec = LLONG_MAX;
	
	for (int i = 1; i <= n; ++i) {
		int e = electricity(i);
		if (e < min_elec) {
			min_elec = e;
		}
	}

	cout << min_elec << endl;

}
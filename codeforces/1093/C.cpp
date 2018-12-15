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
	cout << "debug: " << s << " = [";
	while(n--){cout << *a++ << (n?", ":"");} cout << "]\n";
}
#define F first
#define S second
#define float double
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 2e5+1;

int n, a[N], c[N], b[N];

int32_t main(){
	fast_io();
	cin >> n; n = n/2;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	
	int start = 0, end = b[0];
	a[0] = start;
	c[0] = end;
	for (int i = 1; i < n; ++i) {
		int num = b[i];
		if(num - start > end){
			a[i] = num - end;
			c[i] = end;
		} else {
			a[i] = start;
			c[i] = num - start;
		}
		start = a[i];
		end = c[i];
	}

	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	for (int i = 0; i < n; ++i) {
		cout << c[n-i-1] << " ";
	}
	cout << endl;
	return 0;
}
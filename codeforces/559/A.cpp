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
#define float double
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 5e2+1;

void trysolve(vi m){
	int a, b, c, d, e, f;
	a = m[0]; b = m[1]; c = m[2]; d = m[3]; e = m[4]; f = m[5];
	int x1, y1, x2, y2;
	x1 = a, y1 = 0;
	x2 = 0, y2 = a;
	x1 += b;
	y2 += d;
	x2 += e;
	y1 += c;
	if(y2 + x2 == y1 + x1){
		if(x1 - x2 == f){
			int l = y1 + x1;
			int area = l * l;
			area -= a*a;
			area -= e*e;
			area -= c*c;
			cout << area << endl;
			exit(0);
		}
	}
}

int32_t main(){
	fast_io();
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	vi m = {a,b,c,d,e,f};
	sort(all(m));
	bool go_ahead = true;
	while(go_ahead){
		trysolve(m);
		go_ahead = next_permutation(all(m));
	}
}
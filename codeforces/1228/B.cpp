// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print(){cout << endl;} void prints(){}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef long long int ll;
#define int ll
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e3+1;

char a[N][N];

int modexp(int n, int k){
	int res = 1;
	while(k>0){
		if(k&1){
			res *= n; res %= mod;
		}
		n = n*n; n %= mod;
		k /= 2;
	}
	return res;
}

int32_t main(){
	fast_io();
	int h, w; cin >> h >> w;
	vi r(h), c(w);
	for (int i = 0; i < h; ++i) {
		cin >> r[i];
	}
	for (int i = 0; i < w; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			a[i][j] = '?';
		}
	}
	for (int i = 0; i < h; ++i) {
		int ri = r[i];
		for (int j = 0; j < ri; ++j) {
			a[i][j] = 'b';
		}
		if(ri < w){
			a[i][ri] = 'w';
		}
	}
	for (int i = 0; i < w; ++i) {
		int ci = c[i];
		for (int j = 0; j < ci; ++j) {
			if(a[j][i] == 'w'){
				print(0); return 0;
			}
			a[j][i] = 'b';
		}
		if(ci < h){
			if(a[ci][i] == 'b'){
				print(0); return 0;
			}
			a[ci][i] = 'w';
		}
	}
	int cnt = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			// prints(a[i][j]);
			if(a[i][j] == '?'){
				cnt++;
			}
		}
		// print();
	}
	debug(cnt);
	print(modexp(2, cnt));
	return 0;
}
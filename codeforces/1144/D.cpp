// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
void print(){cout << endl;} void prints(){}
template<typename T=int> T get(){T x; cin >> x; return x;}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clear(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const int N = 1e6+1;

void s(int i, int j, int x, vi & a){
	if (a[i] < x){
		print(1, i+1, j+1);
		return;
	}
	if (a[i] > x){
		print(2, i+1, j+1);
		return;
	}
}

int32_t main(){
	fast_io();

	int n = get();
	vi a(n); get(a, n);

	pair<int, int> c_x;
	map<int, int> cnt;
	for(auto i : a){
		cnt[i]++;
		c_x = max(c_x, {cnt[i], i});
	}

	int z = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == c_x.second){
			z = i; break;
		}
	}

	print(n-c_x.first);

	for (int i = z; i < n; ++i) {
		s(i, i-1, c_x.second, a);
	}
	for (int i = z-1; i >= 0; --i) {
		s(i, i+1, c_x.second, a);
	}

	return 0;
}
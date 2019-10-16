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

int32_t main(){
	fast_io();

	int n = get();
	vi a(n); get(a,n);
	int s = 0;
	for(auto x : a){
		s += x/2;
	}

	for (int i = 0; i < n; ++i) {
		int x = a[i];
		if(x%2 == 0){
			print(x/2);
		} else {
			if(s < 0 and x > 0){
				print(x/2 + 1);
				s++;
			} else if (s > 0 and x < 0) {
				print(x/2 - 1);
				s--;
			} else {
				print(x/2);
			}
		}
	}

	return 0;
}
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

	int n; cin >> n;
	vi a(n); get(a,n);

	int s = accumulate(all(a), 0ll);

	vi even, odd;
	for(auto &i : a){
		if(i % 2 == 0){
			even.push_back(i);
		} else {
			odd.push_back(i);
		}
	}

	sort(rall(even));
	sort(rall(odd));

	int d = 0, i;
	for (i = 0; i < min(even.size(), odd.size()); ++i) {
		d += even[i] + odd[i];
	}
	if (i < even.size()){
		d += even[i];
	}
	if (i < odd.size()){
		d += odd[i];
	}

	print(s-d);

	
	return 0;
}
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

void testcase(int t){
	
	int h = get();
	int n = get();

	vi p(n); get(p, n);
	for(auto &i : p){
		i = -i;
	}
	
	debug(p);
	int cp = -h;
	int ans = 0;
	while (cp < -2){
		auto it = lower_bound(all(p), cp+1);
		if (it == p.end()){
			break;
		}
		if(*it == cp+1){
			auto it2 = lower_bound(all(p), cp+2);
			if(it2 == p.end() or *it2 != cp+2){
				ans++;
				debug(ans);
			}
			cp += 2;
		} else {
			cp = *lower_bound(all(p), cp+1) - 1;
		}
		debug(cp);
	}

	print(ans);
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		testcase(i);
	}
	return 0;
}
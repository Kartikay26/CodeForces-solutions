// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print(){cout << endl;} void prints(){}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}

const int mod = 1e9+7;
const int N = 1e6+1;




void testcase(int t){
	
	int n, k; cin >> n >> k;
	vi xs(n); get(xs, n);
	vi ys(n); get(ys, n);

	map<int, int> cnt;

	for(auto x : xs){
		cnt[x]++;
		cnt[x+k];
	}


	map<int, int> sl;
	auto it1 = cnt.begin();
	auto it2 = cnt.upper_bound(it1->first + k);
	if (it2 == cnt.end()) {
		print(n);
		return;
	}
	int sum = 0;
	for (auto it = it1; it != it2; ++it) {
		sum += it->second;
	}
	sl[it1->first] = (sum);
	for (; it2 != cnt.end();){
		sum -= it1->second;
		++it1;
		auto it_next = cnt.upper_bound(it1->first + k);
		while (it2 != it_next){
			sum += it2->second;
			it2++;
		}
		sl[it1->first] = sum;
	}
	
	debug(sl);

	int l = sl.size();
	int m = -1;
	map<int, int> msl;
	for(auto [x, f] : sl){
		m = msl[x] = max(f, m);
	}
	debug(msl);
	msl[-2e9];
	
	int ans = -1;
	for(auto [x, f] : sl){
		int z = f;
		auto it = msl.upper_bound(x - k-1);
		it--;
		z += it->second;
		ans = max(ans, z);
	}

	print(ans);
	return;
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
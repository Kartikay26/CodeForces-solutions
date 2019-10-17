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
const int N = 2e5+1;

const int inf = 1e18 + 1LL;

bool b[2][N];
pii dp[2][N];
int dp_ptr[2][N];

bool better(pii a, pii b){
	if (a.first == b.first) {
		return a > b;
	} else if (a.second == b.second) {
		return a < b;
	} else {
		assert(false);
	}
}

pair<bool, pii> update(pii a, int x, int d){
	if (d == 0){
		if (x > a.first){
			a.first = x;
			return {true, a};
		}
	} else {
		if (x < a.second){
			a.second = x;
			return {true, a};
		}
	}
	return {false, {0,0}};
}

int32_t main(){
	fast_io();

	int n = get();
	vi a(n); get(a, n);

	b[0][0] = 1;
	b[1][0] = 1;
	dp[0][0] = {a[0], inf};
	dp[1][0] = {-inf, a[0]};

	for (int i = 1; i < n; ++i) {
		for(auto j : {0, 1}){
			
			vector<pair<int, pii>> prev;
			for(auto p : {0, 1}){
				if(b[p][i-1]){
					prev.push_back({p, dp[p][i-1]});
				}
			}
			
			int x = a[i];

			vector<pair<int, pii>> answers;
			for(auto [ptr, p] : prev){
				auto [bb, pp] = update(p, x, j);
				if(bb){
					answers.push_back({ptr, pp});
				}
			}

			if(answers.size() == 0){
				b[j][i] = 0;
			} else if (answers.size() == 1) {
				b[j][i] = 1;
				dp[j][i] = answers[0].second;
				dp_ptr[j][i] = answers[0].first;
			} else if (answers.size() == 2) {
				b[j][i] = 1;
				auto [ptr1, p1] = answers[0];
				auto [ptr2, p2] = answers[1];
				if (better(p1, p2)){
					dp[j][i] = p1;
					dp_ptr[j][i] = ptr1;
				} else {
					dp[j][i] = p2;
					dp_ptr[j][i] = ptr2;
				}
			}

		}
	}

	debug(arr(b[0], n));
	debug(arr(b[1], n));
	debug(arr(dp[0], n));
	debug(arr(dp[1], n));
	debug(arr(dp_ptr[0], n));
	debug(arr(dp_ptr[1], n));

	if(b[0][n-1] == 0 && b[1][n-1] == 0){
		print("NO");
		return 0;
	}

	print("YES");
	vi ans;
	int p;
	if (b[0][n-1]) p = 0;
	if (b[1][n-1]) p = 1;
	for (int i = n-1; i >= 0; --i) {
		// debug(i, p, ans);
		ans.push_back(p);
		p = dp_ptr[p][i];
	}
	reverse(all(ans));
	for(auto i : ans){
		prints(i);
	}

	return 0;
}
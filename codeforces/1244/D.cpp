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
	vi a(n); get(a, n);
	vi b(n); get(b, n);
	vi c(n); get(c, n);
	vector<vi> costs = {a,b,c};
	vi degree(n+1);
	map<int, vi> adj;

	for (int i = 0; i < n-1; ++i) {
		int x, y; cin >> x >> y;
		degree[x]++;
		degree[y]++;
		if(degree[x] > 2 || degree[y] > 2){
			print(-1); return 0;
		}
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	debug(degree);

	vi ends;

	for (int i = 1; i <= n; ++i) {
		if(degree[i] == 1){
			ends.push_back(i);
		}
	}

	assert(ends.size() == 2);

	vi seq;

	function<void(int, int)> dfs = [&](int x, int p){
		seq.push_back(x);
		for(auto y : adj[x]){
			if(y != p){
				dfs(y, x);
			}
		}
	};

	dfs(ends[0], -1);

	debug(seq);

	assert(seq.size() == n);

	vector<vi> seqs = {
		{1, 2, 3},
		{1, 3, 2},
		{2, 1, 3},
		{2, 3, 1},
		{3, 1, 2},
		{3, 2, 1}
	};

	pii ans = {1e18+5, 10};

	for(int si : {0,1,2,3,4,5}){
		vi& s = seqs[si];
		int cost = 0;
		for (int i = 0; i < n; ++i) {
			int n = seq[i];
			int color = s[i % 3];
			cost += costs[color-1][n-1];
		}
		ans = min(ans, {cost, si});
	}

	print(ans.first);
	vi answer(n+1);
	for (int i = 0; i < n; ++i) {
		vi& s = seqs[ans.second];
		int color = s[i % 3];
		answer[seq[i]] = color;
	}
	for (int i = 1; i <= n; ++i) {
		prints(answer[i]);
	}

	return 0;
}
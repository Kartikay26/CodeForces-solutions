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
 
string testcase(int t){
	int n, a, b, da, db;
	cin >> n >> a >> b >> da >> db;
	vi adj[n+1];
	for (int i = 0; i < n-1; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	auto distAB = [&](int a, int b){
		deque<int> q;
		int dist[n+1];
		memset(dist, 0, sizeof(dist));
		q.push_back(a);
		dist[a] = 1;
		while (!q.empty()) {
			int x = q.front();
			q.pop_front();
			for(auto y : adj[x]){
				if(dist[y]) continue;
				q.push_back(y);
				dist[y] = dist[x] + 1;
			}
		}
		return dist[b] - 1;
	};
	auto maxDist = [&](int a){
		deque<int> q;
		int dist[n+1];
		memset(dist, 0, sizeof(dist));
		q.push_back(a);
		dist[a] = 1;
		while (!q.empty()) {
			int x = q.front();
			q.pop_front();
			for(auto y : adj[x]){
				if(dist[y]) continue;
				q.push_back(y);
				dist[y] = dist[x] + 1;
			}
		}
		return make_pair(max_element(dist+1, dist+n+1) - dist,
						*max_element(dist+1, dist+n+1) - 1);
	};
	int treeDia = maxDist(maxDist(1).first).second;
	int AtoB = distAB(a, b);
 
	if (AtoB > da && db > 2*da && treeDia > 2*da) {
		return "Bob";
	}
 
	return "Alice";
}
 
int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		print(testcase(i));
	}
	return 0;
}
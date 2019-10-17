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

int n, m;
vi g[N];
vector<pii> edges;
int color[N];

int32_t main(){
	fast_io();

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.push_back({u,v});
	}

	queue<int> q;
	q.push(1);
	color[1] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : g[u]){
			if(color[v] == 0){
				color[v] = color[u] * -1;
				q.push(v);
			} else {
				if (color[u] == -1 * color[v]){
					// all good
				} else {
					print("NO");
					return 0;
				}
			}
		}
		debug(arr(color+1, n));
	}

	print("YES");
	for(auto [u,v] : edges){
		if(color[u] == 1 and color[v] == -1){
			cout << 1;
		} else if (color[u] == -1 and color[v] == 1){
			cout << 0;
		} else {
			assert(false);
		}
	}
	return 0;
}
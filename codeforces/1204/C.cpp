// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(...)
#define debuga(arr, n)
#define debugg(grid, n) 
#endif
typedef long long int ll;
#define int ll
#define F first
#define S second
#define float double
const int inf = LLONG_MAX;
int get() { int x; cin >> x; return x; }
void getl(int* ar, int sz){ for(int i=0; i<sz; i++) cin >> ar[i];}
template <typename T> void print(T x) { cout << x << "\n";}
template <typename T> void prints(T x) { cout << x << " ";}
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e5+1;

int n, m;
int adj[101][101];
int d[101][101];

int32_t main(){
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < n; ++j) {
			adj[i+1][j+1] = (s[j] - '0');
		}
	}
	for (int i = 0; i < n; ++i) {
		adj[i+1][i+1] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d[i][j] = adj[i][j];
			if(d[i][j] == 0){
				d[i][j] = 100000;
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
	    for (int i = 1; i <= n; ++i) {
	        for (int j = 1; j <= n; ++j) {
	            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
	        }
	    }
	}
	cin >> m; vi l;
	for (int i = 0; i < m; ++i) {
		l.push_back(get());
	}
	vi ans = {l[0]};
	/// ==================================================
	int start = l[0];
	int prev = l[0];
	int v = l[0];
	int steps = 0;
	for (int i = 0; i < m; ++i) {
		prev = v;
		v = l[i];
		if(d[start][v] < steps){
			ans.push_back(prev);
			start = prev;
			steps = 1;
		}
		steps++;
	}

	/// ==================================================
	ans.push_back(*l.rbegin());

	print(ans.size());
	for(auto &i : ans){
		cout << i << " ";
	}
	return 0;
}
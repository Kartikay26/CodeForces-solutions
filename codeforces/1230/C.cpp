// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print(){cout << endl;} void prints(){}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef long long int ll;
#define int ll
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;

int n, m;
vi coloring(8);
vector<pair<int, int>> v;
int ans = 0;

void search(int d=1){
	if( d == n+1 ){
		// print(coloring);
		set<pair<int, int>> s;
		for(auto [x,y] : v){
			int a = coloring[x];
			int b = coloring[y];
			if(a>b) swap(a,b);
			s.insert({a, b});
		}
		int m = s.size();
		if(m == 21){
			debug(s);
		}
		ans = max(m, ans);
	} else {
		for (int i = 1; i <= 6; ++i) {
			coloring[d] = i;
			search(d+1);
		}
	}
}

int32_t main(){
	fast_io();
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	search();
	print(ans);
	return 0;
}
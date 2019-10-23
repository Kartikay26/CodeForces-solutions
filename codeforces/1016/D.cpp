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
#define clr(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const int N = 1e6+1;

int32_t main(){
	fast_io();

	int n, m; cin >> n >> m;
	vi a(n); get(a, n);
	vi b(m); get(b, m);

	int g[n][m]; clr(g);

	for (int i = 0; i < 32; ++i) {
		vi x, y;
		for (int j = 0; j < n; ++j) {
			int z = a[j];
			if(z & (1 << i)){
				x.push_back(j);
			}
		}
		for (int j = 0; j < m; ++j) {
			int z = b[j];
			if(z & (1 << i)){
				y.push_back(j);
			}
		}
		if(x.size() % 2 != y.size() % 2){
			print("NO");
			return 0;
		}
		for (int j = 0; j < max(x.size(), y.size()); ++j) {
			int a, b;
			if(!x.empty()){
				a = x[min(j, int(x.size()-1))];
			} else {
				a = 0;
			}
			if(!y.empty()){
				b = y[min(j, int(y.size()-1))];
			} else {
				b = 0;
			}
			g[a][b] |= (1 << i);
		}
	}

	print("YES");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			prints(g[i][j]);
		}
		print();
	}

	return 0;
}
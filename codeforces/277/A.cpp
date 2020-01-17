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

class DSU {
	vector<int> parent;
	vector<int> sizes;
	public:
		int nsets;
		DSU(int n):parent(n),sizes(n),nsets(n){
			for (int i = 0; i < n; ++i) {
				parent[i] = i; sizes[i] = 1;
			}
		}
		void join(int i, int j){
			i = find(i); j = find(j); if(i==j) return;
			if(sizes[i]<sizes[j]) swap(i,j);
			parent[i] = j;
			sizes[j] += sizes[i];
			nsets--;
		}
		int find(int i){
			while(i != parent[i])
				i = parent[i];
			return i;
		}
		int size(int i){
			i = find(i);
			return sizes[i];
		}
		bool compare(int i, int j){
			return find(i) == find(j);
		}
};

int32_t main(){
	fast_io();

	int n, m, z = 1;
	cin >> n >> m;
	
	DSU d(n); // emp <-> lang

	vi emps[m]; // m -- lang

	for (int i = 0; i < n; ++i) {
		int k; cin >> k;
		z *= (k == 0);
		for (int j = 0; j < k; ++j) {
			int x; cin >> x; x--;
			emps[x].push_back(i);
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < int(emps[i].size()) - 1; ++j) {
			d.join(emps[i][j],emps[i][j+1]);
		}
	}

	if (z == 1)
		print(d.nsets);
	else
		print(d.nsets - 1);

	return 0;
}
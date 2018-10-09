#include <bits/stdc++.h>
// #include "prettyprint.hpp"
using namespace std;

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

#define debug(x) cout << "debug: " << #x " = " << x << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

class DSU {
	vector<int> parent;
	vector<int> sizes;
	public:
		DSU(int n):parent(n),sizes(n){
			for (int i = 0; i < n; ++i) {
				parent[i] = i; sizes[i] = 1;
			}
		}
		void join(int i, int j){
			i = find(i); j = find(j); if(i==j) return;
			if(sizes[i]<sizes[j]) swap(i,j);
			parent[i] = j;
			sizes[j] += sizes[i];
		}
		int find(int a){
			return a == parent[a] ? a : parent[a] = find(parent[a]);
		}
		int size(int i){
			i = find(i);
			return sizes[i];
		}
		bool compare(int i, int j){
			return find(i) == find(j);
		}
};

const int N = 1001;

int n, m;
char a[N][N];

char get(int i, int j){
	if (i>=0 and j>=0 and i<n and j<m) {
		return a[i][j];
	} else {
		return 0;
	}
}

int32_t main(){
	fast_io();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		memcpy(a[i], s.c_str(), s.size());
	}
	DSU d(n*m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (get(i,j) == '.') {
				if(get(i+1,j) == '.') d.join(i*m+j, (i+1)*m+j);
				if(get(i-1,j) == '.') d.join(i*m+j, (i-1)*m+j);
				if(get(i,j+1) == '.') d.join(i*m+j, i*m+(j+1));
				if(get(i,j-1) == '.') d.join(i*m+j, i*m+(j-1));
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		string r;
		for (int j = 0; j < m; ++j) {
			if (get(i,j) == '*') {
				int ans = 1; set<int> comps;
				if(get(i+1,j) == '.') comps.insert(d.find((i+1)*m+j));
				if(get(i-1,j) == '.') comps.insert(d.find((i-1)*m+j));
				if(get(i,j+1) == '.') comps.insert(d.find(i*m+(j+1)));
				if(get(i,j-1) == '.') comps.insert(d.find(i*m+(j-1)));
				for(auto x : comps){
					ans += d.size(x);
				}
				a[i][j] = '0' + (ans%10);
			}
			r += a[i][j];
		}
		cout << r << endl;
	}
}
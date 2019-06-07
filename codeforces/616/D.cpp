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
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 5e5+1;

struct ms{
	// better multiset with "erase one" operation and correct size
	map<int, int> m; int num;
	int size() { return m.size(); }
	void put(int x) { m[x]++; num++;}
	void del(int x) { m[x]--; num--; if (!m[x]) m.erase(x); }
};

int a[N];

int32_t main(){
	fast_io();
	int n = get();
	int k = get();
	getl(a,n);
	ms m; pii ans;
	int i=0, j=0;
	while (j < n){
		if (m.size() <= k){
			m.put(a[j]); j++;
		}
		if (m.size() > k){
			m.del(a[i]); i++;
		}
		if (ans.second - ans.first < j-i){
			ans = {i,j};
		}
	}
	cout << ans.first + 1 << " " << ans.second << endl;
	return 0;
}
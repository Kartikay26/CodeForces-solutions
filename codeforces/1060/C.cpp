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

int32_t main(){
	fast_io();
	int n, m;
	cin >> n >> m;
	vi a(n), b(m); int a_s = 0, b_s = 0; vi as = {0}; vi bs ={0};
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; a_s += a[i]; as.push_back(a_s);
	}
	for (int j = 0; j < m; ++j) {
		cin >> b[j]; b_s += b[j]; bs.push_back(b_s);
	}
	int x; cin >> x;


	vector<pii> is;
	for (int l = 0; l < n; ++l) {
		int min_i1 = 0, min_i2 = l, min_sum = 1e9;
		for (int i1 = 0; i1 < n - l; ++i1) {
			int i2 = i1 + l;
			if (as[i2+1]-as[i1] < min_sum){
				min_i1 = i1;
				min_i2 = i2;
				min_sum = as[i2+1]-as[i1];
			}
		}
		is.push_back({min_i1,min_i2});
	}
	
	int max_ar = 0;

	// for *SOME* i1 .. i2 do this
	// find max j1..j2 so that (as[i2+1]-as[i1])*(bs[j2+1]-as[j1]) is <= x
	for(auto ir : is){
		int i1 = ir.first;
		int i2 = ir.second;
		int j1 = 0, j2 = 0;
		while(j2 != m and j1 != m){
			#define rect ((as[i2+1]-as[i1])*(bs[j2+1]-bs[j1]))
			#define area (i2-i1+1)*(j2-j1+1)
			if (rect <= x){
				max_ar = max(area, max_ar);
				j2++;
			} else {
				j1++;
			}
		}
	}


	cout << max_ar << endl;

}
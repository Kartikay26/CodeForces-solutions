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
const int N = 1e6+1;

int32_t main(){
	fast_io();
	int n; cin >> n;
	string s; cin >> s;
	string ans;
	for(auto &i : s){
		if (i == '0' || i == '1'){

		} else if (i == '6') {
			ans += "53";
		} else if (i == '4') {
			ans += "322";
		} else if (i == '8') {
			ans += "7222";
		} else if (i == '9') {
			ans += "2337";
		} else {
			ans += i;
		}
	}
	sort(all(ans), greater<char>());
	print(ans);
	return 0;
}
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

void testcase(int t){
	int n = get();
	int a = 0;
	while (n % 2 == 0) {
		a++;
		n /= 2;
	}
	while (n % 3 == 0) {
		a++; a++;
		n /= 3;
	}
	while (n % 5 == 0) {
		a++; a++; a++;
		n /= 5;
	}
	if (n == 1) {
		print(a);
	} else {
		print(-1);
	}
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		testcase(i);
	}
	return 0;
}
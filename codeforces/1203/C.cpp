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

map<int, int> fact(long long n) {
    map<int, int> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n > 1)
        factorization[n]++;
    return factorization;
}

int32_t main(){
	fast_io();
	int n = get();
	vi x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	int m = x[0];
	for (int i = 0; i < n; ++i) {
		m = __gcd(m, x[i]);
	}
	map<int, int> mp = fact(m);
	int ans = 1;
	for(auto [x,y] : mp){
		ans *= (y+1);
	}
	print(ans);
	return 0;
}
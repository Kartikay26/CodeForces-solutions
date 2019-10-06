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
#define clear(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const int N = 1e6+1;

bool check(int n, vi& p, int x, int y, int a, int b, int k){
	int l = (a * b) / __gcd(a,b);
	int nab = n / l;
	int na = n / a - nab;
	int nb = n / b - nab;

	int sum = 0;

	for (int i = 0; i < nab; ++i) {
		sum += (p[i] / 100) * (x+y);
		if(sum >= k){
			return true;
		}
	}
	for (int i = nab; i < nab+na; ++i) {
		sum += (p[i] / 100) * (x);
		if(sum >= k){
			return true;
		}
	}
	for (int i = nab+na; i < nab+na+nb; ++i) {
		sum += (p[i] / 100) * (y);
		if(sum >= k){
			return true;
		}
	}
	return false;
}

void testcase(int t){
	
	int n; cin >> n;
	vi p(n); get(p, n);
	int x, a; cin >> x >> a;
	int y, b; cin >> y >> b;
	int k; cin >> k;

	sort(rall(p));
	debug(p);

	if (x < y){
		swap(x,y);
		swap(a,b);
	}

	for (int i = 0; i <= n; ++i) {
		debug(check(i,p,x,y,a,b,k), i);
	}

	if(!check(n,p,x,y,a,b,k)){
		print(-1);
		return;
	}

	int z = 0;
	for(int bs = n; bs >= 1; bs /= 2){
		while(!check(z + bs, p, x, y, a, b, k)) z += bs;
	}
	print(z+1);

}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		testcase(i);
	}
	return 0;
}
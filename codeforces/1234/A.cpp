// kartikay26
#include <bits/stdc++.h>
using namespace std;
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

void testcase(int t){
	int n; cin >> n;
	vi a(n);
	for(auto &ai : a){
		cin >> ai;
	}
	print((accumulate(all(a), 0ll) + n - 1)/ n);
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
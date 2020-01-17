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

int ncr(int n, int r){
	if (r == n or r == 0) {
		return 1;
	}
	// either choose r from last n-1 or choose r-1
	// n.b. there's a formula with the factorial too
	return ncr(n-1, r) + ncr(n-1, r-1);
}

int32_t main(){
	fast_io();

	string s1, s2; cin >> s1 >> s2;

	int total1 = 0;
	for(auto c : s1){
		if (c == '+'){
			total1 ++;
		} else if (c == '-') {
			total1 --;
		}
	}
	int total2 = 0;
	int ques2 = 0;
	for(auto c : s2){
		if (c == '+'){
			total2 ++;
		} else if (c == '-') {
			total2 --;
		} else if (c == '?') {
			ques2++;
		}
	}

	int diff = abs(total2 - total1);

	debug(diff, ques2);
	
	if(diff > ques2 or diff % 2 != ques2 % 2){
		cout << 0 << endl;
	} else {
		// ans = ncr * 2^-n
		int n = ques2;
		int r = (diff + ques2) / 2;
		db ans = ncr(n, r) * pow(2, -n);
		printf("%0.10f",ans);
	}

	return 0;
}
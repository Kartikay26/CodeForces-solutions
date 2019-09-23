// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
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

int32_t main(){
	fast_io();
	int n, k; cin >> n >> k;
	string s; cin >> s;
	if(n == 1 and k == 1){
		print(0);
		return 0;
	}
	for (int i = 0; i < n and k > 0; ++i) {
		if(i == 0){
			if (s[i] != '1'){
				s[i] = '1';
				k--;
			}
		} else {
			if (s[i] != '0'){
				s[i] = '0';
				k--;
			}
		}
	}
	print(s);
	return 0;
}
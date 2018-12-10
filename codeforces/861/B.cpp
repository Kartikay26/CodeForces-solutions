// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#define debuga(arr, n) dbga(arr, n, #arr)
#else
#define debug(...)
#define debuga(arr, n)
#endif
typedef long long int ll;
#define int ll
template<typename T> void dbga(T* a, int n, string s){
	cout << "debug: " << s << "= [";
	while(n--){cout << *a++ << (n?", ":"");} cout << "]\n";
}
#define F first
#define S second
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;

vector<pii> mem;

bool checkIfSatisfies(int K){
	// check if it is possible to have K flats per floor
	// takes O(m) time
	for(auto kf : mem){
		int k = kf.F;
		int f = kf.S;
		if((k - 1)/K + 1 != f){
			return false;
		}
	}
	return true;
}

int32_t main(){
	fast_io();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int k, f;
		cin >> k >> f; // kth flat on fth floor
		mem.push_back({k,f});
	}
	int ans = -1;
	for (int i = 1; i <= 100; ++i) {
		if(ans == -1 and checkIfSatisfies(i)){
			ans = (n - 1) / i + 1;
		}
		else if (ans != -1 and checkIfSatisfies(i)){
			if(ans != (n - 1) / i + 1){
				ans = -1;
				break;
			}
		}
	}
	cout << ans << endl;
}
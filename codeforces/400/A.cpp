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
	cout << "debug: " << s << " = [";
	while(n--){cout << *a++ << (n?", ":"");} cout << "]\n";
}
#define F first
#define S second
#define float double
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;

void testcase(int t){
	string s; cin >> s;
	vi factors = {1,2,3,4,6,12};
	string ans = " "; int win = 0;
	// a b c d
	// e f g h
	// i j k l
	//  x = 3
	//  y = 4
	for(int x : factors){
		int y = 12/x;
		// let x be no of rows
		// y will be num columns
		for (int i = 0; i < y; ++i) {
			// for each column
			// check if all elements are 'X'
			bool allX = true;
			for (int j = 0; j < x; ++j) {
				// i'th column, j'th row
				if (s[i+j*y] != 'X'){
					allX = false; break;
				}
			}
			if(allX){
				win += 1;
				ans += to_string(x)+"x"+to_string(y)+" ";
				break;
			}
			// in case they are, we won
		}
	}
	
	cout << win << ans << endl;
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		testcase(i);
	}
}
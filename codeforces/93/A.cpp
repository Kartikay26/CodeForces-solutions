// kartikay26
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#endif
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print(){cout << endl;} void prints(){} int get() {int x; cin >> x; return x;}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x; prints(r...);}

const int mod = 1e9+7;
const int N = 1e6+1;

int solve(int n, int m, int a, int b);

int testcase(){
	int n = get();
	int m = get();
	int a = get()-1;
	int b = get()-1;
	// for (int i = 0; i < n; ++i) {
	// 	prints(solve(n,m,a,i), "\t");
	// 	if ((i+1) % m == 0) {
	// 		print();
	// 	}
	// }
	// print();
	return solve(n,m,a,b);
}

int solve(int n, int m, int a, int b) {
	if (a>b) return -1;
	int col_a = a % m;
	int row_a = a / m;
	int col_b = b % m;
	int row_b = b / m;
	if (row_a == row_b) {
		/// ---***---
		return 1;
	} else {
		if (col_a == 0) {
			if (col_b == m-1 or b == n-1){
				/// ---------     ---------
				/// ********* or  *********
				/// *****         ---------
				return 1;
			} else {
				/// ---------
				/// *********
				/// *****----
				/// ---------
				return 2;
			}
		} else {
			if (col_b == m-1 or b == n-1){
				/// ---------
				/// ----*****
				/// ******
				return 2;
			} else {
				if (row_b - row_a == 1) {
					/// ---------
					/// ----*****
					/// ******---
					/// ---------
					return 2;
				} else {
					if (col_b == col_a-1) {
						/// ---------
						/// -----****
						/// *********
						/// *****----
						/// ---------
						return 2;
					} else {
						/// ---------    ---------
						/// ----*****    ----*****
						/// ********* or *********
						/// ******---    **-------
						/// ---------    ---------
						return 3;
					}
				}
			}
		}
	}
	return -1;
}

int32_t main(){
	fast_io();
	print(testcase());
	return 0;
}
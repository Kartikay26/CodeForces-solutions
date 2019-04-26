// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = "; _dbg(__VA_ARGS__);
#define debuga(arr, n) _dbga(arr, n, #arr)
#else
#define debug(...)
#define debuga(arr, n)
#endif
typedef long long int ll;
#define int ll
#define F first
#define S second
#define float double
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 2e5+1;

int L[N][4];
int R[N][4];

int a[N];

int n;

int32_t main(){
	fast_io();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	L[0][0] = 1; // l
	L[0][1] = n; // r
	L[0][2] = 0; // max
	L[0][3] = 0; // camefrom
	R[0][0] = 1; // l
	R[0][1] = n; // r
	R[0][2] = 0; // max
	R[0][3] = 0; // camefrom
	for (int i = 1; i <= n; ++i) {
		L[i][2] = inf;
		R[i][2] = inf;
	}
	int maxlen_L = 0;
	int maxlen_R = 0;
	for (int i = 1; i <= n; ++i) {
		// update to L
		if(L[i-1][0] != 0 && a[L[i-1][0]] > L[i-1][2]){ // a[l_Left] > max_L
			if(a[L[i-1][0]] < L[i][2]){
				L[i][0] = L[i-1][0]+1; // shift left ptr
				L[i][1] = L[i-1][1]; // right ptr remains same
				L[i][2] = a[L[i-1][0]]; // update max
				L[i][3] = 1; // 1 = left, came from left
				maxlen_L = i;
			}
		}
		if(R[i-1][0] != 0 && a[R[i-1][0]] > R[i-1][2]){ // a[l_Right] > max_R
			if(a[R[i-1][0]] < L[i][2]){
				L[i][0] = R[i-1][0]+1; // shift left ptr
				L[i][1] = R[i-1][1]; // right ptr remains same
				L[i][2] = a[R[i-1][0]]; // update max
				L[i][3] = 2; // 2 = right, came from right
				maxlen_L = i;
			}
		}
		// update to R
		if(L[i-1][0] != 0 && a[L[i-1][1]] > L[i-1][2]){ // a[r_Left] > max_L
			if(a[L[i-1][1]] < R[i][2]){
				R[i][1] = L[i-1][1]-1; // shift right ptr
				R[i][0] = L[i-1][0]; // left ptr remains same
				R[i][2] = a[L[i-1][1]]; // update max
				R[i][3] = 1; // 1 = left, came from left
				maxlen_R = i;
			}
		}
		if(R[i-1][0] != 0 && a[R[i-1][1]] > R[i-1][2]){ // a[r_Right] > max_R
			if(a[R[i-1][1]] < R[i][2]){
				R[i][1] = R[i-1][1]-1; // shift right ptr
				R[i][0] = R[i-1][0]; // left ptr remains same
				R[i][2] = a[R[i-1][1]]; // update max
				R[i][3] = 2; // 2 = right, came from right
				maxlen_R = i;
			}
		}
	}
	// for (int i = 0; i <= n; ++i) {
	// 	cout << "(" << L[i][0] << ",";
	// 	cout << L[i][1] << ",";
	// 	cout << L[i][2] << ",";
	// 	cout << L[i][3] << ") ";
	// }
	// cout << endl;
	// for (int i = 0; i <= n; ++i) {
	// 	cout << "(" << R[i][0] << ",";
	// 	cout << R[i][1] << ",";
	// 	cout << R[i][2] << ",";
	// 	cout << R[i][3] << ") ";
	// }
	// cout << endl;
	int i = max(maxlen_L, maxlen_R);
	int side = 0;
	if (maxlen_R > maxlen_L){
		side = 2;
	} else {
		side = 1;
	}
	string ans;
	while(i != 0){
		if(side == 1){
			ans += "L";
			side = L[i][3];
			i--;
		} else {
			ans += "R";
			side = R[i][3];
			i--;
		}
	}
	reverse(all(ans));
	cout << ans.size() << endl;
	cout << ans << endl;
	return 0;
}
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
const int N = 2e5+1;

int num[N];
int sums[20][N];
int zeros[N];

void testcase(int t){
	string s; cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		num[i] = s[i] - '0';
	}
	for (int i = 1; i < min(n+1, 19ll); ++i) {
		for (int j = 0; j < n+1 - i; ++j) {
			sums[i][j] = 0;
			for (int k = 0; k < i; ++k) {
				sums[i][j] |= num[j+k];
				sums[i][j] <<= 1;
			}
			sums[i][j] >>= 1;
		}
	}
	debuga(num, n);
	debuga(sums[1], n);
	debuga(sums[2], n);
	debuga(sums[3], n);
	debuga(sums[4], n);
	int zs = 0;
	for (int i = 0; i < n; ++i) {
		if(num[i] == 0) zs++;
		else zs = 0;
		zeros[i] = zs;
	}
	for (int i = 0; i < n; ++i) {
		if(num[i] == 1) {
			if(i == 0){
				zeros[i] = 0;
				continue;
			}
			if(num[i-1] == 0){
				zeros[i] = zeros[i-1];
			}
			else{
				zeros[i] = 0;
			}
		}
	}
	debuga(zeros, n);
	int ans = 0;
	for (int k = 1; k < min(n+1, 19ll); ++k) {
		for (int i = 0; i < n+1 - k; ++i) {
			if (num[i] and sums[k][i] >= k and sums[k][i] <= k + zeros[i]){
				ans++;
				debug(i,k);
			}
		}
	}
	print(ans);
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
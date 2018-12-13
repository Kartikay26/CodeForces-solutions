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
#define float double
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 100+2;

char a[N];

int cnt[N][3]; // 3 = length of "QAQ"

int32_t main(){
	fast_io();
	string s;
	cin >> s;	
	int n = s.length(), ans = 0;
	strcpy(a+1, s.c_str());
	string match = "QAQ";
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < match.length(); ++j) {
			if(a[i] == match[j])
				cnt[i][j] = cnt[i-1][j] + (j>0 ? cnt[i-1][j-1] : 1);
			else
				cnt[i][j] = cnt[i-1][j];
		}
	}
	ans = cnt[n][2];
	cout << ans << endl;
}
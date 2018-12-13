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

int Q[N], QA[N], QAQ[N];

int32_t main(){
	fast_io();
	string s;
	cin >> s;	
	int n = s.length(), ans = 0;
	strcpy(a+1, s.c_str());
	for (int i = 1; i <= n; ++i) {		
		if(a[i] == 'Q')
			Q[i] = Q[i-1] + 1;
		else
			Q[i] = Q[i-1];		
		if(a[i] == 'A')
			QA[i] = QA[i-1] + Q[i-1];
		else
			QA[i] = QA[i-1];
		if(a[i] == 'Q')
			QAQ[i] = QAQ[i-1] + QA[i-1];
		else
			QAQ[i] = QAQ[i-1];
	}
	debuga(a,n);debuga(Q,n);debuga(QA,n);debuga(QAQ,n);
	ans = QAQ[n];
	cout << ans << endl;
}
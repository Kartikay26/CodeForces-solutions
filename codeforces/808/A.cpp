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
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;

int32_t main(){
	fast_io();
	string s; cin >> s;
	int n = s.size();

	string s2 = s;
	for (int i = 1; i < n; ++i) {
		s2[i] = '0';
	}
	int old_num = stoll(s);
	int new_num;
	if(s2[0] == '9'){
		new_num = stoll(s2);
		new_num += new_num/9;
	} else {
		s2[0]++;
		new_num = stoll(s2);
	}
	cout << new_num - old_num;
	return 0;
}
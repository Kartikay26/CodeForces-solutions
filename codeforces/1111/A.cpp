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

bool check(string s, string t){
	set<char> v = {'a','e','i','o','u'};
	if(s.size() != t.size()){
		return false;
	}
	for (int i = 0; i < s.size(); i++){
		if (v.count(s[i]) != v.count(t[i])){
			return false;
		}
	}
	return true;
}

int32_t main(){
	fast_io();
	string s, t;
	cin >> s >> t;
	if (check(s,t)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	return 0;
}
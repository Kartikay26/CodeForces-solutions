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
	int a[6], x = -1;
	for (int i = 0; i < 6; ++i) {
		cin >> a[i];
	}
	sort(a, a+6);
	map<int, int> cnt;
	for (int i = 0; i < 6; ++i) {
		cnt[a[i]]++;
		if(cnt[a[i]] >= 4){
			x = a[i];
		}
	}
	if (x == -1){
		cout << "Alien\n";
		return 0;
	}
	multiset<int> s;
	for (int i = 0; i < 6; ++i) {
		s.insert(a[i]);
	}
	for (int i = 0; i < 4; ++i) {
		s.erase(s.find(x));
	}
	debug(s);
	if (*(s.begin()) == *(s.rbegin())){
		cout << "Elephant\n";
	} else {
		cout << "Bear\n";
	}
	return 0;
}
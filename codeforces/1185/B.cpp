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
const int N = 1e6+1;

void count(string s, vector<pair<char, int>>& v){
	for(auto &i : s){
		if (v.size() > 0 and (*v.rbegin()).first == i){
			(*v.rbegin()).second ++;
		} else {
			v.push_back({i, 1});
		}
	}
}

bool testcase(int t){
	string s1; string s2;
	cin >> s1 >> s2;
	vector<pair<char, int>> one; count(s1, one);
	vector<pair<char, int>> two; count(s2, two);
	debug(one);
	debug(two);
	if (one.size() != two.size()) return false;
	for(int i = 0; i < one.size(); i++){
		if (one[i].first != two[i].first) return false;
		if (one[i].second > two[i].second) return false;
	}
	return true;
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		if (testcase(i)){
			print("YES");
		} else {
			print("NO");
		}
	}
	return 0;
}
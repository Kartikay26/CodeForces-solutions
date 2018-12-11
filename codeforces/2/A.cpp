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
const int N = 1e6+1;

int32_t main(){
	fast_io();
	int n;
	cin >> n;
	int m = 0;
	vector<pair<string, int>> v;
	map<string, int> final_scoremap;
	map<string, int> scoremap;
	string name; int score;
	for (int i = 0; i < n; ++i) {
		cin >> name >> score;
		v.push_back({name, score});
	}
	for(auto x : v){
		tie(name, score) = x;
		final_scoremap[name] += score;
	}
	m = max_element(final_scoremap.begin(), final_scoremap.end(), [](pair<string, int> a, pair<string, int> b){return a.second < b.second;})->second;
	for(auto x : v){
		tie(name, score) = x;
		scoremap[name] += score;
		/// NOTE, >= instead of ==
		/// also, only one of the people who have score m at end can win
		if (scoremap[name] >= m and final_scoremap[name] == m) { 
			cout << name << endl;
			return 0;
		}
	}
}
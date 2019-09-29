// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print(){cout << endl;} void prints(){}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef long long int ll;
#define int ll
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;

bool check(int x){
	string s = to_string(x);
	set<char> st;
	for(auto c : s){
		st.insert(c);
	}
	if(st.size() == s.size()){
		return true;
	} else {
		return false;
	}
}

int32_t main(){
	fast_io();
	int l; int r; cin >> l >> r;
	for (int i = l; i <= r; ++i) {
		if(check(i)){
			print(i);
			return 0;
		}
	}
	print(-1);
	return 0;
}
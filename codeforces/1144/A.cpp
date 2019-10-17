// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
void print(){cout << endl;} void prints(){}
template<typename T=int> T get(){T x; cin >> x; return x;}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clear(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const int N = 1e6+1;

string testcase(int t){
	
	string s; cin >> s;
	int a[26] = {0};
	for(auto c : s){
		a[c-'a']++;
	}
	for(auto &i : a){
		if (i > 1) return "No";
	}
	int first_one = 0, last_one = 0;
	for (int i = 0; i < 26; ++i) {
		if(a[i] == 1){
			first_one = i; break;
		}
	}
	for (int i = 0; i < 26; ++i) {
		if(a[i] == 1){
			last_one = i;
		}
	}
	for (int i = first_one; i <= last_one; ++i) {
		if(a[i] == 0){
			return "No";
		}
	}
	return "Yes";
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		print(testcase(i));
	}
	return 0;
}
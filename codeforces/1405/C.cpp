// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print(){cout << endl;} void prints(){}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}

const int mod = 1e9+7;
const int N = 1e6+1;

bool testcase(int t){
	
	int n, k; cin >> n >> k;
	string s; cin >> s;


	vector<string> v(k);
	for (int i = 0; i < n; ++i) {
		v[i%k] += s[i];
	}
	
	debug(v);

	map<char, int> tc;
	for(auto c : s){
		tc[c]++;
	}
	
	for (int i = 0; i < k; ++i) {
		string z = v[i];
		map<char, int> cnt;
		for(auto c : z){
			cnt[c]++;
		}
		if (cnt['0'] && cnt['1']) {
			return false;
		}
		
		if (cnt['1']) {
			
			for (int j = i; j < n; j += k) {
				s[j] = '1';
			}
			continue;
		}
		if (cnt['0']) {
			
			for (int j = i; j < n; j += k) {
				s[j] = '0';
			}
			continue;
		}
	}

	debug(s);

	map<char, int> cnt;
	for(int i = 0; i < n;){
		cnt[s[i]]++;
		if (i >= k) {
			cnt[s[i-k]]--;
		}
		i++;
		if (i >= k) {
			if (abs(cnt['1'] - cnt['0']) > cnt['?']) {
				return false;
			}
		}
	}

	return true; /// remove
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		if (testcase(i)) {
			print("YES");
		} else {
			print("NO");
		}
	}
	return 0;
}
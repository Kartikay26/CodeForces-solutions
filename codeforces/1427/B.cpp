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
void print(){cout << endl;} void prints(){} int get() {int x; cin >> x; return x;}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}

const int mod = 1e9+7;
const int N = 1e6+1;

int count_score(string& s) {
	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (i and s[i] == 'W' and s[i-1] == 'W') {
			ans += 2;
		} else if (s[i] == 'W') {
			ans += 1;
		}
	}
	return ans;
}

int testcase(int t){
	int n = get();
	int k = get();
	string s; cin >> s;
	debug(n,k);
	debug(s);
	vi pref(n);
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'L') {
			pref[i] = 1;
		} else {
			break;
		}
	}
	for (int i = n-1; i >= 0; --i) {
		if (s[i] == 'L') {
			pref[i] = 1;
		} else {
			break;
		}
	}
	vector<tuple<int, int, int>> g; /// length, start index
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'L') {
			int start = i;
			while (i < n and s[i] == 'L') i++;
			int length = i - start;
			i--;
			g.push_back({pref[start], length, start});
		}
	}
	sort(all(g));
	for (auto [dummy, length, start] : g) {
		int z = min(k, length);
		k -= z;
		if (start != 0) { // normal
			for (int i = 0; i < z; i++) {
				s[i+start] = 'W';
			}
		} else { // special
			for (int i = 0; i < z; i++) {
				s[length-i-1] = 'W';
			}
		}
	}
	debug(s);
	debug(g);
	return count_score(s);
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
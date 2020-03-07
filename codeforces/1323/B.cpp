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

vector<int> count_ones(vector<int> &v){
	vector<int> contiguous_ones;
	int ones = 0;
	for(auto &i : v){
		if(i == 1){
			ones++;
		} else {
			if (ones) contiguous_ones.push_back(ones);
			ones = 0;
		}
	}
	if (ones) contiguous_ones.push_back(ones);
	return contiguous_ones;
}

int count(int num, vi& c){
	vi a;
	for(auto &i : c){
		if (i >= num){
			a.push_back(i - num + 1);
		}
	}
	if (a.size()){
		return accumulate(all(a), 0ll);
	} else {
		return 0;
	}
}

int32_t main(){
	fast_io();

	int n, m, k; cin >> n >> m >> k;

	vector<int> v1(n);
	vector<int> v2(m);

	for(auto &i : v1){ cin >> i; }
	for(auto &i : v2){ cin >> i; }

	vi c1 = count_ones(v1);
	vi c2 = count_ones(v2);

	vi count1(n);
	vi count2(m);

	for(auto &i : c1){
		count1[i-1] += 1;
	}
	for(auto &j : c2){
		count2[j-1] += 1;
	}

	for (int i = n-1, x=0, inc=0; i >= 0; --i) {
		inc += count1[i];
		x += inc;
		count1[i] = x;
	}
	debug(count1);
	for (int i = m-1, x=0, inc=0; i >= 0; --i) {
		inc += count2[i];
		x += inc;
		count2[i] = x;
	}
	debug(count2);

	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		if (k % i != 0) continue;
		int j = k / i;
		if (i>n) continue;
		if (j>m) continue;
		ans += count1[i-1] * count2[j-1];
		debug(i, j, count1[i-1], count2[j-1]);
	}

	print(ans);

	return 0;
}
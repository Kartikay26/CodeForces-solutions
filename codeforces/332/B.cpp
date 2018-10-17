#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
	#include "prettyprint.hpp"
	#define debug(x) cout << "debug: " << #x " = " << x << endl
#else
	#define debug(x) 0
#endif

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e6+1;

int x[N], s[N], segsum[N];

int32_t main(){
	fast_io();
	int n, k;
	cin >> n >> k;
	int s_ = 0;
	s[0] = s_;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		s_ += x[i];
		s[i] = s_;
	}
	for (int i = 1; i <= n-k+1; ++i) {
		segsum[i] = s[i+k-1]-s[i-1];
	}
	// now find max (segsum[i]+segsum[j]) s.t. j>i+k
	int a = 0, b = 0, asum = 0, bsum = 0, best_a = 0, best_b = 0;
	for (int i = k+1; i <= n-k+1; ++i) {
		b = i;
		bsum = segsum[b];
		if (segsum[b-k] > segsum[a]) {
			a = b-k;
		}
		asum = segsum[a];
		if(asum+bsum>segsum[best_a]+segsum[best_b]){
			best_a = a;
			best_b = b;
		}
	}
	cout << best_a << " " << best_b << endl;
}
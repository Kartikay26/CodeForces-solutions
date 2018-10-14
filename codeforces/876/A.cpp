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

int n,a,b,c;

int min_dis(int s, int n){
	if (n == 0) {
		return 0;
	} else {
		if (s == 0) {
			if (a<b)
				return a+min_dis(1,n-1);
			else
				return b+min_dis(2,n-1);
		} else if (s == 1) {
			if (a<c)
				return a+min_dis(0,n-1);
			else
				return c+min_dis(2,n-1);
		} else if (s == 2) {
			if (b<c)
				return b+min_dis(0,n-1);
			else
				return c+min_dis(2,n-1);
		}
	}
	return -1;
}

int32_t main(){
	fast_io();
	cin >> n >> a >> b >> c;
	int dist = min_dis(0,n-1);
	cout << dist << endl;
}
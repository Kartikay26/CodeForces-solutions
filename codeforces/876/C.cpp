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

int sum_digits(int num){
	int sum_d = 0;
	for(auto i : to_string(num)){
		sum_d += i-'0';
	}
	return sum_d;
}

int32_t main(){
	fast_io();
	int n; cin >> n; vi res;
	for (int i = 0; i < 101; ++i) {
		int a = n - i;
		if(a==0) break;
		if(a+sum_digits(a) == n){
			res.push_back(a);
		}
	}
	reverse(all(res));
	cout << res.size() << endl;
	for(auto i : res){
		cout << i << endl;
	}
}
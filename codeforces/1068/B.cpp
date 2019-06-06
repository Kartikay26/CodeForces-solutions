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
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;

vi factorise(int num){
	vi ans;
	for(int i = 2; i * i <= num; i++){
		if(num % i == 0){
			num /= i;
			ans.push_back(i);
			i--;
		}
	}
	if(num > 1) ans.push_back(num);
	return ans;
}

int32_t main(){
	fast_io();
	int n; cin >> n;
	vi f = factorise(n);
	map<int, int> cnt;
	for(auto &i : f){
		cnt[i]++;
	}
	int ans = 1;
	for(auto [x,c] : cnt){
		ans *= (c+1);
	}
	cout << ans;
	return 0;
}
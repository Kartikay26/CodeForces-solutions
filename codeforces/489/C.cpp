// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#else
#define debug(...) 0
#endif
typedef long long int ll;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e6+1;


int32_t main(){
	fast_io();
	int m, s;
	cin >> m >> s;
	if (s > m*9 or (s == 0 and m != 1)) {
		cout << "-1 -1\n";
		return 0;
	}
	string ans_small(m,'0'), ans_large(m,'0');
	int i = 0;
	while(s > 9){
		ans_large[i] = '9';
		ans_small[m-i-1] = '9';
		s -= 9;
		i++;
	}
	ans_large[i] = s+'0';
	ans_small[m-i-1] = s-1+'0';
	ans_small[0]++;
	cout << ans_small << " " << ans_large << endl;
}
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

int32_t main(){
	fast_io();
	
	int n; cin >> n;
	vi a(n); set<int> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; s.insert(a[i]);
	}

	deque<int> ans;
	int i = a[0];
	ans.push_back(i);
	s.erase(i);
	bool go_ahead = true;
	while(go_ahead){
		if (i%3==0 and s.count(i/3)) {
			i = i/3;
			ans.push_back(i);
			s.erase(i);
			continue;
		}
		if (s.count(i*2)) {
			i = i*2;
			ans.push_back(i);
			s.erase(i);
			continue;
		}
		go_ahead = false;
	}
	bool go_back = true;
	i = a[0];
	while(go_back){
		if (s.count(i*3)) {
			i = i*3;
			ans.push_front(i);
			s.erase(i);
			continue;
		}
		if (i%2==0 and s.count(i/2)) {
			i = i/2;
			ans.push_front(i);
			s.erase(i);
			continue;
		}
		go_back = false;
	}
	for(auto i : ans){
		cout << i << " ";
	}
	cout << endl;
}
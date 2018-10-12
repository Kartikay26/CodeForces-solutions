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

	int n;
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	bool impossible = true;
	for (int i = 0; i < n; ++i) {
		if(arr[i]) impossible = false;
	}
	if (impossible) {
		cout << "NO" << endl;
		return 0;
	}

	vector<pii> ans;
	int l = 0, i = 0;
	while(i<n){
		while(arr[i]==0){
			i++;
			if(i==n) {i--; break;}
		}
		ans.push_back({l,i});
		// debug(ans);
		i++;l=i;
	}

	cout << "YES\n";
	if (arr[ans[ans.size()-1].second] == 0) {
		ans.erase(ans.end()-1);
	}
	ans[ans.size()-1].second = n-1;
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
	}
}
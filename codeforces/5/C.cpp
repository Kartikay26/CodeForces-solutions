#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#endif
using namespace std;

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

#define debug(x) cout << "debug: " << #x " = " << x << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int32_t main(){
	fast_io();
	string s;
	cin >> s;
	int n = s.size();
	stack<int> st;
	vector<int> lens(n);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			st.push(i);
			lens[i] = -1;
		} else {
			if (st.empty()) {
				lens[i] = -1;
			} else {
				lens[i] = (i - st.top() + 1);
				st.pop();
			}
		}
	}
	// begin correction
	for (int i = 0; i < n; ++i) {
		if (i-lens[i]>=0 and lens[i]!=-1 and (lens[i-lens[i]]!=-1)){
			lens[i] += lens[i-lens[i]];
		}
	}
	// end correction

	int m = *max_element(all(lens));
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += (lens[i] == m);
	}

	if (m == -1) {
		cout << "0 1" << endl;
	} else {
		cout << m << " " << cnt << endl;
	}
	
}
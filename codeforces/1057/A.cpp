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
	vi parent(n);
	for (int i = 0; i < n-1; ++i) {
		cin >> parent[i+1];
	}
	vi seq;
	int cur = n;
	while(cur != 1){
		seq.push_back(cur);
		cur = parent[cur-1];
	}
	seq.push_back(cur);
	reverse(all(seq));
	for (int i = 0; i < seq.size(); ++i) {
		cout << seq[i] << " ";
	}
	cout << endl;
}
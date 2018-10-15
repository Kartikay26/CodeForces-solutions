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
	vector<pii> walls;
	int n; // rows
	int m; // columns
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '*') {
				walls.push_back({i,j});
			}
		}
	}
	// AAAAAAAAAAAARGH I cant take it anymore
	map<int, int> xcords;
	map<int, int> ycords;
	
	for(auto xy : walls){
		xcords[xy.first]++;
		ycords[xy.second]++;
	}
	
	// SOMEONE PLZ JUST KIL ME NOW IF I GET WA AGAIN (or TLE probably)
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			bool didntwork = false;
			for(auto xyC : walls){
				int xC = xyC.first;
				int yC = xyC.second;
				if (!(xC == x or yC == y)) {
					didntwork = true;
					break;
				}
			}
			if (not didntwork) {
				// it workd, print x and y
				cout << "YES\n" << x+1 << " " << y+1 << endl;
				return 0;
			}
		}
	}
	
	cout << "NO" << endl;
}
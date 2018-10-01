#include <bits/stdc++.h>
// #include "prettyprint.hpp"
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

	int n; cin >> n;

	for (int i = 0; i < n; ++i)
	{
		switch(i%4){
			case 0: case 1: cout << 'a'; break;
			case 2: case 3: cout << 'b'; break;
		}
	}

	cout << endl;

}
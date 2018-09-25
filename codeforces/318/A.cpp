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

	int n, k;
	cin >> n >> k;

	int n_odd = ceil(n/2.);

	if(k<=n_odd){
		cout << k*2-1 << endl;
	}
	else {
		cout << (k-n_odd)*2 << endl;
	}


}
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

	int n,k;
	cin >> n >> k;
	int a[n];
	
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	int s = accumulate(a, a+n, 0);

	int grade = floor(float(s)/n+0.5);
	int ans = 0;
	while(grade < k){
		s += k;
		n += 1;
		ans ++;
		grade = floor(float(s)/n+0.5);
	}

	cout << ans << endl;

}
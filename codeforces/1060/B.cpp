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

	int n;
	cin >> n;

	string sA = to_string(n);

	sA[0]--;
	for (int i = 1; i < sA.size(); ++i) {
		sA[i] = '9';
	}

	int numA = stoll(sA);

	string sB = to_string(n - numA);

	int sumA = 0, sumB = 0;

	for(auto i : sA){
		sumA += (i-'0');
	}
	for(auto i : sB){
		sumB += (i-'0');
	}

	cout << sumA + sumB << endl;

}

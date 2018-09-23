#include <bits/stdc++.h>
// #include "prettyprint.hpp"
using namespace std;

typedef long long int lli;
#define int lli

#define debug(x) cout << "debug: " << #x " = " << x << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int a[105]; int sum = 0;

int N;

bool check(int n){
	if(sum % n != 0)
		return false;
	int i = 0; int psum = 0;
	while(i < N){
		psum += a[i];
		if (psum == sum/n){
			psum = 0;
		}
		if(psum > sum/n){
			return false;
		}
		i++;
	}
	return psum == 0;
}


int32_t main(){
	fast_io();

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		char z;
		cin >> z;
		a[i] = z - '0';
		sum += a[i];
	}

	for (int i = 2; i <= N; ++i)
	{
		if(check(i)){cout << "YES\n"; return 0;};
	}
	cout << "NO\n";
}
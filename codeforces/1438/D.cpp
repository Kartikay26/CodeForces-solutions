// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

void test()
{
	int n; cin >> n;
	int s = 0;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		s ^= v[i];
	}
	if (n % 2 == 0) {
		if (s == 0) {
			n--;
		} else {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	int k = (n-1) / 2;
	cout << k*2 - 1 << endl;
	int a = 1;
	for (int i = 0; i < k; ++i) {
		cout << a << " "
			 << a+1 << " "
			 << a+2 << endl;
		a += 2;
	}
	a -= 4;
	for (int i = 0; i < k-1; ++i) {
		cout << a << " "
			 << a+1 << " "
			 << a+2 << endl;
		a -= 2;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
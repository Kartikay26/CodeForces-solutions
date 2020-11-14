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

bool has_one (string s)
{
	return any_of(s.begin(), s.end(), [](char c){ return c == '1'; });
}

void test()
{
	string a; cin >> a;
	string b; cin >> b;
	cout << ( a.size() == b.size() &&
			 has_one(a) == has_one(b) ? "YES" : "NO") << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
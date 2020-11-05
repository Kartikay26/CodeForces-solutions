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

int a, b, g;

vector<int> f;
set<int> d;
vector<int> D;

vector<int> factorize(int num){
	vector<int> ans;
	for(int i = 2; i * i <= num; i++){
		if(num % i == 0){
			num /= i;
			ans.push_back(i);
			i--;
		}
	}
	if(num > 1) ans.push_back(num);
	return ans;
}

void alldiv(int k, int i)
{
	if (i == int(f.size())) {
		d.insert(k);
	} else {
		alldiv(k, i+1);
		alldiv(k * f[i], i+1);
	}
}

void preprocess()
{
	g = __gcd(a, b);
	f = factorize(g);
	alldiv(1, 0);
	D = vector<int>(d.begin(), d.end());
}

void solve(int)
{
	int low, high; cin >> low >> high;
	auto ans = upper_bound(D.begin(), D.end(), high);
	ans--;
	if (*ans < low or *ans > high) {
		cout << -1 << endl;
	} else {
		cout << *ans << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b;
	preprocess();
	int t; cin >> t;
	for (int i = 0; i < t; ++i)
	{
		solve(i);
	}
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
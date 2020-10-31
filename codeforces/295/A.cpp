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

void applyQ (vector<ll>& vec, vector<array<ll, 3>>& queries)
{
	vector<ll> sum(vec.size());
	for (auto& [l,r,x] : queries)
	{
		sum[l] += x;
		if (r+1 < sum.size())
		{
			sum[r+1] -= x;
		}
	}
	ll p = 0;
	for (auto& i : sum)
	{
		p += i;
		i = p;
	}
	for (ll i = 0; i < vec.size(); ++i)
	{
		vec[i] += sum[i];
	}
}

void solve()
{
	ll n, m, k; cin >> n >> m >> k;
	vector<ll> a(n);
	vector<ll> b(m);
	for (ll i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	vector<array<ll,3>> q(m); // l, r, d
	for (ll i = 0; i < m; ++i)
	{
		cin >> q[i][0] >> q[i][1] >> q[i][2];
		q[i][0]--;
		q[i][1]--;
	}
	vector<array<ll,3>> q2(k); // x, y, 1
	for (ll i = 0; i < k; ++i)
	{
		cin >> q2[i][0] >> q2[i][1];
		q2[i][2] = 1;
		q2[i][0]--;
		q2[i][1]--;
	}
	applyQ(b, q2);
	// mul q by b
	for (ll i = 0; i < m; ++i)
	{
		q[i][2] *= b[i];
	}
	applyQ(a, q);
	for (auto& i : a)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
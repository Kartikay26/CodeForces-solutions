// kartikay26 | st0rmbring3r

#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#else
#define debug(x) 0
#endif
typedef long long int lli;
#define int lli
typedef vector<int> vi;
typedef pair<int, int> pii;

int32_t main()
{
	int n;
	cin >> n;
	vi v00, v11, v01, v10;
	for (int i = 0; i < n; ++i) {
		int p, q; cin >> p >> q;
		if (p == 00) v00.push_back(q);
		if (p == 01) v01.push_back(q);
		if (p == 10) v10.push_back(q);
		if (p == 11) v11.push_back(q);
	}
	int cnt00 = v00.size(); sort(all(v00)); reverse(all(v00));
	int cnt01 = v01.size(); sort(all(v01)); reverse(all(v01));
	int cnt10 = v10.size(); sort(all(v10)); reverse(all(v10));
	int cnt11 = v11.size(); sort(all(v11)); reverse(all(v11));
	int taken_elements = cnt11 + min(cnt10, cnt01)*2;
	multiset<int> remaining;
	remaining.insert(all(v00));
	int s = accumulate(all(v11), 0);

	if (cnt10<cnt01) {
		s += accumulate(all(v10), 0);
		s += accumulate(v01.begin(),v01.begin()+cnt10, 0);
		remaining.insert(v01.begin() + cnt10,v01.end());
	} else {
		s += accumulate(all(v01), 0);
		s += accumulate(v10.begin(),v10.begin()+cnt01, 0);
		remaining.insert(v10.begin() + cnt01,v10.end());
	}

	auto it = remaining.rbegin();
	int N = (cnt11 + min(cnt10, cnt01))*2;
	// debug(N);
	while(taken_elements < N and it != remaining.rend()){
		s += *it;
		it++;
		taken_elements++;
	}


	/*debug(k);

	int i=0;
	while(taken_elements<(cnt11 + min(cnt10,cnt01))*2)
	{
		if(k[i]<v00[i])
		{
			s+=v00[i];
		}
		else
		{
			s+=k[i];
		}
		debug(s);
		taken_elements++;
	}*/

	cout << s << endl;
}
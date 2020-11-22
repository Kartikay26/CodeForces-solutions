// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

int k;
int n;
int m;
vector<int> v;

int update(int i, int x)
{
	i += n;
	v[i] = x;
	for (int d = 0; d < k; ++d) {
		if (d % 2 == 0)
	    	v[i/2] = v[i] | v[i^1];
	    else
	    	v[i/2] = v[i] ^ v[i^1];
	    i /= 2;
	}
	return v[i];
}

void preprocess()
{
	cin >> k;
    cin >> m;
    n = (1 << k);
    v.resize(2*n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        update(i, x);
    }
}

void test(int)
{
    int i, x; cin >> i >> x;
    cout << update(i-1, x) << endl;
}

int32_t main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    preprocess();
    for (int i = 0; i < m; ++i)
    {
        test(i);
    }
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
/*
chirag11032000
Chirag Thakur
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef double db;
typedef pair < ll, ll > pll;

#define pb push_back
#define debug(x) cout << (#x) << " is " << (x) << endl
#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

const db PI = acos(-1);
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
const ll N = 2e5 + 10;

ll s[N], p[N];
bool seen[N];

int main() {
    fast_io();
    ll n, d;
    cin >> n >> d;
    for (ll i = 1; i <= n; ++i) {
    	cin >> s[i];
    }
    for (ll i = 1; i <= n; ++i) {
    	cin >> p[i];
    }
    s[d] += p[1];
    seen[1] = true;
    ll ctr_give = 2, ctr_take = 1;
    for (ll j = 2; j <= n; ++j) {
    	if (s[ctr_take] >= s[d]) {
    		s[ctr_take] += p[ctr_give];
    		seen[ctr_give] = true;
    		++ctr_give, ++ctr_take;
    	} else {
    		break;
    	}
    }
    for (ll i = ctr_take, j = n; i <= n; ++i, --j) {
    	if (i == d) {
    		continue;
    	} else {
    		s[i] += p[j];
    	}
    }
    ll score = s[d];
    sort(s + 1, s + 1 + n, greater < ll >());
    for (ll i = 1; i <= n; ++i) {
    	if (s[i] == score) {
    		cout << i << "\n";
    		return 0;
    	}
    }
    return 0;
}
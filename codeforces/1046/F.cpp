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

ll a[N];

int main() {
    fast_io();
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    ll x, f;
    cin >> x >> f;
    ll res = 0;
    for (ll i = 0; i < n; ++i) {
    	res += f * ((a[i] - 1 + f) / (f + x)); 
    }
    cout << res << "\n";
    return 0;
}
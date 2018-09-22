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
const ll N = 1e5 + 10;

ll a[N][26];
multiset < ll > mst;
set < ll > st;

int main() {
    fast_io();
    ll n;
    cin >> n;
    string s;
    for (ll i = 0; i < n; ++i) {
    	cin >> s;
    	for (auto &c : s) {
    		++a[i][c - 'a'];
    	}
    	ll temp = 0;
    	for (ll j = 0; j < 26; ++j) {
    		if (a[i][j] % 2 == 1) {
    			temp |= (1 << j);
    		}
    	}
    	mst.insert(temp);
    	st.insert(temp);
    }
    ll neq = 0, eq = 0;
    for (auto it : st) {
    	ll cnt = mst.count(it);
    	eq += (cnt * (cnt - 1)) / 2;
    }
    for (auto it : mst) {
    	for (ll j = 0; j < 26; ++j) {
    		ll temp = it;
    		temp ^= (1 << j);
    		neq += mst.count(temp);
    	}
    }
    ll res = neq / 2 + eq;
    cout << res << "\n";
    return 0;
}
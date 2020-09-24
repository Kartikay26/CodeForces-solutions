// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print(){cout << endl;} void prints(){}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}

const int mod = 998244353;
const int MAXN = 3e5+100;

const int m = mod;

int factorial[MAXN+1];

int modexp(int n, int k){
    int res = 1;
    while(k>0){
        if(k&1){
            res *= n; res %= mod;
        }
        n = n*n; n %= mod;
        k /= 2;
    }
    return res;
}

int inverse(int x) {
    return modexp(x, m-2);
}

int binom(int n, int k) {
    if (k > n) return 0;
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
}

int32_t main(){
    fast_io();

    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % m;
    }

    int n, k; cin >> n >> k;
    vector<pair<int, int>> events; // time, t -> 0: on, 1 : off
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        events.push_back({l, 0});
        events.push_back({r, 1});
    }
    sort(all(events));
    int cnt = 0, ans = 0;
    for (auto [time, t] : events) {
        if (!t) {
            cnt ++;
        } else {
            cnt --;
        }
        debug(time, cnt);
        if (!t) {
            int b = binom(cnt-1, k-1);
            debug(time, cnt, b);
            ans += b;
            ans %= mod;
        }
    }
    print(ans);
    return 0;
}
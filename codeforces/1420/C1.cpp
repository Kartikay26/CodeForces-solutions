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

const int mod = 1e9+7;
const int N = 1e6+1;

int testcase(int t){
    
    int n, q; cin >> n >> q;
    debug(n,q);

    vi a(n); get(a,n);
    debug(a);


    vi dp_p(n);
    vi dp_n(n);
    vi dp_m_p(n);
    vi dp_m_n(n);

    dp_p[0] = a[0];
    dp_m_p[0] = a[0];

    for (int i = 1; i < n; i++) {
        dp_p[i] = max(dp_m_n[i-1] + a[i], a[i]);
        dp_m_p[i] = max(dp_m_p[i-1], dp_p[i]);
        dp_n[i] = max(dp_m_p[i-1] - a[i], 0ll);
        dp_m_n[i] = max(dp_m_n[i-1], dp_n[i]);
    }

    debug(dp_p);
    debug(dp_n);
    debug(dp_m_p);
    debug(dp_m_n);

    return max(dp_m_p[n-1],dp_m_n[n-1]);
}

int32_t main(){
    fast_io();
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        print(testcase(i));
    }
    return 0;
}
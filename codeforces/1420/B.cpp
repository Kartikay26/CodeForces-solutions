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

int firstBit(int x){
    int m = 0;
    for (int i = 0; i < 31; i++) {
        if ( x & (1<<i) ){
            m = (1<<i);
        }
    }
    debug(x,m);
    return m;
}

int testcase(int t){
    
    int n; cin >> n;
    vi a(n); get(a,n);

    map<int, int> cnt;
    int ans = 0;

    for(int x : a) {
        int m = firstBit(x);
        ans += cnt[m];
        cnt[m]++;
    }

    return ans;
    
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
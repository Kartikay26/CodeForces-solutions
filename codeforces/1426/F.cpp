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
void print(){cout << endl;} void prints(){} int get() {int x; cin >> x; return x;}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}
 
const int mod = 1e9+7;
const int N = 1e6+1;
 
int32_t main(){
    fast_io();
 
    int a=0, b=0, c=0;
    int n = get();
    string s; cin >> s;
 
    int p = 1;
    for(auto ch : s){
        switch(ch) {
            case 'a': {
                a += p;
                a %= mod;
            } break;
            case 'b': {
                b += a;
                b %= mod;
            } break;
            case 'c': {
                c += b;
                c %= mod;
            } break;
            case '?': {
                int a_ = ((a*3)%mod + p) % mod;
                int b_ = ((b*3)%mod + a) % mod;
                int c_ = ((c*3)%mod + b) % mod;
                a = a_, b = b_, c = c_;
                p *= 3;
                p %= mod;
            } break;
        }
        debug(ch, a,b,c);
    }
 
    print(c);
 
    return 0;
}
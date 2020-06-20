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

void testcase(int t){
    
    int n; cin >> n;
    n = 2*n;
    vi a(n); get(a, n);

    vi evens;
    vi odds;

    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            evens.push_back(i);
        } else {
            odds.push_back(i);
        }
    }
    debug(evens, odds);
    int k = 1;
    while (evens.size() > 1 and k*2 != n) {
        int a = evens.back() + 1; evens.pop_back();
        int b = evens.back() + 1; evens.pop_back();
        print(a,b); k++;
    }
    while (odds.size() > 1 and k*2 != n) {
        int a = odds.back() + 1; odds.pop_back();
        int b = odds.back() + 1; odds.pop_back();
        print(a,b); k++;
    }
    
}

int32_t main(){
    fast_io();
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        testcase(i);
    }
    return 0;
}
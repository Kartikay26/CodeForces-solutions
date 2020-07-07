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

int n, p;
vi cnt(4001); // cnt[i] counts number of ai <= i

bool check(int x){
    for(int i = 0; i < n; i++) {
        int c = cnt[x+i] - i;
        if (c % p == 0 || c <= 0) {
            debug(x, c);
            return false;
        }
    }
    return true;
}

int32_t main(){
    fast_io();

    cin >> n >> p;
    vi a(n);
    get(a, n);

    for(auto ai : a){
        cnt[ai]++;
    }
    for (int i = 1; i < 4001; ++i) {
        cnt[i] += cnt[i-1];
    }

    vi ans;
    for (int i = 0; i < 2001; ++i) {
        if (check(i)) ans.push_back(i);
    }

    print(ans.size());
    for(auto &i : ans){
        prints(i);
    }
    print();

    return 0;
}
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

int below[N];

int32_t main(){
    fast_io();

    int n; cin >> n;
    vector<vi> vec;
    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        vi temp(l);
        get(temp, l);
        vec.push_back(temp);
    }

    int ans = 0;

    vi ends;

    for(auto &v : vec){
        int m = v[0];
        bool asc = false;
        for(auto &i : v){
            if (i > m){
                asc = true;
            }
            m = min(i, m);
        }
        debug(v, asc);
        int start = v[0];
        if (!asc){
            below[start] += 1;
            ends.push_back(v[v.size()-1]);
        }
    }

    for(int i = 1; i < N; i++){
        below[i] += below[i-1];
    }

    debug(arr(below, 10));

    for(auto e : ends){
        ans += below[e];
    }

    print(int(pow(n,2)) - ans);

    return 0;
}
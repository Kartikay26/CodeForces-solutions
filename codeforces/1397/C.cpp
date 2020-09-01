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

int32_t main(){
    fast_io();

    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a){
        cin >> i;
    }

    if (n == 1) {
        int x = a[0];
        print("1 1\n-1\n1 1\n1\n1 1");
        print(-x);
        return 0;
    }

    print(1, n);
    
    for (int i = 0; i < n-1; i++){
        int x = a[i];
        int b = x%n;
        int a = (x-b)/n + b;
        prints(-a*n);
    }
    prints(0);
    print();

    print(1, n-1);

    for (int i = 0; i < n-1; i++){
        int x = a[i];
        int b = x%n;
        int a = (x-b)/n + b;
        prints(b*(n-1));
    }
    print();
    
    print(n, n);
    print(-a[n-1]);

    return 0;
}
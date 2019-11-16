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

    int c = 0;

    map<int, int> present; // empl -> whether he is there or not
    map<int, int> appeared; // empl -> whether he has appeared once
    int present_cnt = 0;

    vi ans;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x > 0){
            if(appeared[x] == 0){
                appeared[x] = 1;
            } else {
                cout << -1 << endl; return 0;
            }
            present[x] = 1;
            present_cnt ++;
        } else {
            x = -x;
            if(present[x]){
                present[x] = 0;
            } else {
                cout << -1 << endl; return 0;
            }
            present_cnt --;
        }
        c++;
        if(present_cnt == 0){
            ans.push_back(c);
            present.clear();
            appeared.clear();
            c = 0;
        }
    }

    if(present_cnt != 0){
        cout << -1 << endl; return 0;
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        if(i != ans.size() - 1){
            cout << ans[i] << " ";
        } else {
            cout << ans[i] << endl;
        }
    }

    return 0;
}
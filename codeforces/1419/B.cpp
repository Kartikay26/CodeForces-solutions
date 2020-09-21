#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
        int ans = 0;
        for (ll a = 1, ar = 1; ar <= x; a = a*2+1, ar = a*(a+1)/2) {
            x -= ar;
            ans++;
        }
        cout << ans << endl;
    }
}
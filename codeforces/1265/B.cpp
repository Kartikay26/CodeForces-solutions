#include <bits/stdc++.h>
using namespace std;

void test(int t){
    int n; cin >> n;
    vector<int> a(n); // perm
    for(auto &i : a){
        cin >> i;
        i--;
    }
    vector<int> p(n); // inverse perm
    for(int i = 0; i < n; i++){
        p[a[i]] = i;
    }
    int lo = n;
    int hi = -1;
    for(int i = 0; i < n; i++){
        lo = min(lo, p[i]);
        hi = max(hi, p[i]);
        if (hi - lo == i){
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        test(i);
    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> R, B;
        for (int i = 1; i <= n; i++) {
            char c; cin >> c;
            int x = c-'0';
            if (i % 2) {
                R.push_back(x);
            } else {
                B.push_back(x);
            }
        }
        if (R.size() > B.size()){
            if (any_of(R.begin(), R.end(), [](int x){return x%2==1;})) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            if (any_of(B.begin(), B.end(), [](int x){return x%2==0;})) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
        }
    }
}

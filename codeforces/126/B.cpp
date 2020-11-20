// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

const int m = 1e9+7;
const int p = 31;

int modexp (int n, int k)
{
    int r = 1;
    while(k>0){
        if(k&1){
            r *= n; r %= m;
        }
        n = n*n; n %= m;
        k /= 2;
    }
    return r;
}

int modinv (int n)
{
    return modexp(n, m - 2);
}

void test()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> hashes;
    vector<int> prefix;
    vector<int> preinv;
    int pi = 1; // p^i
    int pm = 1;
    int p_inv = modinv(p);
    int h = 0;
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a' + 1;
        h = (h + (c*pi)%m)%m;
        hashes.push_back(h);
        preinv.push_back(pm);
        pi = (pi*p)%m;
        pm = (pm*p_inv)%m;
    }
    auto substringHash = [&](int i, int j){
        int hp = (hashes[j] - (i?hashes[i-1]:0) + m) % m;
        int pi = preinv[i];
        return (hp * pi) % m;
    };
    for (int i = 1; i < n; ++i) {
        // find suffix that is also prefix
        if (hashes[i-1] == substringHash(n-i, n-1)) {
            prefix.push_back(i);
        }
    }
    // answer will be either (n)th or (n-1)st in this array
    reverse(prefix.begin(), prefix.end());
    for (int len : prefix) {
        // check if this occurs in the middle of the string (i.e. index [1] to [n-1-len])
        for (int i = 1; i <= n-1-len; ++i) {
            if (hashes[len-1] == substringHash(i, i+len-1)) {
                cout << s.substr(0, len) << endl;
                return;
            }
        }
    }
    cout << "Just a legend" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
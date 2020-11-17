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

const int mod = 1000000007;
const int N = 1e6+1;

int a, b, fact[N];

int modexp (int n, int k)
{
    int res = 1;
    while(k>0){
        if(k&1){
            res *= n; res %= mod;
        }
        n = n*n; n %= mod;
        k /= 2;
    }
    return res;
}

int modinv (int n)
{
    return modexp(n, mod - 2);
}

bool good (int x)
{
    for (char c : to_string(x)) {
        if (!(c-'0' == a || c-'0' == b)) {
            return false;
        }
    }
    return true;
}

void test()
{
    int n;
    cin >> a >> b >> n;
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }

    int ans = 0;

    for (int k = 0; k <= n; ++k) {
        int sum = a*k + b*(n-k);
        if (good(sum)) {
            debug(k, sum);
            ans += (((fact[n] * modinv(fact[k])) % mod) * modinv(fact[n-k])) % mod;
            ans %= mod;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
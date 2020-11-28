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

const int N = 6e5+10;
const int m = 1e9+7;
using Hash = pair<int, int>;

int n, q;
int p1[N] = {31};
int p2[N] = {7};

set<Hash> mem;

Hash stringHash(string s)
{
    int h1 = 0;
    int h2 = 0;
    for (int i = 0; i < s.size(); ++i) {
        h1 = (h1 + (s[i] - 'a' + 1) * p1[i] % m) % m;
        h2 = (h2 + (s[i] - 'a' + 1) * p2[i] % m) % m;
    }
    return {h1, h2};
}

void preprocess()
{
    cin >> n;
    cin >> q;
    for (int i = 1; i < N; ++i) {
        p1[i] = (p1[i-1] * p1[0]) % m;
        p2[i] = (p2[i-1] * p2[0]) % m;
    }
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        mem.insert(stringHash(s));
    }
    debug(mem);
}

bool query(int)
{
    string s; cin >> s;
    debug(s);
    Hash h = stringHash(s);
    for (int i = 0; i < s.size(); ++i) {
        for (int c : {1, 2, 3}) {
            Hash hnew = h;
            if (s[i] == c-1+'a')
                continue;
            int delta1 = (((c - (s[i] - 'a' + 1)) * p1[i]) % m + m) % m;
            hnew.first += delta1;
            hnew.first %= m;
            int delta2 = (((c - (s[i] - 'a' + 1)) * p2[i]) % m + m) % m;
            hnew.second += delta2;
            hnew.second %= m;
            debug(i,c,hnew);
            if (mem.count(hnew)) {
                return true;
            }
        }
    }
    return false;
}

int32_t main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    preprocess();
    for (int i = 0; i < q; ++i)
    {
        cout << (query(i) ? "YES" : "NO") << endl;
    }
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
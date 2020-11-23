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

class RMQ {
    int floorLog2(int n){return (64 - __builtin_clzll(n) - 1);}
public:
    int n, maxK;
    vector<vector<int>> rmq;
    RMQ(vector<int> arr) { // construct RMQ table from array in O(n log n)
        n = arr.size();
        maxK = floorLog2(n) + 1;
        rmq.assign(maxK, vector<int>(n));
        rmq[0] = arr;
        for (int k = 1; k < maxK; k++) {
            for (int i = 0; i < n; i++) {
                if (i+(1<<(k-1)) < n) {
                    rmq[k][i] = __gcd(rmq[k-1][i], rmq[k-1][i+(1<<(k-1))]);
                }
            }
        }
    }
    int gcdq(int l, int r) { // returns gcd
        assert(0 <= l and l <= r and r < n);
        int k = floorLog2(r-l+1);
        return __gcd(rmq[k][l], rmq[k][r+1-(1<<k)]);
    }
};

// BINARY SEARCH : Usage: TTTT..TTFFF  low <= i < high
int findLastTrue(int low, int high, function<bool(int)> check, bool debug = false)
{
    if (debug) {
        bool prev = true;
        for (int i = low; i < high; ++i) {
            bool chk = check(i);
            debug(i, chk);
            assert(prev or not chk);
            prev = chk;
        }
    }
    if (!check(low))
        return low-1;
    int i = low;
    for (int b = (high - low); b > 0; b /= 2) {
        while (i+b < high and check(i+b)) i += b;
    }
    return i;
}

void test()
{
    int n; cin >> n;
    vector<int> a(n);
    vector<int> l(n);
    vector<int> r(n);
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    RMQ g(a);
    for (int i = 0; i < n; ++i) {
        // last one that does not divide
        l[i] = i - findLastTrue(0, i, [&](int x) {
            return g.gcdq(x, i) != a[i];
        }) - 1;
    }
    for (int i = n-1; i >= 0; --i) {
        // last one that does divide
        r[i] = findLastTrue(i, n, [&](int x) {
            return g.gcdq(i, x) == a[i];
        }) - i;
    }
    for (int i = 0; i < n; ++i) {
        s[i] = l[i] + r[i];
    }
    debug(a);
    debug(l);
    debug(r);
    debug(s);
    int max_len = *max_element(s.begin(), s.end());
    set<int> ans;
    for (int i = 0; i < n; ++i) {
        if (s[i] == max_len) {
            ans.insert(i+1 - l[i]);
        }
    }
    int num_ans = ans.size();
    cout << num_ans << " " << max_len << endl;
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
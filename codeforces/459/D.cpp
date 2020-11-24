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

struct BIT {
    // 1-indexed BIT. range 1 to n inclusive.
    vector<int> arr;
    BIT(int n) {
        arr.resize(n+1);
    }
    void add(int x, int delta) {
        assert(x > 0 && x < arr.size());
        for (int u = x; u < arr.size(); u += u&-u)
            arr[u] += delta;
    }
    void inc(int x) { add(x, 1); }
    int query(int r) {
        assert(r >= 0 && r < arr.size());
        int a = 0;
        for (int q = r; q > 0; q -= q&-q)
            a += arr[q];
        return a;
    }
    int query(int l, int r) {
        assert(r > l && l >= 0 && r < arr.size());
        if (l == 1) return query(r);
        return query(r) - query(l-1);
    }
};

void test()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> l(n);
    map<int,int> cl;
    for (int i = 0; i < n; ++i) {
        cl[a[i]]++;
        l[i] = cl[a[i]];
    }
    vector<int> r(n);
    map<int,int> cr;
    for (int i = n-1; i >= 0; --i) {
        cr[a[i]]++;
        r[i] = cr[a[i]];
    }
    BIT b(n);
    int ans = 0;
    for (int i = n-1; i >= 0; --i) {
        // count # r[i] smaller than l[i] to the right of it
        ans += b.query(l[i]-1);
        b.inc(r[i]);
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
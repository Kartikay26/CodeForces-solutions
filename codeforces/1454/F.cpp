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

class RMQ_min {
    int floorLog2(int n){return (64 - __builtin_clzll(n) - 1);}
public:
    int n, maxK;
    vector<vector<int>> rmq;
    RMQ_min(vector<int> arr) { // construct RMQ table from array in O(n log n)
        n = arr.size();
        maxK = floorLog2(n) + 1;
        rmq.assign(maxK, vector<int>(n));
        rmq[0] = arr;
        for (int k = 1; k < maxK; k++) {
            for (int i = 0; i < n; i++) {
                if (i+(1<<(k-1)) < n) {
                    rmq[k][i] = min(rmq[k-1][i], rmq[k-1][i+(1<<(k-1))]);
                }
            }
        }
    }
    int minq(int l, int r) { // returns <value, index> of first minimum in range in O(1)
        assert(0 <= l and l <= r and r < n);
        int k = floorLog2(r-l+1);
        return min(rmq[k][l], rmq[k][r+1-(1<<k)]);
    }
};

class RMQ_max {
    int floorLog2(int n){return (64 - __builtin_clzll(n) - 1);}
public:
    int n, maxK;
    vector<vector<int>> rmq;
    RMQ_max(vector<int> arr) { // construct RMQ table from array in O(n log n)
        n = arr.size();
        maxK = floorLog2(n) + 1;
        rmq.assign(maxK, vector<int>(n));
        rmq[0] = arr;
        for (int k = 1; k < maxK; k++) {
            for (int i = 0; i < n; i++) {
                if (i+(1<<(k-1)) < n) {
                    rmq[k][i] = max(rmq[k-1][i], rmq[k-1][i+(1<<(k-1))]);
                }
            }
        }
    }
    int maxq(int l, int r) { // returns <value, index> of first minimum in range in O(1)
        assert(0 <= l and l <= r and r < n);
        int k = floorLog2(r-l+1);
        return max(rmq[k][l], rmq[k][r+1-(1<<k)]);
    }
};

// Binary Search
// Usage: TTTT..TTFFF  | low <= i < high | low-1 <= output < high
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
// Usage: FFFF..FFTTT  | low <= i < high | low <= output <= high
int findFirstTrue(int low, int high, function<bool(int)> check, bool debug = false)
{
    return findLastTrue(low, high, [&](int i){
        return !check(i);
    }, debug) + 1;
}

void test(int)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    debug(n, v);
    RMQ_min rmin (v);
    RMQ_max rmax (v);
    for (int i = 0; i < n-2; ++i) {
        int m1 = rmax.maxq(0, i);
        int j1 = findFirstTrue(i+1, n-1, [&](int j){
            return rmax.maxq(j+1, n-1) <= m1;
        });
        if (j1 == n-1) continue;
        int j2 = findLastTrue(i+1, n-1, [&](int j){
            return rmax.maxq(j+1, n-1) >= m1;
        });
        if (j2 == i) continue;
        if (j1 > j2) continue;
        //j1 >= i+1 ... j2 <= n-2
        int j = findFirstTrue(j1, j2+1, [&](int j){
            return rmin.minq(i+1, j) <= m1;
        });
        if (j == j2+1) continue;
        if (rmin.minq(i+1, j) != m1) continue;
        cout << "YES" << endl;
        cout << i+1 << " " << j-i << " " << n-1-j << endl;
        return;
    }
    cout << "NO" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
    {
        test(i);
    }
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
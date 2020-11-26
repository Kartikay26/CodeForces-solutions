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

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }
    auto cost = [&](int x) -> int {
        // after the ops, min a = x and max b = x
        int ans = 0;
        for (int i : A) {
            if (i < x) {
                ans += x - i;
            }
        }
        for (int i : B) {
            if (i > x) {
                ans += i - x;
            }
        }
        return ans;
    };
    int cur_min_A = *min_element(A.begin(), A.end());
    int cur_max_B = *max_element(B.begin(), B.end());
    int ans = findFirstTrue(cur_min_A, cur_max_B+1, [&](int i){
        return cost(i) <= cost(i+1);
    });
    cout << cost(ans) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
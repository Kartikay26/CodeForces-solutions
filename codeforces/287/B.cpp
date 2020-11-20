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

// NAIVE ALGO:

// int solve(int n, int k)
// {
//     int a = 1;
//     while (n > k) {
//         debug(a, n, k);
//         n = n - k + 1;
//         k = k - 1;
//         a = a + 1;
//         if (k < 2)
//             return -1;
//     }
//     return a;
// }

// OPTIMISE:

pair<int, int> take_i_steps(int i, int n, int k)  // returns -> <n, k> after `i` steps
{
    // n <- n - (k-1) - (k-2) - .. - (k-i)
    // k <- k - i
    int is = i*(i+1) / 2;
    int n_ = n - (i*k) + is;
    int k_ = k - i;
    return {n_, k_};
}

int solve(int n, int k)
{
    auto check = [&](int i) -> bool {
        auto [n_, k_] = take_i_steps(i, n, k);
        return n_ <= k_;
    };
    if (!check(k-1)) {
        return -1;
    }
    // if n < k, then find the first i for which n was smaller than k
    for (int a = 0; a <= k; ++a) {
        auto [n_, k_] = take_i_steps(a, n, k);
        debug(a, n_, k_, check(a));
    }
    int x = k-1;
    for (int b = k-1; b > 0; b /= 2) {
        while (check(x-b)) x -= b;
    }
    return x+1;
}

void test()
{
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
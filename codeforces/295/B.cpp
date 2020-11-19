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

void test()
{
    int n;
    cin >> n;
    int w[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> w[i][j];
        }
    }
    int v[n];
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int a[n][n];
    int d[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // vertex v[1] th -> n th
            a[n-1-i][n-1-j] = w[v[i]-1][v[j]-1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = a[i][j];
        }
    }
    int ans[n];
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
        int sum = 0;
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                sum += d[i][j];
            }
        }
        ans[n-1-k] = sum; 
    }
    for (auto& x : ans) {
        cout << x << ' ';
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
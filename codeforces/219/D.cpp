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

const int N = 1e6+1;

vector<int> fwd[N];
vector<int> bck[N];

int num[N];

int get_reversed_edges (int i, int p = -1)
{
    int ans = 0;
    for (int j : fwd[i])
    {
        if (j == p) continue;
        ans += get_reversed_edges(j, i);
    }
    for (int j : bck[i])
    {
        if (j == p) continue;
        ans += get_reversed_edges(j, i) + 1;
    }
    return ans;
}

void set_answer_num (int i, int n, int p = -1)
{
    num[i] = n;
    for (int j : fwd[i])
    {
        if (j == p) continue;
        set_answer_num(j, n+1, i);
    }
    for (int j : bck[i])
    {
        if (j == p) continue;
        set_answer_num(j, n-1, i);
    }
}

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        fwd[u].push_back(v);
        bck[v].push_back(u);
    }
    int num1 = get_reversed_edges(1);
    set_answer_num(1, num1);
    debug(arr(num+1, n));
    int ans = *min_element(num+1, num+1+n);
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        if (num[i] == ans) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
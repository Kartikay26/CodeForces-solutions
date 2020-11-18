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

// xx
// ox
#define UP_RIGHT    ans.push_back({i,j,   i,j+1, i+1,j+1});  if(Debug) print("-> UP_RIGHT", i,j);
// xo
// xx
#define DOWN_LEFT   ans.push_back({i,j,   i+1,j, i+1,j+1});  if(Debug) print("-> DOWN_LEFT", i,j);
// ox
// xx
#define DOWN_RIGHT  ans.push_back({i+1,j, i,j+1, i+1,j+1});  if(Debug) print("-> DOWN_RIGHT", i,j);
// xx
// xo
#define UP_LEFT     ans.push_back({i,j,   i,j+1,   i+1,j}); if(Debug) print("-> UP_LEFT", i,j);

const bool Debug = false;


void test(int)
{
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j];
        }
    }
    if (Debug) {
        print("----------------> 1");
        for (int i = 0; i < n; ++i) {
            cout << "--- ";
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    vector<array<int, 6>> ans;
    vector<array<int, 6>> ans2;
    vector<array<int, 6>> ans3;
    if (m % 2 == 1) {
        if (n % 2 == 1) {
            if (a[n-1][m-1] == '1') {
                int i = n-2, j = m-2;
                DOWN_RIGHT;
            }
        }
    }
    for (auto& x : ans) {
        a[x[0]][x[1]] ^= 1;
        a[x[2]][x[3]] ^= 1;
        a[x[4]][x[5]] ^= 1;
    }
    ans3 = ans;
    ans.clear();
    if (m % 2 == 1) {
        int j = m-2;
        for (int i = 0; i < n-1; i+=2) {
            if   (a[i][j+1] == '1'
            and a[i+1][j+1] == '1') {
                UP_RIGHT;
            }
            if   (a[i][j+1] == '0'
            and a[i+1][j+1] == '1') {
                DOWN_LEFT;
            }
            if   (a[i][j+1] == '1'
            and a[i+1][j+1] == '0') {
                UP_LEFT;
            }
        }
    }
    if (n % 2 == 1) {
        int i = n-2;
        for (int j = 0; j < m-1; j+=2) {
            if   (a[i+1][j] == '1' and   a[i+1][j+1] == '1') {
                DOWN_LEFT;
            }
            if   (a[i+1][j] == '1' and   a[i+1][j+1] == '0') {
                UP_LEFT;
            }
            if   (a[i+1][j] == '0' and   a[i+1][j+1] == '1') {
                UP_RIGHT;
            }
        }
    }
    for (auto& x : ans) {
        a[x[0]][x[1]] ^= 1;
        a[x[2]][x[3]] ^= 1;
        a[x[4]][x[5]] ^= 1;
    }
    ans2 = ans;
    ans.clear();
    if (Debug) {
        print("----------------> 2");
        for (int i = 0; i < n; ++i) {
            cout << "--- ";
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    for (int i = 0; i < n-1; i+=2) {
        for (int j = 0; j < m-1; j+=2) {
            // ==========================================4======================================
            // xx
            // xx
            if   (a[i][j] == '1' and   a[i][j+1] == '1'
            and a[i+1][j] == '1' and a[i+1][j+1] == '1') {
                UP_LEFT;
                DOWN_RIGHT;
                DOWN_LEFT;
                UP_RIGHT;
            }
            // ==========================================3======================================
            // ox
            // xx
            if   (a[i][j] == '0' and   a[i][j+1] == '1'
            and a[i+1][j] == '1' and a[i+1][j+1] == '1') {
                DOWN_RIGHT;
            }
            // xx
            // xo
            if   (a[i][j] == '1' and   a[i][j+1] == '1'
            and a[i+1][j] == '1' and a[i+1][j+1] == '0') {
                UP_LEFT;
            }
            // xx
            // ox
            if   (a[i][j] == '1' and   a[i][j+1] == '1'
            and a[i+1][j] == '0' and a[i+1][j+1] == '1') {
                UP_RIGHT;
            }
            // xo
            // xx
            if   (a[i][j] == '1' and   a[i][j+1] == '0'
            and a[i+1][j] == '1' and a[i+1][j+1] == '1') {
                DOWN_LEFT;
            }
            // ==========================================2======================================
            // xo
            // ox
            if   (a[i][j] == '1' and   a[i][j+1] == '0'
            and a[i+1][j] == '0' and a[i+1][j+1] == '1') {
                UP_LEFT;
                DOWN_RIGHT;
            }
            // ox
            // xo
            if   (a[i][j] == '0' and   a[i][j+1] == '1'
            and a[i+1][j] == '1' and a[i+1][j+1] == '0') {
                UP_RIGHT;
                DOWN_LEFT;
            }
            
            // xx
            // oo
            if   (a[i][j] == '1' and   a[i][j+1] == '1'
            and a[i+1][j] == '0' and a[i+1][j+1] == '0') {
                DOWN_RIGHT;
                DOWN_LEFT;
            }
            // oo
            // xx
            if   (a[i][j] == '0' and   a[i][j+1] == '0'
            and a[i+1][j] == '1' and a[i+1][j+1] == '1') {
                UP_RIGHT;
                UP_LEFT;
            }
            // ox
            // ox
            if   (a[i][j] == '0' and   a[i][j+1] == '1'
            and a[i+1][j] == '0' and a[i+1][j+1] == '1') {
                UP_LEFT;
                DOWN_LEFT;
            }
            // xo
            // xo
            if   (a[i][j] == '1' and   a[i][j+1] == '0'
            and a[i+1][j] == '1' and a[i+1][j+1] == '0') {
                UP_RIGHT;
                DOWN_RIGHT;
            }
            // ==========================================1======================================
            // oo
            // ox
            if   (a[i][j] == '0' and   a[i][j+1] == '0'
            and a[i+1][j] == '0' and a[i+1][j+1] == '1') {
                DOWN_RIGHT;
                DOWN_LEFT;
                UP_RIGHT;
            }
            // ox
            // oo
            if   (a[i][j] == '0' and   a[i][j+1] == '1'
            and a[i+1][j] == '0' and a[i+1][j+1] == '0') {
                UP_LEFT;
                DOWN_RIGHT;
                UP_RIGHT;
            }
            // oo
            // xo
            if   (a[i][j] == '0' and   a[i][j+1] == '0'
            and a[i+1][j] == '1' and a[i+1][j+1] == '0') {
                UP_LEFT;
                DOWN_RIGHT;
                DOWN_LEFT;
            }
            // xo
            // oo
            if   (a[i][j] == '1' and   a[i][j+1] == '0'
            and a[i+1][j] == '0' and a[i+1][j+1] == '0') {
                UP_LEFT;
                DOWN_LEFT;
                UP_RIGHT;
            }
            // ==========================================0======================================
            // oo
            // oo
            if   (a[i][j] == '0' and   a[i][j+1] == '0'
            and a[i+1][j] == '0' and a[i+1][j+1] == '0') {
                // nothing
            }
        }
    }
    debug(ans);
    for (auto& x : ans) {
        a[x[0]][x[1]] ^= 1;
        a[x[2]][x[3]] ^= 1;
        a[x[4]][x[5]] ^= 1;
    }
    if (Debug) {
        print("----------------> 3");
        for (int i = 0; i < n; ++i) {
            cout << "--- ";
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            assert(a[i][j] == '0');
        }
    }
    cout << ans.size() + ans2.size() + ans3.size() << endl;
    // cout << ans.size() << endl;
    for (auto& r : ans3) {
        for (auto& x : r) {
            cout << x+1 << ' ';
        }
        cout << '\n';
    }
    for (auto& r : ans2) {
        for (auto& x : r) {
            cout << x+1 << ' ';
        }
        cout << '\n';
    }
    for (auto& r : ans) {
        for (auto& x : r) {
            cout << x+1 << ' ';
        }
        cout << '\n';
    }
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
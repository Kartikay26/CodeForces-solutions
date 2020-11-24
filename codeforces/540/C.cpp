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

int n, m;
int r, c;
char grid[502][502];
bool vist[502][502];

int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

void dbg(int x, int y){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << (i==x and j==y ? 'O' : grid[i][j]) << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool dfs(int x, int y)
{
    if (vist[x][y]) return false;
    vist[x][y] = true;
    // dbg(x,y);
    for (int i = 0; i < 4; ++i) {
        if (x+dx[i] == r and y+dy[i] == c) return true;
        if (grid[x+dx[i]][y+dy[i]] == '.') {
            if (dfs(x+dx[i], y+dy[i])) return true;
        }
    }
    return false;
}

void test()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            grid[i+1][j+1] = s[j];
        }
    }
    int r1, c1;
    cin >> r1 >> c1;
    cin >> r >> c;
    bool reachable = dfs(r1, c1);
    // output YES if (can reach) AND if (target intact) atleast 2 neighbours
    if (reachable) {
        if (grid[r][c] == 'X') {
            print("Reach and fall");
            cout << "YES" << endl;
        } else {
            int ns = 0;
            for (int i = 0; i < 4; ++i) {
                if (grid[r+dx[i]][c+dy[i]] == '.' or (r+dx[i] == r1 and c+dy[i] == c1)) {
                    ns++;
                }
            }
            if (ns >= 2) {
                print("Reachable Twice");
                cout << "YES" << endl;
            } else {
                print("Reachable but no extra neighbour");
                cout << "NO" << endl;
            }
        }
    } else {
        print("Unreachable");
        cout << "NO" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
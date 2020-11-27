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

const int inf = 1e18;

struct DSU {
    vector<int> parent;
    vector<int> sizes;
    int nsets;
    DSU(int n):parent(n),sizes(n),nsets(n){
        for (int i = 0; i < n; ++i) {
            parent[i] = i; sizes[i] = 1;
        }
    }
    void join(int i, int j){
        i = find(i); j = find(j); if(i==j) return;
        if(sizes[i]<sizes[j]) swap(i,j);
        parent[i] = j;
        sizes[j] += sizes[i];
        nsets--;
    }
    int find(int i){
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    int size(int i){
        i = find(i);
        return sizes[i];
    }
    bool compare(int i, int j){
        return find(i) == find(j);
    }
};

void solve()
{
    int n, m, t; cin >> n >> m >> t; // n = bac, m = edges, t = types
    vector<int> tt(t); // to of bac of each type
    for (int i = 0; i < t; ++i) {
        cin >> tt[i];
    }
    vector<int> type(n); // actually the type of each bac
    {
        int i = 0, ti = 0;
        for (auto& tn : tt) {
            for (int j = 0; j < tn; ++j) {
                type[i++] = ti;
            }
            ti++;
        }
    }

    int mat[t][t];
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            mat[i][j] = (i==j ? 0 : inf);
        }
    }
    
    DSU d(n);

    for (int i = 0; i < m; ++i) {
        // read edge
        int u, v, w; cin >> u >> v >> w; u--, v--;
        // connects u to v with wt w
        if (w == 0) {
            d.join(u, v);
        }
        mat[type[v]][type[u]] =
        mat[type[u]][type[v]] =
            min(mat[type[u]][type[v]], w);
    }
    
    // check each type is connnected or not
    map<int, int> component; // type -> component
    for (int i = 0; i < n; ++i) {
        int comp_ = d.find(i);
        int type_ = type[i];
        // if wrong type
        if (component.count(type_) and component[type_] != comp_) {
            cout << "No" << endl; return;
        } else {
            component[type_] = comp_;
        }
    }

    // run floyd warshall on mat
    for (int k = 0; k < t; ++k) {
        for (int i = 0; i < t; ++i) {
            for (int j = 0; j < t; ++j) {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            cout << (mat[i][j] == inf ? -1 : mat[i][j]) << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
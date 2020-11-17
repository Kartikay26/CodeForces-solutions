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
    map<int, int> m;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        m[x]++;
        total += x;
    }
    
    total %= 3;

    if (!m[0]) {
        cout << -1 << endl;
        return;
    }
    
    auto tryRemoving = [&](int d) -> bool {
        if (m[d]) {
            m[d]--;
            return true;
        }
        return false;
    };

    auto tryRemoving2 = [&](int d1, int d2) -> bool {
        // assume d1 is smaller
        if (m[d1] + m[d2] >= 2) {
            int rem = 0;
            if (rem < 2) rem += tryRemoving(d1);
            if (rem < 2) rem += tryRemoving(d1);
            if (rem < 2) rem += tryRemoving(d2);
            if (rem < 2) rem += tryRemoving(d2);
            return true;
        }
        return false;
    };
    
    if (total == 1) {
        if (!tryRemoving(1)) {
            if (!tryRemoving(4)) {
                if (!tryRemoving(7)) {
                    if (!tryRemoving2(2, 5)) {
                        if (!tryRemoving2(2, 8)) {
                            if (!tryRemoving2(5, 8)) {
                                cout << -1 << endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
    } else if (total == 2) {
        if (!tryRemoving(2)) {
            if (!tryRemoving(5)) {
                if (!tryRemoving(8)) {
                    if (!tryRemoving2(1, 4)) {
                        if (!tryRemoving2(1, 7)) {
                            if (!tryRemoving2(4, 7)) {
                                cout << -1 << endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

    bool ok = false;
    for (int i = 1; i <= 9; ++i) {
        if (m[i]) ok = true;
    }
    if (!ok && m[0] >= 1) {
        cout << 0 << endl;
        return;
    }

    for (auto i = m.end(); i != m.begin();) {
        auto [d, v] = *(--i);
        for (int j = 0; j < v; ++j) {
            cout << d;
        }
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
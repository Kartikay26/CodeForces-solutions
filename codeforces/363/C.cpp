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
    string s;
    cin >> s;
    vector<char> str;
    vector<int> len;
    for (int i = 0; i < s.size(); ++i) {
        if (str.empty() or str.back() != s[i]) {
            str.push_back(s[i]);
            len.push_back(1);
        } else {
            len.back()++;
        }
    }
    debug(str);
    debug(len);
    bool flip = false;
    for (int i = 0; i < str.size(); ++i) {
        if (len[i] > 2) {
            len[i] = 2;
        }
        if (flip) {
            len[i] = 1;
            flip = false;
        }
        if (len[i] == 2) {
            flip = true;
        }
    }
    for (int i = 0; i < str.size(); ++i) {
        for (int k = 0; k < len[i]; ++k) {
            cout << str[i];
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
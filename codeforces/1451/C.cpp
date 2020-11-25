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

bool test(int)
{
    int n, k; cin >> n >> k;
    string AA; cin >> AA;
    string BB; cin >> BB;
    int A[27]; memset(A, 0, sizeof(A));
    int B[27]; memset(B, 0, sizeof(B));
    for (int i = 0; i < n; ++i) {
        A[AA[i]-'a']++;
        B[BB[i]-'a']++;       
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        int a = A[c-'a'], b = B[c-'a'];
        if (a == b) continue;
        if (a >= b and a % k == b % k and c != 'z') {
            A[c-'a'+1] += (a - b);
        } else {
            return false;
        }
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << (test(i) ? "Yes" : "No") << endl;
    }
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}
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

double sq (double a) {
    return a * a;
}
bool in_circle(double x, double y, double r){
    return sq(x) + sq(y) <= sq(r);
}

void test(int)
{
    int d, k; cin >> d >> k;
    double r = d * 1. / k;
    int i;
    for (i = 0; in_circle(i,i,r); ++i){
    }
    --i;
    if (in_circle(i+1,i,r)) {
        cout << "Ashish" << endl;
    } else {
        cout << "Utkarsh" << endl;
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
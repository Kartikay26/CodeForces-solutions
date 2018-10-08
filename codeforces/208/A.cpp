#include <bits/stdc++.h>
// #include "prettyprint.hpp"
using namespace std;

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

#define debug(x) cout << "debug: " << #x " = " << x << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int32_t main(){
	fast_io();

	string s;
	cin >> s;

	string r1;
	regex_replace(back_inserter(r1), s.begin(), s.end(), regex("^(WUB)+|(WUB)+$"), "");
	string r2;
	regex_replace(back_inserter(r2), r1.begin(), r1.end(), regex("(WUB)+"), " ");

	cout << r2 << endl;
}
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

	string s, s2, s3, s4;

	cin >> s;

	regex_replace(back_inserter(s2), all(s), regex("(WUB)$"), "");
	regex_replace(back_inserter(s3), all(s2), regex("^(WUB)"), "");
	regex_replace(back_inserter(s4), all(s3), regex("(WUB)+"), " ");

	cout << s4 << endl;

}
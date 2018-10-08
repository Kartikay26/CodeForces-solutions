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

	string s, r = "";
	cin >> s;

	bool beginignoreWUBS = true, replaceWUBS = false, replacingflag = false;

	for (int i = 0; i < s.size(); ) {
		
		if (beginignoreWUBS && s.substr(i,3) == "WUB") {
			i += 3;
		} else {
			beginignoreWUBS = false;
			replaceWUBS = true;
		}

		if (replaceWUBS) {
			if(s.substr(i,3) == "WUB"){
				while(s.substr(i,3) == "WUB"){
					i += 3;
				}
				if(i == s.size())
					break;
				r += " ";
			}
			else{
				r += s[i];
				i++;
			}
		}

	}

	cout << r << endl;
}
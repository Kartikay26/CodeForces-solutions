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

	string s1, s2;
	cin >> s1 >> s2;
	int i = 0, j = 0;
	while(i < s1.size() and s1[i]=='0'){
		if(s1[i] == '0'){
			i++;
		}
	}
	while(j < s2.size() and s2[j]=='0'){
		if(s2[j] == '0'){
			j++;
		}
	}
	if (s1.length() - i > s2.length() - j) {
		cout << ">" << endl; exit(0);
	}
	if (s1.length() - i < s2.length() - j) {
		cout << "<" << endl; exit(0);
	}
	while(i < s1.size() and j < s2.size()){
		if(s1[i] == s2[j]){
			i++; j++; continue;
		}
		if (s1[i] > s2[j]) {
			cout << ">" << endl;
			exit(0);
		}
		if (s1[i] < s2[j]) {
			cout << "<" << endl;
			exit(0);
		}
	}
	cout << "=" << endl;
}
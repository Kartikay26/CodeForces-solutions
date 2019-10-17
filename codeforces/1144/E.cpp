// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
void print(){cout << endl;} void prints(){}
template<typename T=int> T get(){T x; cin >> x; return x;}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clear(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const int N = 1e6+1;

string add (string& s1, string& s2){
	string s3;

	int c = 0, n = s1.size();
	
	for (int i = n-1; i >= 0; --i) {
		int x = s1[i]-'a';
		int y = s2[i]-'a';
		int z = x+y+c;
		c = 0;
		if (z >= 26){
			c = z / 26;
			z %= 26;
		}
		s3 += (z + 'a');
	}
	
	if(c){
		s3 += (c + 'a');
	}
	
	reverse(all(s3));
	
	return s3;
}

string half(string& s1){
	
	string s2;
	
	int n = s1.size();
	int c = 0;
	
	for (int i = 0; i < n; ++i) {
		int x = s1[i] - 'a' + c;
		if(x % 2 == 0){
			c = 0;
		} else {
			c = 26;
		}
		s2 += (x/2) + 'a';
	}
	
	return s2;
}

int32_t main(){
	fast_io();

	int n = get();
	string s1, s2;
	cin >> s1 >> s2;
	
	string s3 = add(s1, s2);
	string s4 = half(s3);

	debug(s1);
	debug(s2);
	debug(s3);
	debug(s4);

	if(s4.size() == n){
		print(s4);
	} else {
		print(s4.substr(1));
	}

	return 0;
}
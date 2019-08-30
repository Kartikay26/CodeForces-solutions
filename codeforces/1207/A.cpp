#include <bits/stdc++.h>
using namespace std;

int query(){
	int b, p, f;
	int h, c;
	cin >> b >> p >> f >> h >> c;
	b /= 2;
	if (h > c){
		swap(p, f);
		swap(h, c);
	}
	// at this point h <= c
	// always make more profit selling chicken
	int ans = 0;
	int q = min(b, f);
	ans += q * c;
	b -= q;
	q = min(b, p);
	ans += q * h;
	return ans;
}

int main(){
	int t = 0;
	cin >> t;
	for(int i = 0; i < t; i++){
		cout << query() << endl;
	}
}

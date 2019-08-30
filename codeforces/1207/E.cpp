#include <bits/stdc++.h>
using namespace std;

int main(){
	cout << "? ";
	for (int i = 1; i <= 100; i++){
		int q = i;
		cout << q << " ";
	}
	cout << endl;
	int a1; cin >> a1;
	cout << "? ";
	for (int i = 1; i <= 100; i++){
		int q = i << 7;
		cout << q << " ";
	}
	cout << endl;
	int a2; cin >> a2;
	cout << "! ";
	int ans = (a1 & 0b11111110000000) | (a2 & 0b00000001111111);
	cout << ans << endl;
	return 0;
}

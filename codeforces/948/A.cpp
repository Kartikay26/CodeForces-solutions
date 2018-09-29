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

	int r, c;
	cin >> r >> c;
	char a[r][c];
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == '.')
			{
				a[i][j] = 'D';
			}
		}
	}

	bool flag = true;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if( (i+1 >= 0 and i+1 < r and a[i][j] == 'S' and a[i+1][j] == 'W') or
				(i-1 >= 0 and i-1 < r and a[i][j] == 'S' and a[i-1][j] == 'W') or
				(j+1 >= 0 and j+1 < c and a[i][j] == 'S' and a[i][j+1] == 'W') or
				(j-1 >= 0 and j-1 < c and a[i][j] == 'S' and a[i][j-1] == 'W'))
			{
				flag = false;
				break;
			}
		}
	}

	if (flag)
	{
		cout << "YES\n";
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cout << a[i][j];
			}
			cout << endl;
		}
	}
	else
	{
		cout << "NO\n";
	}

}
// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

template<typename T>
struct mset : map<T, int> // CUSTOM MULTISET
{
	int distinct_count = 0;
	int total_count = 0;
	void put(T a)
	{
		(*this)[a]++;
		distinct_count = this->size();
		total_count++;
	}
	int get(T a)
	{
		total_count--;
		if (!this->count(a))
			return 0;
		return (*this)[a];
	}
	void del(T a)
	{
		assert((*this)[a]);
		(*this)[a]--;
		if (!(*this)[a]) {
			this->erase(a);
		}
		total_count--;
		distinct_count = this->size();
	}
};

void test()
{
	int n, k; cin >> n >> k;
	vector<int> a(n);
	mset<int> ms;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ms.put(a[i]);
	}
	if (ms.distinct_count < k) {
		cout << "-1 -1\n";
		return;
	}
	int l = 0;
	int r = n-1;
	while (ms.distinct_count > k) {
		ms.del(a[r]);
		r--;
	}
	while (true) {
		if (ms.get(a[l]) > 1) {
			ms.del(a[l]);
			l++;
		} else if (ms.get(a[r]) > 1) {
			ms.del(a[r]);
			r--;
		} else {
			break;
		}
	}
	cout << l+1 << ' ' << r+1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
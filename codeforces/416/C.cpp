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

struct Group {
	int size;
	int money;
	int index;
	bool operator<(Group other) {
		return money > other.money || (money == other.money && size < other.size);
	}
	friend ostream& operator<<(ostream& out, Group g) {
		return out << "Group(" << g.size << ", " << g.money << ")";
	}
};

void test()
{
	int n; cin >> n; // no of grps
	vector<Group> groups(n);
	for (int i = 0; i < n; ++i) {
		cin >> groups[i].size >> groups[i].money;
		groups[i].index = i+1;
	}
	sort(groups.begin(), groups.end());

	int k; cin >> k; // no of tables
	set<pair<int, int>> tables; // table size, index
	for (int i = 0; i < k; ++i) {
		int size; cin >> size;
		tables.insert({size, i+1});
	}

	int money = 0;
	vector<pair<int, int>> ans; // accepted Group <-> assigned tables
	for (int i = 0; i < n; ++i) {
		Group g = groups[i];
		auto it = tables.lower_bound({g.size, 0});
		if (it == tables.end()) {
			continue;
		}
		debug(g, tables);
		money += g.money;
		auto [size, index] = *it;
		ans.push_back({g.index, index});
		tables.erase(it);
	}

	cout << ans.size() << " " << money << endl;

	for (auto& [x, y] : ans) {
		cout << x << " " << y << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
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

void test()
{
	int n; cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	map<char, vector<char>> graph; // k: v -> k should come before v
	map<char, int> indegree;
	for (int i = 0; i < n-1; ++i) {
		string a = v[i];
		string b = v[i+1];
		int index = 0;
		while (a[index] == b[index] and index < min(a.size(), b.size())) {
			index++;
		}
		if (index < min(a.size(), b.size())) {
			char c1 = a[index];
			char c2 = b[index];
			// c1 should come before c2 in the graph
			graph[c1].push_back(c2);
			indegree[c1]; // to make it 0 if it isn't there
			indegree[c2]++;
		} else {
			if (a.size() > b.size()) { // a should be prefix of b, not the other way round
				cout << "Impossible" << endl;
				return;
			}
		}
	}

	// Kahn's algorithm for topological sort
	vector<char> ans;
	while (true) {
		// find vertex with indegree 0
		char v = -1;
		for (auto& [c, d] : indegree) {
			if (d == 0) {
				v = c;
				break;
			}
		}
		if (v == -1) {
			// cannot proceed further, break
			break;
		}
		for (auto& w : graph[v]) {
			indegree[w]--;
		}
		indegree[v]--; // makes it -1, so its not found again
		ans.push_back(v);
	}
	for (auto& [c, d] : indegree) {
		if (d > 0) { // some node remaining => cycle exists
			cout << "Impossible" << endl;
			return;
		}
	}

	// fill in the rest of the alphabets
	for (char c = 'a'; c <= 'z'; ++c) {
		if (!count(ans.begin(), ans.end(), c)) {
			ans.push_back(c);
		}
	}

	for (auto& c : ans) {
		cout << c;
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}
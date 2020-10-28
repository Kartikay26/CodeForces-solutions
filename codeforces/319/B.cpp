// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(...)
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef vector<int> vi; typedef long long int ll;

const int mod = 1e9+7;
const int N = 1e6+1;

struct Node {
	int x;
	Node (){
		// empty node
		x = 0;
	}
	void update(int v){
		// update query on single node
		x = v;
	}
	Node operator+ (Node &o){
		// unite with other node
		Node n;
		n.x = max(x, o.x);
		return n;
	}
};
 
template<typename Node, typename V>
struct SegTree {
	vector<Node> tree;
	// 1 = root, l & r child = 2i, 2i+1, leaves = [n, 2n+1]
	int n;
	SegTree(vector<V> data){
		int k = data.size(); assert(k > 0);
		for (n = 1; n < k; n <<= 1);
		tree.resize(2 * n + 1);
		for (int i = 0; i < k; ++i) {
			update(i, data[i]);
		}
	}
	Node query(int l, int r){
		l += n; r += n;
		Node n;
		while (l <= r){
			if (l%2 == 1) {n = n + tree[l++];}
			if (r%2 == 0) {n = n + tree[r--];}
			l /= 2; r /= 2;
		}
		return n;
	}
	void update(int p, V v){
		p += n;
		tree[p].update(v);
		for (p = p/2; p >= 1; p /= 2) {
			tree[p] = tree[2*p] + tree[2*p+1];
		}
	}
};

int solve(vi& a) {
	int n = a.size();
	// int dp[n];
	vi dp(n);
	vi gt(n);
	SegTree<Node, int> DP(dp);
	stack<pair<int, int>> s;
	dp[0] = 0;
	gt[0] = 0;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		while(!s.empty() and s.top().first < x){
			s.pop();
		}
		if(!s.empty()){
			gt[i] = s.top().second;
			int d = DP.query(gt[i]+1, i).x + 1;
			DP.update(i, d);
			dp[i] = d;
		} else {

		}
		s.push({x, i});
		// for (int j = i-1; j >= 0; --j) {
		// 	if (a[j] < a[i]){
		// 		m = max(m, dp[j]);
		// 	} else {
		// 		dp[i] = m+1;
		// 		break;
		// 	}
		// }
	}
	debug(arr(a,n));
	debug(arr(dp,n));
	debug(arr(gt,n));
	return *max_element(dp.begin(), dp.end());
}

void solve(){
	int n; cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << solve(a) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print(){cout << endl;} void prints(){} int get() {int x; cin >> x; return x;}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x; prints(r...);}

const int mod = 1e9+7;
const int N = 1e6+1;

struct TreeNode {
	string s = "ROOT";
	vector<TreeNode*> next;
};

TreeNode root;
vector<pair<string, int>> v;
map<int, vector<string>> ans;
int maxd = 0;

void parse(int& start, TreeNode* root) {
	TreeNode* node = new TreeNode;
	node->s = v[start].first;
	int n_ch = v[start].second;
	start++;
	for (int i = 0; i < n_ch; ++i) {
		parse(start, node);
	}
	root->next.push_back(node);
}

void dfs(TreeNode* root, int d = 0){
	ans[d].push_back(root->s);
	for(auto n : root->next){
		dfs(n, d+1);
	}
	maxd = max(d, maxd);
}

void testcase(){
	string s; string text;
	int i = 0;
	while(getline(cin, s, ',')){
		if (i%2) {
			int p = stoll(s);
			v.push_back({text, p});
		} else {
			text = s;
		}
		i++;
	}
	int n = v.size();
	int x = 0;
	while (x < n)
		parse(x, &root);
	dfs(&root);
	print(maxd);
	for (int i = 1; i <= maxd; ++i) {
		for(auto &s : ans[i]){
			prints(s, " ");
		}
		print();
	}
}

int32_t main(){
	fast_io();
	testcase();
	return 0;
}
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

vector<vector<int>> ad_list;
vector<vector<int>> adj_rev;

vector<bool> winning;
vector<bool> losing;
vector<bool> visited;
vector<int> outdegree;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj_rev[v]) {
        if (!visited[u]) {
            if (losing[v])
            	winning[u] = true;
            else if (--outdegree[u] == 0)
                losing[u] = true;
            else
                continue;
            dfs(u);
        }
    }
}

int32_t main(){
	fast_io();

	int n; cin >> n; vi nums(n);
	ad_list.resize(n);
	adj_rev.resize(n);
	winning.resize(n);
	losing.resize(n);
	visited.resize(n);
	outdegree.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	for (int i = 0; i < n; ++i) {
		// add links from i to i +/- nums[i] into ad_list
		int num = nums[i];
		for (int p = 1; p <= n/num; ++p) {
			if(i + p*num < n){
				if(nums[i + p*num] > num){
					ad_list[i].push_back(i+p*num);
					adj_rev[i+p*num].push_back(i);
					outdegree[i]++;
				}
			}
			if(0 <= i - p*num){
				if(nums[i - p*num] > num){
					ad_list[i].push_back(i-p*num);
					adj_rev[i-p*num].push_back(i);
					outdegree[i]++;
				}
			}
		}
		if (outdegree[i] == 0) {
			losing[i] = true;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (losing[i])
			dfs(i);
	}

	for(auto i : winning){
		cout << (i?'A':'B');
	}

	cout << endl;

}


// NOTE: some code taken from  https://cp-algorithms.com/game_theory/games_on_graphs.html
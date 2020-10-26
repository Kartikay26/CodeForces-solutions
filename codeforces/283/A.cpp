	// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(...)
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef long long int ll;
#define int ll
typedef vector<int> vi; 

// i give up :(

const int mod = 1e9+7;
const int N = 1e6+1;

struct BIT {
	// 1-indexed BIT. range 1 to n inclusive.
	vector<int> arr;
	BIT(int n) {
		arr.resize(n+1);
	}
	void add(int x, int delta) {
		assert(x > 0 && x < arr.size());
		for (int u = x; u < arr.size(); u += u&-u)
			arr[u] += delta;
	}
	void inc(int x) { add(x, 1); }
	int query(int r) {
		assert(r > 0 && r < arr.size());
		int a = 0;
		for (int q = r; q > 0; q -= q&-q)
			a += arr[q];
		return a;
	}
	int query(int l, int r) {
		assert(r >= l && l > 0 && r < arr.size());
		if (l == 1) return query(r);
		return query(r) - query(l-1);
	}
	// void print() {
	// 	prints("--- bdelta: ");
	// 	for (int i = 1; i < 10; ++i) {
	// 		prints(query(i,i), " ");
	// 	}
	// 	cout << endl;
	// 	prints("--- b:      ");
	// 	for (int i = 1; i < 10; ++i) {
	// 		prints(query(i), " ");
	// 	}
	// 	cout << endl;
	// }
};

BIT bdelta(N); // results for query type 1
// use like this
// update(first a elements, +x) : add +x at 0 and -x at a+1
// query(element at i): sum of all elements upto i
//  1 2 3 4 5
// [0,0,0,0,0]
// update(3, +4):
//   1 2 3  4 5
// [+4,0,0,-4,0]

int elems[N]; // stores directly added elements

int last_idx = 2;
int num_elem = 1;
int total_sum = 0;

double solve(){
	int t; cin >> t;

	if (t == 1) {
		// range sum update - add `x` to first `a` elements
		int a, x; cin >> a >> x;
		bdelta.add(1  , +x);
		bdelta.add(a+1, -x);
		total_sum += a * x;
	} else if (t == 2) {
		// append `k` to list
		int k; cin >> k;
		elems[last_idx] = k;
		last_idx++;
		total_sum += k;
		num_elem++;
	} else { // t == 3
		// if -x appears at last element in `bdelta` we need to move it one back
		if (last_idx>1){
			int last = bdelta.query(last_idx, last_idx);
			// debug(last);
			bdelta.add(last_idx,  -last);
			bdelta.add(last_idx-1, last);
			total_sum += last;
		}
		// remove last element -- the difficult part!
		last_idx--;
		total_sum -= elems[last_idx];
		// also remove the sum in bdelta
		total_sum -= bdelta.query(last_idx);
		num_elem--;
	}
	// debug(last_idx, num_elem, total_sum);
	// debug(arr(elems+1, num_elem));
	// bdelta.print();
	return total_sum * 1. / num_elem;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	cout << fixed << setprecision(10);
	for (int i = 1; i <= t; ++i) {
		cout << solve() << endl;
	}
	return 0;
}
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

int floorLog2(int n){
    return (64 - __builtin_clzll(n) - 1);
}
int highestOneBit(int n) {
    return n ? 1ll << floorLog2(n) : 0;
}
int lowestOneBit(int n) {
    return n&-n;
}
template<int d>
string binary(int x) {
    return bitset<d>(x).to_string();
}


class Trie {
    const static int SZ = 2; //
    const static int B = '0'; //
  
public:
    struct Node {
        Node* nxt[SZ];
        int cnt_pass;
        int cnt_last;

        Node(int _cnt_pass = 0, int _cnt_last = 0) {
            cnt_pass = _cnt_pass;
            cnt_last = _cnt_last;
            for (int i = 0; i < SZ; ++i) {
                nxt[i] = nullptr;
            }
        }
    };

    Node* root = new Node();

    void insert(string& s) {
        Node* node = root;
        for (int i = 0; i < (int) s.size(); ++i) {
            auto& curr = *node;
            int e = s[i] - B;
            if (curr.nxt[e] == nullptr) {
                curr.nxt[e] = new Node();
            }
            node = curr.nxt[e];
            ++(*node).cnt_pass;
        }
        ++(*node).cnt_last;
    }

    void erase(string& s) {
        Node* node = root;
        for (int i = 0; i < (int) s.size(); ++i) {
            auto& curr = *node;
            int e = s[i] - B;
            assert(curr.nxt[e] != nullptr);
            if (((curr.nxt[e]) -> cnt_pass) == 1) {
                curr.nxt[e] = nullptr;
                return;
            }
            node = curr.nxt[e];
            --(*node).cnt_pass;
        }
        --(*node).cnt_last;
    }

    int get(string& s, Node* n = 0) {
    	if (!n) n = root;
    	string ans = "";
    	string follow = "";
    	for(auto c : s){
    		int b = (c-'0'); // want to go if possible
    		if (n->nxt[b]) {
    			n = n->nxt[b];
    			ans += '0';
    			follow += b+'0';
    		} else {
    			n = n->nxt[!b];
    			ans += '1';
    			follow += !b+'0';
    		}
    	}
    	erase(follow);
    	return bitset<32>(ans).to_ullong();
    }
};

void testcase(){
	int n = get();
	vector<int> a(n); get(a,n);
	vector<int> b(n); get(b,n);
	Trie t;
	for(auto x : b){
		string s = binary<32>(x);
		t.insert(s);
	}
	vi ans;
	for(auto x : a){
		string s = binary<32>(x);
		ans.push_back(t.get(s));
	}
	// sort(all(ans));
	for(auto &i : ans){
		prints(i, " ");
	}
	print();
}

int32_t main(){
	fast_io();
	testcase();
	return 0;
}
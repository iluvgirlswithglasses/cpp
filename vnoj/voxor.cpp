
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec  2 16:03:42 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int BITS = 32;

/**
 * utils
 * */
bool* bitset;

void dec2bin(int n) {
	memset(bitset, 0, BITS);
	for (int i = 0; i < BITS; i++) {
		bitset[BITS-1-i] = (n>>i)&1;
	}
}

/**
 * @ trie
 **/
// years of practicing pointers... not wasted
// (actually I've been using C++ for just a year)
struct node {
	node* child[2];
	int cnt;	// số string (bitset) kết thúc với node này

	node() {
		child[0] = NULL;
		child[1] = NULL;
		cnt = 0;
	}
};

node* root;

// thêm 1 số vào cây trie
void insert(bool* bitset) {
	node* p = root;
	// child đầu tiên của root là thông tin của bit thứ 0 từ trái sang
	for (int i = 0; i < BITS; i++) {
		bool nxt = bitset[i];
		if (p->child[nxt] == NULL) 
			p->child[nxt] = new node();
		p = p->child[nxt];
	}
	++p->cnt;
}

// xor toàn bộ số trong a
// --> swapping children ~~
void update(node* p, int bit, bool* bitset) {
	// node ở tầng bit-1 sẽ swap 2 node ở tầng bit với nhau
	// nếu bitset yêu cầu điều đó
	if (bitset[bit]) 
		swap(p->child[0], p->child[1]);
	//
	for (int v = 0; v < 2; v++) {
		if (p->child[v] != NULL) {
			update(p->child[v], bit+1, bitset);
		}
	}
}

// lấy ra số lớn thứ `k` trong cây trie
int get_kth(int n, int k) {
	// cr: store the current rank
	int res = 0, cr = 0;
	//
	
	//
	return res;
}

/** 
 * @ vars 
 **/
int n, q;

/**
 * @ debug
 * */
#include <vector>

void dfs(node* p, vector<int>& pre) {
	if (p->cnt > 0) {
		cout << "x" << p->cnt << ": ";
		for (int i: pre) cout << i;
		cout << "\n";
	}
	//
	for (int v = 0; v < 2; v++) {
		if (p->child[v] != NULL) {
			pre.push_back(v);
			dfs(p->child[v], pre);
			pre.pop_back();
		}
	}
}

/** 
 * @ drivers 
 **/
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	bitset = new bool[BITS];
	root = new node();
	//
	cin >> n >> q; 
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		dec2bin(a);
		insert(bitset);
	}
	//
	while (q--) {
		string typ;
		int x;
		cin >> typ >> x;
		//
		if (typ == "FIND") {
			cout << get_kth(n, x) << "\n";
		} else {
			dec2bin(x);
			update(root, 0, bitset);
		}
	}
	// debug
	vector<int> pre;
	dfs(root, pre);
	return 0;
}

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
#include <string>
using namespace std;

const int BITS = 32;

/**
 * utils
 * */
bool* bitset;

void dec2bin(int n) {
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
	int cnt;	// số string (bitset) kết thúc với node này
	node* child[2];
	int childcnt[2];	// child[i]: số string từ node con i trở xuống

	node() {
		cnt = 0;
		child[0] = NULL;
		child[1] = NULL;
		childcnt[0] = 0; 
		childcnt[1] = 0;
	}
};

node* root;

// thêm 1 số vào cây trie
// O(32)
void insert(bool* bitset) {
	node* p = root;
	// child đầu tiên của root là thông tin của bit thứ 0 từ trái sang
	for (int i = 0; i < BITS; i++) {
		bool nxt = bitset[i];
		if (p->child[nxt] == NULL) 
			p->child[nxt] = new node();
		// ghi nhận xuất hiện của 1 đứa child mới
		++p->childcnt[nxt];
		//
		p = p->child[nxt];
	}
	++p->cnt;
}

// xor toàn bộ số trong a
// --> swapping children ~~
// O(??)
void update(node* p, int bit, bool* bitset) {
	// node ở tầng bit-1 sẽ swap 2 node ở tầng bit với nhau
	// nếu bitset yêu cầu điều đó
	if (bitset[bit])  {
		swap(p->child[0], p->child[1]);
		swap(p->childcnt[0], p->childcnt[1]);
	}
	//
	for (int v = 0; v < 2; v++) {
		if (p->child[v] != NULL) {
			update(p->child[v], bit+1, bitset);
		}
	}
}

// lấy ra số lớn thứ `k` trong cây trie
// O(32)
int get_kth(int n, int k) {
	int res = 0;
	// số lớn thứ k == số nhỏ thứ n - k + 1
	// ở đây lưu ý là có shift xuống 1 đơn vị 
	k = n - k;	
	node* p = root;	
	//
	for (int i = 0; i < BITS; i++) {
		int smaller_cnt = p->childcnt[0];
		if (smaller_cnt <= k) {
			// lớn hơn toàn bộ nhánh trái
			// --> cút ra phải
			k -= smaller_cnt;
			p = p->child[1];
			res |= 1<<(BITS-1-i);
		} else {
			// thuộc về nhánh trái
			p = p->child[0];
		}
	}
	// tới nước này thì k nên = 0
	return res;
}

/** 
 * @ vars 
 **/
int n, q, pending;

/** 
 * @ drivers 
 **/
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
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
			// dec2bin(pending);
			// update(root, 0, bitset);	// upd quá lâu
			pending = 0;
			cout << get_kth(n, x) << "\n";
		} else {
			// đợi được bao nhiêu
			// hay được bấy nhiêu cho anh update() 
			// cái anh mà mình thậm chí k tính đc đpt
			pending ^= x;
		}
	}
	return 0;
}

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

// lấy ra số lớn thứ `k` trong cây trie
// O(32)
int get_kth(int n, int k, bool* xorstate) {
	int res = 0;
	// số lớn thứ k == số nhỏ thứ n - k + 1
	// ở đây lưu ý là có shift xuống 1 đơn vị 
	k = n - k;	
	node* p = root;	
	//
	for (int i = 0; i < BITS; i++) {
		// nếu có swap
		bool s = xorstate[i];
		//
		int smaller_cnt = p->childcnt[s];	// thật ra thì s == index của nhánh nhỏ hơn
		if (smaller_cnt <= k) {
			// lớn hơn toàn bộ nhánh trái
			// --> cút ra phải
			k -= smaller_cnt;
			p = p->child[!s];
			res |= 1<<(BITS-1-i);
		} else {
			// thuộc về nhánh trái
			p = p->child[s];
		}
	}
	// tới nước này thì k nên = 0
	return res;
}

/** 
 * @ vars 
 **/
int n, q, xorstate;

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
			dec2bin(xorstate);
			cout << get_kth(n, x, bitset) << "\n";
		} else {
			xorstate ^= x;
		}
	}
	return 0;
}

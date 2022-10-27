
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 27 11:33:37 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// cách làm tương tự bài voxor
// nhưng dễ hơn nhiều

#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

struct Node {
	int cnt;	// số string (bitset) kết thúc với node này
	Node* child[2];
	int childcnt[2];	// child[i]: số string từ node con i trở xuống

	Node() {
		cnt = 0;
		child[0] = NULL;
		child[1] = NULL;
		childcnt[0] = 0; 
		childcnt[1] = 0;
	}
};

struct Trie {

	int n;
	Node *root;

	void add(int x) {
		n++;
		Node *p = root;
		// child đầu tiên của root là thông tin của bit thứ 0 từ trái sang
		for (int i = 31; i >= 0; i--) {
			bool nxt = x>>i&1;
			if (p->child[nxt] == NULL) 
				p->child[nxt] = new Node();
			// ghi nhận xuất hiện của 1 đứa child mới
			++(p->childcnt[nxt]);
			//
			p = p->child[nxt];
		}
		++(p->cnt);
	}

	void rem(int x) {
		n--;
		Node *p = root;
		for (int i = 31; i >= 0; i--) {
			bool nxt = x>>i&1;
			// if (p->child[nxt] == NULL)
			// 	p->child[nxt] = new Node();
			--(p->childcnt[nxt]);
			p = p->child[nxt];
		}
		--(p->cnt);
	}

	int query(int k) {
		// lấy số lớn thứ `k` (0-indexed)
		int res = 0;
		Node *p = root;
		//
		for (int i = 31; i >= 0; i--) {
			// có bao nhiêu đây số nhỏ hơn
			int smaller_cnt = p->childcnt[0];
			if (smaller_cnt <= k) {
				// lớn hơn toàn bộ nhánh trái
				// --> cút ra phải
				res |= 1<<i;
				k -= smaller_cnt;
				p = p->child[1];
			} else {
				// thuộc về nhánh trái
				p = p->child[0];
			}
		}
		// tới nước này thì k nên bằng 0
		return res;
	}

	void query() {
		if (n&1) {
			cout << query(n>>1) << "\n";
		} else {
			int x = query(n>>1), y = query((n>>1) - 1);
			int z = x + y;
			cout << (z>>1);
			if (z&1) 
				cout << ".5\n";
			else
				cout << "\n";
		}
	}
} tr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	//
	char s[10];
	int x;
	tr.root = new Node();
	while (tt--) {
		cin >> s;
		switch (s[0]) {
			case 'M':
				tr.query();
				break;
			case 'I':
				cin >> x;
				tr.add(x);
				break;
			case 'O':
				cin >> x;
				tr.rem(x);
				break;
		}
	}
	return 0;
}

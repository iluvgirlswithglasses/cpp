
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec  4 08:49:52 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstdio>
using namespace std;

// đảo cho số dương có bit đầu là 1
// số âm có bit đầu là 0
// ... đáng ra từ đầu mọi thứ fải nên vậy
int eviltrick(int x) {
	return x ^ (1<<31);
}

/** @java time */
struct node {
	int cnt;
	node* c[2];
	int ccnt[2];

	node() {
		cnt = 0;
		c[0] = c[1] = NULL;
		ccnt[0] = ccnt[1] = 0;
	}
};

node* root;

int tree_size = 0;

bool exists(int x) {
	node* p = root;
	for (int i = 31; i >= 0; i--) {
		bool bit = x>>i&1;
		if (p->c[bit] == NULL)  {
			return 0;
		}
		p = p->c[bit];
	}
	return p->cnt > 0;
}

void insert(int x) {
	if (exists(x)) return;
	node* p = root;
	for (int i = 31; i >= 0; i--) {
		bool bit = x>>i&1;
		if (p->c[bit] == NULL)
			p->c[bit] = new node();
		p->ccnt[bit]++;
		p = p->c[bit];
	}
	p->cnt++;
	tree_size++;
}

void del(int x) {
	if (!exists(x)) return;
	node* p = root;
	for (int i = 31; i >= 0; i--) {
		bool bit = x>>i&1;
		p->ccnt[bit]--;
		p = p->c[bit];
	}
	p->cnt--;
	tree_size--;
}

int get_kth(int k) {
	int res = 0;
	node* p = root;
	for (int i = 31; i >= 0; i--) {
		int smaller_cnt = p->ccnt[0];
		if (smaller_cnt <= k) {
			// cút qua phải
			k -= smaller_cnt;
			p = p->c[1];
			res |= 1<<i;
		} else {
			// thuộc về nhánh trái
			p = p->c[0];
		}
	}
	return eviltrick(res);
}

int lower_cnt(int x) {
	int res = 0;
	node* p = root;
	for (int i = 31; i >= 0; i--) {
		bool bit = x>>i&1;
		if (bit) {
			res += p->ccnt[0];
		}
		if (p->c[bit] == NULL) return res;
		p = p->c[bit];
	}
	return res;
}

/** @drivers */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	root = new node();
	//
	char typ;
	int q, x; cin >> q;
	while (q--) {
		cin >> typ >> x;
		x = eviltrick(x);
		switch (typ) {
			case 'I':
				insert(x);
				break;
			case 'D':
				del(x);
				break;
			case 'K':
				x = eviltrick(x);
				if (x > tree_size)
					cout << "invalid" << "\n";
				else
					cout << get_kth(x - 1) << "\n";
				break;
			case 'C':
				cout << lower_cnt(x) << "\n";
				break;
			case 'E':
				cout << exists(x) << "\n";
				break;
		}
	}
	return 0;
}

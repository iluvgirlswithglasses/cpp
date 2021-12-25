
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Dec 24 20:09:56 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 1e5+7;
int n, m;

/**
 * @ segtree utils
 * */
//    h: độ cao của cây segtree
// g[i]: số phần tử trong mảng mà segtree quản lý
int  h, f[N<<1], g[N<<1];
bool d[N];

void init() {
	h = 32 - __builtin_clz(n);
	//
	for (int i = 0; i < n; i++)
		g[n+i] = 1;
	for (int i = n-1; i > 0; i--)
		g[i] = g[i<<1] + g[i<<1|1];
}

void assign(int i) {
	/*
	gọi số phần tử trong bitset mà node i quản lý là S
	gọi giá trị hiện tại của node i là T

	nếu có lệnh lật bit trên tất cả các bit của node i,
	node i sẽ có giá trị mới là: S - T
	*/
	f[i] = g[i] - f[i];
	if (i < n) {
		// d[i] == true --> cách node con của i có lệnh lật bit
		d[i] = d[i] ^ 1;
	}
}

void push_down(int i) {
	/*
	đẩy hết pending từ node 1 xuống node i

	dựa vào tính chất của segtree iter, 
	trong i luôn chứa thông tin node cha của chúng
	nên push_down() có thể chạy trong O(logn)
	*/
	for (int x = h-1, idx = i>>x; x > 0; x--, idx = i>>x) {
		if (d[idx]) {
			assign(idx<<1);
			assign(idx<<1|1);
			d[idx] = 0;
		}
	}
}

void push_up(int i) {
	/*
	update các node cha
	*/
	for (i>>=1; i > 0; i>>=1) {
		f[i] = f[i<<1] + f[i<<1|1];
		if (d[i]) 
			f[i] = g[i] - f[i];
	}
}

/**
 * @ segtree
 * */
void upd(int l, int r) {
	l += n; int l0 = l;
	r += n; int r0 = r;
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) assign(l++);
		if (r&1) assign(--r);
	}
	push_up(l0); 
	push_up(r0-1);
}

int get(int l, int r) {
	l += n; push_down(l);
	r += n; push_down(r-1);
	//
	int res = 0;
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) res += f[l++];
		if (r&1) res += f[--r];
	}
	return res;
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	init();
	//
	while (m--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 0) 
			upd(l-1, r);
		else 
			cout << get(l-1, r) << "\n";
	}
	return 0;
}


/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Oct 20 18:01:51 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

// bài này sai vì chỉ đọc được 2 cách đổi
// thay vì N cách đổi như collect-2
// đờ mờ ông ghi đề

#include <bits/stdc++.h>
using namespace std;

#define u16 unsigned short
#define pi pair<u16, u16>
#define st first
#define nd second
const u16 E[] = {1, 5, 25, 125, 625};

u16 k;
// đổi từ bộ f() sang bộ g()
// để đảm bảo bộ f() không thỏa
u16 f, g;
// từ bộ edges[2n] có thể đổi sang bộ edges[2n+1]
u16 edges[4];

/*
definitions:
a:	vàng
b:	bạc
c:	đồng

mỗi một bộ tiền được mã hóa thành một đỉnh trên đồ thị
đỉnh được biểu diễn bằng số đồng tiền mỗi loại trên hệ cơ số 5

ví dụ: bộ "2 4 5" được mã hóa thành đỉnh `2*5^2 + 4*5^1 + 5*5^0`
xem trong hàm encode()
*/

u16 encode(u16 a, u16 b, u16 c) {
	// trọng số `a` giảm dần để dễ dàng xếp theo thứ tự từ điển
	return a*E[2] + b*E[1] + c*E[0];
}

void decode(u16 f, vector<u16> &r) {
	if (f > 0) {
		decode(f/5, r);
		r.push_back(f%5);
	}
}

vector<u16> decode(u16 f) {
	vector<u16> r;
	decode(f, r);
	return r;
}

/**
 * utils
 * */
// kiểm tra xem mọi loại tiền trong bộ `f` đã >= `g` hay chưa
bool llim_check(u16 f, u16 g) {
	// 
	vector<u16> fs = decode(f), gs = decode(g);
	for (int i = 0; i < 3; i++)
		if (fs[i] < gs[i]) return false;
	return true;
}

// kiểm tra xem sau khi `+ g` thì `f` có loại nào quá 4 đồng hay k
bool rlim_check(u16 f, u16 g) {
	vector<u16> fs = decode(f), gs = decode(g);
	for (int i = 0; i < 3; i++)
		if (fs[i] + gs[i] > 4) return false;
	return true;
}
/*
// áp dụng phương pháp đổi thứ `m` lên bộ `f`
// nhớ kiểm tra tính hợp lệ trước
u16 commit_change(u16 f, int m) {
	f -= edges[m<<1];
	f += edges[m<<1|1];
	return f;
}

// kiểm xem `f` có áp dụng được phép đổi `m` hay không
bool trans_check(u16 f, u16 m) {
	if (!llim_check(f, edges[m<<1])) return false;
	f -= edges[m<<1];
	return rlim_check(f, edges[m<<1|1]);
}
*/

/**
 * bfs
 * */
vector<pi> bfs() {
	vector<pi> res;
	// có tất cả 5^3 đỉnh
	vector<bool> visited(E[3]);	
	vector<u16> dist(E[3]);
	deque<u16> q;
	visited[f] = true;
	q.push_back(f);
	//
	while (q.size()) {
		u16 u = q.front(); q.pop_front();
		// không đổi tiếp khi đã đổi được 1 bộ
		if (llim_check(u, g)) {
			res.push_back(make_pair(u, dist[u]));
			continue;
		}
		// đã dùng hết k lượt --> không đổi nữa
		if (dist[u] == k) continue;
		// các cách đổi
		for (int m = 0; m < 2; m++) {
			u16 v = u;
			if (!llim_check(v, edges[m<<1])) continue;
			v -= edges[m<<1];
			if (!rlim_check(v, edges[m<<1|1])) continue;
			v += edges[m<<1|1];
			//
			if (visited[v]) continue;
			visited[v] = true;
			dist[v] = dist[u] + 1;
			q.push_back(v);
		}
	}
	//
	return res;
}

/**
 * drivers
 * */
u16 get_set() {
	u16 a, b, c;
	cin >> a >> b >> c;
	return encode(a, b, c);
}

int main() {
	// inp
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k;
	f = get_set();
	g = get_set();
	for (int i = 0; i < 4; i++)
		edges[i] = get_set();
	//
	vector<pi> res = bfs();
	if (res.size() == 0) {
		cout << -1 << "\n";
	} else {
		cout << res.size() << "\n";
		sort(res.begin(), res.end());
		for (pi &i: res) {
			for (u16 x: decode(i.st)) cout << x << " ";
			cout << i.nd << "\n";
		}
	}
	return 0;
}


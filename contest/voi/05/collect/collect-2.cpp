
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Oct 20 20:43:54 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define pp pair<pack, pack>
#define st first
#define nd second
const int E[] = {1, 5, 25, 125};

/*
definitions:
a:	vàng
b:	bạc
c:	đồng

mỗi một bộ tiền được mã hóa thành một đỉnh trên đồ thị
đỉnh được biểu diễn bằng số đồng tiền mỗi loại trên hệ cơ số 5

ví dụ: bộ "2 4 5" được mã hóa thành đỉnh `2*5^2 + 4*5^1 + 5*5^0`
xem trong hàm pack.encode()
*/

struct pack {
	static const int N = 3;
	vector<int> d;	// {a, b, c, k, }

	// mã hóa `pack` về hệ cơ số 5
	int encode() {
		// trọng số `a` giảm dần để dễ dàng xếp theo thứ tự từ điển
		return d[0]*E[2] + d[1]*E[1] + d[2]*E[0];
	}

	void add(pack &p) {
		for (int i = 0; i < N; i++)
			d[i] += p.d[i];
	}

	void subtract(pack &p) {
		for (int i = 0; i < N; i++)
			d[i] -= p.d[i];
	}

	// so sánh `this` với `p`
	// trả về false nếu có một loại tiền `this` ít hơn so với `p`
	bool compare(pack &p) {
		for (int i = 0; i < N; i++)
			if (d[i] < p.d[i]) return false;
		return true;
	}

	// kiểm tra xem có đổi `p0` lấy `p1` được không
	bool valid_commit(pack &p0, pack &p1) {
		pack tmp = *this;
		tmp.subtract(p0);
		for (int i = 0; i < N; i++)
			if (tmp.d[i] < 0) return false;
		tmp.add(p1);
		for (int i = 0; i < N; i++)
			if (tmp.d[i] > 4) return false;
		return true;
	}

	// đổi `p0` lấy `p1`
	pack commit(pack &p0, pack &p1) {
		pack tmp = *this;
		tmp.subtract(p0);
		tmp.add(p1);
		return tmp;
	}

	/**
	 * getters / setters
	 * */
	int get_k() {
		return d[3];
	}

	void set_k(int k) {
		d[3] = k;
	}

	/**
	 * static
	 * */
	static void decode(int f, vector<int> &r) {
		if (f > 0) {
			decode(f/5, r);
			r.push_back(f%5);
		}
	}

	static pack decode(int f) {
		vector<int> r;
		decode(f, r);
		return mkpack(r[0], r[1], r[2]);
	}

	/**
	 * constructors
	 * */
	static pack mkpack(int a, int b, int c, int k) {
		pack p;
		p.d.resize(4);
		p.d[0] = a, p.d[1] = b, p.d[2] = c, p.d[3] = k;
		return p;
	}

	static pack mkpack(int a, int b, int c) {
		return mkpack(a, b, c, 0);
	}

	static pack stdinget() {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		return mkpack(a, b, c);
	}

	static void stdinget(vector<pp> &v) {
		int a, b, c, x, y, z;
		while (
			scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z) != EOF
		) {
			pack p0 = mkpack(a, b, c);
			pack p1 = mkpack(x, y, z);
			v.push_back(make_pair(p0, p1));
		}
	}
};


/**
 * 
 * */
int k;
// bộ `f`: bộ gốc
// bộ `g`: bộ đẹp
pack f, g;
// từ bộ `edges[i].st` có thể đổi sang bộ `edges[i].nd`
vector<pp> edges;

vector<pi> bfs() {
	vector<pi> res;
	// có tất cả 5^3 đỉnh
	vector<bool> visited(E[3]);	
	deque<pack> q;
	visited[f.encode()] = true;
	q.push_back(f);
	//
	while (q.size()) {
		pack u = q.front(); 
		q.pop_front();
		// không đổi tiếp khi đã đổi được 1 bộ
		if (u.compare(g)) {
			res.push_back(
				make_pair(u.encode(), u.get_k())
			);
			continue;
		}
		// đã dùng hết k lượt --> không đổi nữa
		if (u.get_k() == k) continue;
		// tranverse
		for (pp &p: edges) {
			pack &p0 = p.st;
			pack &p1 = p.nd;
			if (!u.valid_commit(p0, p1)) continue;
			pack v = u.commit(p0, p1);
			//
			if (visited[v.encode()]) continue;
			visited[v.encode()] = true;
			v.set_k(u.get_k() + 1);
			q.push_back(v);
		}
	}
	//
	return res;
}

/**
 * drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d", &k);
	f = pack::stdinget();
	g = pack::stdinget();
	pack::stdinget(edges);
	//
	vector<pi> res = bfs();
	if (res.size() == 0) {
		cout << -1 << "\n";
	} else {
		cout << res.size() << "\n";
		sort(res.begin(), res.end());
		for (pi &i: res) {
			pack p = pack::decode(i.st);
			for (int j = 0; j < pack::N; j++) {
				cout << p.d[j] << " ";
			}
			cout << i.nd << "\n";
		}
	}
	return 0;
}



/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Dec  3 11:43:58 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * @defs
 * */
const int N = 1e4+7, M = 1e5+7, I = 2e9+7;

struct edge {
	int u, v, i;

	static edge mkedge(int u, int v, int i) {
		edge e;
		e.u = u, e.v = v, e.i = i;
		return e;
	}
};

struct DSU {
	vector<int> p;

	DSU(int n) {
		p.reserve(n);
		for (int i = 0; i < n; i++)
			p.push_back(i);
	}

	int find(int u) {
		if (p[u] == u) return u;
		return p[u] = find(p[u]);
	}

	bool join(int u, int v) {
		int a = find(u), b = find(v);
		if (a == b) return false;
		//
		p[a] = b;
		return true;
	}
};


/**
 * @perf
 * */
// trả về số cạnh tối đa mà tập cạnh `v`
// có thể được dùng trong đồ thị
int get_max(int n, vector<edge>& v) {
	int chose = 0;
	DSU dsu(n);
	//
	for (edge& e: v) {
		if (dsu.join(e.u, e.v)) chose++;
	}
	//
	return chose;
}

// có những cạnh mà công ty B không thể lắp được
// công ty A bắc buộc phải cover những cạnh đó
DSU get_min_graph(int n, vector<edge>& e_a, vector<edge>& e_b, vector<int>& chosen_edge) {
	DSU res(n);
	DSU dsu(n);
	//
	for (edge& e: e_b) dsu.join(e.u, e.v);
	for (edge& e: e_a) {
		if (dsu.join(e.u, e.v)) {
			// bắt buộc phải có cạnh này của công ty A trong đồ thị
			// vì nếu không, đồ thì sẽ không liên thông
			res.join(e.u, e.v);
			chosen_edge.push_back(e.i);
		}
	}
	//
	return res;
}

// nhét sao cho đủ `k` cạnh A vào đồ thị
// lúc gọi hàm này thì chosen_edge chỉ chứa các cạnh của công ty A thôi
// nên là thoải mái :)
void increase_to_k(DSU& dsu, int k, vector<edge>& v, vector<int>& chosen_edge) {
	for (edge& e: v) {
		if (chosen_edge.size() == k) return;
		if (dsu.join(e.u, e.v)) {
			chosen_edge.push_back(e.i);
		}
	}
}

// với những gì đã xảy ra ở get_min_graph()
// thì chắc chắn sẽ luôn có cách insert thêm n-1-k cạnh B
void insert_b(DSU& dsu, vector<edge>& v, vector<int>& chosen_edge) {
	for (edge& e: v) {
		if (dsu.join(e.u, e.v)) {
			chosen_edge.push_back(e.i);
		}
	}
}


/**
 * @drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, n, m;
	cin >> t;
	while (t--) {
		/** all of this is about input */
		cin >> n >> m;
		vector<int> cost_a(n-1), cost_b(n-1);
		vector<edge> edge_a, edge_b;
		//
		for (int i = 0; i < n-1; i++)
			cin >> cost_a[i];
		for (int i = 0; i < n-1; i++)
			cin >> cost_b[i];
		//
		for (int i = 1; i <= m; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			if (c == 1) {
				edge_a.push_back(edge::mkedge(--u, --v, i));
			} else {
				edge_b.push_back(edge::mkedge(--u, --v, i));
			}
		}

		/** preparation */
		// chọn trong khoảng [min_a:max_a] cạnh trong `edge_a`
		// gọi k là số: nếu chọn k cạnh trong edge_a thì ra được kết quả tối ưu
		int max_a = get_max(n, edge_a),
		    min_a = n - 1 - get_max(n, edge_b);

		// vì với cùng 1 số lượng, mua kiểu gì thì giá cũng không đổi
		// nên sẽ lựa cách rẻ nhất mà mua
		int k, cost = I;
		for (int i = min_a, j = n-1-i; i <= max_a; i++, j--) {
			int cr_cost = cost_a[i-1] + cost_b[j-1];
			if (cr_cost < cost) {
				cost = cr_cost;
				k = i;
			}
		}

		/** hmmm... showdown ? */
		vector<int> chosen_edge;
		chosen_edge.reserve(n-1);
		DSU graph = get_min_graph(n, edge_a, edge_b, chosen_edge);
		increase_to_k(graph, k, edge_a, chosen_edge);
		insert_b(graph, edge_b, chosen_edge);
		
		/** nothing to write here :)) */
		for (int i: chosen_edge) cout << i << " ";
		cout << "\n";
	}
	return 0;
}


#pragma GCC optimize ("O3")

#include <algorithm>
#include <iostream>
using namespace std;

//@ objs
struct Event {
	static const int TYP_OPEN = 0;
	static const int TYP_VERT = 1;
	static const int TYP_CLOSE = 2;

	int x, y1, y2, typ;

	void set(int _x, int _y1, int _y2, int _typ) {
		x = _x; y1 = _y1; y2 = _y2; typ = _typ;
	}
};


//@ var
const int nlim = 1e5+7;
const int plim = 1e5+7;
int n, t[plim << 1];
Event arr[nlim];


//@ segment tree
// lấy số line trong segment tree giao với khoảng [l, r]
int get(int l, int r) {
	int res = 0;
	//
	r++;	// chuyển [l, r] về [l, r)
	for (l += plim, r += plim; l < r; l >>= 1, r >>= 1) {
		if (l&1) res += t[l++];
		if (r&1) res += t[--r];
	}
	return res;
}

// thêm val line vào segment tree
void upd(int y, int val) {
	for (y += plim; y > 0; y >>= 1) {
		t[y] += val;
	}
}

// thêm một line vào segment tree
void add(int y) {
	upd(y, 1);
}

// xóa một line khỏi segment tree
void rmv(int y) {
	upd(y, -1);
}


//@ perf
bool is_hr(int y1, int y2) {
	return y1 == y2;
}

int calc() {
	int res = 0;
	//
	for (int i = 0; i < n; i++) {
		Event event = arr[i];
		switch (event.typ) {
			case Event::TYP_OPEN:
				add(event.y1);
				break;
			case Event::TYP_CLOSE:
				rmv(event.y1);
				break;
			case Event::TYP_VERT:
				res += get(event.y1, event.y2);
				break;
			default:
				// nah this case will never happen
				return -1;
		}
	}
	//
	return res;
}


//@ drivers
void getinp() {
	cin >> n;
	//
	int event_index = 0;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		// xử lý horizontal line
		if (is_hr(y1, y2)) {
			arr[event_index++].set(x1, y1, y2, Event::TYP_OPEN);
			arr[event_index++].set(x2, y1, y2, Event::TYP_CLOSE);
		} 
		else {
			arr[event_index++].set(x1, y1, y2, Event::TYP_VERT);
		}
	}
	n = event_index;
	sort(arr, arr+n, [](Event &i, Event &j){
		if (i.x == j.x) return i.typ < j.typ;
		return i.x < j.x;
	});
}

int main() {
	getinp();
	cout << calc() << endl;
	return 0;
}


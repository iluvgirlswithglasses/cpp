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


//@ vars
// nlim gốc của bài toán là 1e5
// nhưng chúng ta đổi từ line -> event,
// nên nlim được nhân đôi
const int nlim = 2e5;
// -1e5 < plim < 1e5
// --> plim có 2e5 giá trị
// đồng thời, ta shift mọi giá trị y lên 1e5 để nó không âm
const int plim = 2e5;
// tạm thời dùng segment tree để trả lời...
// ...trong khoảng [y1, y2] thì có bao nhiêu line được kích hoạt trước
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
		// shift y lên để nó không âm
		y1 += (int) 1e5; 
		y2 += (int) 1e5;
		// xử lý horizontal line
		if (is_hr(y1, y2)) {
			// open:  activate một line khi sweep tới điểm mút bên trái của line
			// close: deactivate một line khi sweep tới điểm mút bên phải của line
			arr[event_index++].set(x1, y1, y2, Event::TYP_OPEN);
			arr[event_index++].set(x2, y1, y2, Event::TYP_CLOSE);
		} 
		// xử lý verticle line
		else {
			arr[event_index++].set(x1, y1, y2, Event::TYP_VERT);
		}
	}
	// chuyển n từ số line sang số event
	n = event_index;
	// sort events từ trái sang phải
	sort(arr, arr+n, [](Event &i, Event &j){
		// nếu như cùng 1 giá trị x
		// --> typ có ưu tiên lớn hơn (giá trị bé hơn) sẽ được xếp trước
		// tức là:
		// nếu xét nhiều event trong cùng một tọa độ trục hoành, thì xét theo thứ tự sau
		// open event
		// verticle line event
		// close event
		if (i.x == j.x) return i.typ < j.typ;
		return i.x < j.x;
	});
}

int main() {
	getinp();
	// in ra mành hình số điểm giao nhau
	cout << calc() << endl;
	// returns
	system("pause");
	return 0;
}


#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

//@ objs
struct Event {
	//
	static const bool typ_open = 0;
	static const bool typ_close = 1;
	//
	bool typ;
	int x, y1, y2;
	//
	void set(bool _typ, int _x, int _y1, int _y2) {
		typ = _typ; x = _x; y1 = _y1; y2 = _y2;
	}
};


//@ vars
const int nlim = 1e4 + 1;
int n;
Event events[nlim << 1];
pair<int, int> it[nlim << 2];


//@ perf
void segmenttree_update() {

}

int sweep() {
	int res = 0;
	bool typ;
	int y1, y2, width, height;
	//
	for (int i = 0; i < (n << 1) - 1; i++) {
		//
		width = events[i+1].x - events[i].x;
		height = -1;
		res += width * height;
	}
	//
	return res;
}


//@ drivers
void getinp() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		// each rectangle brings two verticle lines that act as two events: open and close
		events[i<<1].set(Event::typ_open, x1, y1, y2);
		events[i<<1|1].set(Event::typ_close, x2, y1, y2);
	}
	// sort lines so that we can sweep from left to right
	sort(events, events + (n<<1), [](Event i, Event j){
		return i.x < j.x;
	});
}

int main() {
	//
	getinp();
	cout << sweep() << endl;
	// returns
	system("pause");
	return 0;
}


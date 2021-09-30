// this file is written
// just to store the colors of our beloved software - sublime text !
// I'll purchase you someday !

#include <algorithm>
#include <iostream>
using namespace std;

struct Event {
	static const int TYP_OPEN = 0;
	static const int TYP_VERT = 1;
	static const int TYP_CLOSE = 2;

	int x, y1, y2, typ;

	void set(int _x, int _y1, int _y2, int _typ) {
		x = _x; y1 = _y1; y2 = _y2; typ = _typ;
	}
};

const int N = 2e5+7, P = 2e5+7;
int n, t[P << 1];

void upd(int y, int val) {
	for (y += plim; y > 0; y >>= 1) {
		t[y] += val;
	}
}

void add(int y) {
	upd(y, 1);
}

int main() {
	getinp();
	//
	cout << calc() << endl;
	//
	system("pause");
	return 0;
}


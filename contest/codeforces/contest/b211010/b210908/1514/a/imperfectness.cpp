
// some facts:
// (a * a) * (b * b) == ab * ab == số chính phương
// --> số chính phương * số chính phương = số chính phương
// vậy, trong bài toán này chỉ cần tìm một số không chính phương là xong
// số đó có thể không nhân cho ai cả, hoặc nhân với một số khác nó thì đều cho ra kết quả là số không chính phương

#include <math.h>
#include <iostream>
using namespace std;

//@ vars
const int nlim = 100;
const int alim = 1e4+1;
int n, a;

//@ calc
bool is_sqr(int a) {
	static double i = 1.0;
	return modf(sqrt(a), &i) == 0.0;
}

bool calc() {
	bool found = false;
	for (int i = 0; i < n; i++) {
		cin >> a;
		// to clear the cin, we must continue the loop
		if (!found) {
			if (!is_sqr(a)) {
				found = true;
			}
		}
	}
	return found;
}

//@ driver
int main() {
	int t; cin >> t;
	while (t--) {
		//@ inp
		cin >> n;
		if (calc()) { 
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

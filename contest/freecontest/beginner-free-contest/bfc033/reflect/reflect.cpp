#include <iostream>
#include <climits>
#include <math.h>
using namespace std;

long double l, d, x, t;

long long calc() {
	// cout << t << " " << x << endl;
	if (t == 90.0) return 0;
	// quãng đường (hình chiếu) từ khi xuất phát sang lần bật đầu tiên
	long double ch0 = x * tan(t*(atan(1)/45));
	// quãng được (hình chiếu) từ một lần bật sang lần bật kế tiếp
	long double ch1 = d * tan(t*(atan(1)/45));
	//
	if (l - ch0 < 0) {
		return 0;
	} else {
		return 1 + ((l - ch0) / ch1);
	}
}

int main() {
	int n; cin >> n;
	while (n--) {
		cin >> l >> d >> x >> t;
		if (t > 90.0) {
			t = 180.0 - t;
			x = d - x;
		}
		cout << calc() << endl;
	}
	// system("pause");
	return 0;
}

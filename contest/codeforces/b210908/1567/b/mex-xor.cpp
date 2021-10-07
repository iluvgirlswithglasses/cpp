#include <iostream>
using namespace std;

int a, b;

int xor_2a() {
	int r = 0;
	for (int i = a-1; (i+1) % 4 != 0; i--) r ^= i;
	return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> a >> b;
		int res = a, regnant = xor_2a();
		//
		if (b == regnant) {

		} else if ((regnant^b) != a) {
			res++;
		} else {
			res += 2;
		}
		//
		cout << res << "\n";
	}
	return 0;
}

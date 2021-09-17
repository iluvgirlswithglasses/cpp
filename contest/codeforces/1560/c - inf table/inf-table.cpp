#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		int i = floor(sqrt(k-1)), 
			l = i*i + 1, 
			r = (i+1)*(i+1);
		if (k - l - 1 < ((r - l) >> 1)) {
			cout << k-l+1 << " " << i+1 << "\n";
		} else {
			cout << i+1 << " " << r-k+1 << "\n";
		}
	}
	return 0;
}

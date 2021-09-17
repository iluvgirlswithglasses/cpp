#include <math.h>
#include <iostream>
using namespace std;

#define lli long long int

// a= row; b= col;
lli calc(int a, int b) {
	int lenA = a + 1;
	int lenB = b + 1;
	//
	lli larger = max(a, b);
	lli min_val = larger * larger + 1;
	lli max_val = (larger + 1) * (larger + 1);
	//
	if (a > b) {
		// row base
		if (lenA & 1) {
			// if odd
			return min_val + b;
		} else {
			// if even
			return max_val - b;
		}
	} else {
		// column base
		if (lenB & 1) {
			// if odd
			return max_val - a;
		} else {
			// if even
			return min_val + a;
		}
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		// take and shift
		int a, b; cin >> a >> b; 
		a -= 1; b -= 1;
		//
		cout << calc(a, b) << endl;
	}
	//
	return 0;
}

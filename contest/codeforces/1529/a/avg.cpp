#include <iostream>
using namespace std;

//
const int lim = 101;
//
int n, q;
int arr[lim];
//
int minVal;
int minCount;

int main() {
	cin >> q;
	while (q--) {
		// init
		minVal = lim;
		minCount = 0;
		//
		cin >> n;
		int a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a == minVal) minCount += 1;
			if (a < minVal) {
				minVal = a;
				minCount = 1;
			}
		}
		cout << n - minCount << endl;
	}
	return 0;
}

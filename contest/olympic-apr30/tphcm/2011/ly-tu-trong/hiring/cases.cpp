#include <iostream>
using namespace std;

int main() {
	int n = 500, m = 500;
	//
	int c = 0;
	for (int ty = 0; ty < m; ty++) {				// top-y
		for (int tx = 0; tx < n; tx++) {			// top-x
			for (int by = ty; by < m; by++) {		// bot-y
				for (int bx = tx; bx < n; bx++) {	// bot-x
					c += 1;
				}
			}
		}
	}
	cout << c;
	getchar();
	return 0;
}

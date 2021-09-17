#include <iostream>
using namespace std;

bool check(int n) {
	if (n < 2) return false;
	return (n & (n - 1)) == 0;
}

int main() {
	for (int i = 0; i <= 2048; i++) {
		if (check(i)) cout << i << " ";
	}
	getchar();
	return 0;
}

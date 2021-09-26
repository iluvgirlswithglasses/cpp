#include <iostream>
using namespace std;

#define u64 unsigned long long

void calc(int n) {
	if (n == 0) return;
	calc(n/2);
	cout << (n%2);
}

int main() {
	while (true) {
		u64 n; cin >> n;
		calc(n);
		cout << "\n";
	}
}

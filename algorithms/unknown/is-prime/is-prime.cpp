#include <iostream>
using namespace std;

bool is_prime(long long a) {
	if (a < 2) return false;
	for (long long i = 2; i * i <= a; i++) {
		if (a % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//
	while (true) {
		long long a; cin >> a;
		cout << is_prime(a) << endl;
	}
	return 0;
}

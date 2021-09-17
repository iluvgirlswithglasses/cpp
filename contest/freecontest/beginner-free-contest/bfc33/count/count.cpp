#include <iostream>
using namespace std;

#define ll long long
int n;

int calc(int n) {
	ll a = n, b = 1;
	// factorize
	for (ll i = 2; i * i <= n; i++) if (n % i == 0) {
		a *= i-1;
		b *= i;
		while (n % i == 0) n /= i;
	}
	if (n > 1) a *= n-1, b *= n;
	//
	return a / b;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		cout << calc(n) << endl;
	}
	//
	system("pause");
	return 0;
}

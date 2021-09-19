
/*
GCD(A) = X
xóa đi một số phần tử sao cho GCD(A) = Y > X
--> Y = kX
*/
#include <iostream>
#include <map>
using namespace std;

int __gcd(int a, int b) {
	if (b == 0) return a;
	return __gcd(b, a%b);
}

int gcd(int a, int b) {
	if (b > a) swap(a, b);
	return __gcd(a, b);
}

/**
 * 
 * */
const int N = 1e6+7, I = 1e9;
int n, res, a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	if (n == 1) {
		cout << I << "\n";
		return 0;
	}
	//
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//
	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = 0; j < n; j++) if (j != i) {
			x = gcd(a[j], x);
		}
		res = max(res, x);
	}
	cout << res << "\n";
	return 0;
}

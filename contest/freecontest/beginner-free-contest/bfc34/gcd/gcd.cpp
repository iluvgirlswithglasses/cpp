
/*
GCD(A) = X
xóa đi một số phần tử sao cho GCD(A) = Y > X
--> Y = kX
*/

#include <iostream>
using namespace std;

#define ll long long

const int N = 1e5+7, M = 5e6+7;
int n, x, a[N], k[M];
bool e[M];	// e[i] == false --> is_prime(i) == true;

int __gcd(int a, int b) {
	if (b == 0) return a;
	return __gcd(b, a%b);
}

int gcd(int a, int b) {
	if (b > a) swap(a, b);
	return __gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		x = gcd(a[i], x);
	}
	//
	int res = n;
	for (int i = 0; i < n; i++)
		k[a[i]/x]++;
	for (int i = 2; i < M; i++) if (!e[i]) {
		int cr = 0;
		for (int j = i; j < M; j+=i) {
			e[j] = true;
			cr += k[j];
		}
		res = min(res, n-cr);
	}
	//
	if (res == n) res = -1;
	cout << res << "\n";
	return 0;
}

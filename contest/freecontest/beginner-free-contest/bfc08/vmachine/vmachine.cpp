#include <iostream>
#include <math.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		cout << (int) log2(n)+1 << "\n";
		for (ll i = 1; i <= n; i <<= 1) {
			cout << i << " ";
		} cout << "\n";
	}
	return 0;
}

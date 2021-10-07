#include <iostream>
using namespace std;

#define ll long long
int n, r;

bool check(ll i) {
	i++;
	ll chunk = i&-i;
	if (!(chunk&1) && chunk >= 4) {
		return false;
	}
	return true;
}

int main() {
	cin >> n;
	for (ll i = n; check(i); i--) {
		r ^= i;
	}
	cout << r << "\n";
	return 0;
}

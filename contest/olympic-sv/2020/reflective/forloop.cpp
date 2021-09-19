#include <iostream>
using namespace std;

#define ll long long

ll calc(ll r) {
	ll res = 0;
	for (r>>=1; r>0; r>>=1)
		res += r;
	return res;
}

int main() {
	ll l, r; cin >> l >> r;
	ll res = calc(r) - calc(l-1);
	cout << res << "\n";
	return 0;
}

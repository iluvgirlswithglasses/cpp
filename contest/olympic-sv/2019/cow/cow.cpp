#include <iostream>
#include <math.h>
using namespace std;

#define ll long long
#define ld long double

int n;
ll l = 1e14;
ld a, b, x, y, r;

ld sqr(ld x) {
	return x * x;
}

ll calc() {
	ld cr = sqrt(sqr(a-x) + sqr(b-y)) - r;
	if (cr == floor(cr)) cr -= 1;
	return (ll) cr;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n; cin >> a >> b;
	while (n--) {
		cin >> x >> y >> r;
		l = min(l, calc());
	}
	cout << l << "\n";
	return 0;
}

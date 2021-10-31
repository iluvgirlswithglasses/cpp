#include <bits/stdc++.h>
using namespace std;

#define ld long double
ld x, y, a, b, c;

ld sqr(ld x) {
	return x*x;
}

void prf(ld a) {
	cout << setprecision(9) << fixed << a << " ";
}

void prf(ld a, ld b, ld c) {
	if (a > b) swap(a, b);
	prf(a); prf(b); prf(c); cout << "\n";
}

int main() {
	cin >> x >> y;
	ld delta = sqrt(sqr(x*2.0 + y*2.0) - (sqr(y) - sqr(x))*4.0);
	ld a = (y*2.0 + x*2.0 - delta) / 2.0, b = y - a, c = a + x;
	prf(a, b, c);
	return 0;
}

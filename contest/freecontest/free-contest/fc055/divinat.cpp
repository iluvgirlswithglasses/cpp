
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 27 16:32:26 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int S2N = 46341, S4N = 216;

/** eratos */
/*
int p[S2N], pcnt;
bool e[S2N];

void eratos() {
	for (int i = 2; i < S2N; i++) if (e[i] == 0) {
		p[pcnt++] = i;
		if (i < S4N) for (int j = i*i; j < S2N; j+=i) {
			e[j] = 1;
		}
	}
}

void fact(int n) {
	// fact
	for (int _i = 0, i = p[0]; _i < pcnt && i * i <= n; i = p[++_i]) {
		if (n % i == 0) f[fcnt++] = i;
		while (n % i == 0) n /= i;
	}
	if (n > 1) f[fcnt++] = n;
}
*/
 
/** drivers */
int f[S2N], fcnt;

void fact(int n) {
	for (int i = 2; i < S2N && i * i <= n; i++) {
		if (n % i == 0) f[fcnt++] = i;
		while (n % i == 0) n /= i;
	}
	if (n > 1) f[fcnt++] = n;
}

int calc(int n) {
	if (n < 2) return 0;
	//
	fact(n);
	for (int i = 0; i < fcnt; i++) {
		n /= f[i]; n *= f[i] - 1;
	}
	return n;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// eratos();
	int n; cin >> n;
	cout << calc(n) << "\n";
	return 0;
}

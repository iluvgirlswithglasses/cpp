
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Oct 18 19:39:31 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

#define ld long double

const int N = 1e5+7;
int n;
ld a[N], b[N], t, s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		t += a[i] / b[i];
	}
	t /= 2;
	//
	int i;
	for (i = 0; t > a[i]/b[i]; i++) {
		s += a[i];
		t -= a[i] / b[i];
	}
	s += t*b[i];
	cout << s << "\n";
	return 0;
}



/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 12 16:14:11 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 1e5+7;
int n, a[N];

void gen() {
	a[1] = true;
	for (int i = 2; i <= 316; i++) {
		int cr = i*i;
		while (cr < N) {
			a[cr] = true;
			cr *= i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	gen();
	cin >> n;
	for (int i = n; i > 0; i--) if (a[i]) {
		cout << i << "\n";
		break;
	}
	return 0;
}


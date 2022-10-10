
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Oct 10 21:25:06 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 1e5+7, I = 1004;
int n, s, a[N];

void prf(int mk) {
	for (int i = 0; i < n; i++)
		cout << (mk>>i&1);
	cout << "\n";
}

int calc() {
	int res = N;
	for (int mk = 0; mk < (1<<n); mk++) {
		int sum = 0, lef = N, rig = -1;
		for (int i = 1; i < n; i++) if (mk>>i&1) {
			sum += a[i];
			lef = min(lef, i);
			rig = max(rig, i);
		}
		if (sum == s) {
			res = min(res, rig - lef + 1);
			if (rig - lef + 1 == 5) prf(mk);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << calc() << "\n";
	return 0;
}

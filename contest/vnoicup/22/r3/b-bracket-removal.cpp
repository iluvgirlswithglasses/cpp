
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Jul  9 16:10:24 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 1e5+7;
int n, q, l, r, p[N];
char s[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q >> s;
	for (int i = 1; i < n; i++) {
		if (s[i-1] == '(' && s[i] == ')')
			p[i] = 1;
		else
			p[i] = 0;
		p[i] += p[i-1];
	}
	while (q--) {
		cin >> l >> r;
		cout << p[r-1] - p[l-1] << "\n";
	}
	return 0;
}

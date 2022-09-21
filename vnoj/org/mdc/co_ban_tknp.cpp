
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Sep 21 18:53:07 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int find() {
	int n, x, a;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a == x) return i;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << find() << "\n";
	return 0;
}

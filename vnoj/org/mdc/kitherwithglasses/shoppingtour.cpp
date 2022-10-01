
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  1 14:49:16 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
int n, x, a[N];

int calc() {
	for (int i = 0; i < n; i++) {
		if ((x -= a[i]) < 0) return i;
	}
	return n;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	cout << calc() << "\n";
	return 0;
}


/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Dec 27 10:19:23 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

int a, b;

bool is_prime(int i) {
	for (int j = 2; j <= b && j * j <= i; j++)
		if (i % j == 0) return false;
	return true;
}

int calc() {
	for (int i = a; i > b; i--) {
		if (is_prime(i)) return i;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> b >> a;
	cout << calc() << "\n";
	return 0;
}

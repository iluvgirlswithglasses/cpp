
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct  4 17:26:15 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// the simplest prime checking program

#include <iostream>
using namespace std;

bool is_prime(long long a) {
	if (a < 2) return false;
	for (long long i = 2; i * i <= a; i++) {
		if (a % i == 0) return false;
	}
	return true;
}

int main() {
	while (true) {
		long long a; cin >> a;
		cout << is_prime(a) << "\n";
	}
	return 0;
}

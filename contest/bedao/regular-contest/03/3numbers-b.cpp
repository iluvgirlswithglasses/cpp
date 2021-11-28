
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 28 20:19:43 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int n;

long long calc() {
	long long res = 0;
	//
	for (int i = 1; i <= n; i++) 
	for (int j = 1; i * j <= n; j++) 
	for (int k = 1; i * j * k <= n; k++) 
		res++;
	//
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cout << calc() << "\n";
	return 0;
}

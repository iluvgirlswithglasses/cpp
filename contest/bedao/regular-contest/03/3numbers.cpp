
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

/*
	for (int i = 1; i * i <= n; i++) {
		res++;
		for (int j = i+1; i * j <= n; j++) {
			res+=2;
		}
	}

	for (int i = 1; i <= n; i++) 
	for (int j = 1; i * j <= n; j++) 
	for (int k = 1; i * j * k <= n; k++) 
		res++;
*/

#include <iostream>
#include <cstdio>
using namespace std;

int n;

unsigned long long calc() {
	unsigned long long res = 0;
	// i <= j <= k
	for (int i = 1; i*i*i <= n; i++) {
		// i == j == k
		res++;
		// i == j
		for (int k = i+1; i*i*k <= n; k++) {
			res+=3;
		}
		// i != j && i != k
		for (int j = i+1; i*j*j <= n; j++) {
			// j == k
			res+=3;
			// j != k
			// --> k in (j, n/ij)
			res+=6ull*(n/(i*j) - j);
		}
	}
	//
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cout << calc() << "\n";
	return 0;
}

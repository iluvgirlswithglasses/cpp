
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 07 12:30:55 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

#define u64 unsigned long long
u64 n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	//
	u64 r = n / k;
	if (n % k != 0) r++;
	cout << r << "\n";
	return 0;
}


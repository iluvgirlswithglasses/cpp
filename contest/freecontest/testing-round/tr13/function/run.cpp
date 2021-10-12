
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Oct 11 22:38:57 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

#define ll long long
ll n, r;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	r = n>>1;
	if (n&1) r -= n;
	cout << r << "\n";
	return 0;
}


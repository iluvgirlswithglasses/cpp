
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 29 13:32:30 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

unsigned long long n, s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (unsigned long long i = 1; i <= n; i++)
		s += i*(n-i+1);
	cout << s << "\n";
	return 0;
}


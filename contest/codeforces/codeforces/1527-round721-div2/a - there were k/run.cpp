
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 22 19:39:04 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

// 2-secs 2-easy

#include <iostream>
using namespace std;

int n;

int calc() {
	return (1<<(31-__builtin_clz(n))) - 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		cout << calc() << "\n";
	}
	return 0;
}


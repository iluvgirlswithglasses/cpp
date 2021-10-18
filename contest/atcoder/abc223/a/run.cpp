
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 17 19:00:46 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x; cin >> x;
	if (x % 100 == 0 && x > 0) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	return 0;
}


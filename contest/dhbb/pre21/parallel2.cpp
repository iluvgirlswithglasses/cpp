
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 16 19:47:28 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		if ((a <= 1 && b <= 2) || (a <= 2 && b <= 1))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}

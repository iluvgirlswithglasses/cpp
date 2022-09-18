
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep 18 15:33:31 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long

/*
các số `x` không thỏa `a^2 - b^2` là các số:
	2*0, 2*1, 2*2
	2*(2k+1)
*/

int n, c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	if (n == 1)
		cout << "3\n";
	else if (n == 2)
		cout << "5\n";
	else {
		n -= 3;
		int add = n/3;	// số số 2*(2k+1) > 7
		cout << 7 + n + add << "\n";
	}
	return 0;
}

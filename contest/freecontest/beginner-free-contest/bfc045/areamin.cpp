
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Aug 22 17:21:00 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
using namespace std;

/*
note can be found at
https://github.com/iluvgirlswithglasses/cpp/contest/freecontest/beginner-free-contest/bfc045/areamin.pdf
*/

const double P = 3.14;
double n, a, b, x;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		x = n / (b*P + 4*a);
		cout << setprecision(1) << fixed << x * 4 << "\n";
	}
	return 0;
}

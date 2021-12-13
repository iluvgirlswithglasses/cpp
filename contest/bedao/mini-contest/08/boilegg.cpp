
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Dec 13 17:35:17 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cmath>
using namespace std;

/*
trứng lật --> số ước chẵn
úp --> số ước lẻ --> số chính phương
*/

#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll sq = round(sqrt(n));
		if (sq * sq == n)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}

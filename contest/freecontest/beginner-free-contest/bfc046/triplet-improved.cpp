
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep  6 13:59:59 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int n, s;
long long res = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for (int a = max(0, s-(n<<1)); a <= min(n, s); a++) {
		int d = s - a;		// == b+c <= 2n
		int r = min(n, d),	// the biggest that `b` or `c` can get
		    l = d - r;		// the lowest
		res += r-l+1;
	}
	cout << res << "\n";
	return 0;
}

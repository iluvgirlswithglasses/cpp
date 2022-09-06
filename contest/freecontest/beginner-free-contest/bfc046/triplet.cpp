
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep  6 13:45:50 2022
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
long long res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for (int a = 0; a <= n; a++)
	for (int b = 0; b <= n; b++) {
		int c = s - a - b;
		if (0 <= c && c <= n) res++;
	}
	cout << res << "\n";
	return 0;
}

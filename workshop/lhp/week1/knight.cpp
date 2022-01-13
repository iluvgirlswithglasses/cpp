
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Jan 13 13:18:52 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 204;
int  m, n, c, p, q;
bool b[N][N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> c;
	// edge case
	if (m == 1 || n == 1) {
		while (c--) cout << "-1\n";
	}
	//
	while (c--) {
		memset(b, 0, sizeof b);
		cin >> p >> q;
		b[p][q] = true;
	}
	return 0;
}

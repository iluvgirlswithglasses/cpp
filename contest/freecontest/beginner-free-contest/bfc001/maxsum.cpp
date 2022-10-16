
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 16 19:20:40 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define ll long long
const int N = 1004;
int n;
ll  a, s, mx;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s += a;
		mx = max(mx, s);
		if (s < 0) s = 0;
	}
	cout << mx << "\n";
	return 0;
}

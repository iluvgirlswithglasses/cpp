
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  8 10:10:15 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 1e6+7;
int  n;
bool a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j+=i)
			a[j] ^= 1;
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += a[i];
	cout << res << "\n";
	return 0;
}


/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Jul 10 23:20:51 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5+7;
int n, a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a+n);
	cout << max(
		abs(a[0] + a[1]), abs(a[n-1] + a[n-2])
	) << "\n";
	return 0;
}

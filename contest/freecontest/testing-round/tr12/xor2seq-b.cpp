
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 30 12:15:46 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 1e3+7;
int n, res, a[N], b[N], s[N*N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		s[i*n+j] = a[i] + b[j];
	//
	for (int i = 0; i < n*n; i++)
		res ^= s[i];
	cout << res << "\n";
	return 0;
}

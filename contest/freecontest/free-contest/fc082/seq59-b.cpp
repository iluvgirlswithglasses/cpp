
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Dec  3 20:14:56 2021
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

const int N = 1e5+7;
int n, a[N], b[N];
ll res = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	//
	for (int i = 1; i < n; i++)
	for (int j = 0; j < i; j++) {
		res = max(res, min(
			(ll) a[i]*a[j], (ll) b[i]*b[j]
		));
	}
	cout << res << "\n";
	return 0;
}

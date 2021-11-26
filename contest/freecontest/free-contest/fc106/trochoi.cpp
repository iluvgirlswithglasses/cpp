
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 26 17:35:50 2021
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

#define ll long long
const int N = 1e5+7;
int n, a[N];
ll res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	for (int i = 0, j = 1; i < n; i++, j *= -1) {
		res += j*a[i];
	}
	cout << abs(res) << "\n";
	return 0;
}

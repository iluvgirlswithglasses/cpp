
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Feb 12 16:41:03 2022
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

const int N = 104, K = 1e5+7;
int n, k, a[N];

const char* calc() {
	int mx = *max_element(a, a+n), d = 0;
	for (int i = 0; i < n; i++)
		d += mx - a[i];
	if (
		(k -= d) >= 0 &&
		k % n == 0
	) return "YES";
	return "NO";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << calc() << "\n";
	}
	return 0;
}


/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep  6 15:02:42 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 1e5+7;
int n, k, p, a[N][2];	// a[i]: {station, wait from}

bool check(int t) {
	int get = 0;
	for (int i = 0; i < n; i++)
		get += (t + a[i][0] > a[i][1]);	// t + a[i][0] - 1 >= a[i][1]
	return get >= k;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> p;
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1];
	//
	int l = 0, r = 1e9+7;
	while (l < r) {
		int m = (l + r) >> 1;
		if (check(m)) 
			r = m;
		else
			l = m+1;
	}
	cout << r << "\n";
	return 0;
}

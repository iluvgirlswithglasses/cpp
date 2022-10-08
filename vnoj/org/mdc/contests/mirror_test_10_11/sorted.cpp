
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  8 10:00:27 2022
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
int n, a[N];

bool asc() {
	for (int i = 1; i < n; i++)
		if (a[i-1] > a[i]) return false;
	return true;
}

bool dec() {
	for (int i = 1; i < n; i++)
		if (a[i-1] < a[i]) return false;
	return true;
}

bool check() {
	return asc() || dec();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n < 3 || check())
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

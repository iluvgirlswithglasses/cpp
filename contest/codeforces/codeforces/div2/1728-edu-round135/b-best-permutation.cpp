
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 12 13:23:06 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

// clearly: n <= max(x) < 2n
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		//
		if (n&1) {
			cout << "1 2 3 ";
			for (int i = 4; i+1 < n-1; i+=2)
				cout << i+1 << " " << i << " ";
		} else {
			for (int i = 1; i+1 < n-1; i+=2)
				cout << i+1 << " " << i << " ";
		}
		//
		cout << n-1 << " " << n-0 << "\n";
	}
	return 0;
}

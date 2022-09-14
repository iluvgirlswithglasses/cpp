
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Sep 14 11:32:15 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 104;
int  n;
char a[N], b[N];

const char* check() {
	for (int i = 0; i < n; i++) {
		if (a[i] == 'R' && b[i] != 'R') return "No\n";
		if (a[i] != 'R' && b[i] == 'R') return "No\n";
	}
	return "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		cout << check();
	}
	return 0;
}

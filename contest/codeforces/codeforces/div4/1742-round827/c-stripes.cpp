
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 14 13:06:29 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 8;
char m[N][N];

bool red() {
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < N; j++)
			if (m[i][j] != 'R') flag = false;
		if (flag) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		for (int i = 0; i < N; i++)
			cin >> m[i];
		if (red())
			cout << "R\n";
		else
			cout << "B\n";
	}
	return 0;
}

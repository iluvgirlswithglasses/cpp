
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct  2 11:49:43 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
using namespace std;

const int N = 1e6+7, R = 1e9+7;

string s[2];
int n, d[2][N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		cin >> s[0] >> s[1];
		n = s[0].length();
		d[0][0] = s[0][0] == 'X';
		d[1][0] = s[1][0] == 'X';
		//
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				if (s[j][i] == 'O')
					d[j][i] = 0;
				else
					d[j][i] = (d[j][i-1] + d[1-j][i-1]) % R;
			}
		}
		//
		cout << (d[0][n-1] + d[1][n-1]) % R << "\n";
	}
	return 0;
}

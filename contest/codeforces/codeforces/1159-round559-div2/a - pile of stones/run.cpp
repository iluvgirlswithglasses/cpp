
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 24 23:04:22 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '+') {
			cnt++;
		} else {
			cnt--;
		}
		if (cnt < 0) cnt = 0;
	}
	cout << cnt << "\n";
	return 0;
}


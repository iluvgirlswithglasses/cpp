
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 24 22:58:33 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	int n = s.length(),
		cnt = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'a') cnt++;
	cout << min((cnt<<1)-1, n);
	return 0;
}


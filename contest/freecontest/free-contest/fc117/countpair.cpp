
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 16 20:14:25 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
using namespace std;

string s;
int cnt;
long long res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	for (char c: s) {
		if (c == '1')
			cnt++;
		else if (c == '2')
			res += cnt;
	}
	cout << res << "\n";
	return 0;
}



/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 28 20:10:11 2021
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

int n, cnt[26];
string s;
long long res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	n = s.length();
	cnt[s[0] - 'a']++;
	for (int i = 1; i < n; i++) {
		res += i;
		res -= cnt[ s[i] - 'a' ];
		cnt[ s[i] - 'a' ]++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 2) {
			res++;
			break;
		}
	}
	cout << res << "\n";
	return 0;
}


/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec 11 22:09:39 2021
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
char s[N];
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	//
	if (s[0] == '?') s[0] = 'a';
	for (int i = 1; i < n; i++)
		if (s[i] == '?') s[i] = 'b';
	//
	int res = 0;
	for (int i = 0; i < n-1; i++) {
		if (s[i] == 'a' && s[i+1] == 'b') res++;
		if (s[i] == 'b' && s[i+1] == 'a') res--;
	}
	//
	cout << res << "\n";
	return 0;
}

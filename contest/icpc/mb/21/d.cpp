
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 08 16:03:41 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int N = 1e6+7;
int n;
bool mark[N];

int calc(string &s) {
	n = s.length();
	s = "1" + s + "1";
	memset(mark, 0, sizeof(mark[0]) * s.length());
	//
	int res = 0;
	for (int i = 1; i <= n; i++) if (s[i] == '1') {
		if (s[i-1] == '0' && mark[i-1] == 0)
			continue;
		if (s[i+1] == '0')
			mark[i+1] = 1;
		else
			res++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		string s; cin >> s;
		cout << calc(s) << "\n";
	}
	return 0;
}

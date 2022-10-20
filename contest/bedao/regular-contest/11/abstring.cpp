
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 20 09:41:44 2022
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

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e6+7;
int n;
string s;

int calc() {
	// "aba" is guaranteed
	int res = 3, cr = 0;
	int toggle = 0;
	//
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a' + toggle) {
			cr++;
			if ((cr&1) && cr > res)
				res = cr;
			toggle ^= 1;
		} else {
			cr = 0;
			toggle = 0;
			if (s[i] == 'a') i--;	// <-- check this char again
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	int res = calc();
	for (int i = 0; i < res; i++) {
		char c = 'a' + (i&1);
		cout << c;
	}
	cout << "\n";
	return 0;
}

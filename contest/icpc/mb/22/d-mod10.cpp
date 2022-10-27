
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 27 09:46:01 2022
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

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

// cnt[i]: how many times the char `i` is used;
int cnt[10];
// f[i]: i!
int f[10];
int y;

void prf() {
	string s;
	for (int i = 0; i < 10; i++)
		while (cnt[i]--) s += i + '0';
	for (int i = 1; i < s.length(); i++)
		if (s[i] == '1') s[i] == '0';
	cout << s << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	f[0] = f[1] = 1;
	for (int i = 2; i < 10; i++)
		f[i] = f[i-1] * i;
	//
	cin >> y;
	if (y == 1) {
		cout << "0\n";
	} else {
		for (int i = 9; i > 0; i--) {
			while (y >= f[i]) {
				cnt[i]++;
				y -= f[i];
			}
		}
		prf();
	}
	return 0;
}

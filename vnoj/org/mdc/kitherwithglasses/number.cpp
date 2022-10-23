
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 23 08:30:18 2022
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

string a;
int    sa;

void calc() {
	int len = a.length();
	while (len--) {
		cout << min(9, sa);
		sa = max(0, sa-9);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a;
	for (char c: a)
		sa += c - '0';
	calc();
	return 0;
}

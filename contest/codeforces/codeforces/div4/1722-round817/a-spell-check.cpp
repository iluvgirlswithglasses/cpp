
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 12 21:01:11 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int d[204];
const string K = "Timur";
int n;
string s;

bool check() {
	if (n != 5)
		return false;
	for (char c: K) 
		if (d[0+c] != 1) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		memset(d, 0, sizeof(d[0])*204);
		cin >> n >> s;
		for (char c: s) d[0+c]++;
		if (check())
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}

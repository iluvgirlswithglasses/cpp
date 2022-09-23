
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 23 15:58:29 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

int n;
string c, a, b;
vector<pi> pos;

bool has() {
	for (char i: c) if (i == '1') return true;
	return false;
}

void calc() {
	c = "0" + c;
	for (int i = 1; i < n; i++) {
		if (c[i] == '1' && c[i-1] == '0')
			pos.push_back({i-1, -1});
		if (c[i] == '1' && (i+1 == n || c[i+1] == '0'))
			pos.back().nd = i;
	}
	//
	a = b = string(n, '0');
	for (pi &p: pos) 
		a[p.st] = b[p.nd] = '1';
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> c;
	if (has()) {
		calc();
		cout << a << "\n" << b << "\n";
	} else {
		a = string(n-1, '0') + "1";
		cout << a << "\n" << a << "\n";
	}
	return 0;
}

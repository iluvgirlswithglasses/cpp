
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Oct 06 09:50:00 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <string>
using namespace std;

const int N = 102;
string s, t;
int n;

bool calc() {
	int c = 0;
	for (int i = 0; i < n; i++)
		if (s[i] != t[i]) c++;
	return c <= 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	n = s.length();
	//
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> t;
		if (t.length() == n)
			if (calc()) cout << i << " ";
	}
	cout << "\n";
	return 0;
}

